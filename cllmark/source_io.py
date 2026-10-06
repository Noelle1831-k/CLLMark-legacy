"""Read and write source files as UTF-8, touching each file once.

Sources are read as strict UTF-8 with universal newlines (like a text-mode ``open``) and written back as UTF-8.
The corpus is normalized to UTF-8 with LF line endings (see `provenance/` in the data repository), so no encoding
detection is needed; a file that is not UTF-8 is reported with its path instead of being guessed at.
"""

from __future__ import annotations

import os
from pathlib import Path


def translate_newlines(text: str) -> str:
    """Universal newlines: CRLF and CR become LF."""
    return text.replace("\r\n", "\n").replace("\r", "\n")


def decode_source(raw: bytes) -> str:
    """Decode UTF-8 bytes like a text-mode open()."""
    return translate_newlines(raw.decode("utf-8"))


def read_source(path: str | os.PathLike[str]) -> str:
    """The text of the UTF-8 file at `path`."""
    try:
        return decode_source(Path(path).read_bytes())
    except UnicodeDecodeError as error:
        raise ValueError(f"{path} is not UTF-8 ({error.reason} at byte {error.start}); convert it to UTF-8") from error


def write_source(path: str | os.PathLike[str], text: str) -> None:
    """Write `text` as UTF-8, creating parent directories."""
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(text.encode("utf-8"))


def reload_written(text: str) -> str:
    """The text a later read_source() returns after write_source(text), without the disk round trip."""
    return translate_newlines(text)
