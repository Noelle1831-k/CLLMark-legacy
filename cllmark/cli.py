"""Command line: `python -m cllmark {analyze,embed,extract}` on a flat project directory.

The input directory is never modified: `analyze` only reports, and `embed` writes the watermarked copy (with its
`support_transform.json`) to a new output directory, which `extract` can then check.
"""

from __future__ import annotations

import argparse
import json
import shutil
import sys
from collections.abc import Sequence
from pathlib import Path

from . import bch, directories, watermark
from .transform import LANGUAGES, StyleTransformer

EXIT_MATCH, EXIT_NO_MATCH, EXIT_INSUFFICIENT_CAPACITY = 0, 1, 2


def message(value: str) -> list[int]:
    if len(value) != bch.MESSAGE_LENGTH or set(value) - {"0", "1"}:
        raise argparse.ArgumentTypeError(f"expected {bch.MESSAGE_LENGTH} bits such as 1010, got {value!r}")
    return [int(bit) for bit in value]


def parser() -> argparse.ArgumentParser:
    root = argparse.ArgumentParser(prog="cllmark", description=__doc__.split("\n\n")[0])
    commands = root.add_subparsers(dest="command", required=True)

    def command(name: str, help_text: str, bits: bool) -> argparse.ArgumentParser:
        sub = commands.add_parser(name, help=help_text, description=help_text)
        sub.add_argument("directory", type=Path, help="flat directory of source files")
        sub.add_argument("-l", "--language", required=True, choices=LANGUAGES)
        if bits:
            sub.add_argument("-b", "--bits", required=True, type=message, help="4-bit message, e.g. 1010")
        return sub

    command("analyze", "Print the usable rule pairs of each file and the project's capacity.", bits=False)
    embed = command("embed", "Write a watermarked copy of the project.", bits=True)
    embed.add_argument("-o", "--output", required=True, type=Path, help="new directory for the watermarked copy")
    command("extract", "Check a watermarked copy (made by embed) for the message.", bits=True)
    return root


def analyze(arguments: argparse.Namespace) -> int:
    transformer = StyleTransformer(arguments.language)
    support = watermark.analyze(transformer, arguments.language, directories.load_project(arguments.directory))
    capacity = sum(len(pairs) for pairs in support.values())
    print(
        json.dumps(
            {"capacity": capacity, "required": bch.CODE_LENGTH, "support": support}, indent=2, ensure_ascii=False
        )
    )
    return EXIT_MATCH if capacity >= bch.CODE_LENGTH else EXIT_INSUFFICIENT_CAPACITY


def embed(arguments: argparse.Namespace) -> int:
    if arguments.output.exists():
        raise SystemExit(f"cllmark embed: {arguments.output} already exists")
    shutil.copytree(arguments.directory, arguments.output)
    transformer = StyleTransformer(arguments.language)
    capacity = directories.analyze_directory(arguments.output, arguments.language, transformer)
    if capacity < bch.CODE_LENGTH:
        print(f"capacity {capacity} < {bch.CODE_LENGTH}: not enough usable rules; nothing embedded", file=sys.stderr)
        return EXIT_INSUFFICIENT_CAPACITY
    written = directories.embed_directory(arguments.output, arguments.language, arguments.bits, transformer)
    print(f"capacity {capacity}; rewrote {len(written)} file(s) in {arguments.output}")
    return EXIT_MATCH


def extract(arguments: argparse.Namespace) -> int:
    matched, codeword_matched = directories.extract_directory(arguments.directory, arguments.language, arguments.bits)
    print(json.dumps({"message_matches": matched, "codeword_matches": codeword_matched}))
    return EXIT_MATCH if matched else EXIT_NO_MATCH


def main(argv: Sequence[str] | None = None) -> int:
    arguments = parser().parse_args(argv)
    return {"analyze": analyze, "embed": embed, "extract": extract}[arguments.command](arguments)
