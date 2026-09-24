"""Detector for the fixed 10 ms waveform found in Suno audio.

Suno downloads carry a low-level waveform that repeats every 480 samples
(10 ms at 48 kHz). It is the same waveform in every song, it has separate
mid and side components, and its level follows the music's loudness.

Detection folds the audio at a 480-sample period (averaging every 10 ms
frame on top of each other), so anything locked to that grid adds up while
the music averages away. The result is correlated against a reference
pattern at every circular lag, so trimmed files still line up, and the peak
is expressed as a z-score against the correlation at all other lags.
"""
from dataclasses import dataclass
from importlib import resources

import numpy as np
from scipy import signal

from .audio import SR

PERIOD = 480          # 10 ms at 48 kHz
HIGHPASS_HZ = 2000    # most of the music's energy sits below this
UPSAMPLE = 4          # quarter-sample lag resolution
WINDOW_S = 10         # length of the per-window checks
DETECT_Z = 8.0        # see README "How the threshold was chosen"
WEAK_Z = 6.0

_SOS = signal.butter(8, HIGHPASS_HZ, "hp", fs=SR, output="sos")


def load_reference():
    """Reference pattern, shape (2, PERIOD): row 0 mid, row 1 side, each unit norm."""
    with resources.files(__package__).joinpath("data/reference_480.npy").open("rb") as f:
        return np.load(f)


def preprocess(x):
    """(n, channels) audio at 48 kHz -> (2, frames, PERIOD) high-passed, loudness-normalised mid/side."""
    x = np.asarray(x, dtype=np.float64)
    if x.shape[1] == 1:
        mid, side = x[:, 0], np.zeros(len(x))
    else:
        mid, side = x[:, :2].mean(1), (x[:, 0] - x[:, 1]) / 2
    y = signal.sosfiltfilt(_SOS, np.stack([mid, side]), axis=1)
    n = y.shape[1] // PERIOD
    frames = y[:, : n * PERIOD].reshape(2, n, PERIOD)
    # The pattern gets louder and quieter with the music, so give every
    # frame equal weight by dividing out the local level (100 ms average).
    e = (frames ** 2).sum(axis=(0, 2))
    e = np.convolve(e, np.ones(11) / 11, mode="same")
    floor = 1e-4 * np.median(e) + 1e-20
    return frames / np.sqrt(e + floor)[None, :, None]


@dataclass
class Match:
    z: float          # peak height in robust standard deviations of the other lags
    corr: float       # normalised correlation with the reference at the peak
    lag: float        # offset of the pattern grid in samples (quarter-sample resolution)
    flipped: str      # "" or which polarity flip matched ("mid", "side", "both")


def match(folded, ref):
    """Correlate a folded (2, PERIOD) block against the reference at every circular lag."""
    F = np.fft.rfft(folded, axis=1)
    R = np.fft.rfft(ref, axis=1)
    norm = np.linalg.norm(folded) * np.linalg.norm(ref) + 1e-30
    mid = np.fft.irfft(F[0] * np.conj(R[0]), PERIOD * UPSAMPLE) * UPSAMPLE / norm
    side = np.fft.irfft(F[1] * np.conj(R[1]), PERIOD * UPSAMPLE) * UPSAMPLE / norm
    # The reference correlated with itself, used to take a real match out
    # of the noise estimate (its sidelobes would otherwise inflate it).
    auto = np.fft.irfft((np.abs(R) ** 2).sum(axis=0), PERIOD * UPSAMPLE)
    auto /= auto[0]
    # Polarity inversion flips both channels, an L/R swap flips only the side.
    c, flip_side = max(((mid + side, False), (mid - side, True)), key=lambda v: np.abs(v[0]).max())
    k = int(np.argmax(np.abs(c)))
    resid = c - c[k] * np.roll(auto, k)
    med = np.median(resid)
    spread = 1.4826 * np.median(np.abs(resid - med)) + 1e-30
    z, corr = (c[k] - med) / spread, c[k]
    mid_flipped = bool(corr < 0)
    side_flipped = mid_flipped != flip_side
    flipped = {(False, False): "", (True, True): "both", (True, False): "mid", (False, True): "side"}[
        (mid_flipped, side_flipped)
    ]
    return Match(z=float(abs(z)), corr=float(abs(corr)), lag=k / UPSAMPLE, flipped=flipped)


@dataclass
class PatternResult:
    z: float                 # whole-file score
    corr: float
    lag: float
    flipped: str
    windows_hit: int         # windows scoring >= DETECT_Z on their own
    windows_total: int
    seconds: float

    @property
    def verdict(self):
        if self.z >= DETECT_Z:
            return "detected"
        if self.z >= WEAK_Z:
            return "weak"
        return "not found"


def detect(x, ref=None, window_s=WINDOW_S):
    """Run the pattern check on (n, channels) audio at 48 kHz."""
    ref = load_reference() if ref is None else ref
    if len(x) < 2 * SR:
        raise ValueError(f"only {len(x) / SR:.1f} s of audio; the pattern check needs at least 2 s")
    frames = preprocess(x)
    whole = match(frames.mean(axis=1), ref)
    per = int(window_s * SR / PERIOD)
    starts = range(0, frames.shape[1] - per + 1, per)
    hits = sum(match(frames[:, s : s + per].mean(axis=1), ref).z >= DETECT_Z for s in starts)
    return PatternResult(
        z=whole.z, corr=whole.corr, lag=whole.lag, flipped=whole.flipped,
        windows_hit=int(hits), windows_total=len(starts), seconds=frames.shape[1] * PERIOD / SR,
    )


def build_reference(signals):
    """Average the folded patterns of several Suno tracks into a reference (2, PERIOD)."""
    folded = [preprocess(x).mean(axis=1) for x in signals]
    base = folded[0] / np.linalg.norm(folded[0], axis=1, keepdims=True)
    acc = np.zeros_like(base)
    for f in folded:
        f = f / np.linalg.norm(f, axis=1, keepdims=True)
        # align on the joint mid+side correlation in case a file is offset
        c = sum(np.fft.irfft(np.fft.rfft(f[i]) * np.conj(np.fft.rfft(base[i])), PERIOD) for i in range(2))
        acc += np.roll(f, -int(np.argmax(c)), axis=1)
    return acc / np.linalg.norm(acc, axis=1, keepdims=True)
