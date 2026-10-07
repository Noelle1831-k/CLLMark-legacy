"""tools/robust_calibrate.py: the calibration of the stable rule pairs on a few files of the default corpus."""

import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

from tests.robust_samples import HAS_GRAMMARS, ROOT


@unittest.skipUnless(HAS_GRAMMARS and (ROOT / "corpus" / "dataset" / "MBPP_G").is_dir(), "grammars or corpus missing")
class CalibrateTests(unittest.TestCase):
    def test_a_small_calibration_writes_the_table(self):
        with tempfile.TemporaryDirectory() as folder:
            output = Path(folder) / "pairs.json"
            done = subprocess.run(
                [
                    sys.executable,
                    str(ROOT / "tools" / "robust_calibrate.py"),
                    "--limit-files",
                    "12",
                    "--jobs",
                    "2",
                    "--min-usable",
                    "1",
                    "--output",
                    str(output),
                ],
                capture_output=True,
                text=True,
                cwd=ROOT,
                check=False,
            )
            self.assertEqual(done.returncode, 0, done.stderr)
            table = json.loads(output.read_text())
        self.assertEqual(table["criteria"], {"min_ratio": 0.95, "min_usable": 1})
        self.assertEqual(set(table["pairs"]), {"legacy", "extended"})
        self.assertEqual(set(table["calibration"]["files"]), {"python", "c", "cpp", "javascript"})
        self.assertFalse(
            any("codenet" in name.lower() for names in table["calibration"]["cohorts"].values() for name in names)
        )
        entry = table["pairs"]["legacy"]["python"]["tok"]
        self.assertTrue(entry["allowed"])
        self.assertEqual(set(entry["allowed"]) | set(entry["excluded"]), set(entry["stats"]))


if __name__ == "__main__":
    unittest.main()
