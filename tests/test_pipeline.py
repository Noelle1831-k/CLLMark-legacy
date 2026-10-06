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

from cllmark import bch, source_io

ROOT = Path(__file__).resolve().parents[1]
TOOLCHAIN = ROOT / ".benchmark-cache" / "toolchain"
HAS_PYTHON_GRAMMAR = (TOOLCHAIN / "python-languages.so").exists()

PYTHON_PROJECT = {
    "a.py": "def f(x):\n    if x == 1:\n        print(x)\n    y = [1, 2]\n    return x, y\n",
    "b.py": "def g(s):\n    for i in range(10):\n        s += i\n    print('done')\n    return s != 3\n",
    "c.py": "def h(n):\n    while n < 5:\n        n = n + 1\n    return\n",
}


class SourceDecodingTests(unittest.TestCase):
    def test_utf8_with_universal_newlines_like_text_mode_open(self):
        samples = [
            b"int main(){\r\n return 0;\r\n}\r",
            b"x = 1\n",
            "s = '中文'\n".encode(),
            b"",
            b"a ~{ b\n",
            b"esc \x1b[0m\n",
        ]
        for raw in samples:
            with tempfile.TemporaryDirectory() as directory:
                path = Path(directory) / "f.py"
                path.write_bytes(raw)
                with open(path, encoding="utf-8") as stream:
                    self.assertEqual(source_io.read_source(path), stream.read(), raw)

    def test_non_utf8_files_are_reported_with_their_path(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "latin.py"
            path.write_bytes("s = 'café'\n".encode("latin-1"))
            with self.assertRaisesRegex(ValueError, "latin.py is not UTF-8"):
                source_io.read_source(path)

    def test_reload_matches_disk_round_trip(self):
        for value in ["x = 1\n", "s = '中文'\n", "a\r\nb\rc\n"]:
            with tempfile.TemporaryDirectory() as directory:
                path = Path(directory) / "f.py"
                source_io.write_source(path, value)
                self.assertEqual(source_io.reload_written(value), source_io.read_source(path))


@unittest.skipUnless((ROOT / "corpus" / "dataset").is_dir(), "needs the corpus submodule")
class CorpusNormalizationTests(unittest.TestCase):
    PINNED_UPSTREAM = ("corpus/dataset/JS_projects/", "corpus/dataset/JS_repos/")

    def test_benchmark_sources_are_utf8_with_lf_line_endings(self):
        """Pinned upstream copies keep their bytes (verified by tools/setup_javascript.py); everything else is LF."""
        from benchmarks.common import discover_units

        config = json.loads((ROOT / "benchmarks" / "config.json").read_text())
        units, _ = discover_units(ROOT, config)
        offending = []
        for relative in sorted({path for unit in units for path in unit["source_files"]}):
            raw = (ROOT / relative).read_bytes()
            raw.decode("utf-8")
            if b"\r" in raw and not relative.startswith(self.PINNED_UPSTREAM):
                offending.append(relative)
        self.assertEqual(offending, [])


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
