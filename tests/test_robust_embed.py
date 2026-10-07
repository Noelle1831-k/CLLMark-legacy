"""Robust watermark: embedding and blind detection on synthetic projects, no attack and the position-free attacks."""

import unittest

from tests.robust_samples import HAS_GRAMMARS, join, project, split

COUNT = 40
MESSAGES = {4: [[1, 0, 1, 1], [0, 0, 0, 0], [1, 1, 1, 0]], 8: [[1, 0, 1, 1, 0, 0, 1, 0], [0, 0, 0, 0, 0, 0, 0, 0]]}


class EmbedDetectMixin:
    language = None

    @classmethod
    def setUpClass(cls):
        from cllmark.robust import derive_key
        from cllmark.transform import StyleTransformer

        cls.transformer = StyleTransformer(cls.language)
        cls.key = derive_key("embed-tests")
        cls.code = project(cls.language, COUNT)
        cls.marks = {}

    def mark(self, scheme, message):
        from cllmark.robust import embed

        cache = (scheme, tuple(message))
        if cache not in self.marks:
            result = embed(self.transformer, self.language, {"f": self.code}, scheme, self.key, message)
            self.marks[cache] = (result, {"f": result.written.get("f", self.code)})
        return self.marks[cache]

    def detect(self, files, scheme, message):
        from cllmark.robust import detect

        return detect(self.transformer, self.language, files, scheme, self.key, message)

    def schemes(self):
        from cllmark.robust import Scheme

        for anchor in ("tok", "struct"):
            for name in ("s1", "s2"):
                for bits in (4, 8):
                    yield Scheme(name, bits, anchor)

    def test_marked_code_is_detected_and_decoded_without_attack(self):
        for scheme in self.schemes():
            message = MESSAGES[scheme.bits][0]
            result, marked = self.mark(scheme, message)
            label = (self.language, scheme)
            self.assertGreaterEqual(result.votes, 30, label)
            self.assertGreaterEqual(result.set_sites / result.targeted_sites, 0.85, label)
            self.assertLessEqual(result.votes, result.targeted_sites)
            self.assertGreaterEqual(result.unstable_selected, 0)
            self.assertEqual(result.targeted_sites + result.unstable_selected, result.details["available"])
            self.assertGreaterEqual(result.selection_agreement, 0.6, label)  # for(;;) forms lose their key
            self.assertIn("f", result.written)
            self.assertTrue(self.transformer.check_syntax(marked["f"]), label)
            detection = self.detect(marked, scheme, message)
            self.assertLessEqual(detection.p_known, 1e-6, label)
            if scheme.name == "s1" and scheme.bits == 8:
                # the votes of unmarked sites are noise in the per-bit majorities: a bit or two may be wrong
                errors = sum(a != b for a, b in zip(detection.decoded, message, strict=True))
                self.assertLessEqual(errors, 2, label)
            else:
                self.assertEqual(detection.decoded, message, label)
                self.assertLessEqual(detection.p_blind, 1e-3, label)
            self.assertEqual(sum(votes for votes, _ in detection.per_file.values()), detection.votes)
            self.assertEqual(detection.per_file["f"][1], detection.agree)
            self.assertEqual(set(detection.keys) <= {o.key for o in self.observe(marked, scheme)}, True)

    def observe(self, files, scheme):
        from cllmark.robust import observe

        return observe(self.transformer, self.language, files, scheme.anchor)

    def test_unmarked_code_and_wrong_messages_are_rejected(self):
        for scheme in self.schemes():
            message = MESSAGES[scheme.bits][0]
            _, marked = self.mark(scheme, message)
            label = (self.language, scheme)
            neighbours = [[bit ^ (j == i) for j, bit in enumerate(message)] for i in range(scheme.bits)]
            for other in [*MESSAGES[scheme.bits][1:], *neighbours]:
                self.assertGreater(self.detect({"f": self.code}, scheme, other).p_known, 1e-4, label)
                self.assertGreater(self.detect(marked, scheme, other).p_known, 1e-4, (label, other))
            self.assertGreater(self.detect({"f": self.code}, scheme, message).p_known, 1e-4, label)
            self.assertGreater(self.detect({"f": self.code}, scheme, None).p_blind, 1e-4, label)

    def test_deleted_reordered_and_inserted_code_keep_the_watermark(self):
        for scheme in self.schemes():
            message = MESSAGES[scheme.bits][0]
            _, marked = self.mark(scheme, message)
            header, functions = split(self.language, marked["f"])
            label = (self.language, scheme)
            half = join(header, functions[::2])
            self.assertLessEqual(self.detect({"f": half}, scheme, message).p_known, 1e-3, label)
            reordered = self.detect({"f": join(header, functions[::-1])}, scheme, message)
            self.assertLessEqual(reordered.p_known, 1e-6, label)
            extra = project(self.language, 6, start=100)
            appended = marked["f"] + extra[len(header) :]
            self.assertLessEqual(self.detect({"f": appended}, scheme, message).p_known, 1e-3, label)
            # across files: the same functions split over two files and renamed files
            parts = {"b.txt": join(header, functions[:10]), "a.txt": join(header, functions[10:])}
            self.assertLessEqual(self.detect(parts, scheme, message).p_known, 1e-6, label)

    def test_embedding_is_deterministic_and_idempotent(self):
        from cllmark.robust import Scheme, embed

        scheme = Scheme("s2", 4, "tok")
        message = MESSAGES[4][0]
        first, marked = self.mark(scheme, message)
        again = embed(self.transformer, self.language, {"f": self.code}, scheme, self.key, message)
        self.assertEqual(again.written, first.written)
        self.assertEqual(
            (again.votes, again.targeted_sites, again.set_sites), (first.votes, first.targeted_sites, first.set_sites)
        )
        second = embed(self.transformer, self.language, marked, scheme, self.key, message)
        self.assertLessEqual(len(second.written), 1)
        if second.written:  # a few sites never took their bit in the first pass: they may take it now
            self.assertGreaterEqual(second.set_sites, first.set_sites)

    def test_other_messages_and_keys_give_other_code(self):
        from cllmark.robust import Scheme, derive_key, embed

        scheme = Scheme("s2", 4, "tok")
        _, marked = self.mark(scheme, MESSAGES[4][0])
        _, other = self.mark(scheme, MESSAGES[4][1])
        self.assertNotEqual(marked["f"], other["f"])
        stranger = embed(self.transformer, self.language, {"f": self.code}, scheme, derive_key("other"), MESSAGES[4][0])
        self.assertNotEqual(stranger.written["f"], marked["f"])
        from cllmark.robust import detect

        wrong_key = detect(self.transformer, self.language, marked, scheme, derive_key("other"), MESSAGES[4][0])
        self.assertGreater(wrong_key.p_known, 1e-4)

    def test_empty_capacity_embeds_nothing(self):
        from cllmark.robust import Scheme, embed

        result = embed(self.transformer, self.language, {"f": "\n"}, Scheme("s2", 4, "tok"), self.key, MESSAGES[4][0])
        self.assertEqual((result.written, result.votes, result.targeted_sites, result.set_sites), ({}, 0, 0, 0))
        detection = self.detect({"f": "\n"}, Scheme("s2", 4, "tok"), MESSAGES[4][0])
        self.assertEqual((detection.votes, detection.decoded), (0, None))


@unittest.skipUnless(HAS_GRAMMARS, "pinned parser libraries are not built")
class EmbedDetectPython(EmbedDetectMixin, unittest.TestCase):
    language = "python"


@unittest.skipUnless(HAS_GRAMMARS, "pinned parser libraries are not built")
class EmbedDetectC(EmbedDetectMixin, unittest.TestCase):
    language = "c"


@unittest.skipUnless(HAS_GRAMMARS, "pinned parser libraries are not built")
class EmbedDetectCpp(EmbedDetectMixin, unittest.TestCase):
    language = "cpp"


@unittest.skipUnless(HAS_GRAMMARS, "pinned parser libraries are not built")
class EmbedDetectJavaScript(EmbedDetectMixin, unittest.TestCase):
    language = "javascript"


if __name__ == "__main__":
    unittest.main()


@unittest.skipUnless(HAS_GRAMMARS, "pinned parser libraries are not built")
class RulesThatRaiseTests(unittest.TestCase):
    """`while_to_for` (7.8/12) raises on C code with `for(;;)`: the pair has no sites there, as in `cllmark.nodes`."""

    CODE = (
        project("c", 40)
        + "int g(int n) {\n    for (;;) {\n        if (n == 3) { break; }\n        n += 1;\n    }\n    return n;\n}\n"
    )

    def test_a_raising_pair_has_no_sites_and_is_counted(self):
        from cllmark import nodes
        from cllmark.robust import Scheme, derive_key, detect, embed, observe
        from cllmark.robust.anchors import observe_counted
        from cllmark.transform import StyleTransformer

        transformer = StyleTransformer("c")
        self.assertIsNone(nodes._sites_or_none(transformer, transformer.pairs["while_to_for"], self.CODE))
        observations, errors = observe_counted(transformer, "c", {"f": self.CODE}, "tok")
        self.assertEqual(errors, 1)
        self.assertEqual(len(observe(transformer, "c", {"f": self.CODE}, "tok")), len(observations))
        self.assertNotIn("while_to_for", {o.pair for o in observations})
        _, clean = observe_counted(transformer, "c", {"f": project("c", 2)}, "tok")
        self.assertEqual(clean, 0)

        scheme, key, message = Scheme("s2", 4, "tok"), derive_key("raise"), [1, 0, 1, 1]
        result = embed(transformer, "c", {"f": self.CODE}, scheme, key, message)
        self.assertEqual(result.errors, 1)
        self.assertGreaterEqual(result.votes, 30)
        marked = {"f": result.written["f"]}
        detection = detect(transformer, "c", marked, scheme, key, message)
        self.assertLessEqual(detection.p_known, 1e-6)
        self.assertEqual(detection.decoded, message)
        self.assertGreaterEqual(detection.errors, 0)
        self.assertEqual(detect(transformer, "c", {"f": self.CODE}, scheme, key, message).errors, 1)
