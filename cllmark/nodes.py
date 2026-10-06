"""Node-granular watermark slots: every rewritable syntax node of a rule pair can carry one codeword bit.

File granularity (`cllmark.watermark`) gives each (file, rule pair) one slot and rewrites every candidate node of the
selected style, so a file with many matching nodes still holds one bit. Here each node is a slot of its own.

Sites. For a pair (s0, s1) the sites of a file are the nodes that either style rewrites, in pre-order. A node s0
rewrites is not in s0's form and reads 1; a node s1 rewrites reads 0. For the detect-only styles 11/12 of C and C++
the nodes already in s0's output form read 0 (no rewrite produces 1 from them). A node both styles rewrite reads
nothing. A site is usable when the style of the other bit rewrites that node alone with a change beyond spaces and
line breaks. Its window is the text its rewrite edits: the operator of a comparison, the header of a loop, a whole
declaration cluster. A slot names a site by (file, pair, index in the file's site list of the pair).

Slots. Slot order first interleaves the (file, pair) groups that have usable sites over distinct nodes: every group
in turn (files in `watermark.project_order`, pairs in pair order) takes its next usable site whose window meets no
taken text, round after round. The first round takes one node of every (file, pair) of file granularity whose first
site fits, so a project that already has enough slots spreads its bits over as many rules as before, and only
projects short of slots use further nodes of the same rule. The leading slots (see `analyze`) must take and read
back both bits on their own, and a project still short of a codeword stacks: a node may carry one slot
per pair that has it as a site (operand order and strictness of one comparison, as in file granularity), when every
combination of bits of the node's slots takes and reads back, because the rewrites of one pair can change how
another pair reads the same node (`a == b` -> `not a != b`). Slots of different nodes never edit the same text:
their regions (the union of a node's slot windows) are disjoint and do not touch.

Embedding. The selected sites of a file are rewritten pair by pair, all sites of a pair in one pass. Each slot's
node is followed through the applied edits by its byte span (shifted over the edits of other nodes, widened over
the edits of its own node by its own or another pair) and found again among the sites of its pair: by exact span,
or, for a rewritten node, as the one site of the pair inside its region. Its index in the marked code is what the
marked project's support stores: the support names the very nodes that were rewritten, never merely some site that
happens to read the right bit. A slot whose node is lost or does not read its bit (a guard that reads the context of
the node saw another edit) is dropped and the codeword is placed again on the remaining slots, at most REPAIR_ROUNDS
times. Extraction reads the stored slots; a missing or ambiguous site yields a random bit, as an undecidable slot
does in file granularity.
"""

from __future__ import annotations

import functools
import itertools
import json
import random
import weakref
from bisect import bisect_left
from collections import OrderedDict
from collections.abc import Callable, Mapping, Sequence
from pathlib import Path
from typing import NamedTuple

from . import bch
from .directories import SUPPORT_FILE, load_project, read_support
from .rules.engine import Edit, Grammar, apply_groups, changes_beyond_whitespace, edited_tree
from .rules.pairs import WATERMARK_PAIRS
from .source_io import reload_written, write_source
from .transform import StyleTransformer
from .watermark import DETECT_ONLY, project_order

Slot = tuple[str, str, int]
"""(file name, pair name, site index)."""
Span = tuple[int, int]

REPAIR_ROUNDS = 8
# Memory is traded for time: versions of a file are re-read by embedding, its checks, extraction and attacks.
SITE_CACHE_SIZE = 4096
_SITES: weakref.WeakKeyDictionary = weakref.WeakKeyDictionary()  # transformer -> {(styles, code): sites}


class Site(NamedTuple):
    start: int
    end: int
    reading: int | None
    group: Sequence[Edit]  # rewrite of this node alone to the other reading; empty when there is none
    usable: bool
    window: Span  # the text its rewrite edits (the node itself when there is no rewrite)


def sites(transformer: StyleTransformer, styles: tuple[str, str], code: str, tree=None) -> list[Site]:
    """The sites of one rule pair in `code`, in pre-order (cached per transformer: analysis, embedding and
    extraction read the same versions). `tree`, when given, is the syntax tree of `code` (see `edited_tree`).

    All pairs share the language's grammar: queries of single pairs (one more parser and query per pair) gained
    little and, with tree-sitter 0.20.2, made an occasional syntax check of unrelated code in the same process
    report errors that a fresh parse does not.
    """
    cache = _SITES.get(transformer)
    if cache is None:
        cache = _SITES[transformer] = OrderedDict()
    key = (styles, code)
    result = cache.get(key)
    if result is None:
        result = cache[key] = _sites(transformer, styles, code, transformer.grammar, tree)
        if len(cache) > SITE_CACHE_SIZE:
            cache.popitem(last=False)
    else:
        cache.move_to_end(key)
    return result


def _sites(
    transformer: StyleTransformer, styles: tuple[str, str], code: str, grammar: Grammar, tree=None
) -> list[Site]:
    zero, one = styles
    parsed = grammar.parse(code, tree)
    found: dict[int, list] = {}  # node id -> [node, reading, group]
    for node, group in parsed.edits(transformer.rules[zero]):
        if group:  # a candidate the rewrite rejects is not rewritten by the style
            found[node.id] = [node, 1, group]
    if one in DETECT_ONLY:
        others = [(node, ()) for node in parsed.candidates(transformer.rules[DETECT_ONLY[one]].target)]
    else:
        others = [(node, group) for node, group in parsed.edits(transformer.rules[one]) if group]
    for node, group in others:
        entry = found.get(node.id)
        if entry is None:
            found[node.id] = [node, 0, group]
        else:
            entry[1], entry[2] = None, ()
    data = parsed.source.data
    result = []
    for node, reading, group in sorted(found.values(), key=lambda entry: (entry[0].start_byte, -entry[0].end_byte)):
        usable = reading is not None and changes_beyond_whitespace(data, group)
        window = (
            (min(edit.start for edit in group), max(edit.end for edit in group))
            if group
            else (node.start_byte, node.end_byte)
        )
        result.append(Site(node.start_byte, node.end_byte, reading, group, usable, window))
    return result


STACK_LIMIT = 4  # slots on one node at most; a stack is verified for all 2**k bit combinations
VERIFIED_SLOTS = 2 * bch.CODE_LENGTH  # leading slots verified on their own (embedding uses the first codeword)


class _Regions:
    """The text taken by the slots of one file: one region per node, the union of the windows of its slots.

    Regions of different nodes are disjoint and do not touch; a node carries one slot per pair at most.
    """

    def __init__(self) -> None:
        self.starts: list[int] = []
        self.regions: list[list] = []  # [start, end, node span, slots]

    def take(
        self, site: Site, slot: Slot, verify: Callable[[list[Slot]], bool] | None = None, stack: bool = False
    ) -> bool:
        """Add `slot` when its window meets no region, or (`stack`) exactly the region of its own node, which has no
        slot of its pair yet; and `verify(slots of the node with it)` holds when given."""
        node = (site.start, site.end)
        start, end = site.window
        position = bisect_left(self.starts, start)
        lowest = position - 1 if position > 0 and self.regions[position - 1][1] >= start else position
        highest = position
        while highest < len(self.regions) and self.regions[highest][0] <= end:
            highest += 1
        met = self.regions[lowest:highest]
        if not met:
            if stack or (verify is not None and not verify([slot])):
                return False
            self.starts.insert(position, start)
            self.regions.insert(position, [start, end, node, [slot]])
            return True
        if not stack or len(met) > 1 or met[0][2] != node or len(met[0][3]) >= STACK_LIMIT:
            return False
        region = met[0]
        if any(other[1] == slot[1] for other in region[3]):
            return False
        start, end = min(start, region[0]), max(end, region[1])
        if (lowest > 0 and self.regions[lowest - 1][1] >= start) or (
            lowest + 1 < len(self.regions) and self.regions[lowest + 1][0] <= end
        ):
            return False
        if verify is not None and not verify([*region[3], slot]):
            return False
        region[0], region[1] = start, end
        region[3].append(slot)
        self.starts[lowest] = start
        return True


def _holds(transformer: StyleTransformer, language: str, name: str, code: str, stacked: list[Slot]) -> bool:
    """Whether the slots of one node take and read back every combination of bits (rewritten in pair order)."""
    for bits in itertools.product((0, 1), repeat=len(stacked)):
        _, located = place(transformer, language, {name: code}, list(zip(stacked, bits, strict=True)))
        if any(final is None for final in located.values()):
            return False
    return True


def analyze(transformer: StyleTransformer, language: str, files: Mapping[str, str]) -> list[Slot]:
    """Every slot of the project, in slot order.

    First the slots of distinct nodes, interleaved over the (file, pair) groups (see `_Regions`); the first
    VERIFIED_SLOTS of them are kept only when they take and read back both bits on their own (a rewrite may leave a
    node that the inverse style no longer recognizes, `p[i]` -> `*(p + i)`). A project with fewer than a codeword
    then gets stacked slots: further pairs on nodes that already carry a slot, each kept only when every combination
    of bits of the node's slots takes and reads back. A check costs a parse per combination, so later slots of large
    projects are not checked; embedding verifies the slots it uses in any case.
    """
    groups = []
    for name in project_order(files):
        for pair, styles in WATERMARK_PAIRS[language].items():
            try:
                found = sites(transformer, styles, files[name])
            except Exception:  # a rule that raises makes the pair unusable, as a raising probe does per file
                continue
            usable = [index for index, site in enumerate(found) if site.usable]
            if usable:
                groups.append((name, pair, usable, found))

    def select(regions: dict[str, _Regions], stack: bool, slots: list[Slot]) -> None:
        taken = set(slots)
        following = [0] * len(groups)
        progress = True
        while progress:
            progress = False
            for position, (name, pair, usable, found) in enumerate(groups):
                check = None
                if stack or len(slots) < VERIFIED_SLOTS:
                    check = functools.partial(_holds, transformer, language, name, files[name])
                while following[position] < len(usable):
                    index = usable[following[position]]
                    following[position] += 1
                    slot = (name, pair, index)
                    if slot not in taken and regions[name].take(found[index], slot, check, stack):
                        slots.append(slot)
                        taken.add(slot)
                        progress = True
                        break

    regions = {name: _Regions() for name in files}
    slots: list[Slot] = []
    select(regions, stack=False, slots=slots)
    if len(slots) < bch.CODE_LENGTH:
        select(regions, stack=True, slots=slots)
    return slots


def read(transformer: StyleTransformer, language: str, files: Mapping[str, str], slot: Slot) -> int | None:
    """The bit a slot holds, or None when its site is missing or reads nothing."""
    name, pair, index = slot
    found = sites(transformer, WATERMARK_PAIRS[language][pair], files[name])
    return found[index].reading if index < len(found) else None


def _shift(position: int, edits: Sequence[Edit], insertions_before: bool) -> int | None:
    """`position` after the edits; None when it lies strictly inside replaced text.

    Text inserted exactly at `position` is counted before it when `insertions_before`, else after it.
    """
    delta = 0
    for edit in edits:
        size = len(edit.text.encode("utf-8"))
        if edit.start == edit.end:
            if edit.start < position or (edit.start == position and insertions_before):
                delta += size
        elif edit.end <= position:
            delta += size - (edit.end - edit.start)
        elif edit.start < position:
            return None
    return position + delta


def _follow(span: Span, edits: Sequence[Edit], own: Sequence[Edit] = ()) -> tuple[Span | None, bool]:
    """The span of a node after `edits`, and whether the node was rewritten (by its own slot's edits `own`, or by a
    slot of another pair on the same node, whose edits replace text at the node's ends).

    A rewritten node's span becomes the shifted union of the node and the edits that met it; the new node lies in
    it but need not fill it (see `_locate`). Edits strictly inside the node only move its end.
    """
    start = _shift(span[0], edits, insertions_before=True)
    end = _shift(span[1], edits, insertions_before=False)
    covered = any(edit.start < edit.end and edit.start <= span[0] and span[1] <= edit.end for edit in edits)
    if not own and not covered and start is not None and end is not None:
        return (start, end), False
    met = [*own, *(edit for edit in edits if edit.start <= span[1] and span[0] <= edit.end and edit not in own)]
    first = min([span[0], *(edit.start for edit in met)])
    last = max([span[1], *(edit.end for edit in met)])
    start = _shift(first, edits, insertions_before=False)
    end = _shift(last, edits, insertions_before=True)
    return (None if start is None or end is None else (start, end)), True


def _locate(found: Sequence[Site], span: Span | None, rewritten: bool, bit: int | None = None) -> int | None:
    """The index of the one site with exactly this span.

    For a rewritten node, the site must read `bit` when one is given, and when no site with the span qualifies, the
    one qualifying site overlapping the span is taken. Regions of different nodes are disjoint, so that site is the
    node itself, in whichever form its rewrites left it: the two styles of a pair may anchor on different nodes (a
    block of declarations and the declaration merged in it).
    """
    if span is None:
        return None

    def qualifies(site: Site) -> bool:
        return not rewritten or bit is None or site.reading == bit

    matches = [index for index, site in enumerate(found) if (site.start, site.end) == span and qualifies(site)]
    if not matches and rewritten:
        matches = [
            index for index, site in enumerate(found) if site.start < span[1] and span[0] < site.end and qualifies(site)
        ]
    return matches[0] if len(matches) == 1 else None


def _sites_or_none(transformer: StyleTransformer, styles: tuple[str, str], code: str, tree=None) -> list[Site] | None:
    """`sites`, or None when a rule of the pair raises on `code` (the slot is then lost, as a raising probe yields
    no bit in file granularity). `tree` is the syntax tree of `code` when known."""
    try:
        return sites(transformer, styles, code, tree=tree)
    except Exception:
        return None


def place(
    transformer: StyleTransformer,
    language: str,
    files: Mapping[str, str],
    assignments: Sequence[tuple[Slot, int]],
) -> tuple[dict[str, str], dict[Slot, Slot | None]]:
    """Rewrite each assigned site that does not hold its bit yet: pair by pair (slots of different pairs may share a
    node), all sites of a pair in one pass.

    Returns {file: text to write} for the changed files and, for every assigned slot, the slot of the same node in
    the marked code (None when the node was lost or does not read its bit).
    """
    pairs = WATERMARK_PAIRS[language]
    by_file: dict[str, list[tuple[Slot, int]]] = {}
    for slot, bit in assignments:
        by_file.setdefault(slot[0], []).append((slot, bit))
    written: dict[str, str] = {}
    located: dict[Slot, Slot | None] = {}
    for name in project_order(by_file):
        code, text = files[name], None
        tree = transformer.grammar.parse(code).tree  # the analysis parse; later versions are parsed incrementally
        spans: dict[Slot, Span | None] = {}
        for slot, _ in by_file[name]:
            found = _sites_or_none(transformer, pairs[slot[1]], code, tree) or []
            spans[slot] = (found[slot[2]].start, found[slot[2]].end) if slot[2] < len(found) else None
        rewritten: set[Slot] = set()
        for pair, styles in pairs.items():
            wanted = [(slot, bit) for slot, bit in by_file[name] if slot[1] == pair]
            if not wanted:
                continue
            found = _sites_or_none(transformer, styles, code, tree) or []
            groups, owners = [], []
            for slot, bit in wanted:
                index = _locate(found, spans[slot], slot in rewritten)
                if index is None or (found[index].reading != bit and not found[index].usable):
                    spans[slot] = None
                    continue
                spans[slot] = (found[index].start, found[index].end)
                rewritten.discard(slot)
                if found[index].reading != bit:
                    groups.append(found[index].group)
                    owners.append(slot)
            if not groups:
                continue
            data, taken = apply_groups(code.encode("utf-8"), groups)
            own = {owners[position]: groups[position] for position in taken}
            edits = [edit for group in own.values() for edit in group]
            for slot, span in spans.items():
                if span is None or (slot in owners and slot not in own):
                    spans[slot] = None
                    continue
                spans[slot], changed = _follow(span, edits, own.get(slot, ()))
                if changed:
                    rewritten.add(slot)
            text = data.decode("utf-8")
            if reload_written(text) != text:  # line ends changed: byte spans no longer hold, nor does the old tree
                spans, tree = dict.fromkeys(spans), None
            else:
                tree = edited_tree(transformer.grammar.parser, tree, code.encode("utf-8"), data, edits)
            code = reload_written(text)
        if text is not None and code != files[name]:
            written[name] = text
        for slot, bit in by_file[name]:
            final = _sites_or_none(transformer, pairs[slot[1]], code, tree) or []
            index = _locate(final, spans[slot], slot in rewritten, bit)
            located[slot] = (name, slot[1], index) if index is not None and final[index].reading == bit else None
    carried = [slot for slot in located.values() if slot is not None]
    for slot, final in located.items():
        if final is not None and carried.count(final) > 1:
            located[slot] = None
    return written, located


def embed(
    transformer: StyleTransformer, language: str, files: Mapping[str, str], slots: Sequence[Slot], bits: Sequence[int]
) -> tuple[dict[str, str], list[Slot], int]:
    """Embed the codeword of `bits`: ({file: text to write}, the slots that carry it in the marked code, the number
    of analysis slots dropped by repair). The carrying slots are what the caller stores as the marked project's
    support.

    When the slots run out or the rounds end, the last placement is returned with its unverified slots (a lost slot
    keeps its analysis index, which extraction then reads as it finds it).
    """
    codeword = bch.encode(bits)
    slots = list(slots)
    written: dict[str, str] = {}
    carried: list[Slot] = []
    dropped = 0
    for _ in range(REPAIR_ROUNDS):
        if len(slots) < len(codeword):
            break
        assignments = list(zip(slots, codeword, strict=False))
        written, located = place(transformer, language, files, assignments)
        carried = [located[slot] or slot for slot, _ in assignments]
        lost = {slot for slot, _ in assignments if located[slot] is None}
        if not lost:
            break
        slots = [slot for slot in slots if slot not in lost]
        dropped += len(lost)
    return written, carried, dropped


def extract(
    transformer: StyleTransformer, language: str, files: Mapping[str, str], slots: Sequence[Slot], bits: Sequence[int]
) -> tuple[bool, bool]:
    """Expected-message extraction over the stored slots: (BCH-decoded message matches `bits`, raw codeword matches).

    A slot whose site is missing or reads nothing yields a random bit; a slot whose rules raise yields no bit.
    """
    codeword = bch.encode(bits)
    extracted = []
    for slot in slots[: len(codeword)]:
        try:
            reading = read(transformer, language, files, slot)
        except Exception:
            continue
        extracted.append(random.choice([0, 1]) if reading is None else reading)
    return bch.decode(extracted) == list(bits), extracted == codeword


def flip(transformer: StyleTransformer, language: str, code: str, pair: str, index: int) -> str | None:
    """`code` with the one site rewritten to its other reading, or None when that site cannot be rewritten."""
    found = sites(transformer, WATERMARK_PAIRS[language][pair], code)
    if index >= len(found) or not found[index].usable:
        return None
    return apply_groups(code.encode("utf-8"), [found[index].group])[0].decode("utf-8")


# ---------------------------------------------------------------- directories (the counterparts of cllmark.directories)

SUPPORT = {"granularity": "node"}


def is_support(support) -> bool:
    """Whether a support file's content is the slot list of node granularity."""
    return isinstance(support, dict) and support.get("granularity") == "node"


def _write_support(directory, slots: Sequence[Slot], **extra) -> None:
    with open(Path(directory) / SUPPORT_FILE, "w", encoding="utf-8") as stream:
        json.dump({**SUPPORT, "slots": [list(slot) for slot in slots], **extra}, stream, ensure_ascii=False, indent=4)


def _read_slots(directory) -> list[Slot]:
    support = read_support(directory)
    if not is_support(support):
        raise ValueError(f"{directory} holds a file-granular analysis; analyze it with node granularity first")
    return [tuple(slot) for slot in support["slots"]]


def analyze_directory(directory, language: str, transformer: StyleTransformer | None = None) -> int:
    """Analyze a flat project directory, store its slots in its support file and return its capacity.

    The support file is {"granularity": "node", "slots": [[file, pair, site index], ...]}.
    """
    transformer = transformer or StyleTransformer(language)
    slots = analyze(transformer, language, load_project(directory))
    _write_support(directory, slots)
    return len(slots)


def embed_directory(
    directory, language: str, bits: Sequence[int], transformer: StyleTransformer | None = None
) -> list[str]:
    """Embed into the analyzed directory in place; its support then holds the slots that carry the codeword, indexed
    in the marked code, and the number of analysis slots repair dropped. Returns the names of the files rewritten."""
    transformer = transformer or StyleTransformer(language)
    slots = _read_slots(directory)
    files = load_project(directory, {name for name, _, _ in slots})
    written, carried, dropped = embed(transformer, language, files, slots, bits)
    _write_support(directory, carried, dropped=dropped)
    for name, code in written.items():
        write_source(Path(directory) / name, code)
    return sorted(written)


def extract_directory(
    directory, language: str, bits: Sequence[int], transformer: StyleTransformer | None = None
) -> tuple[bool, bool]:
    """Check the embedded directory for the codeword of `bits`: (message matches, raw codeword matches)."""
    transformer = transformer or StyleTransformer(language)
    slots = _read_slots(directory)[: bch.CODE_LENGTH]
    return extract(transformer, language, load_project(directory, {name for name, _, _ in slots}), slots, bits)
