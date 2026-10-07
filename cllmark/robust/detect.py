"""Blind detection from the key alone, and the exact binomial tail.

Votes. The readable, usable, stable sites of the code are grouped by anchor key (`anchors.observe`); the votes of one
key are one vote b(key), the majority of their readings (a tie casts no vote). Nothing is aligned: deleted code only
removes votes, inserted code adds votes unrelated to the PRF, and keys do not depend on position.

Scheme 1 (`s1`): the votes with role j repeat message bit j (target m_j xor white), the others carry a tag
PRF(K, tag, m || key) xor white. Blind: majority per bit (ties are uncertain: at most MAX_CANDIDATES messages are
tried, the first two uncertain bits both ways), then the tag votes test each candidate with Bonferroni over the
candidates. Known message: all votes against the targets of m.

Scheme 2 (`s2`): every vote carries PRF(K, seq, m || key) xor white. Known message: the agreeing votes. Blind: all
2**k messages are tested, p_blind = min(1, 2**k * p_min).

p-values are P[Bin(n, 1/2) >= a]: the null (unmarked code or a wrong message) makes every agreement an independent
fair coin because the targets are PRF values.
"""

from __future__ import annotations

import hmac
import math
from collections import Counter
from collections.abc import Mapping, Sequence
from dataclasses import dataclass, field, replace

from ..transform import StyleTransformer
from .anchors import Observation, observe_counted
from .keys import Scheme, message_bytes, role, target, white

MAX_CANDIDATES = 4  # scheme 1: messages tried when message bits have no majority
EXACT_LIMIT = 2000  # largest n with exact integer arithmetic in binomial_tail


@dataclass(frozen=True)
class Detection:
    votes: int  # votes cast (keys with a majority reading)
    agree: int | None  # votes agreeing with the targets of `message` (None without a message)
    p_known: float | None  # P[Bin(votes, 1/2) >= agree]
    decoded: list[int] | None  # the blind message (None without votes)
    p_blind: float  # p-value of the blind decision, corrected for the messages tried
    margin: float  # log10(p of the runner-up) - log10(p of the decoded message); < 2 is uncertain
    per_file: dict[str, tuple[int, int | None]] = field(default_factory=dict)  # file -> (votes, agree)
    keys: dict[str, int] = field(default_factory=dict)  # vote key -> reading (for the anchor survival)
    errors: int = 0  # (file, rule pair) combinations whose rules raised: they have no sites


# ------------------------------------------------------------------------------------------------ binomial tail


def binomial_tail(n: int, a: int) -> float:
    """P[Bin(n, 1/2) >= a]: exact integer arithmetic up to EXACT_LIMIT, log-space sums beyond."""
    if a <= 0:
        return 1.0
    if a > n:
        return 0.0
    if n <= EXACT_LIMIT:
        return _exact(n, a) / (1 << n)
    return math.exp(_log_tail(n, a)) if _log_tail(n, a) > -745 else 0.0


def _exact(n: int, a: int) -> int:
    """sum_{i >= a} C(n, i) as an integer."""
    if a * 2 <= n:  # the smaller side: 2**n - sum_{i < a}
        term, lower = 1, 0
        for i in range(a):
            lower += term
            term = term * (n - i) // (i + 1)
        return (1 << n) - lower
    term, upper = math.comb(n, a), 0
    for i in range(a, n + 1):
        upper += term
        term = term * (n - i) // (i + 1)
    return upper


def _log_pmf(n: int, i: int) -> float:
    return math.lgamma(n + 1) - math.lgamma(i + 1) - math.lgamma(n - i + 1) - n * math.log(2)


def _log_sum(n: int, start: int, step: int, stop: int) -> float:
    """ln of the sum of the pmf from `start` towards `stop` (terms fall off monotonically from the start)."""
    peak = _log_pmf(n, start)
    total, i = 1.0, start + step
    while (i <= stop) if step > 0 else (i >= stop):
        term = math.exp(_log_pmf(n, i) - peak)
        total += term
        if term < 1e-18 * total:
            break
        i += step
    return peak + math.log(total)


def _log_tail(n: int, a: int) -> float:
    """ln P[Bin(n, 1/2) >= a] for EXACT_LIMIT < n (0 < a <= n)."""
    if a * 2 > n:
        return _log_sum(n, a, 1, n)
    lower = math.exp(_log_sum(n, a - 1, -1, 0))  # P[X < a], a mode-side tail of at most 1/2
    return math.log1p(-lower)


def log10_tail(n: int, a: int) -> float:
    """log10 P[Bin(n, 1/2) >= a] without underflow (-inf when a > n)."""
    if a <= 0:
        return 0.0
    if a > n:
        return -math.inf
    if n <= EXACT_LIMIT:
        return math.log10(_exact(n, a)) - n * math.log10(2)
    return _log_tail(n, a) / math.log(10)


# ------------------------------------------------------------------------------------------------ votes


def cast_votes(observations: Sequence[Observation]) -> tuple[dict[str, int], dict[str, dict[str, int]]]:
    """The votes of the project ({key: bit}) and of each file ({file: {key: bit}}).

    The readings of the usable, stable, readable sites with one key vote together; a tie casts no vote.
    """
    total: dict[str, Counter] = {}
    files: dict[str, dict[str, Counter]] = {}
    for item in observations:
        if item.reading is None or not item.usable or not item.stable:
            continue
        total.setdefault(item.key, Counter())[item.reading] += 1
        files.setdefault(item.file, {}).setdefault(item.key, Counter())[item.reading] += 1
    return _majority(total), {name: _majority(counts) for name, counts in files.items()}


def _majority(counts: Mapping[str, Counter]) -> dict[str, int]:
    votes = {}
    for key, count in counts.items():
        if count[0] != count[1]:
            votes[key] = 0 if count[0] > count[1] else 1
    return votes


def _bits(value: int, width: int) -> list[int]:
    return [(value >> shift) & 1 for shift in range(width - 1, -1, -1)]


def _agreement(key: bytes, scheme: Scheme, message: bytes, votes: Mapping[str, int]) -> int:
    return sum(target(key, scheme, message, bytes.fromhex(vote)) == bit for vote, bit in votes.items())


def score(
    scheme: Scheme,
    key: bytes,
    votes: Mapping[str, int],
    message: Sequence[int] | None,
    per_file_votes: Mapping[str, Mapping[str, int]] | None = None,
    blind: bool = True,
) -> Detection:
    """The decisions of `votes` ({anchor key: majority reading}); `detect` calls this on the observed votes.

    `blind=False` skips the blind decision (decoded None, p_blind 1) when only the known-message test is wanted.
    """
    known = message_bytes(scheme, message) if message is not None else None
    total = len(votes)
    agree = p_known = None
    if known is not None:
        agree = _agreement(key, scheme, known, votes)
        p_known = binomial_tail(total, agree)
    per_file = {}
    for name, cast in (per_file_votes or {}).items():
        per_file[name] = (len(cast), _agreement(key, scheme, known, cast) if known is not None else None)
    decide = _blind_s1 if scheme.name == "s1" else _blind_s2
    decoded, p_blind, margin = decide(scheme, key, votes) if total and blind else (None, 1.0, 0.0)
    return Detection(total, agree, p_known, decoded, p_blind, margin, per_file, dict(votes))


def _blind_s2(scheme: Scheme, key: bytes, votes: Mapping[str, int]) -> tuple[list[int], float, float]:
    size = 1 << scheme.bits
    names = [bytes.fromhex(vote) for vote in votes]
    masks = [white(key, vote) for vote in names]
    bits = list(votes.values())
    agreeing = []
    for value in range(size):
        prefix = b"seq\x00" + bytes(_bits(value, scheme.bits))
        count = 0
        for vote, mask, bit in zip(names, masks, bits, strict=True):
            count += (hmac.digest(key, prefix + vote, "sha256")[0] & 1) ^ mask == bit
        agreeing.append(count)
    order = sorted(range(size), key=lambda value: (-agreeing[value], value))
    best, second = order[0], order[1] if size > 1 else order[0]
    total = len(votes)
    p_best = binomial_tail(total, agreeing[best])
    margin = log10_tail(total, agreeing[second]) - log10_tail(total, agreeing[best]) if size > 1 else 0.0
    return _bits(best, scheme.bits), min(1.0, p_best * size), margin


def _blind_s1(scheme: Scheme, key: bytes, votes: Mapping[str, int]) -> tuple[list[int], float, float]:
    counts = [[0, 0] for _ in range(scheme.bits)]
    tags: list[tuple[bytes, int]] = []  # (vote key, reading xor white): what the tag PRF must equal
    for vote, bit in votes.items():
        name = bytes.fromhex(vote)
        index = role(key, scheme, name)
        reading = bit ^ white(key, name)
        if index is None:
            tags.append((name, reading))
        else:
            counts[index][reading] += 1
    base = [1 if ones > zeros else 0 for zeros, ones in counts]  # a tie reads 0 unless it is enumerated below
    uncertain = [j for j, (zeros, ones) in enumerate(counts) if zeros == ones][:2]
    candidates = []
    for pattern in range(1 << len(uncertain)):
        candidate = list(base)
        for position, j in enumerate(uncertain):
            candidate[j] = (pattern >> position) & 1
        candidates.append(candidate)

    def tag_agreement(candidate: Sequence[int]) -> int:
        prefix = b"tag\x00" + bytes(candidate)
        return sum((hmac.digest(key, prefix + name, "sha256")[0] & 1) == reading for name, reading in tags)

    scored = [(tag_agreement(candidate), candidate) for candidate in candidates]
    best_agree = max(score_ for score_, _ in scored)
    best = next(candidate for score_, candidate in scored if score_ == best_agree)  # first of equal scores
    n_tag = len(tags)
    p_blind = min(1.0, binomial_tail(n_tag, best_agree) * len(candidates))
    # runner-up: another candidate or the decoded message with one bit changed
    rivals = {tuple(candidate): score_ for score_, candidate in scored if candidate != best}
    for j in range(scheme.bits):
        neighbour = list(best)
        neighbour[j] ^= 1
        rivals.setdefault(tuple(neighbour), tag_agreement(neighbour))
    rival = max(rivals.values()) if rivals else best_agree
    margin = log10_tail(n_tag, rival) - log10_tail(n_tag, best_agree) if n_tag else 0.0
    return best, p_blind, margin


def detect(
    transformer: StyleTransformer,
    language: str,
    files: Mapping[str, str],
    scheme: Scheme,
    key: bytes,
    message: Sequence[int] | None,
) -> Detection:
    """Observe the code, cast the votes and decide (known message and blind)."""
    observations, errors = observe_counted(transformer, language, files, scheme.anchor)
    votes, per_file = cast_votes(observations)
    return replace(score(scheme, key, votes, message, per_file), errors=errors)
