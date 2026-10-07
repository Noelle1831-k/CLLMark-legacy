"""Robust watermark: anchor keys are position-free and stable, and unstable sites are flagged."""

import re
import unittest

from tests.robust_samples import HAS_GRAMMARS, LANGUAGES, join, project, split

C_DECLARE = '#include <stdio.h>\nint main(void)\n{\n    int a = 1; int b = 2; int c = a + b;\n    printf("%d\\n", c);\n    return 0;\n}\n'


def stable_keys(observations):
    return sorted(o.key for o in observations if o.stable)


@unittest.skipUnless(HAS_GRAMMARS, "pinned parser libraries are not built")
class AnchorTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        from cllmark.transform import StyleTransformer

        cls.transformers = {language: StyleTransformer(language) for language in LANGUAGES}

    def observe(self, language, code, anchor):
        from cllmark.robust import observe

        return observe(self.transformers[language], language, {"f": code}, anchor)

    def test_observation_fields(self):
        for language in LANGUAGES:
            observations = self.observe(language, project(language, 3), "tok")
            self.assertTrue(observations)
            for item in observations:
                self.assertEqual(item.file, "f")
                self.assertEqual(len(item.key), 32)
                int(item.key, 16)
                self.assertEqual(len(item.window), 2)
                if item.stable:
                    self.assertTrue(item.usable and item.reading is not None)

    def test_most_usable_sites_are_stable(self):
        for language in LANGUAGES:
            for anchor in ("tok", "struct"):
                observations = self.observe(language, project(language, 8), anchor)
                usable = [o for o in observations if o.usable]
                stable = [o for o in usable if o.stable]
                self.assertGreaterEqual(len(stable) / len(usable), 0.9, (language, anchor))

    def test_keys_ignore_position_and_layout(self):
        for language in LANGUAGES:
            header, functions = split(language, project(language, 6))
            base = {
                anchor: stable_keys(self.observe(language, join(header, functions), anchor))
                for anchor in ("tok", "struct")
            }
            reordered = join(header, functions[::-1])
            spaced = join(header, ["\n\n" + function.replace("\n", "\n\n") for function in functions])
            commented = join(
                header,
                [function.replace("\n", "\n// c\n" if language != "python" else "\n# c\n") for function in functions],
            )
            for anchor in ("tok", "struct"):
                for name, code in (("reordered", reordered), ("spaced", spaced), ("commented", commented)):
                    if language == "python" and name == "spaced":
                        continue  # blank lines are harmless in Python too, but the indented bodies keep their layout
                    self.assertEqual(
                        stable_keys(self.observe(language, code, anchor)), base[anchor], (language, anchor, name)
                    )

    def test_inserted_and_deleted_code_keep_the_other_keys(self):
        for language in LANGUAGES:
            header, functions = split(language, project(language, 6))
            full = set(stable_keys(self.observe(language, join(header, functions), "tok")))
            half = set(stable_keys(self.observe(language, join(header, functions[:3]), "tok")))
            self.assertTrue(half and half < full, language)
            extra = project(language, 2, start=50)
            more = set(stable_keys(self.observe(language, join(header, functions) + extra[len(header) :], "tok")))
            self.assertTrue(full <= more, language)

    def test_rename_changes_tok_keys_but_not_struct_keys(self):
        for language in LANGUAGES:
            code = project(language, 5)
            renamed = re.sub(r"\b([abxko])(\d)\b", r"v_\1_\2", code)
            self.assertNotEqual(code, renamed)
            self.assertEqual(
                stable_keys(self.observe(language, code, "struct")),
                stable_keys(self.observe(language, renamed, "struct")),
                language,
            )
            self.assertNotEqual(
                set(stable_keys(self.observe(language, code, "tok"))),
                set(stable_keys(self.observe(language, renamed, "tok"))),
                language,
            )

    def test_stable_keys_survive_rewriting_the_site_itself(self):
        from cllmark import nodes
        from cllmark.robust import observe

        for language in LANGUAGES:
            transformer = self.transformers[language]
            code = project(language, 4)
            for anchor in ("tok", "struct"):
                before = observe(transformer, language, {"f": code}, anchor)
                keys = {o.key for o in before if o.stable}
                checked = 0
                for item in [o for o in before if o.stable][::7]:
                    flipped = nodes.flip(transformer, language, code, item.pair, item.index)
                    self.assertIsNotNone(flipped, (language, item))
                    after = observe(transformer, language, {"f": flipped}, anchor)
                    self.assertTrue(keys <= {o.key for o in after}, (language, anchor, item.pair))
                    checked += 1
                self.assertGreater(checked, 3)

    def test_sites_whose_key_changes_are_not_stable(self):
        # In C the two forms of `declare` are different nodes (a block of declarations and the merged declaration)
        found = [o for o in self.observe("c", C_DECLARE, "tok") if o.pair == "declare" and o.usable]
        self.assertTrue(found)
        self.assertFalse(any(o.stable for o in found))

    def test_support_files_are_not_observed(self):
        from cllmark.robust import observe

        code = project("javascript", 2)
        observations = observe(
            self.transformers["javascript"], "javascript", {"a.js": code, "support.json": "{}"}, "tok"
        )
        self.assertEqual({o.file for o in observations}, {"a.js"})


if __name__ == "__main__":
    unittest.main()
