# suno-detector

Checks an audio file for the markers Suno puts into its downloads and tells
you how confident it can be that the song came from Suno.

```
pip install .
suno-detect song.mp3 [more files...]      # or: python -m suno_detector song.mp3
suno-detect --json song.mp3               # machine-readable
```

```
Broken_in_Stereo.mp3
  Verdict:              SUNO - Verified Suno Content Credentials
  Content Credentials:  verified - signature valid, chains to the pinned Suno root, audio unchanged since signing
                        AI-generated, model chirp-hawk-t1, song 78ad74f9-..., signed 2026-09-18T02:17:48+00:00
  10 ms audio pattern:  detected - score 40.1 (detect >= 8), match 94%, 16/21 ten-second windows, grid offset 0 samples
  Metadata tags:        WOAS: https://suno.com/song/78ad74f9-...; ... (unverified, easy to fake or strip)
```

## What Suno puts in a download

Found by taking apart five songs downloaded from suno.com in September 2026.

1. **Text tags** (ID3): `made with suno; created=...; id=<song id>` and a
   `suno.com/song/<id>` link. Anyone can add or delete these, so they're
   reported as a hint only.
2. **Signed Content Credentials** (C2PA, stored in an ID3 `GEOB` frame). The
   manifest declares the audio `trainedAlgorithmicMedia` (AI-generated),
   names the model (`chirp-hawk-t1`, `chirp-hawk-engine-a`), carries the song
   ID, and hashes the whole file. It is signed (ES256) by
   *Suno Content Credentials*, issued by a self-signed *Suno C2PA Root CA*,
   with a DigiCert timestamp. It also names a soft binding
   `com.suno.fingerprint.v4`, which suggests Suno keeps a server-side audio
   fingerprint for finding songs whose metadata was stripped. We can't check
   that one without Suno's database.
3. **A 10 ms audio pattern.** A fixed waveform repeats every 480 samples
   (10 ms at 48 kHz) under the music. It is the same waveform in every song
   (0.73-0.89 correlation between different songs), it has separate mid and
   side parts, it sits roughly 27 dB below the music, and its level rises and
   falls with the music. Its polarity never flips, so it carries no hidden
   data; it only marks "Suno made this". We can't tell whether Suno added it
   on purpose as a watermark or whether it's a side effect of the model's
   decoder, which would also work in 10 ms frames. Either way it identifies
   the audio.

## How each check works

**Content Credentials.** The file is read with the official C2PA SDK
(`c2pa-python`), with the Suno root certificate as its only trust anchor.
The detector also checks that the root in the file's signing chain matches
the SHA-256 fingerprint pinned in `provenance.py`. Possible results:
- `verified`: signature valid, chains to Suno, file unchanged since signing
- `modified`: signed by Suno, but the file was edited after signing
- `other-signer`: a manifest from someone other than Suno
- `none`: no manifest

The pin was taken from files the user downloaded from suno.com
(trust on first use). Suno's root isn't on a public trust list as of this
writing.

**10 ms pattern** (`pattern.py`). The steps are:
1. Resample to 48 kHz, split into mid and side, and high-pass at 2 kHz.
2. Divide each 10 ms frame by the local loudness.
3. Average all frames on top of each other: anything locked to the 480-sample
   grid adds up, while the music averages toward zero.
4. Correlate the average against the stored reference
   (`data/reference_480.npy`) at every circular lag in quarter-sample steps.
   Trimmed files, and files that went through 44.1 kHz, still line up.
   Swapped channels and inverted polarity are also tried.

The score is the height of the best peak in robust standard deviations of all
other lags, after the reference's own self-correlation is removed. It is a
z-score: about 3 is typical for audio without the pattern.

## Verdicts

| Verdict | Meaning |
|---|---|
| `SUNO` | Credentials verify against the Suno root (or verify as Suno but the file was edited) |
| `LIKELY SUNO` | No valid credentials, but the 10 ms pattern scores 8 or more |
| `INCONCLUSIVE` | Pattern score between 6 and 8 |
| `UNCONFIRMED` | Only the text tags mention Suno |
| `NO SUNO MARKERS` | Nothing found. **This does not mean a human made it:** other AI generators, older Suno versions, Studio exports, or processed files can all land here |

## Evaluation

`tools/evaluate.py --suno DIR --human DIR --transforms --null-trials 100`.
Each Suno song is scored against a reference built only from the *other*
songs (leave-one-out). Test set: 4 signed Suno downloads, 1 Suno Studio
export, and 8 human-made recordings (the librosa example set: Brahms,
Tchaikovsky, ragtime piano, a vocal song, drum & bass, and others).

Pattern score, untouched files: Suno 12.5 / 16.8 / 21.7 / 34.8; human
2.6-5.1. Across 1,300 scores against fake patterns (same spectrum, random
waveform), the highest was 5.8.

| After... | Suno detected | Human flagged |
|---|---|---|
| nothing (original download) | 4/4 | 0/8 |
| MP3 128k, MP3 64k, Opus 96k | 4/4 each | 0/8 |
| MP3 or AAC at 44.1 kHz (streaming-style) | 4/4 | 0/8 |
| cutting a 30 s or 60 s excerpt at an odd offset | 4/4 | 0/6 |
| -6 dB volume | 4/4 | 0/8 |
| mono downmix | 2/4 (other 2 `INCONCLUSIVE`) | 0/8 |
| speeding up 1% | **0/4** | 0/8 |

The lowest Suno score apart from mono and speed changes was 8.8 (MP3 64k).
The highest human score was 6.1 (one `INCONCLUSIVE`, Tchaikovsky as MP3
128k). The threshold of 8 sits between them.

## Limitations

- **Tiny sample.** 4 songs from one account, 2 model versions. The pattern
  could differ in other Suno versions and could change with any Suno update.
  More Suno downloads, plus more real music as negatives, are the most useful
  next step.
- **Suno Studio exports** had neither the credentials nor the pattern (one
  file tested).
- **Speed or pitch changes** of even 1% break the pattern check, because the
  10 ms grid no longer lines up. Searching over speeds is possible but not
  implemented.
- **Mono** keeps only half the pattern, so scores drop to around 8.
- **Short clips.** Under about 30 s the pattern check gets unreliable, and
  10-second windows alone often fall short of the threshold.
- The Content Credentials and tags vanish on any re-encode or re-upload.
  Only the audio pattern survives those.

## Layout

- `suno_detector/provenance.py`: C2PA verification, root pinning, tag hints
- `suno_detector/pattern.py`: the 10 ms pattern detector
- `suno_detector/audio.py`: decoding (soundfile, falling back to ffmpeg) and resampling
- `suno_detector/data/`: the reference pattern (derived numbers, no audio) and the Suno root certificate
- `tools/build_reference.py`: rebuild the reference from Suno downloads with verified credentials
- `tools/evaluate.py`: the evaluation above
- `tests/`: `python -m pytest tests`
