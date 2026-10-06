"""Directory-level watermarking: a project is a flat directory of source files.

Analysis records the usable rule pairs of each file in `support_transform.json` inside the directory; embedding and
extraction read that file back. Each source file is decoded once and each embedded file is written once.
"""

from __future__ import annotations

import json
import os
from collections.abc import Iterable, Sequence
from pathlib import Path

from . import watermark
from .source_io import read_source, write_source
from .transform import StyleTransformer

SUPPORT_FILE = "support_transform.json"

PathLike = str | os.PathLike[str]


def load_project(directory: PathLike, names: Iterable[str] | None = None) -> dict[str, str]:
    """Decoded text of the project's files in slot order: every regular non-JSON file, or only `names`."""
    directory = Path(directory)
    if names is None:
        names = [entry.name for entry in directory.iterdir() if entry.is_file()]
    return {name: read_source(directory / name) for name in watermark.project_order(names)}


def read_support(directory: PathLike) -> watermark.Support:
    """The analysis stored in `directory`."""
    return json.loads((Path(directory) / SUPPORT_FILE).read_text(encoding="utf-8"))


def analyze_directory(directory: PathLike, language: str, transformer: StyleTransformer | None = None) -> int:
    """Analyze the project, store the result in its support file and return its capacity (number of usable slots)."""
    transformer = transformer or StyleTransformer(language)
    support = watermark.analyze(transformer, language, load_project(directory))
    with open(Path(directory) / SUPPORT_FILE, "w", encoding="utf-8") as stream:
        json.dump(support, stream, ensure_ascii=False, indent=4)
    return sum(len(pairs) for pairs in support.values())


def embed_directory(
    directory: PathLike, language: str, bits: Sequence[int], transformer: StyleTransformer | None = None
) -> list[str]:
    """Embed the codeword of `bits` into the analyzed project in place; returns the names of the files rewritten."""
    transformer = transformer or StyleTransformer(language)
    support = read_support(directory)
    files = load_project(directory, watermark.slot_files(support, bits))
    written = watermark.embed(transformer, language, files, support, bits)
    for name, code in written.items():
        write_source(Path(directory) / name, code)
    return sorted(written)


def extract_directory(
    directory: PathLike, language: str, bits: Sequence[int], transformer: StyleTransformer | None = None
) -> tuple[bool, bool]:
    """Check the analyzed project for the codeword of `bits`: (message matches, raw codeword matches)."""
    transformer = transformer or StyleTransformer(language)
    support = read_support(directory)
    files = load_project(directory, watermark.slot_files(support, bits))
    return watermark.extract(transformer, language, files, support, bits)
