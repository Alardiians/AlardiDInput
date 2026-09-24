"""Command line: python -m suno_detector FILE [FILE ...]"""
import argparse
import json
import sys

from . import analyze, pattern

LABELS = {
    "suno": "SUNO",
    "likely-suno": "LIKELY SUNO",
    "inconclusive": "INCONCLUSIVE",
    "unconfirmed": "UNCONFIRMED",
    "no-markers": "NO SUNO MARKERS",
}


def _print_report(r):
    c, p = r.credential, r.pattern
    print(r.path)
    print(f"  Verdict:              {LABELS[r.verdict]} - {r.summary}")
    line = f"{c.status} - {c.detail}"
    if c.status in ("verified", "modified"):
        extras = ["AI-generated" if c.ai_generated else "", f"model {c.model}" if c.model else "",
                  f"song {c.song_id}" if c.song_id else "", f"signed {c.signed_at}" if c.signed_at else ""]
        line += "\n" + " " * 24 + ", ".join(filter(None, extras))
    print(f"  Content Credentials:  {line}")
    print(f"  10 ms audio pattern:  {p.verdict} - score {p.z:.1f} (detect >= {pattern.DETECT_Z:g}), "
          f"match {p.corr:.0%}, {p.windows_hit}/{p.windows_total} ten-second windows"
          + (f", grid offset {p.lag:g} samples" if p.verdict != "not found" else "")
          + (f", polarity flipped ({p.flipped})" if p.flipped and p.verdict != "not found" else ""))
    if p.seconds < 30 and p.verdict != "detected":
        print(f"                        only {p.seconds:.0f} s of audio; under ~30 s the pattern check is unreliable")
    print(f"  Metadata tags:        {'; '.join(r.tags) if r.tags else 'nothing mentioning Suno'}"
          + (" (unverified, easy to fake or strip)" if r.tags else ""))


def main(argv=None):
    ap = argparse.ArgumentParser(prog="suno-detect", description=__doc__)
    ap.add_argument("files", nargs="+")
    ap.add_argument("--json", action="store_true", help="print machine-readable results")
    args = ap.parse_args(argv)
    results, failed = [], False
    for path in args.files:
        try:
            r = analyze(path)
        except Exception as e:
            failed = True
            print(f"{path}\n  error: {e}", file=sys.stderr)
            continue
        if args.json:
            results.append(r.to_dict())
        else:
            _print_report(r)
            print()
    if args.json:
        print(json.dumps(results, indent=2))
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
