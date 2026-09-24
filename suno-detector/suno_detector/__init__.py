"""Detect Suno-generated audio from its Content Credentials and its 10 ms audio pattern."""
from dataclasses import asdict, dataclass

from . import audio, pattern, provenance

__all__ = ["analyze", "Report"]


@dataclass
class Report:
    path: str
    verdict: str
    summary: str
    credential: provenance.Credential
    tags: list
    pattern: pattern.PatternResult

    def to_dict(self):
        d = asdict(self)
        d["pattern"]["verdict"] = self.pattern.verdict
        return d


def _verdict(cred, tags, pat):
    if cred.status == "verified":
        return "suno", "Verified Suno Content Credentials"
    if cred.status == "modified":
        return "suno", "Suno Content Credentials present, but the file was edited after Suno signed it"
    if pat.verdict == "detected":
        return "likely-suno", "Suno's 10 ms audio pattern is present"
    if pat.verdict == "weak":
        return "inconclusive", "Weak match to Suno's audio pattern"
    if tags:
        return "unconfirmed", "Tags mention Suno, but nothing verifiable was found"
    return "no-markers", "No Suno markers found (this does not prove a human made it)"


def analyze(path, ref=None):
    cred = provenance.check_credential(path)
    tags = provenance.metadata_hints(path)
    x, _ = audio.load(path)
    pat = pattern.detect(x, ref)
    verdict, summary = _verdict(cred, tags, pat)
    return Report(str(path), verdict, summary, cred, tags, pat)
