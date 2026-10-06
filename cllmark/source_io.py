"""Read and write corpus files with the original text semantics, touching each file once.

Decoding is identical to ``open(path, encoding=chardet.detect(raw)["encoding"]).read()`` (the original scripts'
reader), including universal newlines; files are written back as UTF-8.
"""

from __future__ import annotations

import os
from pathlib import Path

import chardet

# chardet answers "ascii" for these inputs without running its probers: no high bytes, no NUL (UTF-16/32
# heuristics) and no ESC or "~{" (ISO-2022/HZ escapes).
_CHARDET_TRIGGERS = (b"\x00", b"\x1b", b"~{")


def detect_encoding(raw: bytes) -> str:
    """The encoding chardet reports for `raw` (with a fast path for plain ASCII)."""
    if raw and raw.isascii() and not any(marker in raw for marker in _CHARDET_TRIGGERS):
        return "ascii"
    encoding = chardet.detect(raw)["encoding"]
    if encoding is None:
        raise ValueError("cannot detect the file encoding")
    return encoding


def decode_source(raw: bytes) -> str:
    """Decode like a text-mode open(): detected encoding plus universal newlines."""
    return raw.decode(detect_encoding(raw)).replace("\r\n", "\n").replace("\r", "\n")


def read_source(path: str | os.PathLike[str]) -> str:
    """The decoded text of the file at `path`."""
    return decode_source(Path(path).read_bytes())


def write_source(path: str | os.PathLike[str], text: str) -> None:
    """Write `text` as UTF-8, creating parent directories."""
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(text.encode("utf-8"))


def reload_written(text: str) -> str:
    """The text a later read_source() returns after write_source(text), without the disk round trip."""
    return decode_source(text.encode("utf-8"))
