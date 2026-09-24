"""Measure the detector on known Suno and known human-made files.

    python tools/evaluate.py --suno DIR --human DIR [--transforms] [--out results.json]

Suno files are scored with a leave-one-out reference (built from the other
Suno files that carry verified Suno Content Credentials), so no file is ever
tested against a pattern it helped build. With --transforms every file is
also re-encoded, resampled, trimmed, etc. through ffmpeg and scored again.
"""
import argparse
import json
import subprocess
import sys
import tempfile
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from suno_detector import audio, pattern, provenance  # noqa: E402

AUDIO_EXT = {".mp3", ".wav", ".flac", ".ogg", ".opus", ".m4a", ".aac", ".webm"}

# name -> (output extension, ffmpeg arguments). Real-world things that happen
# to a song after it leaves Suno.
TRANSFORMS = {
    "mp3 128k": (".mp3", ["-c:a", "libmp3lame", "-b:a", "128k"]),
    "mp3 128k 44.1k": (".mp3", ["-c:a", "libmp3lame", "-b:a", "128k", "-ar", "44100"]),
    "aac 128k 44.1k": (".m4a", ["-c:a", "aac", "-b:a", "128k", "-ar", "44100"]),
    "opus 96k": (".opus", ["-c:a", "libopus", "-b:a", "96k"]),
    "mp3 64k": (".mp3", ["-c:a", "libmp3lame", "-b:a", "64k"]),
    "trim 60s": (".wav", ["-ss", "31.2345", "-t", "60"]),
    "trim 30s": (".wav", ["-ss", "31.2345", "-t", "30"]),
    "mono": (".wav", ["-ac", "1"]),
    "gain -6dB": (".wav", ["-af", "volume=-6dB"]),
    "speed +1%": (".wav", ["-af", "asetrate=48480,aresample=48000"]),
}


def files_in(d):
    return sorted(p for p in Path(d).iterdir() if p.suffix.lower() in AUDIO_EXT)


def transform(src, name, tmp):
    ext, args = TRANSFORMS[name]
    out = Path(tmp) / (src.stem + "__" + name.replace(" ", "_").replace("%", "pct") + ext)
    subprocess.run([audio._ffmpeg_exe(), "-v", "error", "-y", "-i", str(src), "-map", "0:a:0",
                    "-ar", "48000", *args, str(out)], check=True)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--suno", required=True)
    ap.add_argument("--human", required=True)
    ap.add_argument("--transforms", action="store_true")
    ap.add_argument("--null-trials", type=int, default=0, help="fake patterns per file for the chance-score test")
    ap.add_argument("--out")
    args = ap.parse_args()

    suno, human = files_in(args.suno), files_in(args.human)
    signed = {p for p in suno if provenance.check_credential(p).status == "verified"}
    decoded = {p: audio.load(p)[0] for p in suno}
    full_ref = pattern.build_reference([decoded[p] for p in signed])
    refs = {p: pattern.build_reference([decoded[q] for q in signed if q != p]) if len(signed) > 1 else full_ref
            for p in suno}
    names = ["original"] + (list(TRANSFORMS) if args.transforms else [])

    rows = []
    with tempfile.TemporaryDirectory() as tmp:
        for kind, group in (("suno", suno), ("human", human)):
            for src in group:
                ref = refs.get(src, full_ref)
                for name in names:
                    path = src if name == "original" else transform(src, name, tmp)
                    x = audio.load(path)[0]
                    if len(x) < 2 * audio.SR:  # e.g. "trim 60s" of a 25 s clip
                        continue
                    r = pattern.detect(x, ref)
                    rows.append(dict(kind=kind, file=src.name, transform=name, signed=src in signed,
                                     z=round(r.z, 2), corr=round(r.corr, 3), verdict=r.verdict,
                                     windows=f"{r.windows_hit}/{r.windows_total}", seconds=round(r.seconds, 1)))
                    print(f"{kind:5s} {src.name[:40]:40s} {name:15s} z={r.z:6.1f} {r.verdict}", flush=True)

    print("\nSummary (pattern check only; Suno files without verified credentials are listed separately)")
    print(f"{'transform':16s} {'Suno detected':>14s} {'Suno weak':>10s} {'human flagged':>14s} {'human weak':>11s}")
    for name in names:
        s = [r for r in rows if r["kind"] == "suno" and r["signed"] and r["transform"] == name]
        h = [r for r in rows if r["kind"] == "human" and r["transform"] == name]
        cnt = lambda rs, v: sum(r["verdict"] == v for r in rs)
        print(f"{name:16s} {cnt(s, 'detected'):>6d} / {len(s):<5d} {cnt(s, 'weak'):>6d}     "
              f"{cnt(h, 'detected'):>6d} / {len(h):<5d} {cnt(h, 'weak'):>6d}")
    other = [r for r in rows if r["kind"] == "suno" and not r["signed"] and r["transform"] == "original"]
    for r in other:
        print(f"  unsigned Suno file {r['file']}: z={r['z']} {r['verdict']}")

    if args.null_trials:
        # Fake references with the real pattern's spectrum but random phase:
        # scores against these show how high the score gets by chance.
        rng = np.random.default_rng(0)
        spec = np.fft.rfft(full_ref, axis=1)
        folded = [pattern.preprocess(decoded[p] if p in decoded else audio.load(p)[0]).mean(axis=1)
                  for p in suno + human]
        null = []
        for _ in range(args.null_trials):
            phase = np.exp(2j * np.pi * rng.random(spec.shape))
            phase[:, 0] = 1
            fake = np.fft.irfft(spec * phase, pattern.PERIOD, axis=1)
            fake /= np.linalg.norm(fake, axis=1, keepdims=True)
            null += [pattern.match(f, fake).z for f in folded]
        null = np.array(null)
        print(f"\nChance scores ({len(null)} file x fake-pattern pairs): median {np.median(null):.1f}, "
              f"99.9th pct {np.percentile(null, 99.9):.1f}, max {null.max():.1f}; "
              f">= {pattern.WEAK_Z:g}: {(null >= pattern.WEAK_Z).sum()}, >= {pattern.DETECT_Z:g}: {(null >= pattern.DETECT_Z).sum()}")
    if args.out:
        Path(args.out).write_text(json.dumps(rows, indent=1))


if __name__ == "__main__":
    main()
