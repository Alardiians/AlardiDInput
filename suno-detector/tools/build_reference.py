"""Rebuild the 480-sample reference pattern from Suno downloads.

    python tools/build_reference.py SUNO_FILE [SUNO_FILE ...]

Only files with verified Suno Content Credentials are used, so an edited or
Studio-exported file can't dilute the pattern. Writes
suno_detector/data/reference_480.npy (derived statistics only, no audio).
"""
import sys
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from suno_detector import audio, pattern, provenance  # noqa: E402

OUT = Path(__file__).resolve().parents[1] / "suno_detector" / "data" / "reference_480.npy"


def main(paths):
    signals = []
    for p in paths:
        status = provenance.check_credential(p).status
        print(f"{'using' if status == 'verified' else 'skipping':8s} {p} ({status})")
        if status == "verified":
            signals.append(audio.load(p)[0])
    if len(signals) < 2:
        sys.exit("need at least two files with verified Suno Content Credentials")
    np.save(OUT, pattern.build_reference(signals))
    print(f"wrote {OUT} from {len(signals)} files")


if __name__ == "__main__":
    main(sys.argv[1:])
