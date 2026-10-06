"""Regression tests for research validity, resumability and functional execution."""

import copy
import io
import json
import tempfile
import unittest
import unittest.mock
from pathlib import Path

from benchmarks.common import (
    digest,
    discover_units,
    javascript_environment,
    parser_smoke,
    project_paths,
    protocol_fingerprint,
    source_fingerprint,
    unit_file_names,
    validate_config,
)
from benchmarks.compare import compare, promote_baseline
from benchmarks.metrics import summarize
from benchmarks.runner import load_rows, run_experiment, validate_workspace, verified_summary, verify_frozen_run
from benchmarks.utility import (
    assemble_test,
    enable_exercism_tests,
    evaluate_utility,
    exercism_solution,
    load_problems,
    run_process,
    run_test,
)

ROOT = Path(__file__).resolve().parents[1]
CONFIG = json.loads((ROOT / "benchmarks" / "config.json").read_text())
HAS_CORPUS = (ROOT / "corpus" / "dataset").is_dir()


def javascript_ready():
    """Whether the pinned JavaScript environment (make setup-javascript) is installed."""
    try:
        javascript_environment(ROOT)
    except Exception:
        return False
    return True


HAS_JAVASCRIPT = HAS_CORPUS and javascript_ready()
NEEDS_JAVASCRIPT = "needs the corpus submodule and the pinned JavaScript environment"


def measured_row(identity, role="generated", eligible=True, matched=True, before="PASS", after="PASS"):
    extraction = {
        "matched": matched,
        "raw_matched": matched,
        "correct_bits": 7 if matched else 0,
        "expected_bit_count": 7,
        "elapsed_ms": 1.0,
    }
    properties = {name: {"passed": 2, "trials": 2} for name in ["idempotence", "reversibility", "independence"]}
    properties.update({"errors": 0, "unsupported_pairs": 0})
    return {
        "id": identity,
        "cohort": identity.split("/")[0],
        "language": "python",
        "role": role,
        "status": "ok",
        "eligible": eligible,
        "original_extraction": extraction if eligible else None,
        "marked_extraction": extraction if eligible else None,
        "analysis_ms": 1.0,
        "embedding_ms": 1.0,
        "properties": properties,
        "syntax_before": {"answer.py": True},
        "syntax_after": {"answer.py": eligible},
        "attacks": {},
        "utility_before": {"status": before},
        "utility_after": {"status": after if eligible else "NOT_EMBEDDED"},
    }


def summary(rows, full=True):
    manifest = {
        "run_id": "fixture",
        "manifest_sha256": "fixture",
        "git": {"commit": "fixture", "dirty": False},
        "source_fingerprint": "source",
        "dataset_fingerprint": "dataset",
        "protocol_fingerprint": "protocol",
        "environment_fingerprint": "environment",
        "config": {"jobs": 1},
        "full": full,
        "units": [{"id": row["id"]} for row in rows],
    }
    return summarize(rows, manifest)


class MeasurementValidityTests(unittest.TestCase):
    def test_missing_oracles_never_count_as_pass(self):
        value = summary([measured_row("unknown/1", "unknown", before="NO_TEST_ORACLE", after="NO_TEST_ORACLE")])
        self.assertIsNone(value["aggregate"]["utility"]["retention"])
        self.assertEqual(value["aggregate"]["utility"]["oracle_units"], 0)

    def test_confusion_matrix_excludes_unknown_and_capacity_failures(self):
        rows = [
            measured_row("g/1"),
            measured_row("h/1", "human", matched=False),
            measured_row("u/1", "unknown"),
            measured_row("g/2", eligible=False),
        ]
        detection = summary(rows)["aggregate"]["detection"]
        self.assertEqual((detection["tp"], detection["tn"], detection["fp"], detection["fn"]), (1, 1, 0, 0))
        self.assertEqual(summary(rows)["aggregate"]["capacity_coverage"], 0.75)

    def test_new_functional_failure_fails_gate(self):
        old = summary([measured_row("g/1")])
        candidate = summary([measured_row("g/1", after="FAIL")])
        result = compare(candidate, old, CONFIG["gates"])
        self.assertFalse(result["passed"])
        self.assertEqual(
            next(c for c in result["checks"] if c["metric"] == "new_functional_regressions")["sample_ids"], ["g/1"]
        )

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

    def test_manifest_tampering_is_detected(self):
        manifest = {"source_files": {}, "input_files": {}}
        manifest["manifest_sha256"] = digest(manifest)
        verify_frozen_run(Path("."), manifest)
        manifest["source_files"] = {"algorithm.py": "0"}
        with self.assertRaises(ValueError):
            verify_frozen_run(Path("."), manifest)

    def test_dirty_source_changes_fingerprint_without_commit(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            path = root / "cllmark" / "algorithm.py"
            path.parent.mkdir()
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

    def test_source_change_is_detected_after_run_and_inputs_are_not_rehashed(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "cllmark").mkdir()
            (root / "cllmark" / "algorithm.py").write_text("version = 1\n")
            data = root / "corpus.txt"
            data.write_text("original")
            run = root / "run"
            run.mkdir()
            manifest = {
                "source_fingerprint": source_fingerprint(root)[0],
                "input_files": {"corpus.txt": {"sha256": digest(data.read_bytes())}},
            }
            self.assertTrue(validate_workspace(root, run, manifest))
            data.write_text("changed")
            self.assertTrue(validate_workspace(root, run, manifest))
            (root / "cllmark" / "algorithm.py").write_text("version = 2\n")
            self.assertFalse(validate_workspace(root, run, manifest))

    def test_summary_cannot_be_promoted_after_raw_results_are_altered(self):
        with tempfile.TemporaryDirectory() as temporary:
            run = Path(temporary)
            row = measured_row("g/1")
            manifest = {
                "run_id": "fixture",
                "source_files": {},
                "input_files": {},
                "environment": {"parser_toolchain": {"grammars": {}}},
                "git": {"commit": "fixture", "dirty": False},
                "source_fingerprint": "source",
                "dataset_fingerprint": "dataset",
                "protocol_fingerprint": "protocol",
                "environment_fingerprint": "environment",
                "config": {"jobs": 1},
                "full": True,
                "units": [{"id": "g/1"}],
            }
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
            config = {
                "cohorts": [
                    {"name": "tiny", "path": "corpus", "language": "python", "level": "project", "role": "generated"}
                ]
            }
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
    def test_actual_language_registries_and_pinned_parsers_load(self):
        self.assertEqual(set(parser_smoke(ROOT)), {"python", "c", "cpp", "javascript"})

    @unittest.skipUnless(HAS_JAVASCRIPT, NEEDS_JAVASCRIPT)
    def test_javascript_mbjsp_test_runs_on_node(self):
        problem = json.loads(
            (ROOT / "corpus" / "dataset" / "Jsonl" / "mbjsp_release_v1.2.jsonl").read_text().splitlines()[0]
        )
        environment = {"javascript": javascript_environment(ROOT)}
        unit = {"oracle": "mbxp", "level": "function", "language": "javascript", "source_files": ["MBJSP_1.js"]}
        config = {**CONFIG, "test_timeout_retries": 0}
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            body = "    return cost[m][n];\n}\n"
            (directory / "MBJSP_1.js").write_text("function minCost(cost, m, n) {\n" + body)
            problems = {"javascript": {"MBJSP/1": problem}}
            result = evaluate_utility(unit, directory, problems, config, directory, environment, directory / "cache")
            self.assertEqual(result["status"], "FAIL")
            (directory / "MBJSP_1.js").write_text("function minCost(cost, m, n) {\n    return ;\n")
            self.assertEqual(
                evaluate_utility(unit, directory, problems, config, directory, environment, directory / "cache")[
                    "status"
                ],
                "COMPILE_ERROR",
            )

    @unittest.skipUnless(HAS_JAVASCRIPT, NEEDS_JAVASCRIPT)
    def test_project_suite_runs_with_overlaid_sources(self):
        environment = {"javascript": javascript_environment(ROOT)}
        unit = {
            "oracle": "project_tests",
            "level": "project",
            "name": "bytes",
            "path": "corpus/dataset/JS_projects",
            "source_files": ["corpus/dataset/JS_projects/bytes/index.js"],
        }
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            original = (ROOT / "corpus" / "dataset" / "JS_projects" / "bytes" / "index.js").read_text()
            (directory / "index.js").write_text(original)
            self.assertEqual(
                evaluate_utility(unit, directory, {}, CONFIG, directory, environment, directory / "cache")["status"],
                "PASS",
            )
            (directory / "index.js").write_text(original.replace("Math.floor", "Math.ceil"))
            failed = evaluate_utility(unit, directory, {}, CONFIG, directory, environment, directory / "cache")
            self.assertEqual(failed["status"], "FAIL")
            # The failing suite's output is kept with the unit and in the cache entry, not inside the project copy.
            evidence = directory / ".utility"
            self.assertIn(
                "failing",
                (evidence / "test-attempt-1.stdout").read_text() + (evidence / "test-attempt-1.stderr").read_text(),
            )
            self.assertEqual(list((Path(failed["artifacts"]) / "project").glob("test-attempt-*")), [])
            self.assertTrue((Path(failed["artifacts"]) / "test-attempt-1.stdout").exists())

    def test_cpp_body_reconstruction_uses_official_signature(self):
        problem = {
            "prompt": "#include <bits/stdc++.h>\nusing namespace std;\nint add(int a,int b){\n",
            "entry_point": "add",
            "test": "int main(){return add(2,3)==5?0:1;}",
        }
        code = assemble_test("cpp", "return a+b;\n}\n", problem, 1)
        self.assertIn("int add(int a,int b)", code)
        self.assertIn("int main()", code)

    def test_subprocess_timeout_is_enforced(self):
        import sys

        with tempfile.TemporaryDirectory() as temporary:
            result = run_process([sys.executable, "-c", "while True: pass"], temporary, 0.2, "timeout")
            self.assertTrue(result["timed_out"])
            self.assertLess(result["elapsed_ms"], 2000)

    def test_timeout_retry_preserves_first_attempt_and_recovery(self):
        import sys

        with tempfile.TemporaryDirectory() as temporary:
            command = [
                sys.executable,
                "-c",
                "from pathlib import Path\nimport time\np=Path('first-launch')\nif not p.exists():\n p.touch()\n time.sleep(3)\n",
            ]
            result = run_test(command, temporary, 0.2, 1, None)
            self.assertTrue(result["attempts"][0]["timed_out"])
            self.assertEqual(result["returncode"], 0)
            self.assertTrue(result["recovered_after_timeout"])
            self.assertEqual(len(result["attempts"]), 2)

    def test_persistent_timeout_remains_failure_after_bounded_retry(self):
        import sys

        with tempfile.TemporaryDirectory() as temporary:
            result = run_test([sys.executable, "-c", "while True: pass"], temporary, 0.2, 1, None)
            self.assertTrue(result["timed_out"])
            self.assertFalse(result["recovered_after_timeout"])
            self.assertEqual(len(result["attempts"]), 2)

    def test_assertion_failure_is_not_retried(self):
        import sys

        with tempfile.TemporaryDirectory() as temporary:
            result = run_test([sys.executable, "-c", "assert False"], temporary, 1, 1, None)
            self.assertFalse(result["timed_out"])
            self.assertNotEqual(result["returncode"], 0)
            self.assertEqual(len(result["attempts"]), 1)

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
            problem = {
                "prompt": "#include <bits/stdc++.h>\nusing namespace std;\nint add(int a,int b){\n",
                "entry_point": "add",
                "test": "int main(){return add(2,3)==5?0:1;}",
            }
            unit = {"oracle": "mbxp", "level": "function", "language": "cpp", "source_files": ["MBCPP_1.cpp"]}
            kwargs = (
                unit,
                root,
                {"cpp": {"MBCPP/1": problem}},
                CONFIG,
                root,
                {"compiler": shutil.which("c++")},
                root / "cache",
            )
            self.assertEqual(evaluate_utility(*kwargs)["status"], "PASS")
            path.write_text("return a-b;\n}\n")
            self.assertEqual(evaluate_utility(*kwargs)["status"], "FAIL")


def fixture_project(root, files):
    """A tiny pinned 'checkout' (no node_modules) and the environment/config that describe it."""
    checkout = Path(root) / "checkout"
    for path, text in files.items():
        (checkout / path).parent.mkdir(parents=True, exist_ok=True)
        (checkout / path).write_text(text)
    pinned = {"checkout": str(checkout), "commit": "fixture", "node_modules_sha256": "none"}
    environment = {"javascript": {"node": "node", "node_version": "v-test", "projects": {"fake": pinned}}}
    return checkout, environment


def project_unit(level, name, sources, **extra):
    return {
        "oracle": "project_tests",
        "level": level,
        "name": name,
        "path": "corpus",
        "language": "javascript",
        "source_files": ["corpus/" + path for path in sources],
        **extra,
    }


class ProjectFileCorpusTests(unittest.TestCase):
    """Per-file units, tree layout and the project-test oracle on a local fixture (no network)."""

    def corpus(self, root):
        for path, lines in {
            "repoA/lib/a.js": 90,
            "repoA/lib/short.js": 10,
            "repoA/index.js": 80,
            "repoB/main.mjs": 120,
            "repoB/notes.txt": 500,
        }.items():
            target = Path(root) / "corpus" / path
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_text("// line\n" * lines)
        return {
            "cohorts": [
                {
                    "name": "files",
                    "path": "corpus",
                    "language": "javascript",
                    "level": "project_file",
                    "role": "human",
                    "oracle": "project_tests",
                    "extensions": [".js", ".mjs"],
                    "min_lines": 80,
                },
                {
                    "name": "repos",
                    "path": "corpus",
                    "language": "javascript",
                    "level": "project",
                    "role": "human",
                    "oracle": "project_tests",
                    "layout": "tree",
                    "extensions": [".js", ".mjs"],
                },
            ]
        }

    def test_files_at_least_min_lines_become_units_with_their_project(self):
        with tempfile.TemporaryDirectory() as temporary:
            units, inventory = discover_units(temporary, self.corpus(temporary))
        files = [u for u in units if u["level"] == "project_file"]
        self.assertEqual(
            [u["id"] for u in files], ["files/repoA/index.js", "files/repoA/lib/a.js", "files/repoB/main.mjs"]
        )
        self.assertEqual([u["project"] for u in files], ["repoA", "repoA", "repoB"])
        self.assertEqual(inventory[0]["available_units"], 3)
        self.assertEqual(project_paths(files[1]), {"corpus/repoA/lib/a.js": "lib/a.js"})
        repos = [u for u in units if u["level"] == "project"]
        self.assertEqual(
            [len(u["source_files"]) for u in repos], [3, 1]
        )  # short.js stays in the project; txt is no source

    def test_tree_layout_separates_repeated_basenames_but_flat_layout_rejects_them(self):
        sources = ["fake/index.js", "fake/lib/index.js"]
        tree = project_unit("project", "fake", sources, layout="tree")
        self.assertEqual(list(unit_file_names(tree).values()), ["index.js", "lib__index.js"])
        with self.assertRaises(ValueError):
            unit_file_names(project_unit("project", "fake", sources))

    def test_invalid_corpus_options_are_rejected(self):
        for change in [
            {"layout": "tree", "level": "project_file", "min_lines": 1},
            {"min_lines": 5},
            {"extensions": ["js"]},
            {"layout": "deep"},
        ]:
            config = copy.deepcopy(CONFIG)
            config["cohorts"] = [
                {
                    "name": "x",
                    "path": "p",
                    "language": "javascript",
                    "level": "project",
                    "role": "human",
                    "oracle": "project_tests",
                    **change,
                }
            ]
            with self.assertRaises(ValueError):
                validate_config(config)
        config = copy.deepcopy(CONFIG)
        del config["exercism"]
        with self.assertRaises(ValueError):
            validate_config(config)

    def test_shipped_configuration_is_valid_and_lists_the_new_cohorts(self):
        validate_config(copy.deepcopy(CONFIG))
        levels = {c["name"]: c["level"] for c in CONFIG["cohorts"]}
        self.assertEqual(
            (levels["js_repos"], levels["js_repo_files"], levels["exercism_js"]),
            ("project", "project_file", "function"),
        )

    def test_single_file_overlay_runs_the_project_suite_and_clean_runs_share_a_cache_entry(self):
        files = {
            "lib/a.js": "exports.value = 1;\n",
            "lib/b.js": "exports.value = 2;\n",
            "test.js": "const assert = require('assert');\nassert.strictEqual(require('./lib/a').value + require('./lib/b').value, 3);\n",
        }
        config = {
            **CONFIG,
            "projects": {"fake": {"test": ["node", "test.js"], "exclusive": True}},
            "test_timeout_retries": 0,
        }
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            checkout, environment = fixture_project(root / "pinned", files)
            cache = root / "cache"
            one = project_unit("project_file", "fake/lib/a.js", ["fake/lib/a.js"], project="fake")
            both = project_unit("project", "fake", ["fake/lib/a.js", "fake/lib/b.js"], layout="tree")
            for unit, names in [(one, ["a.js"]), (both, ["lib__a.js", "lib__b.js"])]:
                directory = root / ("dir-" + unit["level"])
                directory.mkdir()
                for relative, name in zip(unit["source_files"], names, strict=True):
                    (directory / name).write_text(files[relative[len("corpus/fake/") :]])
                result = evaluate_utility(unit, directory, {}, config, directory, environment, cache)
                self.assertEqual(result["status"], "PASS")
                self.assertEqual(result["changed_files"], [])
            self.assertEqual(
                evaluate_utility(one, root / "dir-project_file", {}, config, root, environment, cache)["cache_hit"],
                True,
            )
            keys = {
                evaluate_utility(u, root / ("dir-" + u["level"]), {}, config, root, environment, cache)["cache_key"]
                for u in [one, both]
            }
            self.assertEqual(len(keys), 1, "clean runs of a project share one cache entry")
            (root / "dir-project_file" / "a.js").write_text("exports.value = 5;\n")
            failed = evaluate_utility(one, root / "dir-project_file", {}, config, root, environment, cache)
            self.assertEqual((failed["status"], failed["changed_files"]), ("FAIL", ["lib/a.js"]))
            self.assertTrue((root / "cache" / "exclusive-tests.lock").exists())
            self.assertEqual((checkout / "lib" / "a.js").read_text(), "exports.value = 1;\n")
            # Tree layout: the flat name lib__a.js maps back to lib/a.js
            (root / "dir-project" / "lib__a.js").write_text("exports.value = 5;\n")
            tree_failed = evaluate_utility(both, root / "dir-project", {}, config, root, environment, cache)
            self.assertEqual((tree_failed["status"], tree_failed["changed_files"]), ("FAIL", ["lib/a.js"]))
            self.assertIn("AssertionError", (root / "dir-project" / ".utility" / "test-attempt-1.stderr").read_text())

    def test_overlay_never_writes_through_a_symlink_into_the_pinned_checkout(self):
        files = {
            "real.js": "exports.value = 1;\n",
            "test.js": "process.exit(require('./lib/a').value === 1 ? 0 : 1);\n",
        }
        config = {**CONFIG, "projects": {"fake": {"test": ["node", "test.js"]}}, "test_timeout_retries": 0}
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            checkout, environment = fixture_project(root / "pinned", files)
            (checkout / "lib").mkdir()
            (checkout / "lib" / "a.js").symlink_to("../real.js")
            unit = project_unit("project_file", "fake/lib/a.js", ["fake/lib/a.js"], project="fake")
            directory = root / "dir"
            directory.mkdir()
            (directory / "a.js").write_text("exports.value = 2;\n")
            self.assertEqual(
                evaluate_utility(unit, directory, {}, config, root, environment, root / "cache")["status"], "FAIL"
            )
            self.assertEqual((checkout / "real.js").read_text(), "exports.value = 1;\n")

    def test_totals_wrapper_fails_when_a_suite_reports_failures_but_exits_zero(self):
        wrapper = CONFIG["projects"]["bignumber.js"]["test"]
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            (directory / "test").mkdir()
            for report, expected in [
                ("In total, 7 of 7 tests passed in 3 ms", 0),
                ("In total, 6 of 7 tests passed in 3 ms", 1),
                ("no totals printed", 1),
                ("In total, 0 of 0 tests passed", 1),
            ]:
                (directory / "test" / "test.js").write_text(f"console.log({json.dumps(report)});\n")
                command = [wrapper[0], wrapper[1], wrapper[2], "test/test.js"]
                self.assertEqual(run_process(command, directory, 20, "wrapper")["returncode"], expected, report)


class ExercismOracleTests(unittest.TestCase):
    def test_skip_markers_follow_the_exercism_ci_preparation(self):
        text = "describe('x', () => {\n  xtest('a', f); xtest('b', g);\n  xit('c', h);\n  test.skip('d', i);\n});\nxdescribe('y', j);\n"
        enabled = enable_exercism_tests(text)
        self.assertIn("  test('a', f); xtest('b', g);", enabled)  # first marker per line, as shelljs sed does
        self.assertIn("  test('c', h);", enabled)
        self.assertIn("test.skip('d', i)", enabled)
        self.assertIn("\ndescribe('y', j);", enabled)
        self.assertEqual(
            exercism_solution("import { a } from '../lib/a';\nconst s = 'from ../ is text';"),
            "import { a } from './lib/a';\nconst s = 'from ../ is text';",
        )

    def test_oracle_runs_the_spec_against_the_unit_code_with_support_files(self):
        runner = (
            "const fs = require('fs'), path = require('path');\n"
            "for (const f of fs.readdirSync(process.argv[2])) if (f.endsWith('.spec.js')) require(path.resolve(process.argv[2], f));\n"
        )
        problem = {
            "task_id": "Exercism/adder",
            "slug": "adder",
            "spec_file": "adder.spec.js",
            "support_files": {"data/offset.txt": "10\n"},
            "spec": (
                "const assert = require('assert'), fs = require('fs');\nconst { add } = require('./adder');\n"
                "const offset = Number(fs.readFileSync(__dirname + '/data/offset.txt', 'utf8'));\nassert.strictEqual(add(1, 2) + offset, 13);\n"
            ),
        }
        config = {
            **CONFIG,
            "exercism": {"test": ["node", "node_modules/runner.js", "exercise"]},
            "test_timeout_retries": 0,
        }
        unit = {
            "oracle": "exercism",
            "level": "function",
            "language": "javascript",
            "source_files": ["Exercism_JS/adder.js"],
        }
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            checkout = root / "pinned"
            (checkout / "node_modules").mkdir(parents=True)
            (checkout / "node_modules" / "runner.js").write_text(runner)
            for name in ["jest.config.js", "babel.config.js"]:
                (checkout / name).write_text("module.exports = {};\n")
            environment = {
                "javascript": {
                    "node_version": "v-test",
                    "exercism": {"checkout": str(checkout), "commit": "fixture", "node_modules_sha256": "none"},
                }
            }
            directory = root / "unit"
            directory.mkdir()
            kwargs = (
                unit,
                directory,
                {"exercism": {"Exercism/adder": problem}},
                config,
                root,
                environment,
                root / "cache",
            )
            (directory / "adder.js").write_text("exports.add = (a, b) => a + b;\n")
            first = evaluate_utility(*kwargs)
            self.assertEqual(first["status"], "PASS")
            self.assertTrue(evaluate_utility(*kwargs)["cache_hit"])
            (directory / "adder.js").write_text("exports.add = (a, b) => a - b;\n")
            second = evaluate_utility(*kwargs)
            self.assertEqual(second["status"], "FAIL")
            self.assertNotEqual(first["cache_key"], second["cache_key"])
            self.assertIn("AssertionError", (directory / ".utility" / "test-attempt-1.stderr").read_text())
            self.assertEqual(
                evaluate_utility(unit, directory, {}, config, root, environment, root / "cache")["status"],
                "NO_TEST_ORACLE",
            )


@unittest.skipUnless(HAS_CORPUS, "needs the corpus submodule")
class PinnedJavaScriptCorpusTests(unittest.TestCase):
    """The corpus on disk, the lock file and the configuration agree; real suites run on clean and broken sources."""

    @classmethod
    def setUpClass(cls):
        cls.lock = json.loads((ROOT / "benchmarks" / "javascript.lock.json").read_text())
        cls.units, cls.inventory = discover_units(ROOT, CONFIG, cohorts=["js_repos", "js_repo_files", "exercism_js"])

    def test_every_locked_repository_has_a_test_command_corpus_and_license(self):
        repositories = self.lock["repositories"]
        self.assertGreaterEqual(len(repositories), 12)
        self.assertEqual(
            {p.name for p in (ROOT / "corpus" / "dataset" / "JS_repos").iterdir() if p.is_dir()}, set(repositories)
        )
        for name, spec in repositories.items():
            self.assertIn(spec["license"], ["MIT", "ISC", "Apache-2.0", "BSD-2-Clause", "BSD-3-Clause"], name)
            self.assertRegex(spec["commit"], r"^[0-9a-f]{40}$")
            self.assertRegex(spec["tarball_sha256"], r"^[0-9a-f]{64}$")
            self.assertTrue(CONFIG["projects"][name]["test"], name)
            self.assertTrue(any((ROOT / "corpus" / "dataset" / "JS_repos" / name).glob("LICEN*")), name)
            install = spec["install"]
            if install["mode"] == "npm-ci" and install["lockfile"] != "repository":
                self.assertEqual(digest((ROOT / install["lockfile"]).read_bytes()), install["lockfile_sha256"], name)

    def test_inventory_units_follow_the_configured_filters(self):
        by_cohort = {}
        for unit in self.units:
            by_cohort.setdefault(unit["cohort"] if "cohort" in unit else unit["id"].split("/")[0], []).append(unit)
        self.assertEqual(len(by_cohort["js_repos"]), len(self.lock["repositories"]))
        files = by_cohort["js_repo_files"]
        self.assertEqual(len({u["id"] for u in files}), len(files))
        for unit in files:
            self.assertGreaterEqual(len((ROOT / unit["source_files"][0]).read_bytes().splitlines()), 80)
            self.assertIn(unit["project"], self.lock["repositories"])
        rows = [
            json.loads(line)
            for line in (ROOT / "corpus" / "dataset" / "Jsonl" / "exercism_javascript.jsonl").read_text().splitlines()
        ]
        self.assertEqual(
            sorted(r["slug"] for r in rows), sorted(Path(u["source_files"][0]).stem for u in by_cohort["exercism_js"])
        )
        self.assertTrue(
            all(r["proof_lines"] >= self.lock["exercism"]["min_solution_lines"] and r["spec"] for r in rows)
        )
        polyglot = set(self.lock["exercism"]["aider_polyglot"]["exercises"])
        self.assertEqual({r["slug"] for r in rows if r["aider_polyglot"]}, {r["slug"] for r in rows} & polyglot)

    @unittest.skipUnless(HAS_JAVASCRIPT, NEEDS_JAVASCRIPT)
    def test_real_repository_file_unit_passes_clean_and_fails_when_broken(self):
        environment = {"javascript": javascript_environment(ROOT)}
        unit = next(u for u in self.units if u["id"] == "js_repo_files/qs/lib/utils.js")
        original = (ROOT / unit["source_files"][0]).read_text()
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            (directory / "utils.js").write_text(original)
            self.assertEqual(
                evaluate_utility(unit, directory, {}, CONFIG, directory, environment, directory / "cache")["status"],
                "PASS",
            )
            (directory / "utils.js").write_text(
                original.replace(
                    "var has = Object.prototype.hasOwnProperty;", "var has = function () { return false; };", 1
                )
            )
            result = evaluate_utility(unit, directory, {}, CONFIG, directory, environment, directory / "cache")
            self.assertEqual((result["status"], result["changed_files"]), ("FAIL", ["lib/utils.js"]))

    @unittest.skipUnless(HAS_JAVASCRIPT, NEEDS_JAVASCRIPT)
    def test_real_exercism_exercise_passes_clean_and_fails_when_broken(self):
        environment = {"javascript": javascript_environment(ROOT)}
        unit = next(u for u in self.units if u["id"] == "exercism_js/affine-cipher")
        problems = load_problems(ROOT, CONFIG)
        original = (ROOT / unit["source_files"][0]).read_text()
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            (directory / "affine-cipher.js").write_text(original)
            args = (unit, directory, problems, CONFIG, directory, environment, directory / "cache")
            self.assertEqual(evaluate_utility(*args)["status"], "PASS")
            (directory / "affine-cipher.js").write_text(
                original.replace("'abcdefghijklmnopqrstuvwxyz'", "'bacdefghijklmnopqrstuvwxyz'", 1)
            )
            self.assertEqual(evaluate_utility(*args)["status"], "FAIL")


if __name__ == "__main__":
    unittest.main()


class ProgressTests(unittest.TestCase):
    def test_bar_eta_and_describe(self):
        from benchmarks.progress import LiveLog, ProgressTracker, describe, format_duration, render_bar

        self.assertEqual(render_bar(5, 10, 10), "[#####-----] 5/10  50.0%")
        self.assertEqual(format_duration(3725), "1:02:05")
        ticks = iter(range(100))
        tracker = ProgressTracker(4, clock=lambda: next(ticks))
        with tempfile.TemporaryDirectory() as directory:
            run = Path(directory)
            log = LiveLog(run / "progress.log", tracker, stream=io.StringIO())
            log.record({"id": "a/1", "cohort": "a", "status": "ok", "elapsed_ms": 1500})
            log.record({"id": "a/2", "cohort": "a", "status": "harness_error"})
            log.close()
            self.assertEqual(tracker.done, 2)
            self.assertGreater(tracker.rate, 0)
            self.assertIsNotNone(tracker.eta)
            lines = (run / "progress.log").read_text().splitlines()
            self.assertTrue(lines[0].endswith("ok a/1 1.50s") and "harness_error a/2" in lines[1])
            (run / "state.json").write_text(json.dumps({"status": "running", **tracker.state()}))
            text = describe(run)
            self.assertIn("2/4", text)
            self.assertIn("harness_error=1", text)
            self.assertIn("a/2", text)


class StagedExecutionTests(unittest.TestCase):
    def test_deferred_rows_are_the_ones_needing_functional_tests(self):
        from benchmarks.staged import DEFERRED, load_functional, needs_functional

        self.assertTrue(needs_functional({"status": "ok", "utility_before": dict(DEFERRED)}))
        self.assertFalse(needs_functional({"status": "harness_error"}))
        self.assertFalse(needs_functional({"status": "ok", "utility_before": {"status": "PASS"}}))
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "functional.jsonl"
            path.write_text('{"id":"a"}\n{"id":"b"}\n{"id":')
            self.assertEqual(sorted(load_functional(path)), ["a", "b"])
            self.assertEqual(load_functional(Path(temporary) / "missing.jsonl"), {})

    def test_workers_defer_functional_tests_in_the_engine_only(self):
        from benchmarks import engine, staged

        original = engine.evaluate_utility
        try:
            with unittest.mock.patch.object(engine, "initialize_worker"):
                staged.initialize_worker("run", {"units": [{"id": "u/1"}]})
            self.assertEqual(engine.evaluate_utility(), staged.DEFERRED)
            self.assertEqual(staged.evaluate_utility.__module__, "benchmarks.utility")
        finally:
            engine.evaluate_utility = original
