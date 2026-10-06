"""Node-granular watermark slots: sites, slot order, embedding with read-back repair, extraction and the CLI."""

import io
import itertools
import json
import random
import tempfile
import unittest
from contextlib import redirect_stdout
from pathlib import Path

from cllmark.rules.pairs import WATERMARK_PAIRS

ROOT = Path(__file__).resolve().parents[1]
TOOLCHAIN = ROOT / ".benchmark-cache" / "toolchain"
HAS_GRAMMARS = all(
    (TOOLCHAIN / f"{language}-languages.so").exists() for language in ["python", "c", "cpp", "javascript"]
)
MESSAGES = [[(value >> shift) & 1 for shift in (3, 2, 1, 0)] for value in range(16)]

JAVASCRIPT = (
    "let a = 1;\nlet b = 2;\nx = x + 1;\ny += 2;\nz = z * 3;\n"
    "if (a === b) { f(); }\nif (b === 3) { g(); }\nconst o = {p: 1};\nh(o.p, o.q);\n"
)


def round_trips(transformer, language, files, slots):
    """Messages whose raw codeword is read back exactly after node-granular embedding."""
    from cllmark import nodes

    matched = 0
    for bits in MESSAGES:
        written, used, _ = nodes.embed(transformer, language, files, slots, bits)
        marked = {name: written.get(name, code) for name, code in files.items()}
        random.seed(0)
        matched += nodes.extract(transformer, language, marked, used, bits)[1]
    return matched


@unittest.skipUnless(HAS_GRAMMARS, "pinned parser libraries are not built")
class NodeSlotTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        from cllmark.transform import StyleTransformer

        cls.javascript = StyleTransformer("javascript")

    def test_sites_read_the_form_of_each_node(self):
        from cllmark import nodes

        found = nodes.sites(self.javascript, ("2.1", "2.2"), JAVASCRIPT)
        # x = x + 1 and z = z * 3 are rewritten by 2.1 (bit 0 form: compound), y += 2 by 2.2.
        self.assertEqual([(site.reading, site.usable) for site in found], [(1, True), (0, True), (1, True)])
        self.assertEqual([JAVASCRIPT[site.start : site.end] for site in found], ["x = x + 1", "y += 2", "z = z * 3"])

    def test_nodes_add_capacity_where_files_have_too_few_rule_pairs(self):
        from cllmark import bch, nodes, watermark

        files = {"a.js": JAVASCRIPT}
        per_file = sum(len(pairs) for pairs in watermark.analyze(self.javascript, "javascript", files).values())
        per_node = len(nodes.analyze(self.javascript, "javascript", files))
        self.assertLess(per_file, bch.CODE_LENGTH)
        self.assertGreaterEqual(per_node, bch.CODE_LENGTH)
        self.assertEqual(
            round_trips(self.javascript, "javascript", files, nodes.analyze(self.javascript, "javascript", files)), 16
        )

    def test_slots_interleave_rules_and_different_nodes_never_share_text(self):
        from cllmark import nodes, watermark

        files = {"a.js": JAVASCRIPT, "b.js": "if (k == 1) { m(); }\nn.v = n.v + 1;\n", "c.js": "w -= 1;\n"}
        support = watermark.analyze(self.javascript, "javascript", files)
        file_slots = [(name, pair) for name, pairs in support.items() for pair in pairs]
        slots = nodes.analyze(self.javascript, "javascript", files)
        # The first round takes at most one node per (file, pair), in the order of file granularity.
        first_round = []
        for name, pair, _ in slots:
            if (name, pair) in first_round:
                break
            first_round.append((name, pair))
        self.assertEqual(first_round, [item for item in file_slots if item in first_round])
        regions = {}
        for name, pair, index in slots:
            site = nodes.sites(self.javascript, WATERMARK_PAIRS["javascript"][pair], files[name])[index]
            region = regions.setdefault((name, site.start, site.end), [site.window[0], site.window[1], []])
            region[0], region[1] = min(region[0], site.window[0]), max(region[1], site.window[1])
            self.assertNotIn(pair, region[2])
            region[2].append(pair)
        for name in files:
            spans = sorted(region[:2] for (owner, _, _), region in regions.items() if owner == name)
            self.assertTrue(all(left[1] < right[0] for left, right in itertools.pairwise(spans)), spans)

    def test_a_slot_that_does_not_read_back_is_dropped_and_replaced(self):
        from cllmark import bch, nodes

        files = {"a.js": JAVASCRIPT}
        slots = nodes.analyze(self.javascript, "javascript", files)
        broken = [("a.js", "self_assignment", 99), *slots]
        written, used, dropped = nodes.embed(self.javascript, "javascript", files, broken, [1, 0, 1, 0])
        self.assertEqual(dropped, 1)
        self.assertNotIn(("a.js", "self_assignment", 99), used)
        marked = {name: written.get(name, code) for name, code in files.items()}
        self.assertEqual(nodes.extract(self.javascript, "javascript", marked, used, [1, 0, 1, 0]), (True, True))
        self.assertGreaterEqual(len(used), bch.CODE_LENGTH)

    def test_sites_another_pair_adds_are_followed_by_their_spans(self):
        from cllmark import nodes
        from cllmark.transform import StyleTransformer

        # Rewriting `b == 0` to `not b != 0` adds `!=` sites before the `!=` slots of the other pair.
        python = StyleTransformer("python")
        files = {
            "f.py": "def check(a, b, c):\n    if b == 0 and a == c:\n        return 'Yes'\n"
            "    elif a != 0 and c != 0 and (b ** 2 == 4 * a * c):\n        return 'Yes'\n    else:\n        return 'No'\n"
        }
        slots = nodes.analyze(python, "python", files)
        for bits in MESSAGES:
            _, _, dropped = nodes.embed(python, "python", files, slots, bits)
            self.assertEqual(dropped, 0, bits)
        self.assertEqual(round_trips(python, "python", files, slots), 16)

    def test_spans_follow_edits_before_inside_and_around_a_node(self):
        from cllmark.nodes import _follow
        from cllmark.rules.engine import Edit

        before, inside, around = Edit(0, 1, "xyz"), Edit(12, 13, ""), [Edit(10, 10, "!("), Edit(20, 20, ")")]
        self.assertEqual(_follow((10, 20), [before]), ((12, 22), False))
        self.assertEqual(_follow((10, 20), [before, inside]), ((12, 21), False))
        self.assertEqual(_follow((12, 18), around), ((14, 20), False))
        # The node's own rewrite, or another pair's rewrite of the same node, widens it to the edits that met it.
        self.assertEqual(_follow((10, 20), around, own=around), ((10, 23), True))
        self.assertEqual(_follow((10, 20), [before, Edit(10, 20, "0 < n")]), ((12, 17), True))

    def test_detect_only_loop_sites_carry_bits_only_from_the_rewritable_form(self):
        from cllmark import nodes
        from cllmark.transform import StyleTransformer

        c = StyleTransformer("c")
        code = "int f(int n){int s=0;\nfor (int i = 0; i < n; i++) { s += i; }\nfor (int j = 0; j < n; j++) { s -= j; }\nreturn s;}\n"
        found = nodes.sites(c, ("7.7", "11"), code)
        self.assertTrue(found)
        for site in found:
            self.assertEqual(site.usable, site.reading == 1 and bool(site.group))

    def test_directories_and_command_line_round_trip(self):
        from cllmark import cli, directories

        with tempfile.TemporaryDirectory() as temporary:
            source, output = Path(temporary) / "in", Path(temporary) / "out"
            source.mkdir()
            (source / "a.js").write_text(JAVASCRIPT, encoding="utf-8")
            with redirect_stdout(io.StringIO()):
                self.assertEqual(
                    cli.main(["embed", str(source), "-l", "javascript", "-b", "1010", "-o", str(output), "-g", "node"]),
                    0,
                )
                self.assertEqual(cli.main(["extract", str(output), "-l", "javascript", "-b", "1010"]), 0)
            support = json.loads((output / directories.SUPPORT_FILE).read_text())
            self.assertEqual(support["granularity"], "node")
            self.assertNotEqual((output / "a.js").read_text(), JAVASCRIPT)
            self.assertEqual((source / "a.js").read_text(), JAVASCRIPT)
            self.assertFalse((source / directories.SUPPORT_FILE).exists())


@unittest.skipUnless(HAS_GRAMMARS and (ROOT / "corpus" / "dataset").is_dir(), "corpus or parser libraries missing")
class CorpusRoundTripTests(unittest.TestCase):
    """Every message round-trips on a fixed sample of eligible corpus units of every language."""

    def test_all_messages_round_trip_on_corpus_samples(self):
        from benchmarks.common import discover_units, unit_file_names
        from cllmark import bch, nodes, source_io
        from cllmark.transform import StyleTransformer

        config = json.loads((ROOT / "benchmarks" / "config.json").read_text())
        units, _ = discover_units(ROOT, config)
        rng = random.Random(20261007)
        for language in ["python", "c", "cpp", "javascript"]:
            transformer = StyleTransformer(language)
            members = [unit for unit in units if unit["language"] == language and unit["level"] == "function"]
            checked = 0
            for unit in rng.sample(members, 60):
                names = unit_file_names(unit)
                files = {names[path]: source_io.read_source(ROOT / path) for path in unit["source_files"]}
                slots = nodes.analyze(transformer, language, files)
                if len(slots) < bch.CODE_LENGTH:
                    continue
                with self.subTest(unit=unit["id"]):
                    self.assertEqual(round_trips(transformer, language, files, slots), 16)
                checked += 1
                if checked == 5:
                    break
            self.assertEqual(checked, 5, language)

    def test_incremental_parses_equal_full_parses_and_keep_the_old_tree(self):
        from benchmarks.common import discover_units
        from cllmark import nodes, source_io
        from cllmark.rules.engine import apply_groups, edited_tree
        from cllmark.transform import StyleTransformer

        config = json.loads((ROOT / "benchmarks" / "config.json").read_text())
        units, _ = discover_units(ROOT, config)
        rng = random.Random(20261009)
        for language in ["python", "c", "cpp", "javascript"]:
            transformer = StyleTransformer(language)
            parser = transformer.grammar.parser
            members = [unit for unit in units if unit["language"] == language]
            for unit in rng.sample(members, 10):
                code = source_io.read_source(ROOT / unit["source_files"][0])
                old = code.encode("utf-8")
                tree = parser.parse(old)
                before = tree.root_node.sexp()
                groups = [
                    site.group
                    for styles in WATERMARK_PAIRS[language].values()
                    for site in nodes._sites(transformer, styles, code, transformer.grammar)
                    if site.usable and rng.random() < 0.5
                ]
                new, taken = apply_groups(old, groups)
                edits = [edit for position in taken for edit in groups[position]]
                with self.subTest(unit=unit["id"]):
                    self.assertEqual(
                        edited_tree(parser, tree, old, new, edits).root_node.sexp(), parser.parse(new).root_node.sexp()
                    )
                    self.assertEqual(tree.root_node.sexp(), before)
