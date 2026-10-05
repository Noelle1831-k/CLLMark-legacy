"""Regression tests for research validity, resumability and functional execution."""

import copy
import json
from pathlib import Path
import tempfile
import unittest

from benchmarks.common import digest, discover_units, parser_smoke, protocol_fingerprint, source_fingerprint, validate_config
from benchmarks.compare import compare, promote_baseline
from benchmarks.engine import reset_legacy_state
from benchmarks.metrics import summarize
from benchmarks.runner import load_rows, run_experiment, validate_workspace, verified_summary, verify_frozen_run
from benchmarks.utility import assemble_test, evaluate_utility, run_process


ROOT = Path(__file__).resolve().parents[1]
CONFIG = json.loads((ROOT / "benchmarks" / "config.json").read_text())


def measured_row(identity, role="generated", eligible=True, matched=True, before="PASS", after="PASS"):
    extraction = {"matched": matched, "raw_matched": matched, "correct_bits": 7 if matched else 0,
                  "expected_bit_count": 7, "elapsed_ms": 1.0}
    properties = {name: {"passed": 2, "trials": 2} for name in ["idempotence", "reversibility", "independence"]}
    properties.update({"errors": 0, "unsupported_pairs": 0})
    return {"id": identity, "cohort": identity.split("/")[0], "language": "python", "role": role, "status": "ok",
            "eligible": eligible, "original_extraction": extraction if eligible else None,
            "marked_extraction": extraction if eligible else None, "analysis_ms": 1.0, "embedding_ms": 1.0,
            "properties": properties, "syntax_before": {"answer.py": True}, "syntax_after": {"answer.py": eligible},
            "attacks": {}, "utility_before": {"status": before}, "utility_after": {"status": after if eligible else "NOT_EMBEDDED"}}


def summary(rows, full=True):
    manifest = {"run_id": "fixture", "manifest_sha256": "fixture", "git": {"commit": "fixture", "dirty": False},
                "source_fingerprint": "source", "dataset_fingerprint": "dataset", "protocol_fingerprint": "protocol",
                "environment_fingerprint": "environment", "config": {"jobs": 1}, "full": full,
                "units": [{"id": row["id"]} for row in rows]}
    return summarize(rows, manifest)


class MeasurementValidityTests(unittest.TestCase):
    def test_missing_oracles_never_count_as_pass(self):
        value = summary([measured_row("unknown/1", "unknown", before="NO_TEST_ORACLE", after="NO_TEST_ORACLE")])
        self.assertIsNone(value["aggregate"]["utility"]["retention"])
        self.assertEqual(value["aggregate"]["utility"]["oracle_units"], 0)

    def test_confusion_matrix_excludes_unknown_and_capacity_failures(self):
        rows = [measured_row("g/1"), measured_row("h/1", "human", matched=False),
                measured_row("u/1", "unknown"), measured_row("g/2", eligible=False)]
        detection = summary(rows)["aggregate"]["detection"]
        self.assertEqual((detection["tp"], detection["tn"], detection["fp"], detection["fn"]), (1, 1, 0, 0))
        self.assertEqual(summary(rows)["aggregate"]["capacity_coverage"], 0.75)

    def test_new_functional_failure_fails_gate(self):
        old = summary([measured_row("g/1")])
        candidate = summary([measured_row("g/1", after="FAIL")])
        result = compare(candidate, old, CONFIG["gates"])
        self.assertFalse(result["passed"])
        self.assertEqual(next(c for c in result["checks"] if c["metric"] == "new_functional_regressions")["sample_ids"], ["g/1"])

    def test_existing_failures_are_preserved_without_becoming_new(self):
        old = summary([measured_row("g/1", after="FAIL")])
        self.assertTrue(compare(old, old, CONFIG["gates"])["passed"])

    def test_removing_functional_oracle_or_original_pass_fails_gate(self):
        old = summary([measured_row("g/1")])
        for before, after in [("NO_TEST_ORACLE", "NO_TEST_ORACLE"), ("FAIL", "FAIL")]:
            new = summary([measured_row("g/1", before=before, after=after)])
            self.assertFalse(compare(new, old, CONFIG["gates"])["passed"])

    def test_cohort_regression_is_not_hidden_by_aggregate_gain(self):
        old = summary([measured_row("a/1"), measured_row("b/1", matched=False)])
        new = summary([measured_row("a/1", matched=False), measured_row("b/1")])
        self.assertEqual(old["aggregate"]["watermark_recovery_rate"], new["aggregate"]["watermark_recovery_rate"])
        self.assertFalse(compare(new, old, CONFIG["gates"])["passed"])

    def test_dataset_or_protocol_change_is_incomparable(self):
        old = summary([measured_row("g/1")])
        for field in ["dataset_fingerprint", "protocol_fingerprint", "environment_fingerprint"]:
            candidate = copy.deepcopy(old)
            candidate[field] = "changed"
            result = compare(candidate, old, CONFIG["gates"])
            self.assertFalse(result["comparable"])
            self.assertFalse(result["passed"])

    def test_smoke_cannot_pass_full_gate_or_become_baseline(self):
        value = summary([measured_row("g/1")], full=False)
        self.assertFalse(compare(value, value, CONFIG["gates"])["passed"])
        with tempfile.TemporaryDirectory() as temporary, self.assertRaises(ValueError):
            promote_baseline(value, Path(temporary) / "baseline.json", temporary)

    def test_lost_eligibility_cannot_inflate_recovery_silently(self):
        old = summary([measured_row("g/1"), measured_row("g/2", matched=False)])
        new = summary([measured_row("g/1"), measured_row("g/2", eligible=False)])
        self.assertGreater(new["aggregate"]["watermark_recovery_rate"], old["aggregate"]["watermark_recovery_rate"])
        self.assertFalse(compare(new, old, CONFIG["gates"])["passed"])

    def test_duplicate_or_missing_rows_are_not_complete(self):
        row = measured_row("g/1")
        self.assertFalse(summary([row, row])["complete"])


class ProvenanceAndResumeTests(unittest.TestCase):
    def test_full_comparison_cannot_silently_pass_without_a_reference(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with self.assertRaisesRegex(ValueError, "No pinned baseline"):
                run_experiment(root, CONFIG, root / "results", baseline=root / "missing.json")

    def test_torn_last_row_is_recovered(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "rows.jsonl"
            path.write_bytes(b'{"id":"a"}\n{"id":')
            self.assertEqual(load_rows(path), [{"id": "a"}])
            self.assertEqual(path.read_bytes(), b'{"id":"a"}\n')

    def test_complete_last_row_gets_missing_newline(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "rows.jsonl"
            path.write_bytes(b'{"id":"a"}')
            self.assertEqual(load_rows(path), [{"id": "a"}])
            self.assertTrue(path.read_bytes().endswith(b"\n"))

    def test_middle_corruption_is_not_silently_discarded(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "rows.jsonl"
            path.write_bytes(b'{"id":"a"}\nBROKEN\n{"id":"b"}\n')
            with self.assertRaises(ValueError):
                load_rows(path)

    def test_frozen_source_or_manifest_tampering_is_detected(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "source").mkdir()
            (root / "source" / "algorithm.py").write_text("version = 1\n")
            manifest = {"source_files": {"algorithm.py": digest(b"version = 1\n")}, "input_files": {},
                        "environment": {"parser_toolchain": {"grammars": {}}}}
            manifest["manifest_sha256"] = digest(manifest)
            verify_frozen_run(root, manifest)
            (root / "source" / "algorithm.py").write_text("version = 2\n")
            with self.assertRaises(ValueError):
                verify_frozen_run(root, manifest)

    def test_dirty_source_changes_fingerprint_without_commit(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            path = root / "algorithm.py"
            path.write_text("version = 1\n")
            before = source_fingerprint(root)[0]
            path.write_text("version = 2\n")
            self.assertNotEqual(source_fingerprint(root)[0], before)

    def test_measurement_change_requires_new_protocol_reference(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            for name in ["common.py", "engine.py", "utility.py", "metrics.py", "include/bits/stdc++.h"]:
                path = root / "benchmarks" / name
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text("version 1")
            before = protocol_fingerprint(CONFIG, root)
            (root / "benchmarks" / "engine.py").write_text("version 2")
            self.assertNotEqual(before, protocol_fingerprint(CONFIG, root))

    def test_original_input_change_is_detected_after_run(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            data = root / "corpus.txt"
            data.write_text("original")
            run = root / "run"
            run.mkdir()
            manifest = {"source_fingerprint": source_fingerprint(root)[0], "input_files": {"corpus.txt": {"sha256": digest(data.read_bytes())}}}
            self.assertTrue(validate_workspace(root, run, manifest))
            data.write_text("changed")
            self.assertFalse(validate_workspace(root, run, manifest))
            self.assertEqual(json.loads((run / "validation.json").read_text())["changed_inputs"], ["corpus.txt"])

    def test_summary_cannot_be_promoted_after_raw_results_are_altered(self):
        with tempfile.TemporaryDirectory() as temporary:
            run = Path(temporary)
            row = measured_row("g/1")
            manifest = {"run_id": "fixture", "source_files": {}, "input_files": {}, "environment": {"parser_toolchain": {"grammars": {}}},
                        "git": {"commit": "fixture", "dirty": False}, "source_fingerprint": "source", "dataset_fingerprint": "dataset",
                        "protocol_fingerprint": "protocol", "environment_fingerprint": "environment", "config": {"jobs": 1}, "full": True, "units": [{"id": "g/1"}]}
            manifest["manifest_sha256"] = digest(manifest)
            (run / "manifest.json").write_text(json.dumps(manifest))
            (run / "rows.jsonl").write_text(json.dumps(row) + "\n")
            (run / "summary.json").write_text(json.dumps(summarize([row], manifest)))
            (run / "validation.json").write_text('{"valid":true}')
            verified_summary(run)
            row["marked_extraction"]["matched"] = False
            (run / "rows.jsonl").write_text(json.dumps(row) + "\n")
            with self.assertRaises(ValueError):
                verified_summary(run)

    def test_inventory_retains_small_projects_and_does_not_mutate(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            project = root / "corpus" / "tiny"
            project.mkdir(parents=True)
            (project / "one.py").write_text("x = 1\n")
            config = {"cohorts": [{"name": "tiny", "path": "corpus", "language": "python", "level": "project", "role": "generated"}]}
            before = (project / "one.py").read_bytes()
            units, inventory = discover_units(root, config)
            self.assertEqual(len(units), 1)
            self.assertEqual(inventory[0]["available_units"], 1)
            self.assertEqual((project / "one.py").read_bytes(), before)

    def test_wrong_watermark_and_fractional_jobs_are_rejected(self):
        for field, value in [("watermark", [1, 0]), ("jobs", 1.5)]:
            config = copy.deepcopy(CONFIG)
            config[field] = value
            with self.assertRaises(ValueError):
                validate_config(config)


class UtilityExecutionTests(unittest.TestCase):
    def test_legacy_rule_globals_do_not_leak_between_phases_or_units(self):
        import python.transform8_for as rule
        rule.last_code = "previous unit"
        rule.last_identifiers = {"i", "j"}
        rule.identifiers = {"x"}
        reset_legacy_state("python")
        self.assertEqual(rule.last_code, "")
        self.assertEqual(rule.last_identifiers, set())
        self.assertEqual(rule.identifiers, set())

    def test_actual_language_registries_and_pinned_parsers_load(self):
        self.assertEqual(set(parser_smoke(ROOT)), {"python", "c", "cpp"})

    def test_cpp_body_reconstruction_uses_official_signature(self):
        problem = {"prompt": "#include <bits/stdc++.h>\nusing namespace std;\nint add(int a,int b){\n", "entry_point": "add", "test": "int main(){return add(2,3)==5?0:1;}"}
        code = assemble_test("cpp", "return a+b;\n}\n", problem, 1)
        self.assertIn("int add(int a,int b)", code)
        self.assertIn("int main()", code)

    def test_subprocess_timeout_is_enforced(self):
        import sys
        with tempfile.TemporaryDirectory() as temporary:
            result = run_process([sys.executable, "-c", "while True: pass"], temporary, 0.2, "timeout")
            self.assertTrue(result["timed_out"])
            self.assertLess(result["elapsed_ms"], 2000)

    def test_python_functional_failure_and_cache_invalidation(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            path = root / "MBPP_1.py"
            path.write_text("def add(a,b): return a+b\n")
            problem = {"entry_point": "add", "test": "def check(f): assert f(2,3)==5", "prompt": ""}
            unit = {"oracle": "mbxp", "level": "function", "language": "python", "source_files": ["MBPP_1.py"]}
            kwargs = (unit, root, {"python": {"MBPP/1": problem}}, CONFIG, root, {"compiler": "c++"}, root / "cache")
            first = evaluate_utility(*kwargs)
            self.assertEqual(first["status"], "PASS")
            self.assertTrue(evaluate_utility(*kwargs)["cache_hit"])
            path.write_text("def add(a,b): return a-b\n")
            second = evaluate_utility(*kwargs)
            self.assertEqual(second["status"], "FAIL")
            self.assertNotEqual(first["cache_key"], second["cache_key"])

    def test_cpp_compilation_and_real_assertion_failure(self):
        import shutil
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            path = root / "MBCPP_1.cpp"
            path.write_text("return a+b;\n}\n")
            problem = {"prompt": "#include <bits/stdc++.h>\nusing namespace std;\nint add(int a,int b){\n", "entry_point": "add", "test": "int main(){return add(2,3)==5?0:1;}"}
            unit = {"oracle": "mbxp", "level": "function", "language": "cpp", "source_files": ["MBCPP_1.cpp"]}
            kwargs = (unit, root, {"cpp": {"MBCPP/1": problem}}, CONFIG, root, {"compiler": shutil.which("c++")}, root / "cache")
            self.assertEqual(evaluate_utility(*kwargs)["status"], "PASS")
            path.write_text("return a-b;\n}\n")
            self.assertEqual(evaluate_utility(*kwargs)["status"], "FAIL")


if __name__ == "__main__":
    unittest.main()
