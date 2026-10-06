"""Watermark pipeline: original-equivalent decoding and file I/O, BCH coding, directory and command-line round trips."""

import contextlib
import io
import itertools
import json
import os
import random
import shutil
import tempfile
import unittest
from pathlib import Path
from typing import ClassVar

import chardet

from cllmark import bch, source_io

ROOT = Path(__file__).resolve().parents[1]
TOOLCHAIN = ROOT / ".benchmark-cache" / "toolchain"
HAS_PYTHON_GRAMMAR = (TOOLCHAIN / "python-languages.so").exists()

PYTHON_PROJECT = {
    "a.py": "def f(x):\n    if x == 1:\n        print(x)\n    y = [1, 2]\n    return x, y\n",
    "b.py": "def g(s):\n    for i in range(10):\n        s += i\n    print('done')\n    return s != 3\n",
    "c.py": "def h(n):\n    while n < 5:\n        n = n + 1\n    return\n",
}


def outcome(read, *arguments):
    try:
        return read(*arguments)
    except ValueError as error:
        return type(error)


def original_read(raw):
    """What the original reader (chardet + text-mode open) returned for these bytes."""
    encoding = chardet.detect(raw)["encoding"]
    if encoding is None:
        raise ValueError("cannot detect the file encoding")
    with tempfile.NamedTemporaryFile(delete=False) as handle:
        handle.write(raw)
    try:
        with open(handle.name, encoding=encoding) as file:
            return file.read()
    finally:
        os.unlink(handle.name)


class SourceDecodingTests(unittest.TestCase):
    def test_fast_path_matches_chardet_and_text_mode(self):
        samples = [
            b"int main(){\r\n return 0;\r\n}\r",
            b"x = 1\n",
            "s = '中文'\n".encode(),
            "s = 'café'\n".encode("latin-1"),
            b"a ~{ b\n",
            b"esc \x1b[0m\n",
            b"\xef\xbb\xbfx = 1\n",
        ]
        for raw in samples:
            self.assertEqual(outcome(source_io.decode_source, raw), outcome(original_read, raw), raw)

    def test_empty_file_is_rejected_like_chardet(self):
        with self.assertRaises(ValueError):
            source_io.decode_source(b"")

    def test_reload_matches_disk_round_trip(self):
        for value in ["x = 1\n", "s = '中文'\n", "a ~{ b\n"]:
            with tempfile.TemporaryDirectory() as directory:
                path = Path(directory) / "f.py"
                source_io.write_source(path, value)
                self.assertEqual(outcome(source_io.reload_written, value), outcome(source_io.read_source, path))


class BchTests(unittest.TestCase):
    MESSAGES: ClassVar = [list(bits) for bits in itertools.product([0, 1], repeat=4)]

    def test_codewords_are_systematic_and_distinct(self):
        codewords = [bch.encode(message) for message in self.MESSAGES]
        self.assertEqual(len({tuple(codeword) for codeword in codewords}), 16)
        for message, codeword in zip(self.MESSAGES, codewords, strict=True):
            self.assertEqual(codeword[:4], message)
        self.assertEqual(bch.encode([1, 0, 1, 0]), [1, 0, 1, 0, 0, 1, 1])

    def test_single_bit_errors_are_corrected(self):
        for message in self.MESSAGES:
            codeword = bch.encode(message)
            self.assertEqual(bch.decode(codeword), message)
            for position in range(7):
                received = list(codeword)
                received[position] ^= 1
                self.assertEqual(bch.decode(received), message, (message, position))


class FailingTransformer:
    def apply(self, style, code):
        raise RuntimeError("rule bug")


class ProbeTests(unittest.TestCase):
    def test_rule_probe_errors_yield_no_bit(self):
        from cllmark import watermark

        self.assertIsNone(watermark.probe(FailingTransformer(), "7.3", "x == 1\n"))


@unittest.skipUnless(HAS_PYTHON_GRAMMAR, "pinned parser libraries are not built")
class DirectoryPipelineTests(unittest.TestCase):
    def setUp(self):
        self.previous = Path.cwd()
        self.directory = Path(tempfile.mkdtemp(prefix="cllmark-pipeline-"))
        (self.directory / "build").mkdir()
        shutil.copyfile(TOOLCHAIN / "python-languages.so", self.directory / "build" / "python-languages.so")
        os.chdir(self.directory)
        self.project = self.directory / "project"
        self.project.mkdir()
        for name, code in PYTHON_PROJECT.items():
            (self.project / name).write_text(code)

    def tearDown(self):
        os.chdir(self.previous)
        shutil.rmtree(self.directory)

    def test_embedding_round_trip(self):
        from cllmark import directories

        self.assertGreaterEqual(directories.analyze_directory(self.project, "python"), 7)
        random.seed(0)
        clean = directories.extract_directory(self.project, "python", [1, 0, 1, 0])
        before = {path.name: path.read_bytes() for path in self.project.glob("*.py")}
        written = directories.embed_directory(self.project, "python", [1, 0, 1, 0])
        after = {path.name: path.read_bytes() for path in self.project.glob("*.py")}
        self.assertEqual(sorted(name for name in before if before[name] != after[name]), written)
        random.seed(0)
        self.assertTrue(directories.extract_directory(self.project, "python", [1, 0, 1, 0])[0])
        self.assertEqual(len(clean), 2)

    def test_command_line_never_modifies_its_input(self):
        from cllmark.cli import EXIT_MATCH, main

        before = {path.name: path.read_bytes() for path in self.project.iterdir()}
        output = self.directory / "marked"
        with contextlib.redirect_stdout(io.StringIO()) as report:
            self.assertEqual(main(["analyze", str(self.project), "--language", "python"]), EXIT_MATCH)
        self.assertGreaterEqual(json.loads(report.getvalue())["capacity"], 7)
        with contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(
                main(["embed", str(self.project), "-l", "python", "-b", "1010", "-o", str(output)]), EXIT_MATCH
            )
            random.seed(0)
            self.assertEqual(main(["extract", str(output), "-l", "python", "-b", "1010"]), EXIT_MATCH)
        self.assertEqual({path.name: path.read_bytes() for path in self.project.iterdir()}, before)
        self.assertTrue((output / "support_transform.json").exists())
        with self.assertRaises(SystemExit):
            main(["embed", str(self.project), "-l", "python", "-b", "1010", "-o", str(output)])


if __name__ == "__main__":
    unittest.main()
