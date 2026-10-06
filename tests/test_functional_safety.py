"""Rewrites that broke real repositories (tools/repo_check.py) and are now left alone, next to the cases still taken."""

import unittest

from cllmark.transform import StyleTransformer

# (language, style, code, expected): expected None means the code must stay as it is.
CASES = [
    # networkx: a nested string reusing the f-string's quote is a syntax error before Python 3.12.
    ("python", "6.2", 'x = f" \\"({\',\'.join(v)})\\""\n', None),
    ("python", "6.2", "y = 'a'\n", 'y = "a"\n'),
    # networkx: without parentheses a tuple over several lines ends the return at the first line break.
    ("python", "10.2", "def f():\n    return (\n        a,\n        b,\n    )\n", None),
    ("python", "10.2", "def f():\n    return (a, b)\n", "def f():\n    return a, b\n"),
    # networkx: in-place operators mutate sets, lists and arrays shared with the caller.
    ("python", "7.1", "def f(nodes, v):\n    nodes = nodes - {v}\n", None),
    ("python", "7.1", "def f(M):\n    M = M / M.sum()\n", None),
    ("python", "7.1", "def f():\n    count = 0\n    count = count + 1\n", "def f():\n    count = 0\n    count += 1\n"),
    ("python", "7.2", "def f(lst):\n    lst += [1]\n", None),
    # networkx: element-wise comparisons of arrays are masks; `not` and `and`/`or` raise on them.
    ("python", "7.5", "def f(A):\n    A[A != 0.0] = 1\n", None),
    ("python", "7.3", "def f(A):\n    m = A == 0\n", None),
    (
        "python",
        "7.3",
        "def f(G):\n    if len(G) == 0:\n        pass\n",
        "def f(G):\n    if not (len(G) != 0):\n        pass\n",
    ),
    ("python", "7.9", "def f(k, m, b):\n    s = (k < m) & (b < 1)\n", None),
    ("python", "7.9", "def f(a, b):\n    if g(a) <= b:\n        pass\n", None),  # g would run twice
    (
        "python",
        "7.9",
        "def f(a):\n    if a < 2:\n        pass\n",
        "def f(a):\n    if (a <= 2 and a != 2):\n        pass\n",
    ),
    # networkx: heap entries order by priority but compare equal by identity, so `<` is not `<= and !=`.
    ("python", "7.9", "def f(child, right):\n    if not child < right:\n        pass\n", None),
    # cppcheck: a template declaration misparsed as `std::set < std::string > noreturn` is not a comparison.
    ("cpp", "2.7", "void f() {\n    std::set<std::string> noreturn;\n}\n", None),
    ("cpp", "2.9", "void f() {\n    std::set<std::string> noreturn;\n}\n", None),
    # cppcheck: expcmp evaluates operands twice and overloaded operators need not be a consistent order.
    ("cpp", "2.9", "void f() {\n    if (tok->next() <= end) g();\n}\n", None),
    ("cpp", "2.9", "void f(It a, It b) {\n    if (a <= b) g();\n}\n", None),
    (
        "cpp",
        "2.9",
        "void f(int a) {\n    if (a <= 3) g();\n}\n",
        "void f(int a) {\n    if ((a < 3 || a == 3)) g();\n}\n",
    ),
    (
        "c",
        "2.9",
        "void f(int a, int b) {\n    if (a <= b) g();\n}\n",
        "void f(int a, int b) {\n    if ((a < b || a == b)) g();\n}\n",
    ),
    # zstd: main's parameters are read in its body.
    ("c", "4.1", "int main(int argCount, const char* argv[])\n{\n    return argCount;\n}\n", None),
    ("c", "4.5", "int main(void)\n{\n    int argc = 3;\n    return argc;\n}\n", None),
    # zstd: a freed, returned or qualified allocation cannot become a stack array, nor a sizeof'd array an allocation.
    ("c", "5.2", "void f(int n) {\n    int *q = (int*)malloc(sizeof(int) * n);\n    free(q);\n}\n", None),
    ("c", "5.2", "void f(int n) {\n    char* const d = (char*)malloc(n);\n    g(d);\n}\n", None),
    ("c", "5.2", "int *f(int n) {\n    int *p = (int*)malloc(sizeof(int) * n);\n    return p;\n}\n", None),
    ("c", "5.1", "void f(void) {\n    int b[5];\n    memset(b, 0, sizeof(b));\n}\n", None),
    ("c", "5.1", "static int g[4];\n", None),
    # zstd: a qualifier after the type is not a declarator.
    ("c", "6.1", "void f(void) {\n    size_t const poolSize = sizeof(*pool);\n}\n", None),
]


class FunctionalSafetyTests(unittest.TestCase):
    def test_breaking_rewrites_are_left_alone_and_safe_ones_taken(self):
        transformers = {}
        for language, style, code, expected in CASES:
            with self.subTest(language=language, style=style, code=code):
                transformer = transformers.setdefault(language, StyleTransformer(language))
                rewritten = transformer.apply(style, code)[0]
                self.assertEqual(rewritten, code if expected is None else expected)
                self.assertTrue(transformer.check_syntax(rewritten))
