"""Python token gluing (plan 2026-10-07-rule-fixes, section J): rewrites never fuse with a neighbouring keyword."""

import unittest
import warnings
from pathlib import Path

from cllmark.transform import StyleTransformer

ROOT = Path(__file__).resolve().parents[1]
TRANSFORMER = StyleTransformer("python", rule_set="extended")

# (style, code glued to the previous token: rejected, spaced code: still rewritten, rewritten spaced code)
CASES = [
    ("2.1", "if a in[]:\n    pass\n", "if a in []:\n    pass\n", "if a in list():\n    pass\n"),
    ("2.3", "for _ in[0]*3:\n    pass\n", "for _ in [0]*3:\n    pass\n", "for _ in list([0])*3:\n    pass\n"),
    ("2.3", "def f():\n    return[1, 2]\n", "def f():\n    return [1, 2]\n", "def f():\n    return list([1, 2])\n"),
    ("3.1", "if a in{}:\n    pass\n", "if a in {}:\n    pass\n", "if a in dict():\n    pass\n"),
    ("3.3", "if a in{1: 2}:\n    pass\n", "if a in {1: 2}:\n    pass\n", "if a in dict({1: 2}):\n    pass\n"),
    ("6.3", 'y = a or"NO"\n', 'y = a or "NO"\n', 'y = a or f"NO"\n'),
    ("6.3", 'print(1 if c else"B")\n', 'print(1 if c else "B")\n', 'print(1 if c else f"B")\n'),
    ("7.3", "if(a)==b:\n    pass\n", "if (a)==b:\n    pass\n", "if not ((a) != b):\n    pass\n"),
    ("7.5", "if(a)!=b:\n    pass\n", "if (a)!=b:\n    pass\n", "if not ((a) == b):\n    pass\n"),
    ("7.4", "x = 1 if not (a != b)else 2\n", "x = 1 if not (a != b) else 2\n", "x = 1 if a == b else 2\n"),
    ("7.6", "x = 1 if not (a == b)else 2\n", "x = 1 if not (a == b) else 2\n", "x = 1 if a != b else 2\n"),
    (
        "7.8",
        "print(x if x<(1<<31)else x-m)\n",
        "print(x if x<(1<<31) else x-m)\n",
        "print(x if (1<<31) > x else x-m)\n",
    ),
    (
        "7.8",
        "def f(a, b):\n    return(a)<b\n",
        "def f(a, b):\n    return (a)<b\n",
        "def f(a, b):\n    return b > (a)\n",
    ),
    (
        "7.7",
        "def f(a, b):\n    return(a)>b\n",
        "def f(a, b):\n    return (a)>b\n",
        "def f(a, b):\n    return b < (a)\n",
    ),
    ("7.10", "if(a < 1 or a == 1):\n    pass\n", "if (a < 1 or a == 1):\n    pass\n", "if a <= 1:\n    pass\n"),
    ("14.2", "def f(x, y):\n    return(x) not in y\n", "def f(x, y):\n    return (x) not in y\n", None),
    ("15.2", "def f(x, y):\n    return(x) is not y\n", "def f(x, y):\n    return (x) is not y\n", None),
    ("17.2", "def f(a, c, b):\n    return(a)if c else b\n", "def f(a, c, b):\n    return (a) if c else b\n", None),
    (
        "17.1",
        "def f(a, c, b):\n    return(a)if not c else(b)\n",
        "def f(a, c, b):\n    return (a) if not c else (b)\n",
        None,
    ),
    ("20.2", "i = 3\nwhile(i>=0):\n    i -= 1\n", "i = 3\nwhile (i>=0):\n    i -= 1\n", None),
    ("41.2", "def f(a):\n    return(a)+1\n", "def f(a):\n    return (a)+1\n", "def f(a):\n    return 1+(a)\n"),
    ("41.1", "y = [1+(a)for a in b]\n", "y = [1+(a) for a in b]\n", "y = [(a)+1 for a in b]\n"),
]


def rewrite(style, code):
    return TRANSFORMER.apply(style, code)[0]


def compiles(code):
    with warnings.catch_warnings():
        warnings.simplefilter("error")
        try:
            compile(code, "<test>", "exec")
        except (SyntaxError, SyntaxWarning):
            return False
    return True


class TokenGluingTest(unittest.TestCase):
    def test_glued_position_is_left_alone(self):
        for style, glued, _, _ in CASES:
            with self.subTest(style=style, code=glued):
                self.assertEqual(rewrite(style, glued), glued)

    def test_spaced_position_is_still_rewritten(self):
        for style, _, spaced, expected in CASES:
            if spaced is None:
                continue
            with self.subTest(style=style, code=spaced):
                result = rewrite(style, spaced)
                self.assertNotEqual(result, spaced)
                self.assertTrue(compiles(result), result)
                if expected is not None:
                    self.assertEqual(result, expected)

    def test_hash_order_leaves_glued_operands_alone(self):
        glued, spaced = "if(a)==b:\n    pass\n", "if (a)==b:\n    pass\n"
        for style in ("7.11", "7.12", "7.13", "7.14"):
            self.assertEqual(rewrite(style, glued), glued)
        # Exactly one of the two `==` directions reorders the spaced form.
        self.assertEqual(sum(rewrite(style, spaced) != spaced for style in ("7.11", "7.12")), 1)

    def test_only_the_glued_candidate_is_skipped(self):
        code = "for _ in[0]*3:\n    t = [1]\n"
        self.assertEqual(rewrite("2.3", code), "for _ in[0]*3:\n    t = list([1])\n")

    def test_inverse_direction_removes_prefix_without_gluing(self):
        for style, code, expected in [
            ("2.4", "for _ in list([0])*3:\n    pass\n", "for _ in [0]*3:\n    pass\n"),
            ("6.4", 'y = a or f"NO"\n', 'y = a or "NO"\n'),
        ]:
            self.assertEqual(rewrite(style, code), expected)

    def test_tuple_assignment_does_not_strip_meaningful_spaces(self):
        for style in ("9.1", "9.2"):
            for code in [
                "def f(axis):\n    key, rkey = keys[axis], keys[not axis]\n",
                'def f():\n    a, b = "x y", "z"\n',
            ]:
                with self.subTest(style=style, code=code):
                    self.assertEqual(rewrite(style, code), code)
        self.assertEqual(rewrite("9.1", "def f():\n    a, b = c, d\n"), "def f():\n    a = c\n    b = d\n")

    def test_split_assignment_keeps_tuple_semantics(self):
        for code in [
            "def f(a, b):\n    a, b = b, a\n",
            "def f(a, b):\n    a, b = b, a + b\n",
            "def f(a, b):\n    a, b = 1, a\n",
            "def f(x):\n    a, b = g(x), 2\n",
            "def f(c):\n    a, b = c[0], 2\n",
            "def f(c):\n    a, b = c.x, 2\n",
            "def f(c):\n    a, b = (yield), 2\n",
            "def f(c):\n    x[0], b = 1, 2\n",
            "def f(c):\n    a, b, d = g(x, y), 1\n",
            "def f(c):\n    a, b = [i for i in c], 2\n",
        ]:
            with self.subTest(code=code):
                self.assertEqual(rewrite("9.1", code), code)
        self.assertEqual(rewrite("9.1", "def f(c):\n    x, y = 0, 1\n"), "def f(c):\n    x = 0\n    y = 1\n")
        self.assertEqual(rewrite("9.1", "def f(c, d):\n    a, b = c, d\n"), "def f(c, d):\n    a = c\n    b = d\n")
        self.assertEqual(
            rewrite("9.1", "def f(c):\n    a, b = c + 1, c * 2\n"), "def f(c):\n    a = c+1\n    b = c*2\n"
        )

    def test_split_assignment_needs_its_own_space_indented_line(self):
        for code in [
            "if c: a, b = 1, 2\n",
            "x = 1; a, b = 2, 3\n",
            "def f():\n\ta, b = 1, 2\n",
            "def f():\n    if c:\n\t\ta, b = 1, 2\n",
        ]:
            with self.subTest(code=code):
                self.assertEqual(rewrite("9.1", code), code)
        self.assertEqual(rewrite("9.1", "def f():\n    if c:\n        a, b = 1, 2\n")[-20:], "a = 1\n        b = 2\n")

    def test_chained_assignment_is_not_made_augmented(self):
        chained = "def f(S, x):\n    s = 0\n    S[1] = s = s + x\n"
        self.assertEqual(rewrite("7.1", chained), chained)
        self.assertEqual(rewrite("7.1", "def f(x):\n    s = 0\n    s = s + x\n"), "def f(x):\n    s = 0\n    s += x\n")

    def test_reproduced_codenet_units(self):
        for name, style in [("p00391", "2.3"), ("p02298", "2.3"), ("p00963", "6.3")]:
            path = ROOT / "external" / "codenet" / "dataset" / "Python_H" / f"{name}.py"
            if not path.exists():
                self.skipTest("CodeNet corpus not imported (make codenet-setup)")
            with self.subTest(sample=name):
                code = path.read_text()
                self.assertTrue(compiles(code))
                result = rewrite(style, code)
                self.assertTrue(compiles(result))
                self.assertNotIn("returnlist", result)
                self.assertNotIn("inlist", result)
                self.assertNotIn("orf", result)

    def test_swap_in_codenet_p02920_is_not_split(self):
        path = ROOT / "external" / "codenet" / "dataset" / "Python_G" / "p02920.py"
        if not path.exists():
            self.skipTest("CodeNet corpus not imported (make codenet-setup)")
        code = path.read_text()
        self.assertIn("values[i], values[j] = values[j], values[i]", code)
        self.assertEqual(rewrite("9.1", code), code)


if __name__ == "__main__":
    unittest.main()
