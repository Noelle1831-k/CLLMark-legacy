"""Read and write corpus files with the legacy text semantics, touching each file once.

The original scripts reopened a file (and re-ran chardet) for every rule probe and
wrote it back after every embedded bit. The pipeline now decodes a file once,
keeps its text in memory and persists only the final result. Decoding stays
identical to ``open(path, encoding=chardet.detect(raw)["encoding"]).read()``.
"""

from pathlib import Path

import chardet

# chardet answers "ascii" for these inputs without running its probers: no high
# bytes, no NUL (UTF-16/32 heuristics) and no ESC or "~{" (ISO-2022/HZ escapes).
_CHARDET_TRIGGERS = (b"\x00", b"\x1b", b"~{")


def detect_encoding(raw: bytes) -> str:
    if raw and raw.isascii() and not any(marker in raw for marker in _CHARDET_TRIGGERS):
        return "ascii"
    encoding = chardet.detect(raw)["encoding"]
    if encoding is None:
        raise ValueError("无法检测文件编码")
    return encoding


def decode_source(raw: bytes) -> str:
    """Decode like a text-mode open(): detected encoding plus universal newlines."""
    return raw.decode(detect_encoding(raw)).replace("\r\n", "\n").replace("\r", "\n")


def read_source(path) -> str:
    return decode_source(Path(path).read_bytes())


def write_source(path, text: str) -> None:
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(text.encode("utf-8"))


def reload_written(text: str) -> str:
    """Text a later read_source() returns after write_source(text), without the disk round trip."""
    return decode_source(text.encode("utf-8"))
