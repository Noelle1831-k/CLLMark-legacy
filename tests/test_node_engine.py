"""The standalone node-granular benchmark engine leaves file-granular runs as they are."""

import json
import tempfile
import unittest
import unittest.mock
from pathlib import Path

from benchmarks import engine, node_engine, staged

ROOT = Path(__file__).resolve().parents[1]


class NodeEngineSelectionTests(unittest.TestCase):
    def test_file_runs_keep_their_config_and_node_runs_carry_the_engine_digest(self):
        config = json.loads((ROOT / "benchmarks" / "config.json").read_text())
        self.assertIs(node_engine.protocol_config(config, ROOT), config)
        node = json.loads((ROOT / "benchmarks" / "config-node.json").read_text())
        with_digest = node_engine.protocol_config(node, ROOT)
        self.assertEqual(len(with_digest["node_engine_sha256"]), 64)
        self.assertEqual({key: value for key, value in with_digest.items() if key != "node_engine_sha256"}, node)
        # config-node.json is config.json with one more key.
        self.assertEqual({key: value for key, value in node.items() if key != "slot_granularity"}, config)

    def test_unknown_granularity_is_rejected(self):
        with self.assertRaises(ValueError):
            node_engine.granularity({"slot_granularity": "line"})

    def test_workers_start_the_engine_of_the_run(self):
        for config, chosen in [({}, engine), ({"slot_granularity": "node"}, node_engine)]:
            with (
                unittest.mock.patch.object(engine, "initialize_worker") as legacy,
                unittest.mock.patch.object(node_engine, "initialize_worker") as node,
            ):
                staged.initialize_worker("run", {"config": config, "units": []})
            self.assertEqual((legacy.called, node.called), (chosen is engine, chosen is node_engine))

    def test_only_node_reports_are_annotated(self):
        with tempfile.TemporaryDirectory() as temporary:
            run_dir = Path(temporary)
            report = "# Local CLLMark benchmark\n\nRun: x\nFull inventory: y\n\n| table |\n"
            (run_dir / "report.md").write_text(report)
            node_engine.annotate_report(run_dir, {"config": {}})
            self.assertEqual((run_dir / "report.md").read_text(), report)
            for _ in range(2):
                node_engine.annotate_report(run_dir, {"config": {"slot_granularity": "node"}})
            lines = (run_dir / "report.md").read_text().split("\n")
            self.assertEqual(lines.count(node_engine.REPORT_NOTE), 1)
            self.assertEqual(lines[4], node_engine.REPORT_NOTE)
