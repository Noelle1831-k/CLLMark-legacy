"""Keyed pseudo-random function and the per-vote targets of the two schemes.

PRF(K, x) is HMAC-SHA256 under a domain label (`white`, `role`, `seq`, `tag`), so one output is never reused for two
purposes. A vote is named by its anchor key (hex of the anchor digest, see `anchors`); the bytes of that key are the
PRF input. The target bit of a vote is always whitened: XOR with PRF(K, white, key), which is independent of how the
code reads, so unmarked code agrees with any target in about half of its votes whatever form it naturally takes.

Scheme 1 (`s1`): a share `message_share` of the votes (chosen by `role`) carries the message bits (each vote names the
bit j it repeats), the others carry a tag PRF(K, tag, m || key). Scheme 2 (`s2`): every vote carries
PRF(K, seq, m || key).
"""

from __future__ import annotations

import hashlib
import hmac
from collections.abc import Sequence
from dataclasses import dataclass

SCHEME_NAMES = ("s1", "s2")
ANCHORS = ("tok", "struct")
_SHARE_SCALE = 1 << 64


@dataclass(frozen=True)
class Scheme:
    name: str  # "s1" | "s2"
    bits: int  # message length: 4 | 8
    anchor: str  # "tok" | "struct"
    message_share: float = 0.5  # scheme 1: the share of votes that carry message bits

    def __post_init__(self) -> None:
        if self.name not in SCHEME_NAMES:
            raise ValueError(f"scheme name must be one of {SCHEME_NAMES}: {self.name!r}")
        if self.anchor not in ANCHORS:
            raise ValueError(f"anchor must be one of {ANCHORS}: {self.anchor!r}")
        if not 1 <= self.bits <= 16:
            raise ValueError(f"message length must be 1..16 bits: {self.bits!r}")
        if not 0.0 < self.message_share < 1.0:
            raise ValueError(f"message_share must be in (0, 1): {self.message_share!r}")


def prf(key: bytes, label: str, data: bytes = b"") -> bytes:
    """HMAC-SHA256(key, label || 0x00 || data)."""
    return hmac.digest(key, label.encode("ascii") + b"\x00" + data, "sha256")


def prf_bit(key: bytes, label: str, data: bytes = b"") -> int:
    return prf(key, label, data)[0] & 1


def derive_key(seed: str | int, purpose: str = "cllmark-robust-key") -> bytes:
    """A 32-byte key from an experiment seed (experiments only; deployments keep a secret key)."""
    return hashlib.sha256(f"{purpose}\x00{seed}".encode()).digest()


def derive_message(seed: str | int, unit: str, bits: int) -> list[int]:
    """The message of one unit: uniform in 2**bits, from the seed and the unit id."""
    digest = hashlib.sha256(f"cllmark-robust-message\x00{seed}\x00{unit}".encode()).digest()
    value = int.from_bytes(digest, "big")
    return [(value >> shift) & 1 for shift in range(bits - 1, -1, -1)]


def message_bytes(scheme: Scheme, message: Sequence[int]) -> bytes:
    """The message as the PRF sees it: one byte (0 or 1) per bit."""
    if len(message) != scheme.bits or any(bit not in (0, 1) for bit in message):
        raise ValueError(f"message must be {scheme.bits} bits of 0/1: {list(message)!r}")
    return bytes(int(bit) for bit in message)


def white(key: bytes, vote: bytes) -> int:
    return prf_bit(key, "white", vote)


def role(key: bytes, scheme: Scheme, vote: bytes) -> int | None:
    """Scheme 1: the message bit a vote repeats, or None when the vote carries the tag."""
    digest = prf(key, "role", vote)
    if int.from_bytes(digest[:8], "big") >= int(scheme.message_share * _SHARE_SCALE):
        return None
    return int.from_bytes(digest[8:16], "big") % scheme.bits


def target(key: bytes, scheme: Scheme, message: bytes, vote: bytes) -> int:
    """The reading the vote `vote` must have for `message` (whitened)."""
    mask = white(key, vote)
    if scheme.name == "s2":
        return prf_bit(key, "seq", message + vote) ^ mask
    index = role(key, scheme, vote)
    if index is None:
        return prf_bit(key, "tag", message + vote) ^ mask
    return message[index] ^ mask
