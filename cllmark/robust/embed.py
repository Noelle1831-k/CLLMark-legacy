"""Embedding: set every selected, stable site to the target of its vote.

1. Observe the original code; the usable sites of each file are taken greedily in pre-order when their windows
   meet no earlier window (`cllmark.nodes._Regions`), whether or not their keys are stable (detection selects the
   same way, without a stability check). Only the selected sites are checked for stability; a selected site whose
   key is not stable stays as it was (`EmbedResult.unstable_selected`).
2. A vote is the set of sites with the same anchor key; its target comes from the scheme (`keys.target`).
3. Sites that do not read their target are rewritten pair by pair in one pass (`cllmark.nodes.place`). Sites that still
   do not read it (rewrites of other pairs interfere) are rewritten one at a time in the next rounds, found again by
   their anchor key, up to MAX_ROUNDS rounds in all. Sites that never take their bit stay as noise.

Nothing is stored: detection needs only the key, the scheme and the code.
"""

from __future__ import annotations

from collections import Counter
from collections.abc import Mapping, Sequence
from dataclasses import dataclass, field

from .. import nodes
from ..source_io import reload_written
from ..transform import StyleTransformer
from ..watermark import project_order
from .anchors import file_entries, select_for, selected_stable
from .keys import Scheme, message_bytes, target

MAX_ROUNDS = 4


@dataclass(frozen=True)
class EmbedResult:
    written: dict[str, str]  # {file: text} of the files that changed
    votes: int  # distinct anchor keys among the targeted sites (the votes the embedding aims at)
    targeted_sites: int  # sites given a target (selected and stable)
    set_sites: int  # of those, the sites that read their target in the marked code (counted per vote)
    rounds: int  # rounds used (1 = the first pass set everything)
    details: dict = field(default_factory=dict, compare=False)  # extra counters for reports
    errors: int = 0  # (file, rule pair) combinations whose rules raised on the original code: no sites
    # Jaccard similarity of the anchor keys selected on the marked code (what detection votes on) and the keys
    # selected for embedding; 1.0 when the marked code selects exactly the embedded votes
    selection_agreement: float = 1.0
    unstable_selected: int = 0  # selected sites whose key is not stable: left as they were (noise votes)


def _targets(scheme: Scheme, key: bytes, message: bytes, vote: str) -> int:
    return target(key, scheme, message, bytes.fromhex(vote))


def embed(
    transformer: StyleTransformer,
    language: str,
    files: Mapping[str, str],
    scheme: Scheme,
    key: bytes,
    message: Sequence[int],
) -> EmbedResult:
    encoded = message_bytes(scheme, message)
    anchor = scheme.anchor
    current = {name: files[name] for name in project_order(files)}
    # 1. selection (as detection makes it), then the stability check of the selected sites only
    plan: dict[str, list[tuple[str, int, str, int]]] = {}  # file -> [(pair, index, key, target)]
    wanted: Counter = Counter()  # anchor key -> targeted sites
    goals: dict[str, int] = {}
    available = errors = unstable = 0
    by_pair: dict[str, list[int]] = {}  # rule pair -> [selected sites, unstable selected sites]
    embedded: set[str] = set()  # keys of all selected sites, stable or not
    for name, code in current.items():
        found = file_entries(transformer, language, anchor, code, stability=False)
        errors += found.errors
        selection = select_for(transformer, language, anchor, found)
        available += len(selection)
        embedded.update(entry.key for entry in selection)
        stable = selected_stable(transformer, language, anchor, code, selection)  # only selected sites are checked
        chosen = []
        for entry in selection:
            counts = by_pair.setdefault(entry.pair, [0, 0])
            counts[0] += 1
            if (entry.pair, entry.index) not in stable:
                unstable += 1
                counts[1] += 1
                continue
            goal = goals.get(entry.key)
            if goal is None:
                goal = goals[entry.key] = _targets(scheme, key, encoded, entry.key)
            chosen.append((entry.pair, entry.index, entry.key, goal))
            wanted[entry.key] += 1
        if chosen:
            plan[name] = chosen
    targeted = sum(wanted.values())

    # 2. first pass: every selected site at once
    raw: dict[str, str] = {}
    rounds = 1 if plan else 0
    if plan:
        assignments = [((name, pair, index), goal) for name, sites in plan.items() for pair, index, _, goal in sites]
        written, _ = nodes.place(transformer, language, current, assignments)
        for name, text in written.items():
            raw[name] = text
            current[name] = reload_written(text)

    # 3. later rounds: sites that still read the wrong bit, one at a time, found again by key
    for number in range(2, MAX_ROUNDS + 1):
        attempted = False
        for name, sites in plan.items():
            needed = Counter(site[2] for site in sites)
            text, tried = _repair(transformer, language, anchor, current[name], needed, goals)
            attempted = attempted or tried
            if text is not None:
                raw[name] = text
                current[name] = reload_written(text)
        if not attempted:
            break
        rounds = number

    done = {name: text for name, text in raw.items() if reload_written(text) != files[name]}
    reading: Counter = Counter()
    for name in plan:
        for entry in file_entries(transformer, language, anchor, current[name], stability=False):
            if entry.key in wanted and entry.site.usable and entry.site.reading == goals[entry.key]:
                reading[entry.key] += 1
    set_sites = sum(min(count, reading[vote]) for vote, count in wanted.items())
    detected = {
        entry.key
        for text in current.values()
        for entry in select_for(
            transformer, language, anchor, file_entries(transformer, language, anchor, text, stability=False)
        )
    }
    union = len(detected | embedded)
    agreement = len(detected & embedded) / union if union else 1.0
    return EmbedResult(
        done,
        len(wanted),
        targeted,
        set_sites,
        rounds,
        {
            "available": available,  # selected sites
            "unstable": unstable,
            "pairs": len(by_pair),
            "selected_by_pair": {pair: counts[0] for pair, counts in by_pair.items()},
            "unstable_by_pair": {pair: counts[1] for pair, counts in by_pair.items()},
            "selected_votes": len(embedded),  # distinct anchor keys among the selected sites
        },
        errors,
        agreement,
        unstable,
    )


def _repair(
    transformer: StyleTransformer, language: str, anchor: str, code: str, needed: Counter, goals: Mapping[str, int]
) -> tuple[str | None, bool]:
    """Rewrite single sites of the votes that have fewer sites on their target than sites were targeted in this file.

    Returns the new text of the file (None when nothing was rewritten) and whether a rewrite was attempted.
    """
    text, attempted = None, False
    for vote in sorted(needed):
        for _ in range(needed[vote]):
            entries = [e for e in file_entries(transformer, language, anchor, code, stability=False) if e.key == vote]
            usable = [e for e in entries if e.site.usable]
            if sum(e.site.reading == goals[vote] for e in usable) >= needed[vote]:
                break
            attempted = True
            for entry in usable:
                if entry.site.reading == goals[vote]:
                    continue
                slot = ("f", entry.pair, entry.index)
                try:
                    written, located = nodes.place(transformer, language, {"f": code}, [(slot, goals[vote])])
                except Exception:  # a rule that raises on the rewritten code: try the next site
                    continue
                if located.get(slot) is not None and "f" in written:
                    text = written["f"]
                    code = reload_written(text)
                    break
            else:
                break
    return text, attempted
