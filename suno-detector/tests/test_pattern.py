import numpy as np
import pytest

from suno_detector import pattern

SR = 48000


def synthetic(seconds=60, pattern_db=-30, seed=0):
    """White-noise 'music' with the reference pattern mixed in 30 dB below it."""
    rng = np.random.default_rng(seed)
    n = seconds * SR
    music = rng.standard_normal((n, 2)) * 0.1
    if pattern_db is None:
        return music
    ref = pattern.load_reference()
    reps = n // pattern.PERIOD + 1
    mid, side = np.tile(ref[0], reps)[:n], np.tile(ref[1], reps)[:n]
    level = 0.1 * 10 ** (pattern_db / 20) * np.sqrt(pattern.PERIOD)  # ref rows are unit norm
    return music + level * np.stack([mid + side, mid - side], axis=1)


def test_detects_pattern():
    r = pattern.detect(synthetic())
    assert r.verdict == "detected"
    assert r.lag == 0 and r.flipped == ""


def test_trimmed_file_still_lines_up():
    r = pattern.detect(synthetic()[123:])
    assert r.verdict == "detected"
    assert r.lag == pattern.PERIOD - 123


def test_swapped_channels_flip_the_side():
    r = pattern.detect(synthetic()[:, ::-1])
    assert r.verdict == "detected"
    assert r.flipped == "side"


def test_inverted_polarity():
    r = pattern.detect(-synthetic())
    assert r.verdict == "detected"
    assert r.flipped == "both"


def test_noise_alone_is_not_flagged():
    for seed in range(5):
        assert pattern.detect(synthetic(pattern_db=None, seed=seed)).z < pattern.WEAK_Z


def test_rejects_tiny_clips():
    with pytest.raises(ValueError):
        pattern.detect(synthetic(seconds=1))
