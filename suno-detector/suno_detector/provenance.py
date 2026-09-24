"""Content Credentials (C2PA) verification and metadata hints.

Suno signs its downloads with a C2PA manifest stored inside the file (an ID3
GEOB frame in MP3s). The signing chain ends at a self-signed
"Suno C2PA Root CA", which is not on any public trust list, so we pin it by
its SHA-256 fingerprint and hand it to the C2PA SDK as the only trust anchor.
"""
import hashlib
import json
import struct
from dataclasses import dataclass, field
from importlib import resources

import c2pa
import cbor2
from cryptography import x509

# Fingerprint of the root certificate seen in genuine suno.com downloads
# (Suno C2PA Root CA, valid 2026-07-23 to 2036-07-20).
SUNO_ROOT_SHA256 = "9641a21e22171a3389cbb9404c610bd6823cb0c823543e4598e2a6a9c5c438d1"
AI_SOURCE_TYPES = ("trainedAlgorithmicMedia", "compositeWithTrainedAlgorithmicMedia", "algorithmicMedia")


@dataclass
class Credential:
    status: str                      # verified | modified | other-signer | none | error
    detail: str = ""
    signer: str = ""
    signed_at: str = ""
    ai_generated: bool = False
    model: str = ""
    song_id: str = ""
    failures: list = field(default_factory=list)


def _suno_root_pem():
    return resources.files(__package__).joinpath("data/suno_c2pa_root.pem").read_text()


def _jumbf_boxes(buf, start, end, labels=()):
    """Yield (superbox labels, box type, payload) for every content box in a JUMBF tree."""
    off = start
    while off + 8 <= end:
        size, typ = struct.unpack(">I4s", buf[off : off + 8])
        hdr = 8
        if size == 1:
            size, hdr = struct.unpack(">Q", buf[off + 8 : off + 16])[0], 16
        if size < hdr or off + size > end:
            return
        body, body_end = off + hdr, off + size
        if typ == b"jumb":
            # a superbox is labelled by its first child, the jumd description
            # box: 8-byte header, 16-byte type UUID, 1 toggle byte, label
            jumd_size = struct.unpack(">I", buf[body : body + 4])[0]
            label = buf[body + 25 : body + jumd_size].split(b"\0")[0].decode("utf-8", "replace")
            yield from _jumbf_boxes(buf, body, body_end, labels + (label,))
        elif typ != b"jumd":
            yield labels, typ.decode("latin1"), buf[body:body_end]
        off += size


def _signing_chain(path, manifest_label):
    """Return the DER certificates from the active manifest's COSE signature."""
    buf = open(path, "rb").read()
    idx = buf.find(b"jumdc2pa")
    if idx < 12:
        return []
    store_start = idx - 12
    store_size = struct.unpack(">I", buf[store_start : store_start + 4])[0]
    for labels, typ, payload in _jumbf_boxes(buf, store_start, store_start + store_size):
        if typ == "cbor" and labels[-1:] == ("c2pa.signature",) and manifest_label in labels:
            sign1 = cbor2.loads(payload)
            sign1 = sign1.value if isinstance(sign1, cbor2.CBORTag) else sign1
            protected = cbor2.loads(sign1[0]) if sign1[0] else {}
            chain = protected.get(33) or sign1[1].get(33) or []
            return chain if isinstance(chain, list) else [chain]
    return []


def _root_fingerprint(chain):
    for der in chain:
        cert = x509.load_der_x509_certificate(der)
        if cert.subject == cert.issuer:
            return hashlib.sha256(der).hexdigest()
    return ""


def check_credential(path):
    """Verify the file's embedded C2PA manifest against the pinned Suno root."""
    try:
        ctx = c2pa.Context.from_dict({"trust": {"trust_anchors": _suno_root_pem()}})
        with c2pa.Reader(str(path), context=ctx) as reader:
            store = json.loads(reader.json())
    except Exception as e:  # the SDK raises private exception types
        if "ManifestNotFound" in type(e).__name__:
            return Credential("none", "no Content Credentials in this file")
        if "NotSupported" in type(e).__name__:
            return Credential("none", "file type cannot carry Content Credentials")
        return Credential("error", f"could not read Content Credentials: {e}")

    label = store.get("active_manifest", "")
    manifest = store.get("manifests", {}).get(label, {})
    sig = manifest.get("signature_info") or {}
    results = (store.get("validation_results") or {}).get("activeManifest") or {}
    cred = Credential(
        status="",
        signer=" / ".join(filter(None, [sig.get("issuer"), sig.get("common_name")])),
        signed_at=sig.get("time", ""),
        failures=[f["code"] for f in results.get("failure", [])],
    )
    for a in manifest.get("assertions", []):
        data = a.get("data") or {}
        if a.get("label", "").startswith("c2pa.actions"):
            cred.ai_generated |= any(
                str(act.get("digitalSourceType", "")).rsplit("/", 1)[-1] in AI_SOURCE_TYPES
                for act in data.get("actions", [])
            )
        elif a.get("label") == "com.suno.provenance":
            cred.model = data.get("systemVersion", "")
            cred.song_id = data.get("contentId", "")

    try:
        root = _root_fingerprint(_signing_chain(path, label))
    except Exception:
        root = ""
    suno_root = root == SUNO_ROOT_SHA256
    if suno_root and store.get("validation_state") == "Trusted" and not cred.failures:
        cred.status, cred.detail = "verified", "signature valid, chains to the pinned Suno root, audio unchanged since signing"
    elif suno_root:
        cred.status = "modified"
        cred.detail = "signed by Suno, but validation failed (" + ", ".join(cred.failures) + ") - the file was changed after signing"
    else:
        cred.status = "other-signer"
        cred.detail = f"signed by {cred.signer or 'an unknown signer'}, not the Suno root ({store.get('validation_state')})"
    return cred


def metadata_hints(path):
    """Plain-text tags that mention Suno. Anyone can add or remove these."""
    try:
        import mutagen
        tags = getattr(mutagen.File(str(path)), "tags", None)
    except Exception:
        return []
    hints = []
    for key, value in (tags.items() if tags else []):
        if str(key).startswith(("APIC", "GEOB", "USLT")):
            continue
        text = str(value)
        if "suno" in text.lower():
            hints.append(f"{key}: {text[:120]}")
    return hints
