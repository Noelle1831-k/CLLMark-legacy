"""Robust watermark: PRF, targets, the binomial tail and the statistics of the decisions on synthetic votes."""

import hashlib
import hmac
import importlib
import itertools
import math
import random
import unittest
from fractions import Fraction

from cllmark.robust import Scheme, binomial_tail, derive_key, derive_message, keys

# `cllmark.robust.detect` the module is shadowed by the function `detect` in the package namespace
detect_module = importlib.import_module("cllmark.robust.detect")


def exact_tail(n, a):
    return float(Fraction(sum(math.comb(n, i) for i in range(max(a, 0), n + 1)), 2**n))


def random_votes(rng, count, readings=None):
    """{anchor key: reading}; `readings` fixes every reading (a naturally biased code)."""
    return {f"{rng.getrandbits(128):032x}": rng.getrandbits(1) if readings is None else readings for _ in range(count)}


def planted(scheme, key, message, votes):
    """The readings that carry `message`: every vote at its target."""
    encoded = keys.message_bytes(scheme, message)
    return {vote: keys.target(key, scheme, encoded, bytes.fromhex(vote)) for vote in votes}


def bits_of(value, width):
    return [(value >> shift) & 1 for shift in range(width - 1, -1, -1)]


class PrfTests(unittest.TestCase):
    def test_prf_is_hmac_sha256_under_a_domain_label(self):
        key = derive_key("seed")
        self.assertEqual(len(key), 32)
        expected = hmac.new(key, b"white\x00" + b"abc", hashlib.sha256).digest()
        self.assertEqual(keys.prf(key, "white", b"abc"), expected)
        self.assertNotEqual(keys.prf(key, "white", b"abc"), keys.prf(key, "role", b"abc"))
        self.assertNotEqual(keys.prf(key, "white", b"abc"), keys.prf(derive_key("other"), "white", b"abc"))

    def test_targets_are_balanced_and_depend_on_the_message(self):
        key = derive_key("balance")
        rng = random.Random(1)
        votes = [bytes.fromhex(f"{rng.getrandbits(128):032x}") for _ in range(4000)]
        for name in ("s1", "s2"):
            scheme = Scheme(name, 4, "tok")
            for message in ([0, 0, 0, 0], [1, 0, 1, 0]):
                encoded = keys.message_bytes(scheme, message)
                ones = sum(keys.target(key, scheme, encoded, vote) for vote in votes)
                self.assertLess(abs(ones - 2000), 160, (name, message))  # about 5 standard deviations
        scheme = Scheme("s2", 4, "tok")
        first = [keys.target(key, scheme, keys.message_bytes(scheme, [0, 0, 0, 1]), vote) for vote in votes]
        second = [keys.target(key, scheme, keys.message_bytes(scheme, [0, 0, 1, 1]), vote) for vote in votes]
        self.assertLess(abs(sum(a == b for a, b in zip(first, second, strict=True)) - 2000), 160)

    def test_roles_split_votes_by_share_and_spread_over_bits(self):
        key = derive_key("roles")
        scheme = Scheme("s1", 8, "tok", message_share=0.25)
        rng = random.Random(2)
        roles = [keys.role(key, scheme, bytes.fromhex(f"{rng.getrandbits(128):032x}")) for _ in range(8000)]
        messages = [role for role in roles if role is not None]
        self.assertLess(abs(len(messages) - 2000), 200)
        counts = [messages.count(j) for j in range(8)]
        self.assertTrue(all(abs(count - len(messages) / 8) < 80 for count in counts), counts)

    def test_message_and_key_derivation_are_reproducible(self):
        self.assertEqual(derive_key(7), derive_key(7))
        self.assertNotEqual(derive_key(7), derive_key(8))
        self.assertEqual(derive_message(7, "unit", 8), derive_message(7, "unit", 8))
        seen = {tuple(derive_message(7, f"u{i}", 4)) for i in range(400)}
        self.assertEqual(len(seen), 16)  # uniform over 2**4 messages

    def test_scheme_validates_its_parameters(self):
        for bad in (("s3", 4, "tok"), ("s1", 0, "tok"), ("s1", 4, "position")):
            with self.assertRaises(ValueError):
                Scheme(*bad)
        with self.assertRaises(ValueError):
            Scheme("s1", 4, "tok", message_share=1.0)
        with self.assertRaises(ValueError):
            keys.message_bytes(Scheme("s1", 4, "tok"), [1, 0, 1])


class BinomialTailTests(unittest.TestCase):
    def test_matches_enumeration_for_small_n(self):
        for n in range(17):
            for a in range(-1, n + 3):
                self.assertEqual(binomial_tail(n, a), exact_tail(n, a), (n, a))

    def test_mid_sized_n_is_exact(self):
        for n, a in ((100, 50), (100, 75), (300, 200), (1000, 600), (1999, 1500), (2000, 1100)):
            self.assertEqual(binomial_tail(n, a), exact_tail(n, a), (n, a))

    def test_large_n_uses_logs_and_agrees_with_exact_sums(self):
        for n, a in ((2500, 1250), (2500, 1300), (2500, 1400), (4000, 2100), (4000, 2300), (4000, 1900)):
            expected = exact_tail(n, a)
            self.assertAlmostEqual(binomial_tail(n, a) / expected, 1.0, places=8, msg=(n, a))
        self.assertEqual(binomial_tail(100000, 99999), 0.0)  # underflows to zero, never raises
        self.assertAlmostEqual(detect_module.log10_tail(4000, 2300), math.log10(exact_tail(4000, 2300)), places=6)

    def test_log10_tail_has_no_underflow(self):
        self.assertAlmostEqual(detect_module.log10_tail(100, 100), -100 * math.log10(2))
        self.assertLess(detect_module.log10_tail(5000, 4000), -300)
        self.assertEqual(detect_module.log10_tail(10, 0), 0.0)
        self.assertEqual(detect_module.log10_tail(10, 11), -math.inf)

    def test_tail_is_monotone(self):
        for n in (30, 500, 2600):
            values = [binomial_tail(n, a) for a in range(n + 2)]
            self.assertTrue(all(left >= right for left, right in itertools.pairwise(values)), n)
            self.assertEqual(values[0], 1.0)
            self.assertEqual(values[-1], 0.0)


class DecisionStatisticsTests(unittest.TestCase):
    """The decisions on synthetic votes: calibration under the null, planted messages, wrong messages."""

    def randomized_p(self, rng, n, a):
        low, high = binomial_tail(n, a + 1), binomial_tail(n, a)
        return low + rng.random() * (high - low)

    def assert_uniform(self, values, label):
        values = sorted(values)
        size = len(values)
        deviation = max(max((i + 1) / size - v, v - i / size) for i, v in enumerate(values))
        self.assertLess(deviation, 1.95 / math.sqrt(size), f"{label}: KS statistic {deviation:.4f}")

    def test_known_message_p_values_are_uniform_for_unmarked_code_of_any_bias(self):
        rng = random.Random(3)
        for name in ("s1", "s2"):
            scheme = Scheme(name, 4, "tok")
            for readings in (None, 0, 1):  # random votes, and code that always reads 0 or always 1
                p_values = []
                votes = random_votes(rng, 90, readings)
                for trial in range(1500):
                    key = derive_key(f"{name}-{readings}-{trial}")
                    result = detect_module.score(scheme, key, votes, [1, 0, 1, 0], blind=False)
                    p_values.append(self.randomized_p(rng, result.votes, result.agree))  # all votes: `p_all`
                self.assert_uniform(p_values, f"{name} readings={readings}")

    def test_conservative_p_values_never_exceed_the_level(self):
        rng = random.Random(4)
        votes = random_votes(rng, 120, 0)
        for name in ("s1", "s2"):
            scheme = Scheme(name, 4, "tok")
            for alpha in (0.05, 0.01):
                hits = sum(
                    detect_module.score(scheme, derive_key(f"c{trial}"), votes, [0, 1, 1, 0], blind=False).p_known
                    <= alpha
                    for trial in range(2000)
                )
                self.assertLessEqual(hits / 2000, alpha + 3 * math.sqrt(alpha * (1 - alpha) / 2000), (name, alpha))

    def test_wrong_messages_are_accepted_at_the_level_only(self):
        """Every wrong message, in particular the one-bit neighbours, passes `p_known` at the level only."""
        rng = random.Random(5)
        alpha = 0.05
        for name in ("s1", "s2"):
            scheme = Scheme(name, 4, "tok")
            accepted = near = near_trials = trials = 0
            for trial in range(2000):
                key = derive_key(f"x{name}{trial}")
                message = bits_of(rng.randrange(16), 4)
                votes = planted(scheme, key, message, random_votes(rng, 200))
                self.assertLess(detect_module.score(scheme, key, votes, message, blind=False).p_known, 1e-15)
                wrong = bits_of(rng.choice([v for v in range(16) if bits_of(v, 4) != message]), 4)
                trials += 1
                accepted += detect_module.score(scheme, key, votes, wrong, blind=False).p_known <= alpha
                neighbour = list(message)
                neighbour[rng.randrange(4)] ^= 1
                near_trials += 1
                near += detect_module.score(scheme, key, votes, neighbour, blind=False).p_known <= alpha
            bound = alpha + 3 * math.sqrt(alpha * (1 - alpha) / trials)
            self.assertLessEqual(accepted / trials, bound, (name, accepted / trials))
            self.assertLessEqual(near / near_trials, bound, (name, "one-bit neighbours", near / near_trials))

    def test_scheme_one_all_votes_p_value_is_lenient_to_one_bit_neighbours_but_only_informational(self):
        """`p_all` (message and tag votes against the targets of m) accepts a message one bit away when there are many
        votes: its message votes agree in 3 of 4 bits. `p_known` (tag votes) does not."""
        rng = random.Random(10)
        scheme = Scheme("s1", 4, "tok")
        passed_all = passed_known = 0
        for trial in range(40):
            key = derive_key(f"lenient{trial}")
            message = bits_of(rng.randrange(16), 4)
            votes = planted(scheme, key, message, random_votes(rng, 300))
            neighbour = list(message)
            neighbour[rng.randrange(4)] ^= 1
            result = detect_module.score(scheme, key, votes, neighbour, blind=False)
            passed_all += result.p_all <= 1e-3
            passed_known += result.p_known <= 1e-3
            self.assertEqual(detect_module.score(scheme, key, votes, None).decoded, message)
        self.assertGreater(passed_all, 20)
        self.assertLessEqual(passed_known, 2)

    def test_scheme_two_p_all_equals_p_known(self):
        rng = random.Random(11)
        scheme = Scheme("s2", 4, "tok")
        key = derive_key("pall")
        result = detect_module.score(scheme, key, random_votes(rng, 50), [1, 0, 1, 0], blind=False)
        self.assertEqual(result.p_all, result.p_known)

    def test_blind_decoding_recovers_planted_messages(self):
        rng = random.Random(6)
        for name, bits, count in (("s1", 4, 120), ("s1", 8, 400), ("s2", 4, 40), ("s2", 8, 60)):
            scheme = Scheme(name, bits, "tok")
            for trial in range(25):
                key = derive_key(f"b{name}{bits}{trial}")
                message = bits_of(rng.randrange(1 << bits), bits)
                votes = planted(scheme, key, message, random_votes(rng, count))
                result = detect_module.score(scheme, key, votes, None)
                self.assertEqual(result.decoded, message, (name, bits, trial))
                self.assertLess(result.p_blind, 1e-6, (name, bits, trial))
                self.assertIsNone(result.p_known)
                self.assertGreater(result.margin, 2)

    def test_blind_decoding_survives_flipped_votes(self):
        rng = random.Random(7)
        for name, bits in (("s1", 4), ("s2", 4), ("s2", 8)):
            scheme = Scheme(name, bits, "tok")
            correct = 0
            for trial in range(30):
                key = derive_key(f"n{name}{bits}{trial}")
                message = bits_of(rng.randrange(1 << bits), bits)
                votes = planted(scheme, key, message, random_votes(rng, 300))
                votes = {vote: bit ^ (rng.random() < 0.15) for vote, bit in votes.items()}
                correct += detect_module.score(scheme, key, votes, None).decoded == message
            self.assertGreaterEqual(correct, 28, (name, bits))

    def test_blind_p_value_is_calibrated_for_unmarked_code(self):
        rng = random.Random(8)
        alpha = 0.05
        for name, bits in (("s1", 4), ("s2", 4), ("s2", 8)):
            scheme = Scheme(name, bits, "tok")
            votes = random_votes(rng, 80, 0)
            hits = sum(
                detect_module.score(scheme, derive_key(f"u{name}{bits}{trial}"), votes, None).p_blind <= alpha
                for trial in range(600)
            )
            self.assertLessEqual(hits / 600, alpha + 0.03, (name, bits, hits))

    def test_no_votes_decide_nothing(self):
        for name in ("s1", "s2"):
            result = detect_module.score(Scheme(name, 4, "tok"), derive_key("e"), {}, [1, 0, 1, 0])
            self.assertEqual((result.votes, result.agree, result.p_known, result.decoded), (0, 0, 1.0, None))
            self.assertEqual(result.p_blind, 1.0)

    def test_scheme_one_candidates_are_capped(self):
        scheme = Scheme("s1", 8, "tok")
        # no message votes at all: every bit is a tie, only the first two are tried both ways
        key = derive_key("cap")
        rng = random.Random(9)
        votes = {}
        while len(votes) < 40:
            vote = f"{rng.getrandbits(128):032x}"
            if keys.role(key, scheme, bytes.fromhex(vote)) is None:
                votes[vote] = rng.getrandbits(1)
        result = detect_module.score(scheme, key, votes, None)
        self.assertEqual(result.decoded[2:], [0] * 6)
        self.assertLessEqual(result.p_blind, 1.0)


if __name__ == "__main__":
    unittest.main()
