"""The CodeNet stdin/stdout oracle, its checkers, config validation, the importer and the cross-variant report."""

import contextlib
import copy
import importlib.util
import io
import json
import shutil
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from benchmarks import codenet, rule_sets, utility  # noqa: E402


def quiet(function, *args, **kwargs):
    with contextlib.redirect_stdout(io.StringIO()):
        return function(*args, **kwargs)


def load_tool(name):
    spec = importlib.util.spec_from_file_location(name, ROOT / "tools" / (name + ".py"))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


NODE = shutil.which("node")
CONFIG = {
    "seed": 7,
    "compile_timeout_seconds": 30,
    "test_timeout_retries": 0,
    "problem_files": {"codenet": "problems.jsonl"},
    "codenet": {"problem_file": "codenet", "time_factor": 1},
}
ENVIRONMENT = {
    "python_executable": sys.executable,
    "python": sys.version,
    "compiler": shutil.which("c++"),
    "javascript": {"node": NODE, "node_version": "test"},
}
ADD_CASES = [
    {"input": "1 2\n", "expected": "3\n", "set": "sample"},
    {"input": "10 20\n", "expected": "30\n", "set": "test"},
]
SOURCES = {
    "python": ("py", "a, b = map(int, input().split())\nprint(a + b)\n"),
    "c": ("c", '#include <stdio.h>\nint main(){int a,b;scanf("%d %d",&a,&b);printf("%d\\n",a+b);return 0;}\n'),
    "cpp": ("cpp", "#include <iostream>\nint main(){int a,b;std::cin>>a>>b;std::cout<<a+b<<std::endl;return 0;}\n"),
    "javascript": (
        "js",
        "const [a, b] = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split(/\\s+/).map(Number);\n"
        "console.log(a + b);\n",
    ),
}


def problem(cases=None, checker="token", limit=5000):
    return {
        "task_id": "p00001",
        "time_limit_ms": limit,
        "checker": checker,
        "test_cases": cases if cases is not None else ADD_CASES,
    }


class CheckerTests(unittest.TestCase):
    def test_token_checker(self):
        self.assertTrue(codenet.check("token", "1 2\n3\n", "1   2 3")[0])
        ok, why = codenet.check("token", "1 2", "1 3")
        self.assertFalse(ok)
        self.assertIn("token #2", why)
        self.assertFalse(codenet.check("token", "1 2", "1")[0])
        self.assertFalse(codenet.check("token", "0.1", "0.1000001")[0])

    def test_float_tolerance(self):
        checker = "token+float:1e-6"
        self.assertTrue(codenet.check(checker, "3.14159265", "3.1415926")[0])
        self.assertTrue(codenet.check(checker, "1000000.0", "1000000.5")[0])  # relative tolerance for large values
        self.assertFalse(codenet.check(checker, "1.0", "1.00001")[0])
        self.assertFalse(codenet.check(checker, "1.0 2.0", "1.0")[0])
        self.assertFalse(codenet.check(checker, "yes 1.0", "no 1.0")[0])
        self.assertFalse(codenet.check(checker, "nan", "inf")[0])

    def test_unknown_checker(self):
        for value in ["exact", "float:1e-6", "", None]:
            with self.assertRaises(ValueError):
                codenet.check(value, "1", "1")


class OracleTests(unittest.TestCase):
    def evaluate(self, language, code, cases=None, **options):
        temporary = Path(tempfile.mkdtemp())
        self.addCleanup(shutil.rmtree, temporary, ignore_errors=True)
        extension = SOURCES[language][0]
        directory = temporary / "clean"
        directory.mkdir()
        (directory / f"p00001.{extension}").write_text(code, encoding="utf-8")
        unit = {"oracle": codenet.ORACLE, "language": language, "source_files": [f"corpus/G/p00001.{extension}"]}
        config = copy.deepcopy(CONFIG)
        config["codenet"]["time_factor"] = options.pop("time_factor", 1)
        problems = {"codenet": {"p00001": problem(cases, **options)}}
        arguments = (unit, directory, problems, config, temporary, ENVIRONMENT, temporary / "cache")
        return codenet.evaluate_utility(*arguments), arguments

    def test_pass_in_every_language(self):
        for language, (_, code) in SOURCES.items():
            if language == "javascript" and not NODE:
                continue
            with self.subTest(language=language):
                result, arguments = self.evaluate(language, code)
                self.assertEqual(result["status"], "PASS", result)
                self.assertEqual((result["cases_total"], result["cases_passed"]), (2, 2))
                self.assertEqual(result["verdict_counts"], {"AC": 2})
                self.assertEqual(result["test_kind"], "codenet_stdio_cases")
                self.assertFalse(result["cache_hit"])
                self.assertTrue((arguments[1] / ".utility" / "result.json").is_file())
                self.assertTrue(codenet.evaluate_utility(*arguments)["cache_hit"])

    def test_c_wrong_answer_and_runtime_error(self):
        wrong = SOURCES["c"][1].replace("a+b", "a-b")
        result, _ = self.evaluate("c", wrong)
        self.assertEqual(result["status"], "FAIL")
        self.assertEqual(result["verdict_counts"], {"WA": 2})
        self.assertEqual(result["first_failure"]["verdict"], "WA")
        crashing = "#include <stdlib.h>\nint main(){exit(3);}\n"
        result, _ = self.evaluate("c", crashing)
        self.assertEqual(result["status"], "FAIL")
        self.assertEqual(result["verdict_counts"], {"RE": 2})
        self.assertIn("exit code 3", result["cases"][0]["detail"])

    def test_c_compile_error(self):
        result, _ = self.evaluate("c", "int main( {")
        self.assertEqual(result["status"], "COMPILE_ERROR")
        self.assertEqual(result["cases_passed"], 0)

    def test_python_syntax_error(self):
        result, _ = self.evaluate("python", "def (:\n")
        self.assertEqual(result["status"], "COMPILE_ERROR")

    def test_python_time_limit_skips_the_remaining_cases(self):
        cases = [*ADD_CASES, {"input": "3 4\n", "expected": "7\n", "set": "test"}]
        result, arguments = self.evaluate("python", "while True:\n    pass\n", cases, limit=200)
        self.assertEqual(result["status"], "TIMEOUT")
        self.assertEqual([c["verdict"] for c in result["cases"]], ["TLE", "SKIPPED", "SKIPPED"])
        self.assertEqual(result["verdict_counts"], {"TLE": 1, "SKIPPED": 2})
        self.assertFalse(codenet.evaluate_utility(*arguments)["cache_hit"])  # timeouts are not cached

    def test_float_checker_applies(self):
        code = "print(1 / 3)\n"
        cases = [{"input": "", "expected": "0.3333333\n", "set": "test"}]
        self.assertEqual(self.evaluate("python", code, cases, checker="token+float:1e-6")[0]["status"], "PASS")
        self.assertEqual(self.evaluate("python", code, cases, checker="token")[0]["status"], "FAIL")

    def test_missing_problem(self):
        temporary = Path(tempfile.mkdtemp())
        self.addCleanup(shutil.rmtree, temporary, ignore_errors=True)
        (temporary / "p9.py").write_text("print(1)\n")
        unit = {"oracle": codenet.ORACLE, "language": "python", "source_files": ["x/p9.py"]}
        result = codenet.evaluate_utility(unit, temporary, {"codenet": {}}, CONFIG, temporary, ENVIRONMENT, temporary)
        self.assertEqual(result, {"status": "NO_TEST_ORACLE", "task_id": "p9"})

    def test_other_oracles_are_delegated(self):
        temporary = Path(tempfile.mkdtemp())
        self.addCleanup(shutil.rmtree, temporary, ignore_errors=True)
        unit = {"oracle": "none", "level": "function", "language": "python", "source_files": ["x/a.py"]}
        arguments = (unit, temporary, {}, CONFIG, temporary, ENVIRONMENT, temporary)
        self.assertEqual(codenet.evaluate_utility(*arguments), utility.evaluate_utility(*arguments))
        self.assertEqual(codenet.evaluate_utility(*arguments)["status"], "NO_TEST_ORACLE")


class ConfigTests(unittest.TestCase):
    def read(self, name):
        return json.loads((ROOT / "benchmarks" / name).read_text())

    def test_codenet_configs_validate(self):
        for name in ["", "-extended", "-node", "-node-extended"]:
            with self.subTest(name=name):
                config = self.read(f"config-codenet{name}.json")
                self.assertIs(codenet.validate_config(config), config)
                self.assertEqual(len(config["cohorts"]), 8)
                self.assertTrue(all(c["oracle"] == codenet.ORACLE for c in config["cohorts"]))
                self.assertEqual(config["cohorts"][0]["oracle"], codenet.ORACLE)  # not replaced by the stand-in

    def test_invalid_codenet_settings(self):
        base = self.read("config-codenet.json")
        for mutate in [
            lambda c: c.pop("codenet"),
            lambda c: c["codenet"].update(time_factor=0),
            lambda c: c["codenet"].update(time_factor=True),
            lambda c: c["codenet"].update(problem_file="missing"),
            lambda c: c["cohorts"][0].update(level="project"),
        ]:
            config = copy.deepcopy(base)
            mutate(config)
            with self.assertRaises(ValueError):
                codenet.validate_config(config)

    def test_default_configs_are_unchanged(self):
        config = self.read("config.json")
        self.assertIs(codenet.validate_config(config), config)
        self.assertNotIn("codenet_oracle_sha256", rule_sets.protocol_config(config, ROOT))
        marked = rule_sets.protocol_config(self.read("config-codenet.json"), ROOT)
        self.assertEqual(
            marked["codenet_oracle_sha256"], utility.digest((ROOT / "benchmarks" / "codenet.py").read_bytes())
        )
        with self.assertRaises(ValueError):
            utility_config = copy.deepcopy(self.read("config-codenet.json"))
            from benchmarks.common import validate_config

            validate_config(utility_config)  # the common validator alone does not know the oracle


def build_dataset(root):
    """A two-problem dataset repository (p00001, p00002, plus p00000 with code but no tests, JS only for p00001)."""
    cases = [{"input": "1\n", "expected": "1\n", "set": "test"}]
    languages = {"python": "py", "c": "c", "cpp": "cpp", "js": "js"}
    (root / "hf").mkdir(parents=True)
    for language in languages:
        pids = ["p00001"] if language == "js" else ["p00001", "p00002"]
        rows = [
            {
                "problem_id": pid,
                "source": "AIZU",
                "title": "T " + pid,
                "test_cases": cases,
                "time_limit_ms": 1000,
                "memory_limit_mb": 256,
            }
            for pid in pids
        ]
        (root / "hf" / f"{language}.jsonl").write_text("".join(json.dumps(r) + "\n" for r in rows))
    for pid, checker in [("p00001", "token+float:1e-6"), ("p00002", "token")]:
        (root / "testdata" / pid).mkdir(parents=True)
        (root / "testdata" / pid / "meta.json").write_text(json.dumps({"checker": {"type": checker}}))
    for pid in ["p00000", "p00001"]:  # p00002 has no generated code
        for extension in languages.values():
            (root / "generated" / pid).mkdir(parents=True, exist_ok=True)
            (root / "generated" / pid / f"sol.{extension}").write_text(f"gen {pid} {extension}\n")
    for pid, extensions in [("p00001", list(languages.values())), ("p00002", ["py", "c", "cpp"])]:
        for extension in extensions:
            (root / "solutions" / pid).mkdir(parents=True, exist_ok=True)
            (root / "solutions" / pid / f"ref.{extension}").write_text(f"ref {pid} {extension}\n")
    for command in [["init", "-q"], ["add", "-A"], ["-c", "user.name=t", "-c", "user.email=t@t", "commit", "-qm", "x"]]:
        subprocess.check_call(["git", "-C", str(root), *command])
    return subprocess.check_output(["git", "-C", str(root), "rev-parse", "HEAD"], text=True).strip()


class ImporterTests(unittest.TestCase):
    def test_import_a_small_dataset(self):
        importer = load_tool("import_codenet")
        with tempfile.TemporaryDirectory() as temporary:
            source, root = Path(temporary) / "dataset", Path(temporary) / "repo"
            source.mkdir()
            commit = build_dataset(source)
            (root / "benchmarks").mkdir(parents=True)
            (root / "benchmarks" / "codenet.lock.json").write_text(
                json.dumps({"repository": "unused", "commit": commit, "output": "external/codenet"})
            )
            self.assertEqual(quiet(importer.main, ["--source", str(source)], root=root), 0)
            output = root / "external" / "codenet"
            self.assertEqual((output / "dataset" / "Python_G" / "p00001.py").read_text(), "gen p00001 py\n")
            self.assertEqual((output / "dataset" / "CPP_H" / "p00002.cpp").read_text(), "ref p00002 cpp\n")
            self.assertEqual(
                {p.name for p in (output / "dataset").iterdir()},
                {f"{d}_{r}" for d in ["Python", "C", "CPP", "JS"] for r in "GH"},
            )
            self.assertFalse((output / "dataset" / "Python_G" / "p00000.py").exists())
            rows = [json.loads(line) for line in (output / "problems.jsonl").read_text().splitlines()]
            self.assertEqual([r["task_id"] for r in rows], ["p00001", "p00002"])
            self.assertEqual([r["checker"] for r in rows], ["token+float:1e-6", "token"])
            self.assertEqual(rows[0]["time_limit_ms"], 1000)
            self.assertEqual(rows[0]["test_cases"][0]["expected"], "1\n")
            report = json.loads((output / "import-report.json").read_text())
            self.assertEqual(report["commit"], commit)
            self.assertEqual(report["groups"]["Python_G"], 1)
            self.assertEqual(report["groups"]["Python_H"], 2)
            self.assertEqual(report["groups"]["JS_H"], 1)
            excluded = {(e["group"], tuple(e["problems"])) for e in report["excluded"]}
            self.assertIn(("generated", ("p00000",)), excluded)
            self.assertIn(("Python_G", ("p00002",)), excluded)
            self.assertIn(("JS_H", ("p00002",)), excluded)
            # Idempotent: unchanged input leaves the output alone; a damaged output is rebuilt.
            marker = (output / "problems.jsonl").stat().st_mtime_ns
            quiet(importer.main, ["--source", str(source)], root=root)
            self.assertEqual((output / "problems.jsonl").stat().st_mtime_ns, marker)
            (output / "dataset" / "C_G" / "p00001.c").write_text("damaged\n")
            quiet(importer.main, ["--source", str(source)], root=root)
            self.assertEqual((output / "dataset" / "C_G" / "p00001.c").read_text(), "gen p00001 c\n")
            self.assertFalse((root / "external" / "codenet.tmp").exists())
            with self.assertRaises(SystemExit):
                quiet(importer.main, ["--source", str(source), "--commit", "0" * 40], root=root)

    def test_differing_test_cases_are_an_error(self):
        importer = load_tool("import_codenet")
        with tempfile.TemporaryDirectory() as temporary:
            source = Path(temporary) / "dataset"
            source.mkdir()
            commit = build_dataset(source)
            rows = [json.loads(line) for line in (source / "hf" / "c.jsonl").read_text().splitlines()]
            rows[0]["test_cases"] = [{"input": "9\n", "expected": "9\n", "set": "test"}]
            (source / "hf" / "c.jsonl").write_text("".join(json.dumps(r) + "\n" for r in rows))
            root = Path(temporary) / "repo"
            (root / "benchmarks").mkdir(parents=True)
            (root / "benchmarks" / "codenet.lock.json").write_text(
                json.dumps({"repository": "unused", "commit": commit, "output": "external/codenet"})
            )
            with self.assertRaises(SystemExit):
                quiet(importer.main, ["--source", str(source), "--commit", commit], root=root)

    def test_python_reference_adapters_are_unwrapped(self):
        importer = load_tool("import_codenet")
        program = b"import sys\nprint(sum(map(int, sys.stdin.read().split())))\n"
        encoded = __import__("base64").b64encode(program).decode()
        adapter = (
            "def solve(data: str) -> str:\n"
            '    """Run the reference submission for this task on one complete stdin."""\n'
            "    import base64, os, subprocess, sys, tempfile\n"
            f"    src = base64.b64decode('{encoded}')\n"
            "    return ''\n"
        ).encode()
        self.assertEqual(importer.unwrap_adapter(adapter), program)
        self.assertIsNone(importer.unwrap_adapter(program))


class ReportTests(unittest.TestCase):
    def test_report_from_synthetic_rows(self):
        report_tool = load_tool("codenet_report")

        def row(cohort, language, role, name, before, after, rules=("self_assignment",), eligible=True):
            return {
                "id": f"{cohort}/{name}", "cohort": cohort, "language": language, "role": role, "status": "ok",
                "eligible": eligible, "capacity": 9, "analysis_ms": 1.0, "embedding_ms": 2.0, "syntax_after": {"f": True},
                "embedding_slots": [{"rule": r} for r in rules],
                "marked_extraction": {"matched": True, "correct_bits": 7},
                "original_extraction": {"matched": False},
                "attacks": {"flip_1": {"fully_applied": True, "extraction": {"matched": False}}},
                "properties": {"idempotence": {"passed": 1, "trials": 1}},
                "utility_before": before, "utility_after": after,
            }  # fmt: skip

        passed = {"status": "PASS", "cases_total": 2, "cases_passed": 2}
        failed = {
            "status": "FAIL",
            "cases_total": 2,
            "cases_passed": 1,
            "first_failure": {"name": "case-1", "verdict": "WA"},
        }
        rows = [
            row("codenet_c_generated", "c", "generated", "a", passed, passed),
            row("codenet_c_generated", "c", "generated", "b", passed, failed, rules=("self_assignment", "x")),
            row("codenet_c_human", "c", "human", "a", failed, {"status": "NOT_EMBEDDED"}, eligible=False),
            {"id": "codenet_c_human/z", "cohort": "codenet_c_human", "language": "c", "role": "human", "status": "harness_error"},
        ]  # fmt: skip
        report = report_tool.analyse([{"directory": "d", "run_id": "r", "variant": "file/legacy", "rows": rows}])
        self.assertEqual(len(report["regressions"]), 1)
        self.assertEqual(report["regressions"][0]["rules"], ["self_assignment", "x"])
        rules = {r["rule"]: (r["regressed_units"], r["paired_units"]) for r in report["rules"]}
        self.assertEqual(rules, {"self_assignment": (1, 2), "x": (1, 1)})
        self.assertEqual(report["cases"][0]["units_partially_regressed"], 1)
        self.assertEqual([r["id"] for r in report["human_failures"]], ["codenet_c_human/a"])
        text = report_tool.render(report)
        self.assertIn("N/A", text)
        self.assertIn("## 5.", text)


if __name__ == "__main__":
    unittest.main()
