"""In-memory watermark analysis, embedding and extraction for one project.

A project is a mapping {file name: decoded text}. Probes and rewrites run on that text (with the transformer's
parse cache), so the caller reads each file once and writes each embedded result once. Slot order, the mapping from
codeword bits to rules and the random choice for undecidable slots follow the original implementation exactly.
"""

from __future__ import annotations

import hashlib
import random
from collections import deque
from collections.abc import Iterable, Iterator, Mapping, Sequence

from . import bch
from .source_io import reload_written
from .transform import StyleTransformer

# Detect-only loop styles of C and C++: a file "has" one when the matcher of the paired style finds a node in the
# form it would produce. Embedding them leaves the code unchanged.
DETECT_ONLY = {"11": "7.7", "12": "7.8"}

Support = dict[str, list[str]]
"""File name -> names of the rule pairs usable in it, both in slot order."""


def project_order(names: Iterable[str]) -> list[str]:
    """Slot order of a project's files: by SHA-256 of the file name (not its content); JSON side files are skipped."""
    return sorted(
        (name for name in names if ".json" not in name),
        key=lambda name: hashlib.sha256(name.encode("utf-8")).hexdigest(),
    )


def probe(transformer: StyleTransformer, style: str, code: str) -> bool | None:
    """Whether `style` changes `code` beyond whitespace; None when the rule raised."""
    try:
        if style in DETECT_ONLY:
            return transformer.count_target_form(DETECT_ONLY[style], code) > 0
        new_code, changed, _ = transformer.apply(style, code)
        return bool(changed and new_code != code)
    except Exception:
        return None


def analyze(transformer: StyleTransformer, language: str, files: Mapping[str, str]) -> Support:
    """Rule pairs usable in each file, in slot order: a pair counts when either of its styles applies."""
    pairs = transformer.pairs
    return {
        name: [
            pair for pair, styles in pairs.items() if any(probe(transformer, style, files[name]) for style in styles)
        ]
        for name in project_order(files)
    }


def slots(support: Support, codeword: Sequence[int]) -> Iterator[tuple[str, str, int]]:
    """(file, pair, bit) assignments: codeword bits consume the usable pairs file by file."""
    queue = deque(codeword)
    for name, pairs in support.items():
        for pair in pairs:
            if not queue:
                return
            yield name, pair, queue.popleft()


def slot_files(support: Support, bits: Sequence[int]) -> set[str]:
    """Files that carry at least one bit of the codeword of `bits`."""
    return {name for name, _, _ in slots(support, bch.encode(bits))}


def embed(
    transformer: StyleTransformer, language: str, files: Mapping[str, str], support: Support, bits: Sequence[int]
) -> dict[str, str]:
    """Apply the style selected by each codeword bit; returns {file: text to write} for the files that changed."""
    written: dict[str, str] = {}
    for name, pair, bit in slots(support, bch.encode(bits)):
        style = transformer.pairs[pair][bit]
        if style in DETECT_ONLY:
            continue
        code = reload_written(written[name]) if name in written else files[name]
        try:
            new_code, changed, _ = transformer.apply(style, code)
        except Exception:
            continue
        if changed and new_code != code:
            written[name] = new_code
    return written


def extract(
    transformer: StyleTransformer, language: str, files: Mapping[str, str], support: Support, bits: Sequence[int]
) -> tuple[bool, bool]:
    """Expected-message extraction: (BCH-decoded message matches `bits`, raw codeword matches).

    A slot reads bit b when only the style for b no longer applies; when both or neither apply the bit is drawn at
    random, and a slot whose probe raised yields no bit.
    """
    codeword = bch.encode(bits)
    extracted = []
    for name, pair, bit in slots(support, codeword):
        styles = transformer.pairs[pair]
        marked = probe(transformer, styles[bit], files[name])
        unmarked = probe(transformer, styles[1 - bit], files[name])
        if marked is None or unmarked is None:
            continue
        if marked == unmarked:
            extracted.append(random.choice([0, 1]))
        else:
            extracted.append(bit if unmarked else 1 - bit)
    return bch.decode(extracted) == list(bits), extracted == codeword
