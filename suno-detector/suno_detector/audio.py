"""Decode audio files to float arrays at 48 kHz."""
import shutil
import subprocess
from math import gcd

import numpy as np
import soundfile as sf
from scipy import signal

SR = 48000


def _ffmpeg_exe():
    exe = shutil.which("ffmpeg")
    if exe:
        return exe
    try:
        import imageio_ffmpeg
        return imageio_ffmpeg.get_ffmpeg_exe()
    except ImportError:
        return None


def _decode_ffmpeg(path):
    exe = _ffmpeg_exe()
    if exe is None:
        raise RuntimeError(f"cannot decode {path}: install ffmpeg or imageio-ffmpeg")
    out = subprocess.run(
        [exe, "-v", "error", "-i", str(path), "-map", "0:a:0", "-f", "f32le", "-ac", "2", "-ar", str(SR), "-"],
        capture_output=True, check=True,
    ).stdout
    return np.frombuffer(out, dtype="<f4").reshape(-1, 2), SR


def load(path):
    """Return (samples, 48000) with samples shaped (n, channels), float32."""
    try:
        x, sr = sf.read(str(path), dtype="float32", always_2d=True)
    except Exception:  # m4a, aac, opus-in-webm, ... go through ffmpeg
        x, sr = _decode_ffmpeg(path)
    if sr != SR:
        g = gcd(SR, sr)
        x = signal.resample_poly(x, SR // g, sr // g, axis=0).astype(np.float32)
    return x, SR
