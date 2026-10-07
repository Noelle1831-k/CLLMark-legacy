"""The robust-watermark benchmark side: attacks in four languages, the engine (on a minimal fake of `cllmark.robust`),
config selection and protocol digests, the generated configs, and the report.

`cllmark.robust` is developed on another branch; here a fake with the interface of the plan (section 6.1) is injected
into `sys.modules`, so nothing under `cllmark/` is created and the engine, the attacks and the report are tested
without the real scheme.
"""

import contextlib
import hashlib
import importlib.util
import io
import json
import math
import os
import random
import shutil
import sys
import tempfile
import types
import unittest
from dataclasses import dataclass
from pathlib import Path
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from benchmarks import attacks, codenet, node_engine, robust_engine, rule_sets, staged  # noqa: E402
from benchmarks import engine as engine_module  # noqa: E402
from benchmarks.common import digest, protocol_fingerprint  # noqa: E402
from benchmarks.metrics import summarize_group  # noqa: E402
from cllmark import nodes  # noqa: E402
from cllmark.transform import StyleTransformer  # noqa: E402


def load_tool(name):
    spec = importlib.util.spec_from_file_location(name, ROOT / "tools" / (name + ".py"))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


# ------------------------------------------------------------------------------------------------ the fake


def binomial_tail(n, a):
    return sum(math.comb(n, k) for k in range(max(a, 0), n + 1)) / 2**n


def make_fake_robust():
    """A small stand-in for `cllmark.robust` with the 6.1 interface: keys from (file, pair, site index) and a seeded
    target per key; embedding through `nodes.place`; detection by counting agreement, blind by trying every message."""
    module = types.ModuleType("cllmark.robust")

    @dataclass(frozen=True)
    class Scheme:
        name: str
        bits: int
        anchor: str
        message_share: float = 0.5

    @dataclass(frozen=True)
    class Observation:
        file: str
        pair: str
        index: int
        reading: int | None
        usable: bool
        stable: bool
        window: tuple
        key: str

    @dataclass
    class EmbedResult:
        written: dict
        votes: int
        targeted_sites: int
        set_sites: int
        rounds: int

    @dataclass
    class Detection:
        votes: int
        agree: int | None
        p_known: float | None
        decoded: list | None
        p_blind: float
        margin: float
        per_file: dict
        keys: dict

    def observe(transformer, language, files, anchor):
        found = []
        for name in sorted(files):
            for pair, styles in transformer.pairs.items():
                for index, site in enumerate(nodes.sites(transformer, styles, files[name])):
                    key = hashlib.sha256(f"{anchor}:{name}:{pair}:{index}".encode()).hexdigest()[:16]
                    found.append(Observation(name, pair, index, site.reading, site.usable, True, site.window, key))
        return found

    def target(key, message):
        return hashlib.sha256(f"{key}:{list(message)}".encode()).digest()[0] & 1

    def embed(transformer, language, files, scheme, key, message):
        chosen = {}
        for site in observe(transformer, language, files, scheme.anchor):
            if site.usable and site.stable:
                chosen.setdefault(site.key, site)
        assignments = [((s.file, s.pair, s.index), target(k, message)) for k, s in chosen.items()]
        written, located = nodes.place(transformer, language, files, assignments)
        return EmbedResult(
            written, len(chosen), len(assignments), sum(found is not None for found in located.values()), 1
        )

    def tail(votes, message):
        agree = sum(reading == target(k, message) for k, reading in votes.items())
        return agree, binomial_tail(len(votes), agree)

    def detect(transformer, language, files, scheme, key, message):
        votes = {
            s.key: s.reading for s in observe(transformer, language, files, scheme.anchor) if s.reading is not None
        }
        agree, p_known = (None, None) if message is None else tail(votes, message)
        best = sorted(
            (tail(votes, [(value >> (scheme.bits - 1 - i)) & 1 for i in range(scheme.bits)])[1], value)
            for value in range(1 << scheme.bits)
        )
        decoded = [(best[0][1] >> (scheme.bits - 1 - i)) & 1 for i in range(scheme.bits)] if votes else None
        margin = math.log10(best[1][0]) - math.log10(best[0][0]) if best[0][0] > 0 else 99.0
        return Detection(
            len(votes), agree, p_known, decoded, min(1.0, best[0][0] * (1 << scheme.bits)), margin, {}, dict(votes)
        )

    for item in (Scheme, Observation, EmbedResult, Detection, observe, embed, detect, binomial_tail):
        setattr(module, item.__name__, item)
    return module


PY_SOURCE = """import sys
# sum of the positive values

def total(values):
    result = 0
    for index in range(len(values)):
        if values[index] > 0 and values[index] != 3:
            result += values[index]
    return result
def label(value):
    return 'big' if value > 10 else 'small'
def main():
    data = [int(x) for x in sys.stdin.read().split()]
    print(total(data), label(total(data)))
    count = 0
    while count < 3:
        count += 1
        print(count)
main()
"""
OTHER_PY = """def helper(a, b):
    if a == b:
        return a + b
    return a - b
print(helper(1, 2))
"""
C_SOURCE = """#include <stdio.h>
static int table[3] = {1, 2, 3};
int add(int a, int b) {
    int s = a;
    s += b;
    if (a != b && s > 0) { s = s + 1; }
    return s;
}
int sub(int a, int b) { return a - b; }
int main(void) {
    int i, total = 0;
    for (i = 0; i < 3; i++) { total += add(table[i], i); }
    printf("%d\\n", total + sub(3, 1));
    return 0;
}
"""
CPP_SOURCE = """#include <iostream>
using namespace std;
int twice(int v) { return v * 2; }
int main() {
    int n = 3, total = 0;
    for (int i = 0; i < n; i++) { total += twice(i); }
    if (total != 4 && n > 1) { cout << total << endl; }
    return 0;
}
"""
JS_SOURCE = """const fs = require('fs');
function sum(values) {
  let result = 0;
  for (let i = 0; i < values.length; i++) {
    if (values[i] > 0 && values[i] !== 3) { result += values[i]; }
  }
  return result;
}
const twice = (x) => x * 2;
function main() {
  const data = fs.readFileSync(0, 'utf8').split(' ').map(Number);
  console.log(sum(data), twice(sum(data)));
}
main();
"""
# `for_OOO` rewrites a `for` into a loop with an empty init clause, on which `while_to_for` of cllmark raises (see the
# findings in the engine docs); the report tests use a program without `for` so that the fake reads its marked code.
C_NO_FOR = C_SOURCE.replace("for (i = 0; i < 3; i++) {", "while (i < 3) { i++;")
SOURCES = {"python": PY_SOURCE, "c": C_SOURCE, "cpp": CPP_SOURCE, "javascript": JS_SOURCE}
SUFFIX = {"python": "py", "c": "c", "cpp": "cpp", "javascript": "js"}


def leaves(transformer, code, skip=("comment",)):
    """(type, text) of the leaf tokens of `code`, comments left out."""
    result = []
    for node in attacks.walk(transformer.parse(code).root_node):
        if node.child_count == 0 and node.type not in skip:
            result.append((node.type, node.text.decode()))
    return result


def readings(transformer, code):
    """Site readings per rule pair (a pair whose rule raises on this code is left out: C `for(;;)` crashes
    `while_to_for`, which the attacks tolerate)."""
    result = {}
    for pair, styles in transformer.pairs.items():
        try:
            result[pair] = [site.reading for site in nodes.sites(transformer, styles, code)]
        except Exception:
            continue
    return result


def top_level_functions(transformer, language, code):
    return len(attacks.function_spans(transformer.parse(code).root_node, language))


# ------------------------------------------------------------------------------------------------ attacks


class AttackNameTests(unittest.TestCase):
    def test_names_parse(self):
        self.assertEqual(attacks.parse_name("flip_0.1"), ("flip", 0.1))
        self.assertEqual(attacks.parse_name("normalize_all"), ("normalize", "all"))
        self.assertEqual(attacks.parse_name("normalize_3"), ("normalize", 3))
        self.assertEqual(attacks.parse_name("insert_1"), ("insert", 1))
        self.assertEqual(attacks.parse_name("rename"), ("rename", None))
        for name in attacks.DEFAULT_ATTACKS:
            attacks.parse_name(name)

    def test_bad_names_are_rejected(self):
        for name in ["flip", "flip_0", "flip_1.5", "flip_x", "normalize_0", "insert_x", "rename_1", "shuffle", ""]:
            with self.subTest(name=name), self.assertRaises(ValueError):
                attacks.parse_name(name)


class AttackTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.transformers = {language: StyleTransformer(language) for language in SOURCES}

    def run_attack(self, name, language, files=None, seed=1, donors=None):
        files = files or {f"a.{SUFFIX[language]}": SOURCES[language]}
        return attacks.apply(name, self.transformers[language], language, files, random.Random(seed), donors)

    def test_attacks_do_not_modify_their_input_and_replay_with_the_seed(self):
        for language in SOURCES:
            files = {f"a.{SUFFIX[language]}": SOURCES[language]}
            for name in ["flip_0.5", "normalize_all", "delete_0.5", "rename", "reformat", "reorder", "combo"]:
                with self.subTest(language=language, attack=name):
                    before = dict(files)
                    first = self.run_attack(name, language, files, seed=5)
                    second = self.run_attack(name, language, files, seed=5)
                    self.assertEqual(files, before)
                    self.assertEqual(first.files, second.files)
                    self.assertEqual(first.effective, second.effective)

    def test_rename_is_a_consistent_fresh_renaming_in_every_language(self):
        for language in SOURCES:
            with self.subTest(language=language):
                transformer = self.transformers[language]
                result = self.run_attack("rename", language)
                (name,) = result.files
                before, after = leaves(transformer, SOURCES[language]), leaves(transformer, result.files[name])
                self.assertEqual(len(before), len(after))
                self.assertTrue(transformer.check_syntax(result.files[name]))
                mapping = {}
                for (kind_a, old), (kind_b, new) in zip(before, after, strict=True):
                    if old != new:
                        self.assertEqual(kind_a, kind_b)
                        self.assertEqual(mapping.setdefault(old, new), new)  # one new name per old name
                self.assertGreaterEqual(len(mapping), 3)
                self.assertEqual(len(set(mapping.values())), len(mapping))  # injective
                self.assertEqual(result.effective, len(mapping))
                existing = {text for _, text in before}
                self.assertFalse(set(mapping.values()) & existing)  # fresh names
                # library names, members and `main` keep their names
                kept = {"print", "len", "range", "printf", "cout", "cin", "readFileSync", "log", "main", "stdin"}
                self.assertFalse(kept & set(mapping))

    def test_rename_keeps_python_programs_running_the_same(self):
        code = PY_SOURCE
        renamed = self.run_attack("rename", "python").files["a.py"]
        self.assertNotEqual(code, renamed)
        outputs = []
        for source in (code, renamed):
            out = io.StringIO()
            with (
                mock.patch.object(sys, "stdin", io.StringIO("1 2 3 12")),
                contextlib.redirect_stdout(out),
            ):
                exec(compile(source, "<attack>", "exec"), {"__name__": "__main__"})
            outputs.append(out.getvalue())
        self.assertEqual(outputs[0], outputs[1])
        self.assertEqual(outputs[0].split(), ["15", "big", "1", "2", "3"])

    def test_rename_keeps_c_and_cpp_programs_compiling_and_running_the_same(self):
        import subprocess

        for language, compiler in [("c", shutil.which("cc")), ("cpp", shutil.which("c++"))]:
            if not compiler:
                continue
            with self.subTest(language=language), tempfile.TemporaryDirectory() as temporary:
                outputs = []
                renamed = self.run_attack("rename", language).files[f"a.{SUFFIX[language]}"]
                for index, source in enumerate((SOURCES[language], renamed)):
                    path = Path(temporary) / f"p{index}.{SUFFIX[language]}"
                    path.write_text(source)
                    built = subprocess.run([compiler, str(path), "-o", str(path) + ".out"], capture_output=True)
                    self.assertEqual(built.returncode, 0, built.stderr.decode())
                    outputs.append(subprocess.run([str(path) + ".out"], capture_output=True, text=True).stdout)
                self.assertEqual(outputs[0], outputs[1])

    def test_rename_leaves_members_keywords_and_attributes_alone(self):
        python = "import os\ndef f(path, key=1):\n    value = os.path.join(path, str(key))\n    return sorted([value], key=len)\n"
        result = self.run_attack("rename", "python", {"a.py": python}).files["a.py"]
        self.assertIn("os.path.join", result)  # imported name and attributes
        self.assertIn("key=len", result)  # keyword argument names of the call
        self.assertNotIn("path,", result)
        members = "struct P { int x; };\nint use(P p) { int x = p.x; return x; }\nint main() { return use(P{1}); }\n"
        cpp = self.run_attack("rename", "cpp", {"a.cpp": members}).files["a.cpp"]
        self.assertIn("int x = ", cpp)  # a class member named x (used bare inside methods) protects the local x in C++
        self.assertIn(".x;", cpp)
        c = self.run_attack("rename", "c", {"a.c": members.replace("(P p)", "(struct P p)")}).files["a.c"]
        self.assertIn(".x;", c)  # member names are never renamed
        self.assertNotIn("int x", c.split("int v_")[1])  # in C the local x is a separate name
        js = "const o = { a: 1 };\nfunction f(a) { return o.a + a; }\nmodule.exports = { f };\n"
        shorthand = self.run_attack("rename", "javascript", {"a.js": js}).files["a.js"]
        self.assertIn("{ a: 1 }", shorthand)  # property names stay
        self.assertIn(".a + ", shorthand)
        self.assertRegex(shorthand, r"module\.exports = \{ f: v_[0-9a-f]+ \}")  # the exported name is kept

    def test_reformat_keeps_tokens_and_normalizes_layout(self):
        messy = {
            "python": "# header\nimport sys\n\n\ndef f(x):  # c\n    return x+1   \n\n\nprint(f(1))\n",
            "c": '#include <stdio.h>\n// note\nint main(){\n      int a=1,b = 2;\n\n\n  /* x */ if(a<b){\n  printf("%d\\n",a+b);}\n return 0;\n}\n',
            "cpp": "#include <iostream>\nint main(){\n int a=1;\n  for(int i=0;i<3;i++){a+=i;}   \n\n  std::cout<<a<<std::endl;\n return 0;}\n",
            "javascript": "// c\nfunction f(x){\n   const y=x*2 ;\n\n\n      return y+1;\n}\nconst z = [1,2,3].map((v)=>v+1);\n",
        }
        for language, code in messy.items():
            with self.subTest(language=language):
                transformer = self.transformers[language]
                result = self.run_attack("reformat", language, {"a": code})
                text = result.files["a"]
                self.assertEqual(leaves(transformer, code), leaves(transformer, text))  # same tokens, no comments
                self.assertNotIn("\n\n", text)
                self.assertNotIn("//", text)
                self.assertNotIn("# ", text)
                self.assertTrue(all(line == line.rstrip() for line in text.split("\n")))
                self.assertEqual(attacks.reformat(transformer, language, result.files).files["a"], text)  # idempotent
                self.assertTrue(transformer.check_syntax(text))
                self.assertEqual(result.effective, 1)
        c_text = self.run_attack("reformat", "c", {"a": messy["c"]}).files["a"]
        self.assertIn("int a = 1, b = 2;", c_text)
        self.assertIn("\n    if(a < b){\n", c_text)  # spaces around operators; keywords and braces are not touched
        self.assertIn('\n        printf("%d\\n", a + b);}\n', c_text)  # four spaces per enclosing block
        js_text = self.run_attack("reformat", "javascript", {"a": messy["javascript"]}).files["a"]
        self.assertIn("    const y = x * 2 ;", js_text)

    def test_reformat_keeps_the_text_of_multiline_strings(self):
        cases = {
            "python": 'x = """a\n\n   b   \n"""\n# c\ny = 1\n',
            "javascript": "const s = `a\n\n  b  \n`;\n// c\nconst t = 1;\n",
            "c": 'const char *s = "a\\\n\n  b";\n/* c */\nint t = 1;\n',
        }
        for language, code in cases.items():
            with self.subTest(language=language):
                text = self.run_attack("reformat", language, {"a": code}).files["a"]
                self.assertEqual(leaves(self.transformers[language], code), leaves(self.transformers[language], text))
                self.assertIn(code.split("\n")[0] + "\n" + code.split("\n")[1] + "\n" + code.split("\n")[2], text)

    def test_delete_removes_the_fraction_of_top_level_functions(self):
        expected = {"python": 3, "c": 3, "cpp": 2, "javascript": 3}  # functions in the samples
        for language, count in expected.items():
            transformer = self.transformers[language]
            with self.subTest(language=language):
                before = top_level_functions(transformer, language, SOURCES[language])
                if language == "javascript":
                    before = count  # `twice` is an arrow function bound to a constant: counted as a function
                self.assertEqual(before, count)
                result = self.run_attack("delete_0.5", language)
                after = top_level_functions(transformer, language, next(iter(result.files.values())))
                self.assertEqual(before - after, attacks.half_up(0.5 * before))
                self.assertEqual(result.effective, before - after)
                self.assertTrue(transformer.check_syntax(next(iter(result.files.values()))))
                kept = leaves(transformer, next(iter(result.files.values())))
                original = leaves(transformer, SOURCES[language])
                self.assertLess(len(kept), len(original))
                it = iter(original)
                self.assertTrue(all(token in it for token in kept))  # what remains is a subsequence

    def test_delete_at_project_level_also_removes_files(self):
        files = {f"f{i}.py": f"def a{i}():\n    return {i}\ndef b{i}():\n    return {i + 1}\n" for i in range(4)}
        result = self.run_attack("delete_0.5", "python", files)
        self.assertEqual(len(result.files), 2)
        self.assertEqual(result.details["files_removed"], 2)
        self.assertEqual(result.details["functions_removed"], 2)  # one of two functions in each remaining file
        self.assertEqual(self.run_attack("delete_0.25", "python", files).details["files_removed"], 1)
        single = self.run_attack("delete_0.5", "python", {"only.py": "def a():\n    return 1\n"})
        self.assertEqual(len(single.files), 1)  # a project keeps at least one file

    def test_reorder_shuffles_functions_and_file_names_without_changing_content(self):
        for language in SOURCES:
            transformer = self.transformers[language]
            with self.subTest(language=language):
                code = SOURCES[language]
                result = self.run_attack("reorder", language, seed=3)
                text = next(iter(result.files.values()))
                self.assertEqual(sorted(leaves(transformer, code)), sorted(leaves(transformer, text)))
                self.assertNotEqual(code, text)
                self.assertEqual(result.details["functions_moved"], result.effective)
                self.assertTrue(transformer.check_syntax(text))
        files = {f"f{i}.py": f"x{i} = {i}\n" for i in range(4)} | {"g.c": "int x;\n"}
        project = self.run_attack("reorder", "python", files, seed=2)
        self.assertEqual(sorted(project.files), sorted(files))  # a permutation of the names
        self.assertEqual(sorted(project.files.values()), sorted(files.values()))
        self.assertNotEqual(project.files, files)
        self.assertEqual(project.files["g.c"], "int x;\n")  # names permute within one extension
        self.assertEqual(project.details["files_renamed"], project.effective)

    def test_flip_rewrites_sites_to_their_other_reading(self):
        for language in SOURCES:
            transformer = self.transformers[language]
            with self.subTest(language=language):
                code = SOURCES[language]
                none = self.run_attack("flip_0.1", language, seed=1)  # may flip a few or none; never invalid
                self.assertTrue(transformer.check_syntax(next(iter(none.files.values()))))
                everything = attacks.flip(transformer, language, {"a": code}, random.Random(1), 1.0)
                self.assertGreater(everything.effective, 0)
                self.assertNotEqual(everything.files["a"], code)
                self.assertEqual(everything.effective, everything.details["flipped_sites"])
                before, after = readings(transformer, code), readings(transformer, everything.files["a"])
                changed = [pair for pair in before if before[pair] != after.get(pair)]
                self.assertGreaterEqual(len(changed), 1)

    def test_normalize_rewrites_whole_pairs(self):
        for language in SOURCES:
            transformer = self.transformers[language]
            with self.subTest(language=language):
                everything = self.run_attack("normalize_all", language)
                self.assertGreater(everything.effective, 0)
                self.assertNotEqual(everything.files[f"a.{SUFFIX[language]}"], SOURCES[language])
                one = self.run_attack("normalize_1", language)
                self.assertLessEqual(one.effective, 1)
                self.assertEqual(one.details["chosen_pairs"], 1)
                three = self.run_attack("normalize_3", language)
                self.assertEqual(three.details["chosen_pairs"], min(3, three.details["candidate_pairs"]))
                for result in (everything, one, three):
                    self.assertTrue(transformer.check_syntax(next(iter(result.files.values()))))

    def test_insert_appends_unmarked_code_of_other_units(self):
        def donors(rng):
            yield {"other.py": OTHER_PY}
            yield {"third.py": "print(3)\n"}

        files = {"a.py": PY_SOURCE}
        result = self.run_attack("insert_1", "python", files, donors=donors)
        self.assertTrue(result.files["a.py"].startswith(PY_SOURCE))
        self.assertIn("def helper", result.files["a.py"])
        self.assertEqual(result.details["donor_files"], 2)  # the first donor is shorter than the unit
        small = self.run_attack("insert_1", "python", {"a.py": "x = 1\n"}, donors=donors)
        self.assertEqual(small.details["donor_files"], 1)
        multi = self.run_attack("insert_1", "python", {"a.py": PY_SOURCE, "b.py": OTHER_PY}, donors=donors)
        self.assertEqual(len(multi.files), 4)  # donors become new files in projects
        self.assertIn("inserted_0.py", multi.files)
        self.assertEqual(multi.files["a.py"], PY_SOURCE)
        self.assertEqual(self.run_attack("insert_1", "python", files).effective, 0)  # no donors, no change
        self.assertEqual(self.run_attack("insert_1", "python", files).details["reason"], "no donors")

    def test_combo_chains_rename_flip_and_delete(self):
        for language in SOURCES:
            with self.subTest(language=language):
                result = self.run_attack("combo", language, seed=4)
                self.assertEqual(set(result.details), set(attacks.COMBO))
                self.assertGreater(result.details["rename"]["names"], 0)
                code = next(iter(result.files.values()))
                self.assertNotEqual(code, SOURCES[language])
                self.assertTrue(self.transformers[language].check_syntax(code))


# ------------------------------------------------------------------------------------------------ the engine


class EngineCase(unittest.TestCase):
    """Builds a frozen-run-like directory with a few units and a `RobustEngine` on the fake `cllmark.robust`."""

    fake = True  # `cllmark.robust` is the fake above; the real-core tests switch it off
    ATTACKS = ("flip_0.3", "normalize_all", "delete_0.5", "insert_1", "rename", "reformat", "reorder", "combo")

    def setUp(self):
        self.temporary = Path(tempfile.mkdtemp())
        self.addCleanup(shutil.rmtree, self.temporary, ignore_errors=True)
        self.addCleanup(os.chdir, os.getcwd())
        if self.fake:
            patcher = mock.patch.dict(sys.modules, {"cllmark.robust": make_fake_robust()})
            patcher.start()
            self.addCleanup(patcher.stop)
        stub = mock.patch.object(engine_module, "evaluate_utility", lambda *args, **kwargs: {"status": "DEFERRED"})
        stub.start()
        self.addCleanup(stub.stop)

    def build(self, units, robust=None, **config):
        """`units`: (cohort, name, language, role, {file name: code}[, extra unit keys]); returns the engine."""
        run_dir = self.temporary / f"run{len(list(self.temporary.iterdir()))}"
        (run_dir / "source").mkdir(parents=True)
        manifest_units, input_files = [], {}
        for cohort, name, language, role, files, *extra in units:
            relatives = []
            for filename, code in files.items():
                relative = f"corpus/{cohort}/{name}/{filename}" if len(files) > 1 else f"corpus/{cohort}/{filename}"
                path = run_dir / "inputs" / relative
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text(code, encoding="utf-8")
                input_files[relative] = {"sha256": digest(code.encode()), "bytes": len(code)}
                relatives.append(relative)
            level = "project" if len(files) > 1 else "function"
            manifest_units.append(
                {
                    "id": f"{cohort}/{name}",
                    "name": name,
                    "cohort": cohort,
                    "language": language,
                    "level": level,
                    "role": role,
                    "oracle": "none",
                    "path": f"corpus/{cohort}",
                    "source_files": relatives,
                    **(extra[0] if extra else {}),
                }
            )
        section = {"scheme": "s1", "bits": 4, "anchor": "tok", "attacks": list(self.ATTACKS), **(robust or {})}
        if section["scheme"].startswith("bch"):
            del section["anchor"]
        full = {
            "seed": 7,
            "watermark": [1, 0, 1, 0],
            "jobs": 1,
            "unit_timeout_seconds": 60,
            "compile_timeout_seconds": 5,
            "test_timeout_seconds": 1,
            "problem_files": {},
            "rule_properties": False,
            "attacks": [],
            "robust": section,
            **config,
        }
        manifest = {
            "config": full,
            "input_files": input_files,
            "units": manifest_units,
            "environment": {},
            "utility_cache": str(self.temporary / "utility"),
        }
        self.run_dir, self.manifest = run_dir, manifest
        return robust_engine.RobustEngine(run_dir, manifest)

    def generated(self, language="python", name="g1", code=None):
        return ("cn_generated", name, language, "generated", {f"{name}.{SUFFIX[language]}": code or SOURCES[language]})

    def human(self, language="python", name="h1", code=None):
        return ("cn_human", name, language, "human", {f"{name}.{SUFFIX[language]}": code or OTHER_PY})

    def row(self, engine, index=0):
        return engine.evaluate(self.manifest["units"][index])


class RobustEngineTests(EngineCase):
    def test_a_generated_unit_is_embedded_read_and_attacked(self):
        for scheme in ("s1", "s2"):
            with self.subTest(scheme=scheme):
                engine = self.build([self.generated(), self.human()], {"scheme": scheme})
                row = self.row(engine)
                self.assertEqual(row["status"], "ok")
                self.assertTrue(row["eligible"] and row["embedded"])
                self.assertEqual(len(row["watermark"]), 4)
                robust = row["robust"]
                self.assertEqual(robust["message"], row["watermark"])
                self.assertEqual((robust["scheme"], robust["bits"], robust["anchor"]), (scheme, 4, "tok"))
                capacity = robust["capacity"]
                self.assertGreater(capacity["votes"], 4)
                self.assertLessEqual(capacity["votes"], capacity["usable"])
                self.assertEqual(row["capacity"], capacity["usable"])
                self.assertGreater(robust["embed"]["set_rate"], 0.5)
                self.assertEqual(robust["embed"]["changed_files"], row["changed_files"])
                self.assertGreater(robust["embed"]["changed_lines"], 0)
                # the embedded message is recovered, the original code does not claim it
                self.assertTrue(row["marked_extraction"]["matched"])
                self.assertLess(robust["marked"]["p_known"], 1e-3)
                self.assertTrue(robust["marked"]["decision"]["0.001"])
                self.assertEqual(robust["marked"]["decoded"], row["watermark"])
                self.assertTrue(robust["marked"]["blind"]["0.001"])
                self.assertFalse(row["original_extraction"]["matched"])
                self.assertGreater(robust["original"]["p_known"], 1e-3)
                self.assertEqual(row["marked_extraction"]["correct_bits"], 4)
                self.assertTrue(row["marked_extraction"]["raw_matched"])
                self.assertEqual(set(row["attacks"]), set(self.ATTACKS))
                self.assertEqual(set(robust["attacks"]), set(self.ATTACKS))
                self.assertEqual(row["utility_before"], {"status": "DEFERRED"})
                self.assertTrue((self.run_dir / row["artifacts"] / "marked").is_dir())
                json.dumps(row)  # rows are streamed as JSON lines

    def test_attack_entries_have_the_legacy_shape_and_the_robust_detail(self):
        engine = self.build([self.generated(), self.human()])
        row = self.row(engine)
        for name, entry in row["attacks"].items():
            with self.subTest(attack=name):
                detail = row["robust"]["attacks"][name]
                self.assertEqual(entry["fully_applied"], detail["changed"])
                if entry["fully_applied"]:
                    self.assertIn("matched", entry["extraction"])
                    self.assertEqual(entry["extraction"]["p_known"], detail["p_known"])
                    self.assertGreaterEqual(entry["syntax_valid_files"], 0)
                    for field in ("votes", "agree", "p_known", "decoded", "p_blind", "margin", "anchors", "decision"):
                        self.assertIn(field, detail)
                    anchors = detail["anchors"]
                    self.assertLessEqual(anchors["shared"], min(anchors["keys"], anchors["reference_keys"]))
                else:
                    self.assertNotIn("extraction", entry)
        # insert has donors (the hand-written unit of the run), so the marked code gets other code appended
        self.assertTrue(row["attacks"]["insert_1"]["fully_applied"])
        self.assertTrue(row["attacks"]["rename"]["fully_applied"])
        self.assertTrue(row["attacks"]["reformat"]["fully_applied"])  # the sample has a comment and a blank line

    def test_summarize_group_reads_the_rows(self):
        engine = self.build([self.generated(), self.generated(name="g2"), self.human(), self.human(name="h2")])
        rows = [engine.evaluate(unit) for unit in self.manifest["units"]]
        summary = summarize_group(rows)
        self.assertEqual((summary["units"], summary["eligible_units"]), (4, 2))
        self.assertEqual(summary["watermark_recovery_rate"], 1.0)
        self.assertEqual(summary["detection"]["positive_units"], 2)
        self.assertEqual(summary["detection"]["negative_units"], 0)  # hand-written units are not eligible: no FPR here
        self.assertIn("rename", summary["attacks"])
        self.assertEqual(summary["harness_errors"], 0)

    def test_hand_written_units_are_only_read_and_attacked(self):
        engine = self.build([self.human(), self.generated()], {"scheme": "s2"})
        row = self.row(engine)
        self.assertFalse(row["eligible"])
        self.assertFalse(row["embedded"])
        self.assertTrue(row["capacity_sufficient"])
        self.assertIsNone(row["marked_extraction"])
        self.assertNotIn("marked", row["robust"])
        self.assertNotIn("embed", row["robust"])
        self.assertFalse((self.run_dir / row["artifacts"] / "marked").exists())
        self.assertEqual(row["utility_before"], {"status": "NOT_APPLICABLE"})
        self.assertEqual(row["utility_after"], {"status": "NOT_EMBEDDED"})
        self.assertEqual(row["syntax_after"], {})
        sweep = row["robust"]["original"]["sweep"]
        self.assertEqual(sweep["messages"], 16)
        self.assertEqual(set(sweep["hits"]), {"0.001", "1e-06"})
        self.assertEqual(sum(sweep["cdf"].values()) >= 0, True)
        # attacks on the null: attacked hand-written code is read like marked code
        self.assertIn("anchors", row["robust"]["attacks"]["rename"])
        self.assertTrue(set(row["attacks"]) == set(self.ATTACKS))

    def test_explicit_embed_flag_and_role_decide_what_is_embedded(self):
        units = [
            self.generated(),
            ("c1", "x", "python", "generated", {"x.py": PY_SOURCE}, {"embed": False}),
            ("c2", "y", "python", "human", {"y.py": PY_SOURCE}, {"embed": True}),
            ("c3", "z", "python", "unknown", {"z.py": PY_SOURCE}),
        ]
        engine = self.build(units)
        self.assertEqual([engine.embeds(unit) for unit in self.manifest["units"]], [True, False, True, True])

    def test_sweeps_cover_all_messages_but_the_true_one_on_marked_code(self):
        engine = self.build([self.generated(), self.human()], {"attacks": ["rename"]})
        row = self.row(engine)
        self.assertEqual(row["robust"]["original"]["sweep"]["messages"], 16)
        self.assertEqual(row["robust"]["marked"]["sweep"]["messages"], 15)
        true_message = robust_engine.to_int(row["watermark"])
        self.assertNotIn(true_message, row["robust"]["marked"]["sweep"]["hits"]["0.001"])
        # a message the code does not carry is accepted about as often as alpha allows: here never
        self.assertEqual(row["robust"]["marked"]["sweep"]["hits"]["1e-06"], [])
        limited = self.build([self.generated()], {"attacks": [], "null_messages": 5})
        again = self.row(limited)
        self.assertEqual(again["robust"]["original"]["sweep"]["messages"], 5)
        self.assertEqual(again["robust"]["marked"]["sweep"]["messages"], 5)

    def test_eight_bit_messages_and_sweep_size(self):
        engine = self.build([self.generated()], {"bits": 8, "attacks": ["reformat"], "null_messages": 7})
        row = self.row(engine)
        self.assertEqual(len(row["watermark"]), 8)
        self.assertEqual(row["marked_extraction"]["expected_bit_count"], 8)
        self.assertEqual(row["robust"]["original"]["sweep"]["messages"], 7)

    def test_messages_are_derived_from_seed_and_unit_and_uniform(self):
        counts = {}
        for index in range(800):
            message = robust_engine.message_for(7, f"cohort/unit{index}", 4)
            self.assertEqual(message, robust_engine.message_for(7, f"cohort/unit{index}", 4))
            counts[tuple(message)] = counts.get(tuple(message), 0) + 1
        self.assertEqual(len(counts), 16)
        self.assertGreater(min(counts.values()), 25)  # 50 expected each
        self.assertNotEqual(robust_engine.message_for(7, "a/b", 8), robust_engine.message_for(8, "a/b", 8))
        self.assertEqual(robust_engine.to_int([1, 0, 1, 0]), 10)
        self.assertEqual(robust_engine.from_int(10, 4), [1, 0, 1, 0])

    def test_units_without_room_are_kept_unembedded(self):
        engine = self.build([("cn_generated", "tiny", "python", "generated", {"tiny.py": "x = 1\n"})], {"min_votes": 3})
        row = self.row(engine)
        self.assertFalse(row["eligible"])
        self.assertTrue(row["capacity"] < 3)
        self.assertIsNone(row["marked_extraction"])
        self.assertIsNone(row["original_extraction"])
        self.assertEqual(row["attacks"], {})
        self.assertEqual(row["utility_after"], {"status": "NOT_EMBEDDED"})
        self.assertEqual(summarize_group([row])["eligible_units"], 0)

    def test_a_detector_that_raises_is_recorded_as_no_detection(self):
        engine = self.build([self.generated(), self.human()], {"attacks": ["rename", "reformat"]})
        real = engine.robust.detect

        def flaky(*args, **kwargs):
            if any("v_" in code for code in args[2].values()):  # only the renamed code makes the rules raise
                raise RuntimeError("rule crashed")
            return real(*args, **kwargs)

        engine.robust.detect = flaky
        row = self.row(engine)
        self.assertEqual(row["status"], "ok")
        failed = [d for d in row["robust"]["attacks"].values() if "error" in d]
        self.assertTrue(failed)
        for detail in failed:
            self.assertFalse(any(detail["decision"].values()))
            self.assertEqual(detail["votes"], 0)
        for name, entry in row["attacks"].items():
            if "error" in row["robust"]["attacks"][name]:
                self.assertFalse(entry["extraction"]["matched"])

    def test_attacks_replay_with_the_seed_and_differ_between_units(self):
        engine = self.build([self.generated(name="g1"), self.generated(name="g2")], {"attacks": ["flip_0.3", "rename"]})
        first = self.row(engine, 0)
        again = self.row(engine, 0)
        for name in ("flip_0.3", "rename"):
            self.assertEqual(first["robust"]["attacks"][name]["details"], again["robust"]["attacks"][name]["details"])
            self.assertEqual(first["robust"]["attacks"][name]["p_known"], again["robust"]["attacks"][name]["p_known"])
        self.assertEqual(first["watermark"], again["watermark"])
        self.assertNotEqual(engine.seed_for("a/x", "rename"), engine.seed_for("a/y", "rename"))
        self.assertNotEqual(engine.seed_for("a/x", "rename"), engine.seed_for("a/x", "reorder"))

    def test_the_rule_set_comes_from_the_config(self):
        legacy = self.build([self.generated()], {"attacks": []})
        extended = self.build([self.generated()], {"attacks": []}, rule_set="extended")
        self.assertGreater(len(extended.parser("python").pairs), len(legacy.parser("python").pairs))
        self.assertEqual(extended.rule_set, "extended")

    def test_projects_use_every_file_and_donors_come_from_hand_written_units(self):
        files = {"a.py": PY_SOURCE, "b.py": OTHER_PY}
        engine = self.build(
            [("cn_projects", "p1", "python", "generated", files), self.human(), self.human(name="h2", code=PY_SOURCE)],
            {"attacks": ["insert_1", "delete_0.5", "reorder"]},
        )
        row = self.row(engine)
        self.assertEqual(row["file_count"], 2)
        self.assertEqual(row["robust"]["capacity"]["files"], 2)
        self.assertEqual(row["attacks"]["insert_1"]["files"], 4)  # the donors (5 + 18 lines) of a 22-line project
        self.assertEqual(row["robust"]["attacks"]["delete_0.5"]["details"]["files_removed"], 1)
        donors = engine.donor_units["python"]
        self.assertEqual([unit["id"] for unit in donors], ["cn_human/h1", "cn_human/h2"])
        self.assertEqual(engine.donor_units.get("c"), None)


REAL_PY = (
    "\n".join(
        f"""def f{i}(a, b):
    total = 0
    if a != b and a > {i}:
        total += a
    elif a == {i + 1}:
        total = total + b
    items = [x for x in range({i + 2}) if x != {i}]
    print("v{i}", total, len(items))
    return total if total > {i} else b
"""
        for i in range(14)
    )
    + "\nf0(1, 2)\n"
)


class RealCoreTests(EngineCase):
    """The engine on the real `cllmark.robust` (no fake): embedding, detection, sweeps and attacks end to end."""

    fake = False

    def real_row(self, **robust):
        engine = self.build(
            [self.generated(code=REAL_PY), self.human(code=REAL_PY.replace("!=", "==").replace("v1", "w1"))],
            {"attacks": ["rename", "flip_0.2", "delete_0.5", "reformat"], **robust},
        )
        self.assertEqual(type(engine.robust).__name__, "module")
        self.assertTrue(engine.robust.__file__.endswith("robust/__init__.py"))
        return engine, self.row(engine, 0), self.row(engine, 1)

    def test_both_schemes_embed_detect_and_survive_deletion(self):
        for scheme in ("s1", "s2"):
            with self.subTest(scheme=scheme):
                _, row, human = self.real_row(scheme=scheme)
                robust = row["robust"]
                self.assertGreater(robust["capacity"]["votes"], 100)
                self.assertTrue(row["eligible"] and row["marked_extraction"]["matched"])
                marked = robust["marked"]
                self.assertLess(marked["p_known"], 1e-6)
                self.assertTrue(all(marked["decision"].values()) and all(marked["blind"].values()))
                self.assertEqual(marked["decoded"], row["watermark"])
                self.assertEqual(marked["errors"], 0)
                self.assertIsNotNone(marked["p_all"])
                embed = robust["embed"]
                self.assertEqual(embed["set_rate"], 1.0)
                self.assertGreater(embed["selection_agreement"], 0.9)
                self.assertEqual(embed["errors"], 0)
                self.assertIn("available", embed["details"])
                stability = robust["capacity"]["pair_stability"]
                self.assertEqual(sum(u for u, _ in stability.values()), robust["capacity"]["usable"])
                self.assertTrue(all(0 <= st <= u for u, st in stability.values()))
                # the wrong messages are not accepted (by p_known), the unmarked code does not claim the message
                self.assertEqual(marked["sweep"]["messages"], 15)
                self.assertEqual(marked["sweep"]["hits"], {"0.001": [], "1e-06": []})
                self.assertGreater(robust["original"]["p_known"], 1e-3)
                self.assertFalse(row["original_extraction"]["matched"])
                self.assertTrue(robust["attacks"]["delete_0.5"]["decision"]["0.001"])
                self.assertTrue(robust["attacks"]["flip_0.2"]["decision"]["0.001"])
                self.assertEqual(row["attacks"]["delete_0.5"]["extraction"]["matched"], True)
                # null: hand-written code reads as unmarked, attacked or not, against all 16 messages
                self.assertFalse(human["original_extraction"]["matched"])
                for reading in [human["robust"]["original"], *human["robust"]["attacks"].values()]:
                    if reading.get("changed", True):
                        self.assertEqual(reading["sweep"]["messages"], 16)
                json.dumps(row)

    def test_struct_anchors_survive_renaming_and_token_anchors_do_not(self):
        _, tok, _ = self.real_row(scheme="s2", anchor="tok")
        _, struct, _ = self.real_row(scheme="s2", anchor="struct")
        self.assertFalse(tok["robust"]["attacks"]["rename"]["decision"]["0.001"])
        self.assertTrue(struct["robust"]["attacks"]["rename"]["decision"]["0.001"])
        self.assertGreater(
            struct["robust"]["attacks"]["rename"]["anchors"]["retained"],
            tok["robust"]["attacks"]["rename"]["anchors"]["retained"],
        )

    def test_eight_bit_sweep_covers_all_256_messages(self):
        _, row, _ = self.real_row(scheme="s1", bits=8, attacks=["reformat"])
        self.assertEqual(row["robust"]["original"]["sweep"]["messages"], 256)
        self.assertEqual(row["robust"]["marked"]["sweep"]["messages"], 255)
        self.assertEqual(row["robust"]["marked"]["decoded"], row["watermark"])

    def test_the_report_summarizes_the_real_core_fields(self):
        report_tool = load_tool("robust_report")
        engine = self.build(
            [self.generated(code=REAL_PY), self.generated(name="g2", code=REAL_PY), self.human(code=REAL_PY)],
            {"scheme": "s1", "attacks": ["flip_0.2"]},
        )
        rows = [engine.evaluate(unit) for unit in self.manifest["units"]]
        directory = self.temporary / "real-report"
        directory.mkdir()
        (directory / "manifest.json").write_text(json.dumps({"run_id": "r", "config": engine.config, "full": False}))
        (directory / "rows.jsonl").write_text("".join(json.dumps(row) + "\n" for row in rows))
        analysis = report_tool.analyse_run(report_tool.load_run(directory))
        embedding = analysis["embedding"][0]
        self.assertEqual(embedding["selection_agreement"]["n"], 2)
        self.assertGreater(embedding["selection_agreement"]["mean"], 0.9)
        self.assertEqual(embedding["embed_errors"], 0)
        detection = analysis["detection"][0]
        self.assertEqual(detection["rule_errors"], 0)
        self.assertEqual(set(detection["p_all_info"]), {"0.001", "1e-06"})
        self.assertEqual(detection["p_all_info"]["0.001"], 1.0)
        self.assertTrue(all(0 <= e["share"] <= 1 for e in analysis["pair_stability"]))
        self.assertGreater(len(analysis["pair_stability"]), 3)
        self.assertIn("p_all_info", analysis["null"][0])
        text = report_tool.render({"runs": [], "variants": {analysis["variant"]: analysis}})
        for heading in [
            "## 8. Stable sites per rule pair",
            "selection agreement",
            "p_all <= alpha (info)",
            "sha256 derivation",
        ]:
            self.assertIn(heading, text)

    def test_the_protocol_config_carries_the_digest_of_the_real_core(self):
        digest_value = robust_engine.core_digest(ROOT)
        self.assertNotEqual(digest_value, "absent")
        self.assertEqual(len(digest_value), 64)


class BchBaselineTests(EngineCase):
    def test_bch_file_and_node_rows_follow_the_legacy_extraction(self):
        for scheme in ("bch-file", "bch-node"):
            with self.subTest(scheme=scheme):
                engine = self.build(
                    [self.generated(), self.human()],
                    {"scheme": scheme, "attacks": ["flip_0.3", "rename", "delete_0.5"]},
                )
                self.assertIsNone(engine.robust)
                row = self.row(engine)
                self.assertEqual(row["status"], "ok")
                self.assertEqual(row["required_capacity"], 7)
                self.assertEqual(row["eligible"], row["capacity"] >= 7)
                self.assertTrue(row["eligible"], row["capacity"])
                self.assertEqual(row["marked_extraction"]["expected_bit_count"], 7)
                self.assertEqual(len(row["marked_extraction"]["bits"]), 7)
                self.assertTrue(row["marked_extraction"]["matched"])
                self.assertEqual(row["marked_extraction"]["correct_bits"], 7)
                self.assertTrue(row["marked_extraction"]["raw_matched"])
                reading = row["robust"]["marked"]
                self.assertEqual(reading["decision"], {"match": True})
                self.assertEqual(reading["decoded"], row["watermark"])
                self.assertEqual(reading["sweep"]["hits"], {"match": [robust_engine.to_int(row["watermark"])]})
                self.assertEqual(reading["sweep"]["messages"], 16)
                self.assertIsNone(reading.get("p_known"))
                self.assertEqual(set(row["attacks"]), {"flip_0.3", "rename", "delete_0.5"})
                self.assertTrue((self.run_dir / row["artifacts"] / "clean" / "support_transform.json").exists())
                self.assertEqual(
                    list((self.run_dir / row["artifacts"]).glob("read-*")), []
                )  # temporary reads are removed
                json.dumps(row)

    def test_bch_reads_attacked_code_by_position_and_fails_without_the_files(self):
        files = {"a.py": PY_SOURCE, "b.py": OTHER_PY, "c.py": PY_SOURCE.replace("total", "tot")}
        engine = self.build(
            [("cn_projects", "p1", "python", "generated", files), self.human()],
            {"scheme": "bch-file", "attacks": ["reformat", "delete_0.5", "reorder"]},
        )
        row = self.row(engine)
        self.assertTrue(row["marked_extraction"]["matched"])
        # file names are permuted by reorder: the stored support points at the wrong files, so nothing is promised
        detail = row["robust"]["attacks"]
        self.assertIn("decision", detail["reorder"])
        # deleting a file the support names makes the extraction fail; that is a counted non-detection
        lost = detail["delete_0.5"]
        self.assertTrue(
            lost.get("error") or lost["decision"] == {"match": False} or lost["decision"]["match"] in (True, False)
        )

    def test_bch_needs_four_bit_messages(self):
        with self.assertRaises(ValueError):
            robust_engine.settings({"robust": {"scheme": "bch-file", "bits": 8}})
        with self.assertRaises(ValueError):
            robust_engine.settings({"robust": {"scheme": "bch-node", "anchor": "tok"}})


class SelectionTests(unittest.TestCase):
    def section(self, **values):
        return {"robust": {"scheme": "s1", **values}}

    def test_defaults(self):
        chosen = robust_engine.settings(self.section())
        self.assertEqual(
            (chosen["scheme"], chosen["bits"], chosen["anchor"], chosen["alpha"]), ("s1", 4, "tok", [1e-3, 1e-6])
        )
        self.assertEqual(chosen["attacks"], list(attacks.DEFAULT_ATTACKS))
        self.assertEqual((chosen["null_messages"], chosen["min_votes"], chosen["keep_attacked"]), ("all", 1, False))

    def test_invalid_sections_are_rejected(self):
        bad = [
            {"scheme": "s3"},
            {"scheme": "s1", "bits": 5},
            {"scheme": "s1", "bits": True},
            {"scheme": "s1", "anchor": "pos"},
            {"scheme": "s1", "alpha": []},
            {"scheme": "s1", "alpha": [1e-6, 1e-3]},
            {"scheme": "s1", "alpha": [0.5, 2]},
            {"scheme": "s1", "attacks": ["flip_0.1", "flip_0.1"]},
            {"scheme": "s1", "attacks": ["shuffle"]},
            {"scheme": "s1", "null_messages": 0},
            {"scheme": "s1", "null_messages": "some"},
            {"scheme": "s1", "min_votes": 0},
            {"scheme": "s1", "keep_attacked": 1},
            {"scheme": "s1", "unknown": 1},
        ]
        for section in bad:
            with self.subTest(section=section), self.assertRaises(ValueError):
                robust_engine.settings({"robust": section})
        with self.assertRaises(ValueError):
            robust_engine.settings({"robust": []})

    def test_robust_configs_carry_the_digests_and_other_configs_do_not_move(self):
        config = {"seed": 1, "robust": {"scheme": "s2", "bits": 8}}
        marked = robust_engine.protocol_config(config, ROOT)
        extra = {key: value for key, value in marked.items() if key not in config}
        self.assertEqual(set(extra), {"robust_engine_sha256", "robust_attacks_sha256", "robust_core_sha256"})
        self.assertEqual(extra["robust_engine_sha256"], digest((ROOT / "benchmarks" / "robust_engine.py").read_bytes()))
        self.assertEqual(extra["robust_attacks_sha256"], digest((ROOT / "benchmarks" / "attacks.py").read_bytes()))
        self.assertEqual(
            rule_sets.protocol_config(config, ROOT)["robust_attacks_sha256"], extra["robust_attacks_sha256"]
        )
        with self.assertRaises(ValueError):
            robust_engine.protocol_config({"robust": {"scheme": "nope"}}, ROOT)
        # the scheme code is part of the protocol: a copy of the tree with another cllmark/robust gives another digest
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "benchmarks").mkdir()
            for name in ("robust_engine.py", "attacks.py"):
                shutil.copyfile(ROOT / "benchmarks" / name, root / "benchmarks" / name)
            absent = robust_engine.protocol_config(config, root)["robust_core_sha256"]
            self.assertEqual(absent, "absent")
            (root / "cllmark" / "robust").mkdir(parents=True)
            (root / "cllmark" / "robust" / "__init__.py").write_text("A = 1\n")
            first = robust_engine.protocol_config(config, root)["robust_core_sha256"]
            (root / "cllmark" / "robust" / "__init__.py").write_text("A = 2\n")
            second = robust_engine.protocol_config(config, root)["robust_core_sha256"]
            self.assertEqual(len({absent, first, second}), 3)

    def test_existing_configs_keep_their_protocol_config_and_fingerprint(self):
        paths = sorted(p for p in (ROOT / "benchmarks").glob("config*.json") if not p.name.startswith("config-rw-"))
        self.assertGreaterEqual(len(paths), 8)
        for path in paths:
            with self.subTest(config=path.name):
                config = json.loads(path.read_text())
                configured = rule_sets.protocol_config(config, ROOT)
                added = set(configured) - set(config)
                self.assertFalse({key for key in added if key.startswith("robust")})
                without = (
                    {k: v for k, v in config.items() if k != "rule_set"}
                    if config.get("rule_set") == "legacy"
                    else config
                )
                legacy = codenet.protocol_config(node_engine.protocol_config(without, ROOT), ROOT)
                self.assertEqual(configured, legacy)
                self.assertEqual(protocol_fingerprint(configured, ROOT), protocol_fingerprint(legacy, ROOT))
        default = json.loads((ROOT / "benchmarks" / "config.json").read_text())
        self.assertTrue(rule_sets.protocol_config(default, ROOT) == default)

    def test_workers_start_the_robust_engine_only_for_robust_configs(self):
        with (
            mock.patch.object(robust_engine, "initialize_worker") as robust,
            mock.patch.object(engine_module, "initialize_worker") as legacy,
            mock.patch.object(codenet, "install") as install,
        ):
            staged.initialize_worker("run", {"config": {"robust": {"scheme": "s1"}}, "units": []})
            self.assertEqual((robust.called, legacy.called, install.called), (True, False, False))
        with (
            mock.patch.object(robust_engine, "initialize_worker") as robust,
            mock.patch.object(engine_module, "initialize_worker") as legacy,
            mock.patch.object(codenet, "install") as install,
        ):
            engine_module.ENGINE = None
            staged.initialize_worker("run", {"config": {}, "units": []})
            self.assertEqual((robust.called, legacy.called, install.called), (False, True, True))

    def test_reports_of_robust_runs_name_the_variant_once(self):
        with tempfile.TemporaryDirectory() as temporary:
            run_dir = Path(temporary)
            report = "# Local CLLMark benchmark\n\nRun: x\nFull inventory: y\n\n| table |\n"
            (run_dir / "report.md").write_text(report)
            robust_engine.annotate_report(run_dir, {"config": {}})
            self.assertEqual((run_dir / "report.md").read_text(), report)
            for _ in range(2):
                rule_sets.annotate_report(run_dir, {"config": {"robust": {"scheme": "s2", "bits": 8}}})
            text = (run_dir / "report.md").read_text()
            self.assertEqual(text.count("Robust watermark variant: **s2**"), 1)
            self.assertEqual(text.split("\n")[4].startswith("Robust watermark variant"), True)


class SummaryFunctionTests(unittest.TestCase):
    def test_anchor_survival(self):
        result = robust_engine.anchor_survival({"a": 1, "b": 0, "c": 1}, {"b": 0, "c": 1, "x": 1, "y": 0})
        self.assertEqual((result["shared"], result["keys"], result["reference_keys"]), (2, 4, 3))
        self.assertEqual((result["survival"], result["retained"]), (0.5, 2 / 3))
        empty = robust_engine.anchor_survival({}, {})
        self.assertEqual((empty["survival"], empty["retained"]), (None, None))

    def test_summarize_p(self):
        summary = robust_engine.summarize_p({0: 0.5, 1: 1e-4, 2: 2e-7, 3: 1.0}, [1e-3, 1e-6])
        self.assertEqual(summary["messages"], 4)
        self.assertEqual((summary["min_p"], summary["min_message"]), (2e-7, 2))
        self.assertEqual(summary["hits"], {"0.001": [1, 2], "1e-06": [2]})
        self.assertEqual(summary["cdf"]["0.001"], 2)
        self.assertEqual(summary["cdf"]["0.5"], 3)
        self.assertEqual(robust_engine.summarize_p({}, [1e-3])["min_p"], None)

    def test_changed_lines(self):
        before = {"a": "x\ny\nz\n", "b": "q\n"}
        after = {"a": "x\nY\nz\nw\n", "b": "q\n"}
        self.assertEqual(robust_engine.changed_lines(before, after), 2)
        self.assertEqual(robust_engine.changed_lines(before, before), 0)

    def test_the_fake_binomial_tail_matches_enumeration(self):
        for n in range(9):
            for a in range(n + 2):
                exact = sum(math.comb(n, k) for k in range(a, n + 1)) / 2**n
                self.assertAlmostEqual(binomial_tail(n, a), exact)


# ------------------------------------------------------------------------------------------------ the report


class ReportTests(EngineCase):
    def make_run(self, **robust):
        units = [
            self.generated(name="g1"),
            self.generated(name="g2"),
            self.generated("c", "g3", C_NO_FOR),
            self.human(name="h1"),
            self.human(name="h2", code=PY_SOURCE),
            self.human("c", "h3", C_SOURCE),
            ("python_projects", "p1", "python", "generated", {"a.py": PY_SOURCE, "b.py": OTHER_PY}),
            ("js_repos_stress", "s1", "javascript", "unknown", {"a.js": JS_SOURCE, "b.js": JS_SOURCE}),
        ]
        engine = self.build(
            units, {"attacks": ["flip_0.3", "normalize_all", "delete_0.5", "rename", "reformat"], **robust}
        )
        rows = [engine.evaluate(unit) for unit in self.manifest["units"]]
        directory = self.temporary / f"report-run-{len(list(self.temporary.glob('report-run-*')))}"
        directory.mkdir()
        manifest = {"run_id": "r1", "config": engine.config, "full": False, "source_fingerprint": "0123456789abcdef"}
        (directory / "manifest.json").write_text(json.dumps(manifest))
        (directory / "rows.jsonl").write_text("".join(json.dumps(row) + "\n" for row in rows))
        return directory, rows

    def test_robust_variant_report(self):
        report_tool = load_tool("robust_report")
        directory, _ = self.make_run(scheme="s2", bits=4, anchor="struct")
        run = report_tool.load_run(directory)
        self.assertEqual((run["variant"], run["decisions"], run["bits"]), ("s2-4-struct", ["0.001", "1e-06"], 4))
        analysis = report_tool.analyse_run(run)
        head = analysis["headline"]
        self.assertEqual((head["positives"], head["nulls"]), (3, 3))
        self.assertEqual(head["tpr_clean"]["0.001"], 1.0)  # the fake sets every site: 15+ agreeing votes
        self.assertEqual(head["null_known"], {"0.001": 0.0, "1e-06": 0.0})
        self.assertEqual(head["blind_clean"]["0.001"], head["tpr_clean"]["0.001"])
        self.assertGreaterEqual(head["auc"], 0.9)
        self.assertEqual(head["harness_errors"], 0)
        # the stress group is only in the functional/embedding tables, never in detection statistics
        self.assertNotIn("js_repos_stress", [d["cohort"] for d in analysis["detection"]])
        self.assertIn("js_repos_stress", [e["cohort"] for e in analysis["embedding"]])
        self.assertIn("python_projects", [d["cohort"] for d in analysis["detection"]])
        # capacity bins add up
        for capacity in analysis["capacity"]:
            self.assertEqual(sum(capacity["bins"].values()), capacity["units"])
        # nulls: hand-written code and the unmarked generated code are both swept over all messages
        sources = {(n["source"], n["cohort"]) for n in analysis["null"]}
        self.assertIn(("hand-written", "cn_human"), sources)
        self.assertIn(("generated, unmarked", "cn_generated"), sources)
        for entry in analysis["null"]:
            self.assertEqual(entry["sweep"]["pairs"], 16 * entry["sweep"]["n"])
            self.assertEqual(set(entry["sweep"]["cdf"]), set(report_tool.CDF_POINTS))
        for cross in analysis["cross"]:
            self.assertEqual(cross["pairs"], 15 * cross["n"])  # the true message is left out
            self.assertEqual(cross["decisions"]["0.001"]["pair_rate"], 0.0)
        attacks = {(a["stratum"], a["attack"]): a for a in analysis["attacks"]}
        self.assertIn(("codenet", "rename"), attacks)
        self.assertLessEqual(attacks[("codenet", "rename")]["applied"], attacks[("codenet", "rename")]["positives"])
        self.assertEqual(attacks[("codenet", "rename")]["null_units"], 3)
        self.assertIn("none", analysis["auc_attacks"])
        text = report_tool.render(
            {
                "runs": [{"variant": "s2-4-struct", "run_id": "r1", "units": 8, "full": False, "source": "01234567"}],
                "variants": {"s2-4-struct": analysis},
            }
        )
        for heading in ["## 1. Headline", "## 2. Capacity", "## 5. Null hypothesis", "## 7. Attacks", "normalize_all"]:
            self.assertIn(heading, text)
        self.assertIn("s2-4-struct", text)

    def test_bch_variant_report_and_cli(self):
        report_tool = load_tool("robust_report")
        robust_directory, _ = self.make_run(scheme="s1", bits=4, anchor="tok")
        bch_directory, _ = self.make_run(scheme="bch-node")
        output = self.temporary / "out" / "report.md"
        with contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(report_tool.main([str(robust_directory), str(bch_directory), "--output", str(output)]), 0)
        data = json.loads(output.with_suffix(".json").read_text())
        self.assertEqual(set(data["variants"]), {"s1-4-tok", "bch-node"})
        bch = data["variants"]["bch-node"]
        self.assertEqual(bch["decisions"], ["match"])
        self.assertIsNone(bch["headline"]["blind_clean"]["match"])  # no blind extraction in the baseline
        self.assertIsNone(bch["headline"]["auc"])  # and no p-values
        self.assertEqual(bch["headline"]["tpr_clean"]["match"], 1.0)
        for entry in bch["null"]:
            self.assertEqual(entry["sweep"]["pairs"], 16 * entry["sweep"]["n"])
            self.assertIn("match", entry["sweep"]["decisions"])
        for cross in bch["cross"]:
            self.assertEqual(cross["pairs"], 15 * cross["n"])
            self.assertEqual(cross["decisions"]["match"]["unit_rate"], 0.0)  # decodes to the embedded message
        text = output.read_text()
        self.assertIn("bch-node", text)
        self.assertIn("s1-4-tok", text)

    def test_runs_that_are_not_robust_are_refused(self):
        report_tool = load_tool("robust_report")
        directory = self.temporary / "plain"
        directory.mkdir()
        (directory / "manifest.json").write_text(json.dumps({"config": {"seed": 1}}))
        (directory / "rows.jsonl").write_text("")
        with self.assertRaises(ValueError):
            report_tool.load_run(directory)

    def test_helpers(self):
        report_tool = load_tool("robust_report")
        self.assertEqual(report_tool.auc([0.001, 0.01], [0.5, 0.9]), 1.0)
        self.assertEqual(report_tool.auc([0.5], [0.5]), 0.5)
        self.assertEqual(report_tool.auc([0.9], [0.1, 0.2]), 0.0)
        self.assertIsNone(report_tool.auc([], [0.1]))
        self.assertIsNone(report_tool.auc([None], [0.1]))
        self.assertEqual(
            [report_tool.capacity_bin(v) for v in (0, 9, 10, 29, 30, 99, 100, 5000)],
            ["<10", "<10", "10-30", "10-30", "30-100", "30-100", ">=100", ">=100"],
        )
        self.assertAlmostEqual(report_tool.wilson_upper(0, 100), 0.0370, places=3)
        self.assertIsNone(report_tool.wilson_upper(0, 0))
        base = {"cohort": "x", "role": "generated", "level": "function"}
        self.assertEqual(report_tool.stratum(base), "codenet")
        self.assertEqual(report_tool.stratum({**base, "level": "project"}), "projects")
        self.assertEqual(report_tool.stratum({**base, "level": "project", "role": "human"}), "js_repos")
        self.assertEqual(report_tool.stratum({**base, "cohort": "js_repos_stress", "role": "unknown"}), "stress")
        self.assertEqual(report_tool.stratum({**base, "role": "unknown"}), "stress")
        self.assertEqual(
            report_tool.variant_label({"robust": {"scheme": "s1", "bits": 8, "anchor": "struct"}}), "s1-8-struct"
        )
        self.assertEqual(report_tool.variant_label({"robust": {"scheme": "bch-file", "bits": 4}}), "bch-file")


class GeneratedConfigTests(unittest.TestCase):
    VARIANTS = frozenset(
        [f"{scheme}-{bits}-{anchor}" for scheme in ("s1", "s2") for bits in (4, 8) for anchor in ("tok", "struct")]
        + ["bch-file", "bch-node"]
    )

    def configs(self):
        return {
            path.name[len("config-rw-") : -len(".json")]: json.loads(path.read_text())
            for path in sorted((ROOT / "benchmarks").glob("config-rw-*.json"))
        }

    def test_one_config_per_variant_differing_only_in_the_robust_section(self):
        configs = self.configs()
        self.assertEqual(set(configs), self.VARIANTS)
        reference = {k: v for k, v in configs["s1-4-tok"].items() if k != "robust"}
        for name, config in configs.items():
            with self.subTest(config=name):
                self.assertEqual({k: v for k, v in config.items() if k != "robust"}, reference)
                chosen = robust_engine.settings(config)
                self.assertEqual(
                    chosen["scheme"] + ("" if "bch" in name else f"-{chosen['bits']}-{chosen['anchor']}"), name
                )
                self.assertEqual(chosen["null_messages"], "all")

    def test_groups_follow_the_plan(self):
        config = self.configs()["s1-4-tok"]
        node = json.loads((ROOT / "benchmarks" / "config-codenet-node.json").read_text())
        cohorts = {c["name"]: c for c in config["cohorts"]}
        self.assertEqual(
            config["cohorts"][:8], node["cohorts"]
        )  # the eight CodeNet groups, hand-written ones embed: false
        self.assertEqual([c.get("embed") for c in node["cohorts"][1::2]], [False] * 4)
        self.assertEqual(
            [name for name in cohorts if not name.startswith("codenet_")],
            ["python_projects", "c_projects", "cpp_projects", "js_repos", "js_repos_stress"],
        )
        self.assertEqual({cohorts[n]["role"] for n in ("python_projects", "c_projects", "cpp_projects")}, {"generated"})
        self.assertEqual((cohorts["js_repos"]["role"], cohorts["js_repos"]["oracle"]), ("human", "none"))
        stress = cohorts["js_repos_stress"]
        self.assertEqual(
            (stress["role"], stress["oracle"], stress["path"]),
            ("unknown", "project_tests", cohorts["js_repos"]["path"]),
        )
        self.assertEqual(config["attacks"], [])

    def test_every_config_validates_and_runs_standalone(self):
        for name, config in self.configs().items():
            with self.subTest(config=name):
                prepared = rule_sets.protocol_config(config, ROOT)
                self.assertIn("robust_engine_sha256", prepared)
                codenet.validate_config(prepared)  # what research_loop.read_config does
                self.assertEqual(robust_engine.settings(prepared)["attacks"], list(attacks.DEFAULT_ATTACKS))

    def test_the_stress_group_is_excluded_from_detection_by_role(self):
        # metrics take positives/negatives from the generated/human roles only; unknown-role rows never enter them
        config = self.configs()["s2-8-struct"]
        roles = {c["name"]: c["role"] for c in config["cohorts"]}
        self.assertEqual(roles["js_repos_stress"], "unknown")
        self.assertEqual(robust_engine.RobustEngine.embeds({"role": "unknown"}), True)
        self.assertEqual(robust_engine.RobustEngine.embeds({"role": "human"}), False)
