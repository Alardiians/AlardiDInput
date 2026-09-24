import hashlib

import numpy as np
import soundfile as sf
from cryptography import x509
from cryptography.hazmat.primitives import serialization

from suno_detector import _verdict, pattern, provenance


def test_plain_wav_has_no_credentials(tmp_path):
    path = tmp_path / "plain.wav"
    sf.write(path, np.zeros((48000, 2), dtype=np.float32), 48000)
    assert provenance.check_credential(path).status == "none"
    assert provenance.metadata_hints(path) == []


def test_pinned_root_matches_bundled_certificate():
    cert = x509.load_pem_x509_certificate(provenance._suno_root_pem().encode())
    der = cert.public_bytes(serialization.Encoding.DER)
    assert hashlib.sha256(der).hexdigest() == provenance.SUNO_ROOT_SHA256


def _pat(z):
    return pattern.PatternResult(z=z, corr=0, lag=0, flipped="", windows_hit=0, windows_total=0, seconds=60)


def test_verdict_priorities():
    none = provenance.Credential("none")
    assert _verdict(provenance.Credential("verified"), [], _pat(0))[0] == "suno"
    assert _verdict(provenance.Credential("modified"), [], _pat(0))[0] == "suno"
    assert _verdict(none, [], _pat(pattern.DETECT_Z))[0] == "likely-suno"
    assert _verdict(none, [], _pat(pattern.WEAK_Z))[0] == "inconclusive"
    assert _verdict(none, ["COMM: made with suno"], _pat(0))[0] == "unconfirmed"
    assert _verdict(none, [], _pat(0))[0] == "no-markers"
