"""Rule engine semantics, rule catalog consistency and golden rewrites per language."""

import json
from pathlib import Path
import unittest

from rule_engine import Edit, Grammar, Matcher, apply_edits, guard

ROOT = Path(__file__).resolve().parents[1]
TOOLCHAIN = ROOT / ".benchmark-cache" / "toolchain"
HAS_GRAMMARS = all((TOOLCHAIN / f"{language}-languages.so").exists() for language in ["python", "c", "cpp", "javascript"])


class EditApplicationTests(unittest.TestCase):
    def test_groups_apply_atomically_and_nested_groups_are_skipped(self):
        data = b"f(g(x))"
        outer = [Edit(0, 7, "F(g(x))")]
        inner = [Edit(2, 6, "G(x)")]
        self.assertEqual(apply_edits(data, [outer, inner]), (b"F(g(x))", 1))

    def test_insertions_at_one_offset_keep_their_order(self):
        data = b"int a, bb;"
        group = [Edit(0, 0, "int a;\n"), Edit(0, 0, "int bb;\n"), Edit(0, 10, "")]
        self.assertEqual(apply_edits(data, [group])[0], b"int a;\nint bb;\n")

    def test_insertion_next_to_a_replacement_is_not_a_conflict(self):
        data = b"a == b"
        self.assertEqual(apply_edits(data, [[Edit(0, 6, "b == a")], [Edit(6, 6, ";")]])[0], b"b == a;")

    def test_overlapping_edits_inside_one_rewrite_are_a_rule_bug(self):
        with self.assertRaises(ValueError):
            apply_edits(b"abcdef", [[Edit(0, 4, "x"), Edit(2, 6, "y")]])

    def test_multibyte_text_uses_byte_offsets(self):
        data = "s = '中' == t".encode()
        start = data.index(b"'")
        self.assertEqual(apply_edits(data, [[Edit(start, len(data), "t == '中'")]])[0].decode(), "s = t == '中'")


class GuardTests(unittest.TestCase):
    def test_guards_compose_and_explain(self):
        positive = guard("positive")(lambda value: value > 0)
        even = guard("even")(lambda value: value % 2 == 0)
        matcher = Matcher("((identifier) @node)", (positive, ~even))
        self.assertTrue(matcher.accepts(3))
        self.assertEqual(matcher.explain(-2), ["positive", "not even"])
        self.assertEqual((positive | even).name, "(positive or even)")


@unittest.skipUnless(HAS_GRAMMARS, "pinned parser libraries are not built")
class CatalogTests(unittest.TestCase):
    def test_unsupported_query_predicates_are_rejected(self):
        with self.assertRaises(ValueError):
            Grammar(str(TOOLCHAIN / "python-languages.so"), "python",
                    [Matcher('((call function: (identifier) @_f) @node (#any-of? @_f "print"))')])

    def test_style_catalog_rules_and_watermark_pairs_agree(self):
        import change_program_style
        import rule_dict_bit_acc
        import watermark_core
        catalog = json.loads((ROOT / "styleList.json").read_text())
        for language, pairs in rule_dict_bit_acc.rule_dict.items():
            rules = change_program_style.load_rules(language).RULES
            self.assertEqual(set(catalog[language]) - {"13"}, set(rules), language)
            for name, styles in pairs.items():
                self.assertEqual(len(set(styles)), 2, name)
                for style in styles:
                    self.assertIn(watermark_core.DETECT_ONLY.get(style, style), rules, (language, name, style))

    def test_rules_have_no_state_between_files(self):
        from change_program_style import SCTS
        scts = SCTS("cpp")
        first = "int main(){int i = 0; while (i < 3) { i++; } return 0;}"
        expected = scts.change_file_style("7.8", first)[0]
        scts.change_file_style("7.8", "int f(){int k=0; while(k){k++;} return k;}")
        self.assertEqual(scts.change_file_style("7.8", first)[0], expected)


@unittest.skipUnless(HAS_GRAMMARS, "pinned parser libraries are not built")
class ExtensionRuleTests(unittest.TestCase):
    """Extension rules are exact inverses of each other on canonical code."""
    CASES = {
        "python": ("def f(xs, y, d):\n    total = sum(xs)\n    if xs[0] not in d and d is not None:\n        total += 1\n"
                   "    if valid(y):\n        print(y)\n    else:\n        log(y)\n    z = total if ready(d) else 0\n"
                   "    while i < 10:\n        i += 1\n    if y > 3:\n        return 1\n    return 2\n",
                   ["14", "15", "16", "17", "18", "20", "21"]),
        "c": ("int g(struct N *p, int n) {\n    if (n > 0 && p->k) {\n        n = p->next->v;\n    }\n    if (n) {\n        n = 1;\n"
              "    } else {\n        n = 2;\n    }\n    return n ? n : 0;\n}\nvoid h(int *a) {\n    a[0] = 1;\n}\n",
              ["14", "15", "16", "17", "18", "19"]),
        "javascript": ("function f(o, n) {\n    let t = 0;\n    while (n > 0) {\n        n--;\n    }\n    if (o.ok && n) {\n        t = t + 1;\n"
                       "    }\n    return t ? {t: t} : null;\n}\n", ["2", "3", "7", "15", "16", "18", "19", "23"]),
    }

    def test_both_directions_round_trip(self):
        from change_program_style import SCTS
        for language, (code, families) in self.CASES.items():
            scts, styles = SCTS(language), SCTS(language).rules
            for family in families:
                for forward in [style for style in styles if style.split(".")[0] == family]:
                    changed = scts.change_file_style(forward, code)[0]
                    if changed == code:
                        continue
                    with self.subTest(language=language, style=forward):
                        self.assertTrue(scts.check_syntax(changed))
                        self.assertEqual(scts.change_file_style(forward, changed)[0], changed)
                        back = [style for style in styles if style.split(".")[0] == family and style != forward]
                        self.assertTrue(any(scts.change_file_style(other, changed)[0] == code for other in back))


class GoldenRewriteTests(unittest.TestCase):
    CASES = {
        "python": [
            ("1.1", "print(x)\n", "print(x, flush=True)\n"),
            ("1.2", "print(flush=True, end='')\n", "print(end='')\n"),
            ("7.3", "y = a == b\n", "y = not (a != b)\n"),
            ("7.4", "y = not (a != b)\n", "y = a == b\n"),
            ("7.10", "if (x < 3 or x == 3): pass\n", "if x <= 3: pass\n"),
            ("10.2", "def f():\n    return (a, b)\n", "def f():\n    return a, b\n"),
        ],
        "c": [
            ("2.3", "int f(int a){return a == 1;}", "int f(int a){return ! (a != 1);}"),
            ("3.1", "void f(){int i; i++;}", "void f(){int i; ++i;}"),
            ("4.1", "int main(){\n    f();\n}", "int main(void){\n    f();\n    return 0;\n}"),
            ("6.1", "void f(){\n    int a, b;\n}", "void f(){\n    int a;\n    int b;\n    \n}"),
            ("6.2", "void f(){\n    int a;\n    int b;\n}", "void f(){\n    int a, b;\n\n}"),
        ],
        "cpp": [
            ("9.1", 'int main(){printf("hi\\n");}', 'int main(){cout << "hi\\n";}'),
            ("9.2", 'int main(){int x; cout << x << endl;}', 'int main(){int x; printf("%d\\n", x);}'),
            ("22.1", "double f(int a){return (double)a / 2;}", "double f(int a){return double(a) / 2;}"),
            ("21.1", "typedef long long ll;", "using ll = long long;"),
        ],
        "javascript": [
            ("2.3", "if (a === b) f();", "if (!(a !== b)) f();"),
            ("2.7", "if (0 < n) f();", "if (n > 0) f();"),
            ("6.1", "function f() {\n    let a = 1, b = 2;\n}", "function f() {\n    let a = 1;\n    let b = 2;\n}"),
            ("19.2", "x = o.p.q;", 'x = o["p"]["q"];'),
            ("23.1", "g({a: a, b});", "g({a, b});"),
        ],
    }

    def test_golden_rewrites(self):
        from change_program_style import SCTS
        for language, cases in self.CASES.items():
            scts = SCTS(language)
            for style, before, after in cases:
                with self.subTest(language=language, style=style):
                    self.assertEqual(scts.change_file_style(style, before)[0], after)
