"""In-memory watermark pipeline: legacy-equivalent decoding and file I/O, and embed/extract behaviour."""

import os
from pathlib import Path
import random
import shutil
import tempfile
import unittest

import chardet

import code_io

ROOT = Path(__file__).resolve().parents[1]
TOOLCHAIN = ROOT / ".benchmark-cache" / "toolchain"

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


def legacy_read(raw):
    """What the original read_file_with_auto_encoding returned for these bytes."""
    encoding = chardet.detect(raw)["encoding"]
    if encoding is None:
        raise ValueError("无法检测文件编码")
    with tempfile.NamedTemporaryFile(delete=False) as handle:
        handle.write(raw)
    try:
        with open(handle.name, "r", encoding=encoding) as file:
            return file.read()
    finally:
        os.unlink(handle.name)


class SourceDecodingTests(unittest.TestCase):
    def test_fast_path_matches_chardet_and_text_mode(self):
        samples = [b"int main(){\r\n return 0;\r\n}\r", b"x = 1\n", "s = '中文'\n".encode("utf-8"),
                   "s = 'café'\n".encode("latin-1"), b"a ~{ b\n", b"esc \x1b[0m\n", b"\xef\xbb\xbfx = 1\n"]
        for raw in samples:
            self.assertEqual(outcome(code_io.decode_source, raw), outcome(legacy_read, raw), raw)

    def test_empty_file_is_rejected_like_chardet(self):
        with self.assertRaises(ValueError):
            code_io.decode_source(b"")

    def test_reload_matches_disk_round_trip(self):
        for value in ["x = 1\n", "s = '中文'\n", "a ~{ b\n"]:
            with tempfile.TemporaryDirectory() as directory:
                path = Path(directory) / "f.py"
                code_io.write_source(path, value)
                self.assertEqual(outcome(code_io.reload_written, value), outcome(code_io.read_source, path))


@unittest.skipUnless((TOOLCHAIN / "python-languages.so").exists(), "pinned parser libraries are not built")
class InMemoryPipelineTests(unittest.TestCase):
    def setUp(self):
        self.previous = Path.cwd()
        self.directory = Path(tempfile.mkdtemp(prefix="cllmark-pipeline-"))
        (self.directory / "build").mkdir()
        for name in ["styleList.json"]:
            shutil.copyfile(ROOT / name, self.directory / name)
        shutil.copyfile(TOOLCHAIN / "python-languages.so", self.directory / "build" / "python-languages.so")
        os.chdir(self.directory)

    def tearDown(self):
        os.chdir(self.previous)
        shutil.rmtree(self.directory)

    def test_embedding_round_trip(self):
        import folder_transform_check, watermark_bit, watermark_extract
        project = self.directory / "project"
        project.mkdir()
        for name, code in PYTHON_PROJECT.items():
            (project / name).write_text(code)
        capacity = folder_transform_check.check_support_transform("python", str(project))
        self.assertGreaterEqual(capacity, 7)
        random.seed(0)
        clean = watermark_extract.folder_bit_extract([1, 0, 1, 0], str(project), "python")
        before = {path.name: path.read_bytes() for path in project.glob("*.py")}
        watermark_bit.folder_bit_watermark([1, 0, 1, 0], str(project), "python")
        after = {path.name: path.read_bytes() for path in project.glob("*.py")}
        self.assertNotEqual(before, after)
        random.seed(0)
        self.assertTrue(watermark_extract.folder_bit_extract([1, 0, 1, 0], str(project), "python")[0])
        self.assertEqual(len(clean), 2)

    def test_rule_probe_errors_yield_no_bit(self):
        import watermark_core

        class Failing:
            def change_file_style(self, style, code):
                raise RuntimeError("rule bug")

        self.assertIsNone(watermark_core.probe(Failing(), "7.3", "x == 1\n"))


if __name__ == "__main__":
    unittest.main()
