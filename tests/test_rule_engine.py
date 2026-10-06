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
            # Adjacent declarations merge whatever their initialisers; a later one hops over statements only if
            # its initialiser is pure and the statements neither mention its names nor call or write through memory.
            ("6.2", "void f(int n){\n    int a = n + 1;\n    int b = g(a);\n}",
             "void f(int n){\n    int a = n + 1, b = g(a);\n\n}"),
            ("6.2", "void f(int n){\n    int a = 0;\n    n = n + 1;\n    int b = n;\n}",
             "void f(int n){\n    int a = 0;\n    n = n + 1;\n    int b = n;\n}"),
            ("6.2", "void f(int n){\n    int a = 0;\n    g();\n    int b = n;\n}",
             "void f(int n){\n    int a = 0;\n    g();\n    int b = n;\n}"),
            ("6.2", "void f(int n){\n    int a = 0;\n    a = 1;\n    int b = n * 2;\n}",
             "void f(int n){\n    int a = 0, b = n * 2;\n    a = 1;\n\n}"),
            ("6.2", "void f(){\n    char a = 'x';\n    g();\n    char b = 'y';\n}",
             "void f(){\n    char a = 'x', b = 'y';\n    g();\n\n}"),
            ("6.2", "void f(int n){\n    int a = 0;\n    (*p)++;\n    int b = n;\n}",
             "void f(int n){\n    int a = 0;\n    (*p)++;\n    int b = n;\n}"),
            ("6.2", "void f(int n){\n    int a = 0;\n    g();\n    int b[n];\n}",
             "void f(int n){\n    int a = 0;\n    g();\n    int b[n];\n}"),
            ("6.2", "void f(int n){\n    int a = 0;\nL:\n    n++;\n    int b = 3;\n}",
             "void f(int n){\n    int a = 0;\nL:\n    n++;\n    int b = 3;\n}"),
            # v2: a first declaration in mid-line keeps what precedes it and adds no blanks (stable on repetition);
            # a syntax error between the declarations, a mixed 1-D/multi-dimensional array group, and specifiers
            # the merged kind would lose all keep the declarations apart.
            ("6.2", "void f(){ int a;\n    int b;\n}", "void f(){ int a, b;\n\n}"),
            ("6.2", "void f(int n){\n    int a = 0;\n    n = ;;\n    @@@ x y;\n    int b = 3;\n}",
             "void f(int n){\n    int a = 0;\n    n = ;;\n    @@@ x y;\n    int b = 3;\n}"),
            ("6.2", "void f(){\n    int a[3];\n    int b[2][2];\n}", "void f(){\n    int a[3];\n    int b[2][2];\n}"),
            ("6.2", "void f(){\n    int a[3];\n    int b[4];\n}", "void f(){\n    int a[3], b[4];\n\n}"),
            ("6.2", "void f(){\n    static const int a = 1;\n    static const int b = 2;\n}",
             "void f(){\n    static const int a = 1;\n    static const int b = 2;\n}"),
            ("6.1", "dump(int ssort[],char leader[])\n{\n  int i;\n}", "dump(int ssort[],char leader[])\n{\n  int i;\n}"),
            # The counter update stays in the body (empty third clause) unless it is the last statement.
            ("7.8", "void f(int n){\n    int i = 0;\n    while (i < n) {\n        i++;\n        g(i);\n    }\n}",
             "void f(int n){\n    int i = 0;\n    for(int identifier = 1; i < n; ) {\n        i++;\n        g(i);\n    }\n}"),
        ],
        "cpp": [
            ("9.1", 'int main(){printf("hi\\n");}', 'int main(){cout << "hi\\n";}'),
            ("9.2", 'int main(){int x; cout << x << endl;}', 'int main(){int x; printf("%d\\n", x);}'),
            ("22.1", "double f(int a){return (double)a / 2;}", "double f(int a){return double(a) / 2;}"),
            ("21.1", "typedef long long ll;", "using ll = long long;"),
            ("6.2", "void f(){\n    auto a = 1;\n    auto b = 2.0;\n}", "void f(){\n    auto a = 1;\n    auto b = 2.0;\n}"),
            # A write to a C++ reference may change what the hoisted initialiser reads.
            ("6.2", "void f(int n){\n    int &r = n;\n    int a = 0;\n    r = 5;\n    int b = n;\n}",
             "void f(int n){\n    int &r = n, a = 0;\n\n    r = 5;\n    int b = n;\n}"),
            ("6.2", "void f(int &n){\n    int a = 0;\n    n = 5;\n    int b = 1;\n}",
             "void f(int &n){\n    int a = 0, b = 1;\n    n = 5;\n\n}"),
            ("6.2", "void f(int &r, int n){\n    int a = 0;\n    r = 5;\n    int b = n;\n}",
             "void f(int &r, int n){\n    int a = 0;\n    r = 5;\n    int b = n;\n}"),
            ("6.2", "void f(){\n    volatile int a = 1;\n    volatile int b = 2;\n}",
             "void f(){\n    volatile int a = 1;\n    volatile int b = 2;\n}"),
        ],
        "javascript": [
            ("2.3", "if (a === b) f();", "if (!(a !== b)) f();"),
            ("2.7", "if (0 < n) f();", "if (n > 0) f();"),
            ("6.1", "function f() {\n    let a = 1, b = 2;\n}", "function f() {\n    let a = 1;\n    let b = 2;\n}"),
            ("19.2", "x = o.p.q;", 'x = o["p"]["q"];'),
            ("23.1", "g({a: a, b});", "g({a, b});"),
            # only the changed token is edited: spacing and comments between the parts survive
            ("2.3", "if (a  === b) f();", "if (!(a  !== b)) f();"),
            ("2.4", "if (!(a  !== b)) f();", "if (a  === b) f();"),
            ("2.7", "if (0x30/* 0 */ <= c) f();", "if (c/* 0 */ >= 0x30) f();"),
            ("2.12", "y = CONTEXT_BLOCK_IN  === nodeContext;", "y = nodeContext  === CONTEXT_BLOCK_IN;"),
            ("3.1", "maxIndex ++;", "++ maxIndex;"),
            ("19.2", "x = o\n  .p\n  .q;", 'x = o\n  ["p"]\n  ["q"];'),
            ("19.1", 'x = o\n  ["p"]\n  ["q"];', "x = o\n  .p\n  .q;"),
            ("6.2", "function f() {\n    let a = 1, b = 2;\n    let c = 3;\n}", "function f() {\n    let a = 1, b = 2, c = 3;\n}"),
            ("6.1", "function f() {\n    let a = 1, b = 2;\n    let c = 3;\n}", "function f() {\n    let a = 1;\n    let b = 2;\n    let c = 3;\n}"),
            ("7.2", "while (i < 3) { i++; }", "for (; i < 3; ) { i++; }"),
            # 20.x: else after return (not in function bodies, which void-return owns)
            ("20.1", "function f(a) {\n    while (a > 0) {\n        if (a > 5) {\n            return a;\n        }\n        a--;\n    }\n}\n",
             "function f(a) {\n    while (a > 0) {\n        if (a > 5) {\n            return a;\n        } else {\n            a--;\n        }\n    }\n}\n"),
            ("20.2", "function f(a) {\n    while (a > 0) {\n        if (a > 5) {\n            return a;\n        } else {\n            a--;\n        }\n    }\n}\n",
             "function f(a) {\n    while (a > 0) {\n        if (a > 5) {\n            return a;\n        }\n        a--;\n    }\n}\n"),
            # 24.x: arrow function body
            ("24.1", "const f = x => { return x + 1; };", "const f = x => x + 1;"),
            ("24.2", "const f = x => x + 1;", "const f = x => { return x + 1; };"),
            ("24.2", "const f = x => ({a: x});", "const f = x => { return ({a: x}); };"),
            ("24.2", "const f = x => (a, b);", "const f = x => { return (a, b); };"),
            # 25.x: const / let
            ("25.1", "function f() {\n    let a = 1;\n    return a;\n}", "function f() {\n    const a = 1;\n    return a;\n}"),
            ("25.2", "function f() {\n    const a = 1;\n    return a;\n}", "function f() {\n    let a = 1;\n    return a;\n}"),
            # 26.x: logical assignment
            ("26.2", "function f(a, b) {\n    a = a || b;\n    return a;\n}", "function f(a, b) {\n    a ||= b;\n    return a;\n}"),
            ("26.1", "function f(a, b) {\n    a ??= b;\n    return a;\n}", "function f(a, b) {\n    a = a ?? b;\n    return a;\n}"),
            # 27.x: Math.pow / **
            ("27.2", "function f(a) {\n    return Math.pow(a, 2);\n}", "function f(a) {\n    return a ** 2;\n}"),
            ("27.1", "function f(a) {\n    return a ** 2;\n}", "function f(a) {\n    return Math.pow(a, 2);\n}"),
            # 28.x: parseInt / Number.parseInt
            ("28.2", "function f(s) {\n    return parseInt(s, 10) + parseFloat(s);\n}", "function f(s) {\n    return Number.parseInt(s, 10) + Number.parseFloat(s);\n}"),
            ("28.1", "function f(s) {\n    return Number.parseInt(s, 10);\n}", "function f(s) {\n    return parseInt(s, 10);\n}"),
            # 29.x: undefined / void 0
            ("29.2", "function f(a) {\n    return a ? 1 : undefined;\n}", "function f(a) {\n    return a ? 1 : void 0;\n}"),
            ("29.1", "function f(a) {\n    return a ? 1 : void 0;\n}", "function f(a) {\n    return a ? 1 : undefined;\n}"),
            # a comment that follows a block's closing brace is parsed as part of the block; it must stay where it is
            ("24.2", "const f = () => true // note\ng();\n", "const f = () => { return true; } // note\ng();\n"),
            ("24.1", "const f = () => { return true; } // note\ng();\n", "const f = () => true // note\ng();\n"),
        ],
    }

    # Sites a rule must leave alone: (style, code). The guards behind each one are listed in the comment.
    UNCHANGED = {
        "javascript": [
            # 2.4: the bare comparison would bind to the wrong operands
            ("2.4", "if (x < !(a !== b)) f();"),
            # 6.x: multi-line declarators are not in the canonical layout either rule produces
            ("6.1", "function f() {\n    var a = 1,\n        b = 2;\n}"),
            # 2.1, 19.x, 23.1: spelling the rewrite would normalise (so the pair could not undo it)
            ("2.1", "x=x+1;"),
            ("19.1", 'y = o["p" ];'),
            ("19.2", "y = o. p;"),
            ("23.1", "z = {a:a};"),
            # 2.7, 2.12: the swapped operand would fuse with the keyword before it (`returna`)
            ("2.7", 'function f(a) { return"a"<a; }'),
            ("2.12", 'function f(a) { return"a"===a; }'),
            # 3.1: the value of `n--` is the loop test (the loop-form rule writes `while (n--)` as `for (; n--; )`)
            ("3.1", "function f(n) {\n    for (; n--; ) {\n        g();\n    }\n}"),
            # 14.2, 20.1, 18.2: a trailing comment would end up in front of the moved or added text
            ("14.2", "function f(c) {\n    if (c) {\n        a();\n    } else {\n        b();\n    } // note\n}"),
            ("20.1", "function f(c) {\n    while (c) {\n        if (c > 1) {\n            return 1;\n        } // note\n        c--;\n    }\n}"),
            ("18.2", "function f(c) {\n    a(); // note\n}"),
            # 7.2: spacing the rewrite would normalise
            ("7.2", "while(i < 3){ i++; }"),
            # 20.x: block-scoped declarations change meaning when moved in or out of an else block
            ("20.1", "function f(a) {\n    while (a > 0) {\n        if (a > 5) {\n            return a;\n        }\n        let b = a - 1;\n        a = b;\n    }\n}\n"),
            ("20.2", "function f(a) {\n    while (a > 0) {\n        if (a > 5) {\n            return a;\n        } else {\n            let b = a - 1;\n            a = b;\n        }\n    }\n}\n"),
            # 20.x: function bodies belong to void-return (18.x), whose final-return view an else would change
            ("20.1", "function f(a) {\n    if (a > 5) {\n        return a;\n    }\n    a--;\n    return a;\n}\n"),
            # 24.1: a returned object or sequence cannot lose its braces without parentheses (not reversible)
            ("24.1", "const f = x => { return {a: x}; };"),
            ("24.1", "const f = x => { return x, 1; };"),
            # 24.1: the concise body would swallow the next line
            ("24.1", "const f = x => { return 1; }\n(0, g)();\n"),
            # 24.2: arrow inside an equality operand (changes what the equality rules see)
            ("24.2", "if ((x => x) === y) f();"),
            # 25.1: written bindings
            ("25.1", "function f() {\n    let a = 1;\n    a = 2;\n    return a;\n}"),
            ("25.1", "function f() {\n    let a = 1;\n    [a] = [2];\n    return a;\n}"),
            ("25.1", "function f() {\n    let a = 1;\n    for (a of [1]) {}\n    return a;\n}"),
            ("25.1", "function f() {\n    let a = 1;\n    a++;\n    return a;\n}"),
            # 25.x: neighbouring declarations belong to the declare pair
            ("25.1", "function f() {\n    let a = 1;\n    let b = 2;\n    return a + b;\n}"),
            ("25.2", "function f() {\n    const a = 1;\n    const b = 2;\n    return a + b;\n}"),
            # 26.2: a const of that name anywhere in the file
            ("26.2", "function g() {\n    const a = 2;\n    return a;\n}\nfunction f(a, b) {\n    a = a || b;\n    return a;\n}"),
            # 26.2: an anonymous function would get a name from ||= but not from ||
            ("26.2", "function f(a) {\n    a = a || function () {};\n    return a;\n}"),
            # 27.2: BigInt, shadowed Math, unary minus, right-associative **
            ("27.2", "function f(a) {\n    const big = 10n;\n    return Math.pow(a, 2);\n}"),
            ("27.2", "function f(Math, a) {\n    return Math.pow(a, 2);\n}"),
            ("27.2", "function f(a) {\n    return -Math.pow(a, 2);\n}"),
            ("27.1", "function f(a, b) {\n    return a ** b ** 2;\n}"),
            # 28.2: shadowed parseInt
            ("28.2", "function f(s) {\n    function parseInt() { return 1; }\n    return parseInt(s, 10);\n}"),
            # a binding named undefined shadows the value
            ("29.2", "function f(undefined) { return undefined; }"),
            # 29.2: inside a comparison, or as the object of a member access
            ("29.2", "function f(a) {\n    if (a === undefined) return 1;\n}"),
            ("29.2", "function f(a) {\n    return undefined.x;\n}"),
        ],
    }

    def test_loop_with_update_kept_in_body_is_still_marked_and_stable(self):
        """Style 12 has no rewrite: it detects the marker form, and the marked loop is not rewritten again."""
        from change_program_style import SCTS
        scts = SCTS("c")
        before = "void f(int n){\n    int i = 0;\n    while (i < n) {\n        i++;\n        g(i);\n    }\n}"
        after = scts.change_file_style("7.8", before)[0]
        self.assertEqual(scts.get_file_popularity("7.8", before), 0)
        self.assertEqual(scts.get_file_popularity("7.8", after), 1)
        self.assertEqual(scts.change_file_style("7.8", after)[0], after)
        self.assertTrue(scts.check_syntax(after))

    def test_golden_rewrites(self):
        from change_program_style import SCTS
        for language, cases in self.CASES.items():
            scts = SCTS(language)
            for style, before, after in cases:
                with self.subTest(language=language, style=style):
                    self.assertEqual(scts.change_file_style(style, before)[0], after)

    def test_guarded_sites_are_left_alone(self):
        from change_program_style import SCTS
        for language, cases in self.UNCHANGED.items():
            scts = SCTS(language)
            for style, code in cases:
                with self.subTest(language=language, style=style, code=code):
                    self.assertEqual(scts.change_file_style(style, code)[0], code)

    def test_golden_pairs_are_exact_inverses(self):
        """A golden case also holds backwards: the other style of the pair undoes it."""
        import rule_dict_bit_acc
        from change_program_style import SCTS
        pair_of = {style: styles for pairs in rule_dict_bit_acc.rule_dict["javascript"].values() for styles in [pairs] for style in styles}
        scts = SCTS("javascript")
        for style, before, after in self.CASES["javascript"]:
            if style in pair_of and style.split(".")[0] in {"20", "24", "25", "26", "27", "28", "29"}:
                other = [candidate for candidate in pair_of[style] if candidate != style][0]
                with self.subTest(style=style):
                    self.assertEqual(scts.change_file_style(other, after)[0], before)


import shutil  # noqa: E402  (kept next to the only tests that run Node, so other languages' edits merge cleanly)
import subprocess  # noqa: E402
import tempfile  # noqa: E402


@unittest.skipUnless(HAS_GRAMMARS and shutil.which("node"), "needs the pinned parsers and Node.js")
class JavaScriptExecutionTests(unittest.TestCase):
    """Programs print the same output before and after each rewrite of a JavaScript rule."""
    PROGRAMS = [
        (["20.1"], """
function first(list) {
    for (let i = 0; i < list.length; i++) {
        if (list[i] > 3) {
            return list[i];
        }
        console.log('skip', list[i]);
    }
    return null;
}
console.log(first([1, 2, 5, 7]), first([1]));
"""),
        (["24.2"], """
const f = x => x + 1;
const g = x => ({a: x});
const h = (a, b) => (a, b);
const k = async x => await x;
console.log(f(1), g(2), h(3, 4), [1, 2, 3].map(x => x * 2));
k(5).then(v => console.log(v));
"""),
        (["25.1"], """
function counter() {
    let start = 10;
    const fns = [];
    for (let i = 0; i < 3; i++) {
        let doubled = i * 2;
        fns.push(() => doubled + start);
    }
    return fns.map(fn => fn());
}
console.log(counter());
"""),
        (["26.2"], """
function pick(a, b) {
    a = a || b;
    return a;
}
function both(a, b) {
    a = a && b;
    return a;
}
function fill(a, b) {
    a = a ?? b;
    return a;
}
console.log(pick(0, 5), pick(3, 5), both(0, 5), both(3, 5), fill(0, 5), fill(null, 5), fill(undefined, 5));
"""),
        (["27.2"], """
let n = 5;
const values = [Math.pow(2, 10), Math.pow(0, 0), Math.pow(-8, 1 / 3), Math.pow(2, 0.5), Math.pow(1, Infinity), 3 * Math.pow(n, 2) + 1];
console.log(values, [1, 2, 3].map(x => x ** n));
"""),
        (["28.2"], """
console.log(parseInt('12px', 10), parseFloat('3.5e2x'), parseInt('0x1f'), Number.parseInt === parseInt, ['1', '2'].map(s => parseInt(s, 10)));
"""),
        (["29.2"], """
const pairs = [1, undefined, void 0];
function pick(a) {
    return a ? a : undefined;
}
console.log(pairs, pick(0), typeof undefined, [undefined].length);
"""),
        (["2.3", "2.5", "2.7", "2.12", "3.1", "6.1", "7.2", "19.2"], """
let i = 0, total = 0;
let flag = true;
while (i < 3) {
    if (0 < i  &&  flag  === true) {
        total += i;
    }
    i ++;
}
const o = {p: {q: 4}};
console.log(total, o
  .p
  .q, i !== 3);
"""),
    ]

    def execute(self, code):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "program.js"
            path.write_text(code)
            result = subprocess.run([shutil.which("node"), str(path)], capture_output=True, text=True, timeout=30)
        self.assertEqual(result.returncode, 0, result.stderr)
        return result.stdout

    def test_rewrites_keep_program_output(self):
        import rule_dict_bit_acc
        from change_program_style import SCTS
        scts = SCTS("javascript")
        partner = {style: [other for other in styles if other != style][0]
                   for styles in rule_dict_bit_acc.rule_dict["javascript"].values() for style in styles}
        for styles, program in self.PROGRAMS:
            expected = self.execute(program)
            for style in styles:
                with self.subTest(style=style):
                    rewritten = scts.change_file_style(style, program)[0]
                    self.assertNotEqual(rewritten, program, "the program gives the rule nothing to rewrite")
                    self.assertEqual(self.execute(rewritten), expected)
                    # and the partner style, which turns the rewritten form back, keeps the output as well
                    self.assertEqual(self.execute(scts.change_file_style(partner[style], rewritten)[0]), expected)
