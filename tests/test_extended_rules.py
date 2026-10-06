"""The opt-in extended rule set: its pairs, exact inverses, exclusions, and the plumbing that keeps legacy unchanged."""

import json
import tempfile
import unittest
import unittest.mock
from pathlib import Path

from benchmarks import engine, node_engine, rule_sets, staged
from cllmark import cli, directories, nodes
from cllmark.rules.pairs import EXTENSION_PAIRS, WATERMARK_PAIRS, rule_set_of, watermark_pairs
from cllmark.transform import LANGUAGES, StyleTransformer, rule_table

ROOT = Path(__file__).resolve().parents[1]

# (language, style, code, rewritten code); the pair's other style rewrites the result back to `code`.
GOLDEN = [
    ("python", "40.2", "def f(x):\n    return x + 1\n", "def f(x):\n    return (x + 1)\n"),
    ("python", "41.2", "y = x * 2\n", "y = 2 * x\n"),
    ("python", "41.1", "y = 2 * x\n", "y = x * 2\n"),
    # The outer sum holds a candidate of its own, so only the inner one is taken (one pass edits text once).
    ("python", "41.2", "y = d[i + 1] + 2\n", "y = d[1 + i] + 2\n"),
    ("python", "42.2", "if x > 1:\n    pass\n", "if (x > 1):\n    pass\n"),
    ("python", "43.2", "a = [1, 2]\n", "a = [1, 2,]\n"),
    ("python", "45.2", "z = x + y\n", "z = (x + y)\n"),
    ("c", "40.2", "int f(int x) { return x + 1; }\n", "int f(int x) { return (x + 1); }\n"),
    ("c", "41.2", "int f(int x) { int y = x * 2; return y; }\n", "int f(int x) { int y = 2 * x; return y; }\n"),
    ("c", "45.2", "void f(int a, int b) { int c = a + b; }\n", "void f(int a, int b) { int c = (a + b); }\n"),
    (
        "cpp",
        "46.1",
        "void f(V v) {\n    for (int x : v) {\n        g(x);\n    }\n}\n",
        "void f(V v) {\n    for (int x : v)\n        g(x);\n}\n",
    ),
    (
        "cpp",
        "46.1",
        "void f(V v) {\n    for (int x : v) { g(x); }\n}\n",
        "void f(V v) {\n    for (int x : v) g(x);\n}\n",
    ),
    # The lambda's return is inside the comparison (hash-order rules read its text); the outer return is not.
    (
        "cpp",
        "40.2",
        "bool f(V v) { return 0 == g(v, [](int i) { return i > 0; }); }\n",
        "bool f(V v) { return (0 == g(v, [](int i) { return i > 0; })); }\n",
    ),
    ("javascript", "40.2", "function f(x) { return x + 1; }\n", "function f(x) { return (x + 1); }\n"),
    ("javascript", "44.1", 'const s = "ab";\n', "const s = 'ab';\n"),
    ("javascript", "45.2", "let c = a - b;\n", "let c = (a - b);\n"),
    ("javascript", "46.2", "while (k) k--;\n", "while (k) { k--; }\n"),
    ("javascript", "46.1", "for (const q of o) {\n  w(q);\n}\n", "for (const q of o)\n  w(q);\n"),
]

# (language, style, code): no candidate, because the form belongs to a legacy rule or the rewrite would not be exact.
EXCLUDED = [
    ("python", "40.2", "def f(a, b):\n    return a, b\n"),  # tuple returns: 10.x
    ("python", "40.1", "def f(a, b):\n    return (a < b or a == b)\n"),  # expcmp reads the parentheses
    ("python", "42.2", "if x:\n    a()\nelse:\n    b()\n"),  # branch order (16.x) reads if/else conditions
    ("python", "42.2", "if not x:\n    a()\n"),
    ("python", "45.2", "x = x + 1\n"),  # self-assignment: 7.x
    ("c", "40.1", "int f(int a, int b) { return (a < b || a == b); }\n"),
    ("c", "41.2", "void f(int *p, int i) { int y = p[i * 2]; }\n"),  # C subscripts: 5.x
    ("c", "45.2", "void f(int a) { a = a + 1; }\n"),
    ("c", "45.2", "void f(int a, int b) { int c = a == b; }\n"),
    ("cpp", "46.2", "void f(V v) { for (int x : v) g(x); }\n"),  # the loop does not end its line
    ("cpp", "45.2", "void f(int a) { int c = a << 2; }\n"),  # stream operators: 9.x
    ("javascript", "41.2", "a = a * 2;\n"),  # compound assignment: 2.x
    ("javascript", "45.2", "x = a ** b;\n"),  # power: 27.x
    ("javascript", "44.2", "import { A } from './a';\nconst b = require('./b');\n"),  # module specifiers
    ("javascript", "46.1", "while (k) {\n  k--;\n}\n"),  # loop form (7.x) reads `while (c) ` headers
    ("javascript", "46.2", "for (;;) f(); // note\n"),
]


def other_style(language, style):
    for pair in EXTENSION_PAIRS[language].values():
        if style in pair:
            return pair[1 - pair.index(style)]
    raise KeyError(style)


class CatalogTests(unittest.TestCase):
    def test_legacy_table_is_the_default_and_extension_pairs_follow_it(self):
        for language in LANGUAGES:
            self.assertIs(watermark_pairs(language), WATERMARK_PAIRS[language])
            extended = watermark_pairs(language, "extended")
            self.assertEqual(list(extended)[: len(WATERMARK_PAIRS[language])], list(WATERMARK_PAIRS[language]))
            self.assertEqual({k: extended[k] for k in EXTENSION_PAIRS[language]}, EXTENSION_PAIRS[language])
            self.assertFalse(set(EXTENSION_PAIRS[language]) & set(WATERMARK_PAIRS[language]))
            self.assertIs(rule_table(language), rule_table(language, "legacy"))

    def test_every_extension_style_has_a_rule_and_a_catalog_entry(self):
        catalog = json.loads((ROOT / "cllmark" / "rules" / "extension_styles.json").read_text())
        legacy = json.loads((ROOT / "cllmark" / "rules" / "styles.json").read_text())
        for language in LANGUAGES:
            styles = {style for pair in EXTENSION_PAIRS[language].values() for style in pair}
            self.assertEqual(styles, set(catalog[language]))
            self.assertEqual(styles, set(rule_table(language, "extended")) - set(rule_table(language)))
            self.assertFalse(styles & set(legacy[language]))

    def test_unknown_rule_set_is_rejected(self):
        with self.assertRaises(ValueError):
            watermark_pairs("python", "everything")
        with self.assertRaises(ValueError):
            rule_sets.rule_set({"rule_set": "everything"})


class RewriteTests(unittest.TestCase):
    def test_golden_rewrites_are_exact_inverses_and_idempotent(self):
        for language, style, code, expected in GOLDEN:
            with self.subTest(language=language, style=style, code=code):
                transformer = StyleTransformer(language, rule_set="extended")
                rewritten, changed, candidates = transformer.apply(style, code)
                self.assertEqual(rewritten, expected)
                self.assertTrue(changed and candidates)
                self.assertEqual(transformer.apply(style, rewritten)[0], rewritten)
                self.assertEqual(transformer.apply(other_style(language, style), rewritten)[0], code)
                self.assertTrue(transformer.check_syntax(rewritten))

    def test_forms_of_legacy_rules_are_left_alone(self):
        for language, style, code in EXCLUDED:
            with self.subTest(language=language, style=style, code=code):
                transformer = StyleTransformer(language, rule_set="extended")
                self.assertEqual(transformer.apply(style, code), (code, False, 0))

    def test_legacy_transformers_have_no_extension_styles(self):
        with self.assertRaises(KeyError):
            StyleTransformer("python").apply("40.2", "def f():\n    return 1\n")


class StoredRuleSetTests(unittest.TestCase):
    def test_rule_set_is_read_from_the_pairs_a_support_file_names(self):
        self.assertEqual(rule_set_of("python", ["print_end", "list"]), "legacy")
        self.assertEqual(rule_set_of("python", ["print_end", "return_paren"]), "extended")
        file_support = {"a.py": ["return_paren"]}
        node_support = {"granularity": "node", "slots": [["a.py", "list", 0]]}
        self.assertEqual(directories.support_transformer("python", file_support).rule_set, "extended")
        self.assertEqual(directories.support_transformer("python", node_support).rule_set, "legacy")

    def test_extended_cli_round_trip_in_both_granularities(self):
        lines = [f"def f{i}(x, y):\n    z = x + y\n    if z > {i}:\n        pass\n    return z * 2\n" for i in range(4)]
        with tempfile.TemporaryDirectory() as temporary:
            source = Path(temporary) / "project"
            source.mkdir()
            for index, code in enumerate(lines):
                (source / f"m{index}.py").write_text(code)
            for granularity in ["file", "node"]:
                output = Path(temporary) / granularity
                arguments = ["embed", str(source), "-l", "python", "-b", "1011", "-o", str(output)]
                self.assertEqual(cli.main([*arguments, "-g", granularity, "-r", "extended"]), cli.EXIT_MATCH)
                support = directories.read_support(output)
                if nodes.is_support(support):
                    used = [slot[1] for slot in support["slots"]]
                else:
                    used = [pair for pairs in support.values() for pair in pairs]
                self.assertTrue(set(used) & set(EXTENSION_PAIRS["python"]))
                self.assertEqual(cli.main(["extract", str(output), "-l", "python", "-b", "1011"]), cli.EXIT_MATCH)
                self.assertEqual(cli.main(["extract", str(output), "-l", "python", "-b", "0110"]), cli.EXIT_NO_MATCH)


class BenchmarkSelectionTests(unittest.TestCase):
    def test_legacy_configs_are_unchanged_and_extended_configs_differ_by_the_key(self):
        config = json.loads((ROOT / "benchmarks" / "config.json").read_text())
        self.assertEqual(rule_sets.protocol_config(config, ROOT), config)
        self.assertEqual(rule_sets.protocol_config({**config, "rule_set": "legacy"}, ROOT), config)
        for plain, extended in [
            ("config.json", "config-extended.json"),
            ("config-node.json", "config-node-extended.json"),
        ]:
            base = json.loads((ROOT / "benchmarks" / plain).read_text())
            other = json.loads((ROOT / "benchmarks" / extended).read_text())
            self.assertEqual({key: value for key, value in other.items() if key != "rule_set"}, base)
            self.assertEqual(other["rule_set"], "extended")

    def test_workers_start_the_engine_of_the_rule_set(self):
        cases = [({}, engine), ({"slot_granularity": "node"}, node_engine), ({"rule_set": "extended"}, rule_sets)]
        for config, chosen in cases:
            with (
                unittest.mock.patch.object(engine, "initialize_worker") as legacy,
                unittest.mock.patch.object(node_engine, "initialize_worker") as node,
                unittest.mock.patch.object(rule_sets, "initialize_worker") as extended,
            ):
                staged.initialize_worker("run", {"config": config, "units": []})
            self.assertEqual(
                (legacy.called, node.called, extended.called),
                (chosen is engine, chosen is node_engine, chosen is rule_sets),
            )

    def test_extended_engines_use_extended_transformers_and_pairs(self):
        for config, base in [({}, engine.LegacyEngine), ({"slot_granularity": "node"}, node_engine.NodeEngine)]:
            with unittest.mock.patch.object(base, "__init__", lambda self, run_dir, manifest: None):
                chosen = rule_sets.ExtendedNodeEngine if config else rule_sets.ExtendedEngine
                instance = chosen.__new__(chosen)
                instance.config, instance.parsers = {**config, "rule_set": "extended"}, {}
                instance.transform = __import__("cllmark.transform", fromlist=["StyleTransformer"])
                rule_sets.ExtendedRules.__init__(instance, "run", {})
            self.assertEqual(instance.rules["javascript"], watermark_pairs("javascript", "extended"))
            self.assertEqual(instance.parser("python").rule_set, "extended")

    def test_only_extended_reports_carry_the_rule_set_note(self):
        with tempfile.TemporaryDirectory() as temporary:
            run_dir = Path(temporary)
            report = "# Local CLLMark benchmark\n\nRun: x\nFull inventory: y\n\n| table |\n"
            (run_dir / "report.md").write_text(report)
            rule_sets.annotate_report(run_dir, {"config": {}})
            self.assertEqual((run_dir / "report.md").read_text(), report)
            for _ in range(2):
                rule_sets.annotate_report(run_dir, {"config": {"rule_set": "extended"}})
            lines = (run_dir / "report.md").read_text().split("\n")
            self.assertEqual(lines.count(rule_sets.REPORT_NOTE), 1)
