"""Position guards added to the C and C++ rules after the robust-watermark CodeNet runs
(docs/plans/2026-10-08-rule-fixes-robust.md, A-G): the keyed embedding rewrites every selected site, which exposed
positions the BCH runs never touched. Every class has the minimal counter-example from the bisect and a control the
rule must still rewrite."""

import unittest

from tests.test_rule_fixes_c import RuleFixCase, apply


class StatementCastTests(RuleFixCase):
    """A: `(void)x;` -> `void(x);` declares a variable x of type void (C++ most vexing parse)."""

    def test_statement_leading_cast_is_left_alone(self):
        self.assertRejected("cpp", "22.1", "void f(int digest){ (void)digest; }")
        self.assertRejected("cpp", "22.1", "void f(int x){ (double)x; }")

    def test_casts_inside_expressions_still_rewrite(self):
        self.assertRewrites("cpp", "22.1", "double f(int a){ return (double)a / 2; }")
        self.assertRewrites("cpp", "22.1", "void f(int a){ g((double)a); }", "void f(int a){ g(double(a)); }")
        self.assertRewrites("cpp", "22.1", "void f(int a){ x = (double)a; }", "void f(int a){ x = double(a); }")


class MisparsedConditionalTests(RuleFixCase):
    """B: tree-sitter-cpp reads `x < y ? a : b` as `x < (y ? a : b)`; negating that condition negates `y` alone."""

    def test_conditional_under_a_comparison_is_left_alone(self):
        # the minimal context from CodeNet p01843: the first comparison opens a template argument list
        code = (
            "\t\t\tif (params.x < 0.0 || params.y < 0.0) continue;\n"
            "\tfor (int i = 0; i < count; i++) scores[i] = pool.scoreAt(i);\n"
            "\tint answer = count > 0 ? scores[count - 1] : 0;\n"
        )
        self.assertRejected("cpp", "15.2", code)
        self.assertNotEqual(apply("c", "15.2", code), code)  # C has no templates: the same text parses and swaps

    def test_plain_conditionals_still_swap(self):
        self.assertRewrites("c", "15.2", "int f(int a){ return a ? 1 : 2; }", "int f(int a){ return !(a) ? 2 : 1; }")
        self.assertRewrites("cpp", "15.2", "int f(bool neg, int v){ return neg ? -v : v; }")
        code = "int f(int count, int *s){ int answer = count > 0 ? s[count - 1] : 0; return answer; }"
        self.assertRewrites(
            "cpp", "15.2", code, code.replace("count > 0 ? s[count - 1] : 0", "!(count > 0) ? 0 : s[count - 1]")
        )
        self.assertRewrites("c", "15.2", "int f(int a, int b){ return (a > b) ? a : b; }")


class ExpandedComparisonTests(RuleFixCase):
    """C: only the four forms the expansion writes contract, and never the parentheses of a statement condition."""

    def test_other_pairings_and_statement_conditions_are_left_alone(self):
        self.assertRejected("c", "2.10", "void f(int n){ if (n <= 0 && n == 0) g(); }")
        self.assertRejected("c", "2.10", "int f(int n){ return (n < 0 && n == 0); }")
        self.assertRejected("c", "2.10", "int f(int n){ return (n <= 0 || n != 0); }")
        self.assertRejected("c", "2.10", "void f(int n){ while (n < 9 || n == 9) n--; }")

    def test_the_expansions_still_contract(self):
        for code, expected in [
            ("int f(int n){ return (n < 3 || n == 3); }", "int f(int n){ return n <= 3; }"),
            ("int f(int n){ return (n >= 3 && n != 3); }", "int f(int n){ return n > 3; }"),
            ("void f(int n){ if ((n > 1 || n == 1)) g(); }", "void f(int n){ if (n >= 1) g(); }"),
        ]:
            self.assertRewrites("c", "2.10", code, expected)
        expanded = apply("c", "2.9", "int f(int n){ return n <= 3; }")
        self.assertEqual(apply("c", "2.10", expanded), "int f(int n){ return n <= 3; }")


class SubscriptBaseTests(RuleFixCase):
    """D: `p->cells[to][k]` became `*(*(*(p + cells) + to) + k)`."""

    def test_member_bases_are_left_alone(self):
        self.assertRejected("c", "5.3", "void f(T *p, int to, int k){ p->cells[to][k] = 0; }")
        self.assertRejected("c", "5.3", "void f(T s, int i, int j){ s.grid[i][j] = 0; }")
        self.assertRejected("c", "5.3", "void f(T *p, int i){ p->cells[i] = 0; }")

    def test_array_names_still_rewrite(self):
        self.assertRewrites(
            "c",
            "5.3",
            "void f(int a[3][3], int r, int c){ a[r][c] = 0; }",
            "void f(int a[3][3], int r, int c){ *(*(a + r) + c) = 0; }",
        )
        self.assertRewrites("c", "5.3", "void f(int *a, int i){ a[i] = 0; }", "void f(int *a, int i){ *(a + i) = 0; }")


class MallocToArrayTests(RuleFixCase):
    """E: `T *p = malloc(...)` -> `T p[n]` only for a small literal size and a pointer that never leaves its block."""

    HEADER = "#include <stdlib.h>\n"

    def test_escaping_or_large_allocations_are_left_alone(self):
        for body in [
            "char *grown = (char*)malloc(sizeof(char) * 12); a->items = grown;",
            "char *grown = (char*)malloc(sizeof(char) * 12); char *alias = grown; use(alias);",
            "char *grown = (char*)malloc(sizeof(char) * 12); q = grown + 1;",
            "char *grown = (char*)malloc(sizeof(char) * 12); grown++;",
            "char *grown = (char*)malloc(sizeof(char) * 12); n = sizeof(grown);",
            "char *grown = (char*)malloc(sizeof(char) * n); grown[0] = 1;",
            "char *grown = (char*)malloc(sizeof(char) * 100000); grown[0] = 1;",
            "char *grown = (char*)malloc(sizeof(char) * 12); free(grown);",
        ]:
            self.assertRejected("c", "5.2", self.HEADER + "void f(S *a, char *q, int n){ " + body + " }")

    def test_a_bare_sizeof_allocation_is_left_alone_without_raising(self):
        # zstd: `T *p = (T*)malloc(sizeof(T));` raised IndexError in element_count before the size check
        self.assertRejected("c", "5.2", self.HEADER + "void f(void){ S *p = (S*)malloc(sizeof(S)); p->x = 1; }")

    def test_local_buffers_still_become_arrays(self):
        code = self.HEADER + "void f(void){ char *buf = (char*)malloc(sizeof(char) * 16); buf[0] = 1; g(buf); }"
        self.assertRewrites("c", "5.2", code, self.HEADER + "void f(void){ char buf[16]; buf[0] = 1; g(buf); }")


class TemplateMisparsedLoopTests(RuleFixCase):
    """F: `while (r.count < 8 && seek < cursor) {...} ... struct S {` parsed as template arguments; the while-to-for
    rewrite then deleted everything up to the struct."""

    CODE = (
        "struct R { int count; };\n"
        "bool f(R &record, long seek, long cursor) {\n"
        "    while (record.count < 8 && seek < cursor) {\n"
        "        record.count += 1;\n"
        "    }\n"
        "    return record.count > 0;\n"
        "}\n"
        "struct UtilSink {\n"
        "    int used;\n"
        "};\n"
    )

    def test_loops_in_a_misparsed_statement_are_left_alone(self):
        result = apply("cpp", "7.8", self.CODE)
        self.assertIn("struct UtilSink {", result)
        self.assertIn("record.count < 8 && seek < cursor", result)

    def test_plain_loops_still_rewrite(self):
        self.assertRewrites("cpp", "7.8", "void f(int n){ while (n > 0) { n -= 1; } }")
        self.assertRewrites("c", "7.8", "void f(int n){ while (n > 0) { n -= 1; } }")


class ForUpdateTests(RuleFixCase):
    """G: moving `c` of `for (a; b; c)` to the end of the body is skipped by `continue`; a brace-less body has no end
    inside the loop."""

    def test_continue_and_braceless_bodies_are_left_alone(self):
        with_continue = "void f(int n){ for (int i = 0; i < n; i++) { if (i == 2) continue; g(i); } }"
        for style in ["7.3", "7.4", "7.5"]:
            self.assertRejected("c", style, with_continue)
        braceless = "void f(int n){ int i; for (i = 0; i < n; i++) g(i); }"
        for style in ["7.2", "7.3", "7.4", "7.5", "7.6"]:
            self.assertRejected("c", style, braceless)

    def test_the_condition_may_still_move_past_a_continue(self):
        self.assertRewrites("c", "7.2", "void f(int n){ for (int i = 0; i < n; i++) { if (i == 2) continue; g(i); } }")

    def test_braced_bodies_without_continue_still_rewrite(self):
        self.assertRewrites("c", "7.4", "void f(int n){ for (int i = 0; i < n; i++) { g(i); } }")


if __name__ == "__main__":
    unittest.main()
