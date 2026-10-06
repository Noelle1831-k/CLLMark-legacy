"""Rule sets in the benchmark: "rule_set": "extended" measures the legacy pairs plus the extension pairs.

The default rule set is "legacy" (the paper's pairs, `cllmark.rules.pairs.WATERMARK_PAIRS`), and a config without the
key, or with "legacy", gives the same protocol config as before, so normal runs and their fingerprints do not change.
An extended run keeps the measurement code of its granularity (`engine.LegacyEngine` or `node_engine.NodeEngine`)
and only gives it transformers and pair tables of the extended rule set (see docs/EXTENDED_RULES.md). Its config
carries the key, so its protocol fingerprint differs from legacy runs and it needs a baseline of its own.
"""

import importlib
import os

from . import engine, node_engine

RULE_SETS = ("legacy", "extended")
REPORT_NOTE = (
    "Rule set: **extended** (the legacy rule pairs followed by the extension pairs of docs/EXTENDED_RULES.md; not "
    "comparable with legacy-rule baselines)."
)


def rule_set(config):
    value = config.get("rule_set", "legacy")
    if value not in RULE_SETS:
        raise ValueError(f"rule_set must be one of {RULE_SETS}: {value!r}")
    return value


def protocol_config(config, root):
    """The config of a run (see `node_engine.protocol_config`); an explicit "legacy" is dropped, as it is the default."""
    if rule_set(config) == "legacy":
        config = {key: value for key, value in config.items() if key != "rule_set"}
    return node_engine.protocol_config(config, root)


def annotate_report(run_dir, manifest):
    """State the granularity and the rule set under the title of the report of a node or extended run."""
    node_engine.annotate_report(run_dir, manifest)
    if rule_set(manifest.get("config", {})) == "legacy":
        return
    report = run_dir / "report.md"
    if report.exists():
        lines = report.read_text(encoding="utf-8").split("\n")
        if REPORT_NOTE not in lines:
            lines.insert(4, REPORT_NOTE)
            report.write_text("\n".join(lines), encoding="utf-8")


class ExtendedRules:
    """Engine mixin: the transformers and pair tables of the config's rule set (the engines read both from here)."""

    def __init__(self, run_dir, manifest):
        super().__init__(run_dir, manifest)
        self.rule_set = rule_set(self.config)
        pairs = importlib.import_module("cllmark.rules.pairs")
        self.rules = {language: pairs.watermark_pairs(language, self.rule_set) for language in pairs.WATERMARK_PAIRS}

    def parser(self, language):
        if language not in self.parsers:
            self.parsers[language] = self.transform.StyleTransformer(language, rule_set=self.rule_set)
        return self.parsers[language]


class ExtendedEngine(ExtendedRules, engine.LegacyEngine):
    pass


class ExtendedNodeEngine(ExtendedRules, node_engine.NodeEngine):
    pass


def initialize_worker(run_dir, manifest):
    """`engine.initialize_worker` with the engine of the run's granularity, on the extended rule set."""
    os.environ.setdefault("MPLBACKEND", "Agg")
    node = node_engine.granularity(manifest.get("config", {})) == "node"
    engine.ENGINE = (ExtendedNodeEngine if node else ExtendedEngine)(run_dir, manifest)
