"""Position guards added to the C and C++ rules after the CodeNet evaluation (docs/plans/2026-10-07-rule-fixes.md,
sections A-I): every class has a minimal counter-example the rule must leave alone and an example it must still
rewrite. The Python rules (section J) are covered elsewhere."""

import unittest

from cllmark.transform import StyleTransformer

TRANSFORMERS = {}


def apply(language, style, code):
    if language not in TRANSFORMERS:
        TRANSFORMERS[language] = StyleTransformer(language, rule_set="extended")
    return TRANSFORMERS[language].apply(style, code)[0]


class RuleFixCase(unittest.TestCase):
    def assertRejected(self, language, style, code):
        self.assertEqual(apply(language, style, code), code, (language, style))

    def assertRewrites(self, language, style, code, expected=None):
        result = apply(language, style, code)
        self.assertNotEqual(result, code, (language, style))
        if expected is not None:
            self.assertEqual(result, expected, (language, style))


class MacroRedefinedTypeTests(RuleFixCase):
    """A: `#define int long long` changes what rules that write `int` / `double` / sizeof(int) mean."""

    MACRO = "#define int long long\n"

    def test_main_style_keeps_signed_main(self):
        self.assertRejected("cpp", "4.1", self.MACRO + "signed main(){ return 0; }")
        self.assertRejected("c", "4.5", self.MACRO + "signed main(){ return 0; }")
        self.assertRewrites("cpp", "4.1", "signed main(){ }", "int main(void){\n    return 0; }")

    def test_cast_style_and_array_init(self):
        self.assertRejected("cpp", "22.1", self.MACRO + "double f(int a){ return (int)(a) / 2.0; }")
        self.assertRewrites("cpp", "22.1", "double f(int a){ return (double)a / 2; }")
        code = "#include <stdlib.h>\nvoid f(){ int a[5]; a[0] = 1; }"
        self.assertRewrites("c", "5.1", code)
        self.assertRejected("c", "5.1", self.MACRO + code)

    def test_stream_rules_keep_their_form(self):
        header = "#include <iostream>\nusing namespace std;\n"
        self.assertRejected("cpp", "9.2", self.MACRO + "void f(){ int x; cout << x << endl; }")
        self.assertRejected("cpp", "9.4", self.MACRO + "void f(){ int x; cin >> x; }")
        self.assertRejected("cpp", "9.1", self.MACRO + header + 'void f(){ int x; printf("%d\\n", x); }')
        self.assertRejected("cpp", "9.3", self.MACRO + header + 'void f(){ int x; scanf("%d", &x); }')

    def test_other_defines_do_not_matter(self):
        self.assertRewrites("c", "4.1", "#define ll long long\nsigned main(){ }")
        self.assertRewrites("c", "4.1", "#define integer 1\nsigned main(){ }")


class MainWithFunctionTryBlockTests(RuleFixCase):
    def test_try_block_main_is_left_alone(self):
        self.assertRejected("cpp", "4.5", "int main() try { f(); } catch (...) {}")
        self.assertRewrites("cpp", "4.5", "int main() { f(); }")


class UserOperatorTests(RuleFixCase):
    """B and G: a user type may overload only some operators; `operator+=` written as `*this = *this + b`."""

    OPERATORS = "struct M { int v; };\nM operator+(M a, M b);\n"

    def test_compound_and_comparisons_are_rejected_when_operators_are_overloaded(self):
        for styles, code in [
            (["2.1"], "void f(M p, M s){ p = p - s; }"),
            (["2.2"], "void f(M p, M s){ p -= s; }"),
            (["2.3"], "bool f(M a, M b){ return a == b; }"),
            (["2.4"], "bool f(M a, M b){ return !(a != b); }"),
            (["2.5"], "bool f(M a, M b){ return a != b; }"),
            (["2.6"], "bool f(M a, M b){ return !(a == b); }"),
            (["2.7"], "bool f(int a, int b){ return a > b; }"),
            (["2.8"], "bool f(int a, int b){ return a < b; }"),
            (["2.9"], "bool f(int a){ return a < 3; }"),
            (["2.10"], "bool f(int a){ return (a < 3 || a == 3); }"),
            (["2.11", "2.12"], "bool f(int a, int b){ return a == b; }"),
            (["2.13", "2.14"], "bool f(int a, int b){ return a != b; }"),
        ]:
            self.assertTrue(any(apply("cpp", style, code) != code for style in styles), (styles, "control"))
            for style in styles:
                self.assertRejected("cpp", style, self.OPERATORS + code)

    def test_recursive_operator_body_is_not_rewritten(self):
        body = "struct W { void operator+=(const W &b) { *this = *this + b; } };\n"
        self.assertRejected("cpp", "2.1", body)

    def test_without_overloads_the_rules_still_apply(self):
        self.assertRewrites("cpp", "2.1", "void f(int p, int s){ p = p - s; }", "void f(int p, int s){ p -= s; }")
        self.assertRewrites("cpp", "2.3", "bool f(int a, int b){ return a == b; }")
        self.assertRewrites("cpp", "2.9", "bool f(int a){ return a < 3; }")

    def test_c_is_unchanged_by_the_operator_guard(self):
        self.assertRewrites("c", "2.1", "void f(int p, int s){ p = p - s; }")


class TemplateMisparseTests(RuleFixCase):
    """C: tree-sitter-cpp reads `P.y < A.y || ... > 0` as a member template `y<...>`."""

    SNIPPET = "if (P.y < A.y || B.y <= P.y || A.y == B.y) {\n  continue;\n}\nif (sign(x) > 0) { n++; }"

    def test_comparisons_inside_a_misparsed_template_are_not_rewritten(self):
        self.assertEqual(
            apply("cpp", "2.12", self.SNIPPET).split("\n")[0], "if (P.y < A.y || B.y <= P.y || A.y == B.y) {"
        )
        self.assertEqual(
            apply("cpp", "2.3", self.SNIPPET).split("\n")[0], "if (P.y < A.y || B.y <= P.y || A.y == B.y) {"
        )

    def test_comparison_elsewhere_in_the_file_still_applies(self):
        self.assertEqual(apply("cpp", "2.7", self.SNIPPET).split("\n")[-1], "if (0 < sign(x)) { n++; }")
        code = "void f(int a, int b){ if (a == b) { g(); } }"
        self.assertTrue(apply("cpp", "2.11", code) != code or apply("cpp", "2.12", code) != code)

    def test_candidate_with_parse_errors_is_rejected(self):
        self.assertRejected("cpp", "2.7", "int f(){ return x > ; }")


class ArrayAccessTests(RuleFixCase):
    """D: `a[i]` -> `*(a + i)` must keep precedence and tokens."""

    def test_postfix_context_is_rejected(self):
        for code in [
            "void f(int *a, int i){ a[i]++; }",
            "void f(int *a, int i){ a[i]--; }",
            "void f(struct S *a, int i){ a[i].x = 1; }",
            "void f(struct S *a, int i){ a[i]->x = 1; }",
            "void f(void (*a[])(void), int i){ a[i](); }",
        ]:
            self.assertRejected("c", "5.3", code)

    def test_prefix_and_plain_uses_still_rewrite(self):
        self.assertRewrites("c", "5.3", "void f(int *a, int i){ ++a[i]; }", "void f(int *a, int i){ ++*(a + i); }")
        self.assertRewrites(
            "c", "5.3", "int f(int *a, int i){ return a[i]; }", "int f(int *a, int i){ return *(a + i); }"
        )
        self.assertRewrites(
            "c", "5.3", "int f(int *a, int i){ return a[i-1]; }", "int f(int *a, int i){ return *(a + i-1); }"
        )

    def test_low_precedence_index_is_rejected(self):
        for index in ["2<<17", "i<n", "i&1", "i||j", "c?1:2", "k=1", "i,j"]:
            self.assertRejected("c", "5.3", f"int f(int *P, int i, int n, int j, int c, int k){{ return P[{index}]; }}")

    def test_tight_index_still_rewrites(self):
        for index in ["i+1", "i*2", "i%n", "(i<<1)"]:
            self.assertRewrites("c", "5.3", f"int f(int *P, int i, int n){{ return P[{index}]; }}")

    def test_a_slash_before_the_access_would_start_a_comment(self):
        self.assertRejected("c", "5.3", "int f(int *f, int mid, int i){ return mid/f[i]; }")
        self.assertRewrites("c", "5.3", "int f(int *f, int mid, int i){ return mid+f[i]; }")

    def test_items_with_parse_errors_are_rejected(self):
        self.assertRejected("c", "5.3", "o[256],z[256];\nmain(N){ N = o[N]; }\n".replace("main(N){ N = o[N]; }", "{"))

    def test_pointer_form_needs_a_plus(self):
        self.assertRejected("c", "5.4", "int f(int *a, int i){ return *(a - i); }")
        self.assertRewrites(
            "c", "5.4", "int f(int *a, int i){ return *(a + i); }", "int f(int *a, int i){ return a[i]; }"
        )
        self.assertRewrites(
            "c", "5.4", "int f(int *a, int i){ return *(a + i - 1); }", "int f(int *a, int i){ return a[i - 1]; }"
        )


class ArrayInitTests(RuleFixCase):
    """E: `int a[n]` -> malloc needs malloc declared (an implicit declaration returns int and truncates the pointer)."""

    def test_without_stdlib_the_array_stays(self):
        self.assertRejected("c", "5.1", "#include <stdio.h>\nint main(){ int L[100]; L[0] = 1; return L[0]; }")

    def test_a_fragment_without_includes_is_left_to_the_harness(self):
        self.assertRewrites("c", "5.1", "int f(){ int L[100]; L[0] = 1; return L[0]; }")

    def test_with_stdlib_it_becomes_allocation(self):
        self.assertRewrites(
            "c",
            "5.1",
            "#include <stdlib.h>\nint main(){ int L[100]; L[0] = 1; return L[0]; }",
            "#include <stdlib.h>\nint main(){ int *L = (int*)malloc(sizeof(int) * 100); L[0] = 1; return L[0]; }",
        )

    def test_array_semantics_still_block_it(self):
        header = "#include <stdlib.h>\n"
        self.assertRejected("c", "5.1", header + "int f(){ int a[4]; return sizeof(a); }")
        self.assertRejected("c", "5.1", header + "int *f(){ int a[4]; return &a[0] == 0 ? 0 : (int *)&a; }")
        self.assertRejected("c", "5.1", header + "int a[4];")


class SelfAssignmentTests(RuleFixCase):
    """F: the target of `x = x op y` / `x op= y` is evaluated once or twice: it must have no side effects."""

    def test_side_effects_in_the_target_are_rejected(self):
        self.assertRejected("c", "2.2", "void f(char *ans){ *ans++ += '0'; }")
        self.assertRejected("c", "2.1", "void f(char *ans){ *ans++ = *ans++ + '0'; }")
        self.assertRejected("c", "2.2", "void f(int *a){ a[g()] += 1; }")
        self.assertRejected("c", "2.2", "void f(int *a, int i){ a[i = 2] += 1; }")

    def test_plain_targets_still_rewrite(self):
        self.assertRewrites(
            "c", "2.2", "void f(int *a, int i){ a[i] += 1; }", "void f(int *a, int i){ a[i] = a[i] + 1; }"
        )
        self.assertRewrites(
            "c", "2.1", "void f(int *a, int i){ a[i] = a[i] + 1; }", "void f(int *a, int i){ a[i] += 1; }"
        )


class NestedLoopTests(RuleFixCase):
    """H: a brace-less loop or branch body would keep only the first of the two statements `a;` / `for(;;)`."""

    def test_loop_as_a_braceless_body_is_rejected(self):
        self.assertRejected(
            "cpp", "7.7", "void f(int n, int s){ for (int i = 0; i < n; i++) for (int j = i; j < n; j++) { s++; } }"
        )
        self.assertRejected("c", "7.7", "void f(int n, int s, int j){ if (n) for (j = 0; j < n; j++) { s++; } }")
        self.assertRejected(
            "c", "7.7", "void f(int n, int s, int j){ if (n) { } else for (j = 0; j < n; j++) { s++; } }"
        )
        self.assertRejected("c", "7.7", "void f(int n, int s, int j){ while (n--) for (j = 0; j < n; j++) { s++; } }")

    def test_loops_in_blocks_and_cases_still_rewrite(self):
        self.assertRewrites("c", "7.7", "void f(int n, int s, int j){ for (j = 0; j < n; j++) { s++; } }")
        self.assertRewrites(
            "c",
            "7.7",
            "void f(int n, int s, int i, int j){ for (i = 0; i < n; i++) { for (j = 0; j < n; j++) { s++; } } }",
        )
        self.assertRewrites(
            "c", "7.7", "void f(int n, int s, int j){ switch (n) { case 1: for (j = 0; j < n; j++) { s++; } } }"
        )


class IostreamTests(RuleFixCase):
    """I: stdio <-> iostream rules."""

    HEADER = "#include <iostream>\n#include <cstdio>\nusing namespace std;\n"

    def printf(self, body, declarations="int x; long long y; char c; double d;"):
        return self.HEADER + f"void f(){{ {declarations} {body} }}"

    def test_printf_format_string_is_taken_from_the_tree(self):
        self.assertRewrites(
            "cpp",
            "9.1",
            self.printf('printf("%d\\n", x);'),
            self.printf('cout << x << "\\n";'),
        )
        self.assertRewrites(
            "cpp",
            "9.1",
            self.printf('printf("a=%d b=%lld\\n", x, y);'),
            self.printf('cout << "a=" << x << " b=" << y << "\\n";'),
        )
        self.assertRewrites("cpp", "9.1", self.printf('printf("hello\\n");'), self.printf('cout << "hello\\n";'))
        self.assertRewrites("cpp", "9.1", self.printf('printf("%c", c);'), self.printf("cout << c;"))

    def test_printf_with_formatting_or_mismatched_types_is_rejected(self):
        for body in [
            'printf("%.2f\\n", d);',
            'printf("%f\\n", d);',
            'printf("%lf\\n", d);',
            'printf("%5d\\n", x);',
            'printf("%e\\n", d);',
            'printf("%g\\n", d);',
            'printf("%d\\n", y);',
            'printf("%c\\n", x);',
            'printf("%d\\n", d);',
            'printf("100%%\\n");',
            'if (printf("%d", x)) {}',
            'int r = printf("%d", x);',
        ]:
            self.assertRejected("cpp", "9.1", self.printf(body))

    def test_scanf_to_cin(self):
        declarations = "int a, b; double d; char s[10]; int v[3];"
        self.assertRewrites(
            "cpp",
            "9.3",
            self.printf('scanf("%d %d", &a, &b);', declarations),
            self.printf("cin >> a >> b;", declarations),
        )
        self.assertRewrites(
            "cpp", "9.3", self.printf('scanf("%lf", &d);', declarations), self.printf("cin >> d;", declarations)
        )
        self.assertRewrites(
            "cpp", "9.3", self.printf('scanf("%s", s);', declarations), self.printf("cin >> s;", declarations)
        )
        self.assertRewrites(
            "cpp", "9.3", self.printf('scanf("%d", &v[1]);', declarations), self.printf("cin >> v[1];", declarations)
        )

    def test_scanf_that_cin_cannot_express_is_rejected(self):
        declarations = "int a, b; double d; char s[10]; int v[3];"
        for body in [
            'if (scanf("%d", &a) <= 0) {}',
            'int r = scanf("%d", &a);',
            'scanf("%lf,%lf", &d, &d);',
            'scanf("%c", &s[0]);',
            'scanf("%[a-z]", s);',
            'scanf("%5d", &a);',
            'scanf("%*d");',
            'scanf("%d", v + 1);',
            'scanf("%d\\n", &a);',
            'scanf("x%d", &a);',
            'scanf("%i", &a);',
        ]:
            self.assertRejected("cpp", "9.3", self.printf(body, declarations))

    def test_cout_to_printf(self):
        self.assertRewrites(
            "cpp", "9.2", "void f(){ int x; cout << x << endl; }", 'void f(){ int x; printf("%d\\n", x); }'
        )
        self.assertRewrites(
            "cpp",
            "9.2",
            'void f(){ int x; long long y; cout << "a" << x << " " << y; }',
            'void f(){ int x; long long y; printf("a%d %lld", x, y); }',
        )

    def test_cout_with_floats_manipulators_or_percent_signs_is_rejected(self):
        for body, declarations in [
            ("cout << d << endl;", "double d;"),
            ("cout << f << endl;", "float f;"),
            ("cout << setprecision(3) << x << endl;", "int x;"),
            ("cout << fixed << x << endl;", "int x;"),
            ("cout << hex << x << endl;", "int x;"),
            ('cout << "50%" << x;', "int x;"),
            ("cout << x << endl;", "long double x;"),
            ("cout << x << endl;", "unsigned long long x;"),
        ]:
            self.assertRejected("cpp", "9.2", f"void f(){{ {declarations} {body} }}")

    def test_cin_to_scanf(self):
        self.assertRewrites(
            "cpp",
            "9.4",
            "void f(){ int a; double d; cin >> a >> d; }",
            'void f(){ int a; double d; scanf("%d%lf", &a, &d); }',
        )
        self.assertRewrites("cpp", "9.4", "void f(){ char s[9]; cin >> s; }", 'void f(){ char s[9]; scanf("%s", s); }')
        self.assertRewrites(
            "cpp",
            "9.4",
            "void f(){ long long v[3]; cin >> v[1]; }",
            'void f(){ long long v[3]; scanf("%lld", &v[1]); }',
        )

    def test_cin_of_strings_and_small_types_is_rejected(self):
        for declarations in ["string s;", "short s;", "char s;", "long double s;"]:
            self.assertRejected("cpp", "9.4", f"void f(){{ {declarations} cin >> s; }}")

    def test_inner_declaration_wins_over_the_outer_one(self):
        self.assertRewrites(
            "cpp",
            "9.4",
            "void f(){ int a; { long long a; cin >> a; } }",
            'void f(){ int a; { long long a; scanf("%lld", &a); } }',
        )

    def test_any_other_use_of_cin_blocks_the_file(self):
        self.assertRejected("cpp", "9.4", "void f(){ int n; while (cin >> n) { } int a; cin >> a; }")
        self.assertRejected("cpp", "9.4", "void f(){ int a; cin >> a; if (cin.eof()) {} }")
        self.assertRejected("cpp", "9.4", "void f(){ int a; cin >> a; if (!cin) {} }")

    def test_synchronization_changes_block_all_four_rules(self):
        sync = "void g(){ ios::sync_with_stdio(false); cin.tie(0); }\n"
        self.assertRejected("cpp", "9.1", sync + self.printf('printf("%d\\n", x);'))
        self.assertRejected("cpp", "9.2", sync + "void f(){ int x; cout << x; }")
        self.assertRejected("cpp", "9.3", sync + self.printf('scanf("%d", &x);'))
        self.assertRejected("cpp", "9.4", sync + "void f(){ int x; cin >> x; }")

    def test_cin_and_cout_must_be_declared_for_the_stdio_directions(self):
        code = 'void f(){ int x; printf("%d\\n", x); scanf("%d", &x); }'
        self.assertRejected("cpp", "9.1", "#include <stdio.h>\n" + code)
        self.assertRejected("cpp", "9.3", "#include <stdio.h>\n" + code)
        self.assertRejected("cpp", "9.1", "#include <iostream>\n" + code)
        self.assertRewrites("cpp", "9.1", "#include <bits/stdc++.h>\nusing namespace std;\n" + code)
        self.assertRewrites("cpp", "9.3", "#include <iostream>\n#include <cstdio>\nusing namespace std;\n" + code)

    def test_a_fragment_without_includes_takes_its_declarations_from_the_harness(self):
        self.assertRewrites(
            "cpp", "9.1", 'void f(){ int x; printf("%d\\n", x); }', 'void f(){ int x; cout << x << "\\n"; }'
        )
        self.assertRewrites("cpp", "9.3", 'void f(){ int x; scanf("%d", &x); }', "void f(){ int x; cin >> x; }")

    def test_the_reverse_directions_need_the_same_declarations(self):
        self.assertRejected("cpp", "9.2", "#include <iostream>\nvoid f(){ int x; cout << x; }")
        self.assertRejected("cpp", "9.4", "#include <iostream>\nvoid f(){ int x; cin >> x; }")
        self.assertRewrites(
            "cpp", "9.2", "#include <iostream>\n#include <cstdio>\nusing namespace std;\nvoid f(){ int x; cout << x; }"
        )

    def test_printf_and_scanf_must_be_declared_for_both_directions(self):
        iostream = "#include <iostream>\nusing namespace std;\n"
        printf = 'void f(){ int x; printf("%d\\n", x); }'
        scanf = 'void f(){ int x; scanf("%d", &x); }'
        self.assertRejected("cpp", "9.2", iostream + "void f(){ int x; cout << x; }")
        self.assertRejected("cpp", "9.4", iostream + "void f(){ int x; cin >> x; }")
        self.assertRejected("cpp", "9.1", iostream + printf)
        self.assertRejected("cpp", "9.3", iostream + scanf)
        for header in ["#include <cstdio>\n", "#include <stdio.h>\n", "#include <bits/stdc++.h>\n"]:
            if "bits" not in header:
                header += iostream
            else:
                header += "using namespace std;\n"
            self.assertRewrites("cpp", "9.2", header + "void f(){ int x; cout << x; }")
            self.assertRewrites("cpp", "9.4", header + "void f(){ int x; cin >> x; }")
            self.assertRewrites("cpp", "9.1", header + printf)
            self.assertRewrites("cpp", "9.3", header + scanf)

    def test_redefined_io_names_block_the_rules(self):
        self.assertRejected("cpp", "9.2", "#define cout cerr\nvoid f(){ int x; cout << x; }")
        self.assertRejected("cpp", "9.4", "#define cin myin\nvoid f(){ int x; cin >> x; }")


if __name__ == "__main__":
    unittest.main()
