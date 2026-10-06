"""Dispatch order of the functional stage."""

import unittest

from benchmarks.runner import functional_priority


class FunctionalPriorityTests(unittest.TestCase):
    def test_serialized_suites_first_then_longer_kinds_of_test(self):
        manifest = {
            "config": {"projects": {"ws": {"exclusive": True}, "lodash": {}}},
            "units": [
                {"id": "mbpp/A", "oracle": "mbxp", "name": "A"},
                {"id": "js_repo_files/lodash/a.js", "oracle": "project_tests", "project": "lodash"},
                {"id": "exercism/x", "oracle": "exercism", "name": "x"},
                {"id": "js_repos/ws", "oracle": "project_tests", "name": "ws"},
                {"id": "mbpp/B", "oracle": "mbxp", "name": "B"},
                {"id": "js_repo_files/ws/b.js", "oracle": "project_tests", "project": "ws"},
            ],
        }
        rows = [{"id": unit["id"]} for unit in manifest["units"]]
        ordered = [row["id"] for row in sorted(rows, key=functional_priority(manifest))]
        self.assertEqual(
            ordered,
            ["js_repos/ws", "js_repo_files/ws/b.js", "js_repo_files/lodash/a.js", "exercism/x", "mbpp/A", "mbpp/B"],
        )
