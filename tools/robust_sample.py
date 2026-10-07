#!/usr/bin/env python3
"""Core sample of the robust watermark (docs/plans/2026-10-07-robust-watermark.md, v2-v4): 20 generated (embedded) and
20 hand-written (read unmarked) CodeNet files per language, both anchors, schemes s1/s2 with 4 and 8 bits.

Per generated file: embed, detect the known message, its single-bit neighbours and 8 far messages, blind decoding.
Per hand-written file: p-values of the known-message test under 50 random keys (randomised for the discrete tail, so
they are uniform under the null) and 10 blind decodings. Rows and per-cell summaries go to one TSV.

Usage:
  tools/robust_sample.py run OUT.tsv [--rule-sets legacy extended] [--pairs TABLE.json] [--jobs N]
  tools/robust_sample.py compare NAME=TSV [NAME=TSV ...]

`--pairs TABLE.json` (a `robust_calibrate.py --output X.json` table) replaces `cllmark/robust/stable_pairs.py` in this process and its workers (threshold experiments); the
benchmark always uses the committed table.
"""

import argparse
import glob
import importlib
import math
import os
import random
import statistics
import sys
import time
from collections import defaultdict
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

REPOSITORY = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPOSITORY))

LANGS = {
    "python": ("Python_G", "Python_H"),
    "c": ("C_G", "C_H"),
    "cpp": ("CPP_G", "CPP_H"),
    "javascript": ("JS_G", "JS_H"),
}
ANCHORS = ("tok", "struct")
CELLS = [(n, b) for n in ("s1", "s2") for b in (4, 8)]
NKEYS = 50
_T = {}


def transformer(rule_set, language):
    from cllmark.transform import StyleTransformer

    k = (rule_set, language)
    if k not in _T:
        _T[k] = StyleTransformer(language, rule_set=rule_set)
    return _T[k]


def pick(group, count=20):
    files = sorted(glob.glob(str(REPOSITORY / "external" / "codenet" / "dataset" / group / "*")))
    rng = random.Random(20261007)
    return sorted(rng.sample(files, count))


def row(**fields):
    return fields


def run_g(args):
    rule_set, language, path = args
    from cllmark.robust import Scheme, derive_key, derive_message, detect, embed
    from cllmark.robust.anchors import observe_counted
    from cllmark.source_io import read_source

    tr = transformer(rule_set, language)
    code = read_source(path)
    rows = []
    key = derive_key("core-sample")
    for anchor in ANCHORS:
        obs, errs = observe_counted(tr, language, {"f": code}, anchor, stability=True)
        sel = observe_counted(tr, language, {"f": code}, anchor, selected=True)[0]
        usable = [o for o in obs if o.usable]
        stable = [o for o in usable if o.stable]
        rows.append(
            row(
                section="capacity",
                rule_set=rule_set,
                language=language,
                group="G",
                selected=len(sel),
                selected_votes=len({o.key for o in sel}),
                file=path.rsplit("/", 1)[1],
                anchor=anchor,
                rule_errors=errs,
                sites=len(obs),
                usable=len(usable),
                stable=len(stable),
                votes_distinct=len({o.key for o in stable}),
            )
        )
        for name, bits in CELLS:
            sc = Scheme(name, bits, anchor)
            m = derive_message("core-sample", path, bits)
            t = time.time()
            r = embed(tr, language, {"f": code}, sc, key, m)
            marked = {"f": r.written.get("f", code)}
            d = detect(tr, language, marked, sc, key, m)
            nb = [[x ^ (j == i) for j, x in enumerate(m)] for i in range(bits)]
            dn = [detect(tr, language, marked, sc, key, other) for other in nb]
            far = [derive_message("core-sample-far", path + str(i), bits) for i in range(8)]
            far = [f for f in far if f != m]
            df = [detect(tr, language, marked, sc, key, other) for other in far]
            rows.append(
                row(
                    section="embed",
                    rule_set=rule_set,
                    language=language,
                    group="G",
                    file=path.rsplit("/", 1)[1],
                    anchor=anchor,
                    scheme=name,
                    bits=bits,
                    votes_planted=r.votes,
                    targeted=r.targeted_sites,
                    set=r.set_sites,
                    rounds=r.rounds,
                    changed=int(bool(r.written)),
                    det_votes=d.votes,
                    agree=d.agree,
                    log10_p_known=round(math.log10(max(d.p_known, 1e-300)), 2),
                    blind_ok=int(d.decoded == m),
                    log10_p_blind=round(math.log10(max(d.p_blind, 1e-300)), 2),
                    margin=round(d.margin, 2),
                    sel_agreement=round(r.selection_agreement, 3),
                    p_all_log10=round(math.log10(max(d.p_all, 1e-300)), 2),
                    nb_n=len(dn),
                    nb_le_1e3=sum(x.p_known <= 1e-3 for x in dn),
                    nb_all_le_1e3=sum(x.p_all <= 1e-3 for x in dn),
                    nb_le_05=sum(x.p_known <= 0.05 for x in dn),
                    far_n=len(df),
                    far_le_05=sum(x.p_known <= 0.05 for x in df),
                    rule_errors=d.errors,
                    unstable_selected=r.unstable_selected,
                    seconds=round(time.time() - t, 2),
                )
            )
    return rows, {}


def run_h(args):
    rule_set, language, path = args
    from cllmark.robust import Scheme, derive_key

    detect_mod = importlib.import_module("cllmark.robust.detect")
    from cllmark.source_io import read_source

    tr = transformer(rule_set, language)
    code = read_source(path)
    rows, ps = [], {}
    rng = random.Random(path)
    for anchor in ANCHORS:
        from cllmark.robust.anchors import observe_counted

        obs, errs = observe_counted(tr, language, {"f": code}, anchor, stability=True)
        sel = observe_counted(tr, language, {"f": code}, anchor, selected=True)[0]
        usable = [o for o in obs if o.usable]
        stable = [o for o in usable if o.stable]
        votes, _ = detect_mod.cast_votes(sel)
        rows.append(
            row(
                section="capacity",
                rule_set=rule_set,
                language=language,
                group="H",
                selected=len(sel),
                selected_votes=len({o.key for o in sel}),
                file=path.rsplit("/", 1)[1],
                anchor=anchor,
                rule_errors=errs,
                sites=len(obs),
                usable=len(usable),
                stable=len(stable),
                votes_distinct=len({o.key for o in stable}),
                det_votes=len(votes),
            )
        )
        for name, bits in CELLS:
            sc = Scheme(name, bits, anchor)
            values, blind_hits = [], 0
            for i in range(NKEYS):
                k = derive_key(f"null-{path}-{i}")
                m = [rng.getrandbits(1) for _ in range(bits)]
                res = detect_mod.score(sc, k, votes, m, blind=False)
                if name == "s1":  # p_known tests the tag votes only
                    tag = {v: b for v, b in votes.items() if detect_mod.role(k, sc, bytes.fromhex(v)) is None}
                    n_t, a_t = len(tag), detect_mod._agreement(k, sc, detect_mod.message_bytes(sc, m), tag)
                else:
                    n_t, a_t = res.votes, res.agree
                low, high = detect_mod.binomial_tail(n_t, a_t + 1), res.p_known
                assert high == detect_mod.binomial_tail(n_t, a_t)
                values.append(low + rng.random() * (high - low))
            for i in range(10):
                res = detect_mod.score(sc, derive_key(f"blind-{path}-{i}"), votes, None)
                blind_hits += res.p_blind <= 0.05
            ps[(anchor, name, bits)] = (values, blind_hits)
            rows.append(
                row(
                    section="null",
                    rule_set=rule_set,
                    language=language,
                    group="H",
                    file=path.rsplit("/", 1)[1],
                    anchor=anchor,
                    scheme=name,
                    bits=bits,
                    det_votes=len(votes),
                    null_mean_p=round(statistics.mean(values), 3),
                    null_le_05=sum(v <= 0.05 for v in values) / NKEYS,
                    blind_le_05=blind_hits / 10,
                )
            )
    return rows, ps


def ks(values):
    values = sorted(values)
    n = len(values)
    return max(max((i + 1) / n - v, v - i / n) for i, v in enumerate(values))


def mean(xs):
    xs = list(xs)
    return round(sum(xs) / len(xs), 3) if xs else ""


def use_pairs(path):
    """Worker initializer: read the stable-pair table from `path` instead of the committed one."""
    if path:
        from cllmark.robust import anchors

        anchors.STABLE_PAIRS_OVERRIDE = Path(path)
        anchors._stable_pairs.cache_clear()


def run(args):
    out, rule_sets = args.output, args.rule_sets
    use_pairs(args.pairs)
    jobs = []
    for rs in rule_sets:
        for lang, (g, h) in LANGS.items():
            jobs += [("g", (rs, lang, p)) for p in pick(g)] + [("h", (rs, lang, p)) for p in pick(h)]
    t = time.time()
    rows, pvals = [], defaultdict(list)
    blind = defaultdict(lambda: [0, 0])
    with ProcessPoolExecutor(max_workers=args.jobs, initializer=use_pairs, initargs=(args.pairs,)) as pool:
        futures = [(pool.submit(run_g if kind == "g" else run_h, a), kind, a) for kind, a in jobs]
        for done, (f, _kind, a) in enumerate(futures):
            r, ps = f.result()
            rows += r
            for (anchor, name, bits), (values, hits) in ps.items():
                pvals[(a[0], a[1], anchor, name, bits)] += values
                blind[(a[0], a[1], anchor, name, bits)][0] += hits
                blind[(a[0], a[1], anchor, name, bits)][1] += 10
            print(f"{done + 1}/{len(futures)} {time.time() - t:.0f}s", file=sys.stderr, flush=True)
    summary = []
    for rs in rule_sets:
        for lang in LANGS:
            for anchor in ANCHORS:
                cap = [
                    r
                    for r in rows
                    if r["section"] == "capacity" and (r["rule_set"], r["language"], r["anchor"]) == (rs, lang, anchor)
                ]
                for grp in "GH":
                    c = [r for r in cap if r["group"] == grp]
                    summary.append(
                        row(
                            section="summary_capacity",
                            rule_set=rs,
                            language=lang,
                            group=grp,
                            anchor=anchor,
                            files=len(c),
                            sites=mean(r["sites"] for r in c),
                            usable=mean(r["usable"] for r in c),
                            stable=mean(r["stable"] for r in c),
                            stable_frac=round(sum(r["stable"] for r in c) / max(sum(r["usable"] for r in c), 1), 3),
                            votes_distinct=mean(r["votes_distinct"] for r in c),
                            rule_errors=sum(r["rule_errors"] for r in c),
                            selected=mean(r["selected"] for r in c),
                            selected_votes=mean(r["selected_votes"] for r in c),
                            det_votes=mean(r.get("det_votes", 0) for r in c if "det_votes" in r) if grp == "H" else "",
                        )
                    )
                for name, bits in CELLS:
                    e = [
                        r
                        for r in rows
                        if r["section"] == "embed"
                        and (r["rule_set"], r["language"], r["anchor"], r["scheme"], r["bits"])
                        == (rs, lang, anchor, name, bits)
                    ]
                    p = pvals[(rs, lang, anchor, name, bits)]
                    hits, total = blind[(rs, lang, anchor, name, bits)]
                    lp = sorted(r["log10_p_known"] for r in e)
                    summary.append(
                        row(
                            section="summary_cell",
                            rule_set=rs,
                            language=lang,
                            anchor=anchor,
                            scheme=name,
                            bits=bits,
                            files=len(e),
                            votes_planted=mean(r["votes_planted"] for r in e),
                            targeted=mean(r["targeted"] for r in e),
                            set_rate=round(sum(r["set"] for r in e) / max(sum(r["targeted"] for r in e), 1), 3),
                            changed=mean(r["changed"] for r in e),
                            det_votes=mean(r["det_votes"] for r in e),
                            log10_p_known=lp[len(lp) // 2],
                            p_le_1e6=mean(r["log10_p_known"] <= -6 for r in e),
                            p_le_1e3=mean(r["log10_p_known"] <= -3 for r in e),
                            blind_ok=mean(r["blind_ok"] for r in e),
                            sel_agreement_mean=mean(r["sel_agreement"] for r in e),
                            sel_agreement_p10=sorted(r["sel_agreement"] for r in e)[len(e) // 10],
                            sel_agreement_min=min(r["sel_agreement"] for r in e),
                            sel_agreement_ge_09=mean(r["sel_agreement"] >= 0.9 for r in e),
                            nb_tests=sum(r["nb_n"] for r in e),
                            nb_le_1e3=sum(r["nb_le_1e3"] for r in e),
                            nb_le_05=sum(r["nb_le_05"] for r in e),
                            nb_all_le_1e3=sum(r["nb_all_le_1e3"] for r in e),
                            far_tests=sum(r["far_n"] for r in e),
                            far_le_05=sum(r["far_le_05"] for r in e),
                            null_files=len(p) // NKEYS,
                            null_ks=round(ks(p), 4) if p else "",
                            null_ks_crit=round(1.63 / math.sqrt(len(p)), 4) if p else "",
                            null_le_05=mean(v <= 0.05 for v in p),
                            null_le_01=mean(v <= 0.01 for v in p),
                            blind_fp_le_05=round(hits / total, 3) if total else "",
                        )
                    )
    cols = []
    for r in rows + summary:
        for k in r:
            if k not in cols:
                cols.append(k)
    with open(out, "w") as f:
        f.write("\t".join(cols) + "\n")
        for r in rows + summary:
            f.write("\t".join(str(r.get(c, "")) for c in cols) + "\n")
    print("done", time.time() - t, file=sys.stderr)


CELL_COLUMNS = ("log10_p_known", "p_le_1e6", "blind_ok")


def load_cells(path):
    import csv

    with open(path) as stream:
        rows = list(csv.DictReader(stream, delimiter="\t"))
    cells = defaultdict(list)
    for r in rows:
        if r["section"] == "summary_cell":
            cells[(r["rule_set"], r["anchor"], r["scheme"], r["bits"])].append(r)
    return rows, cells


def compare(args):
    """Per cell (rule set, anchor, scheme, bits; mean over the 4 languages): median log10 p_known, share p <= 1e-6,
    blind decoding rate and its worst language; then the null checks and the selection statistics per input."""
    named = [item.split("=", 1) for item in args.tsv]
    data = {name: load_cells(path) for name, path in named}
    names = [name for name, _ in named]
    keys = sorted(set.intersection(*(set(cells) for _, cells in data.values())))
    print("cell\t" + "\t".join(f"{c} ({'/'.join(names)})" for c in (*CELL_COLUMNS, "worst_blind")))
    for key in keys:
        values = []
        for column in CELL_COLUMNS:
            values.append(
                " / ".join(str(round(statistics.mean(float(x[column]) for x in data[n][1][key]), 3)) for n in names)
            )
        values.append(" / ".join(str(min(float(x["blind_ok"]) for x in data[n][1][key])) for n in names))
        print(" ".join(key) + "\t" + "\t".join(values))
    print()
    for scheme in ("s1", "s2"):
        for n in names:
            c = [x for k, v in data[n][1].items() if k[2] == scheme for x in v]
            print(
                f"{scheme} {n}: neighbours p<=1e-3 {sum(int(x['nb_le_1e3']) for x in c)}, p<=0.05 "
                f"{sum(int(x['nb_le_05']) for x in c)}/{sum(int(x['nb_tests']) for x in c)}; far p<=0.05 "
                f"{sum(int(x['far_le_05']) for x in c)}/{sum(int(x['far_tests']) for x in c)}; null KS max "
                f"{max(float(x['null_ks']) for x in c)} (crit {min(float(x['null_ks_crit']) for x in c)}); "
                f"P(p<=0.05) {min(float(x['null_le_05']) for x in c)}-{max(float(x['null_le_05']) for x in c)}"
            )
    print()
    for n in names:
        for anchor in ("tok", "struct"):
            e = [r for r in data[n][0] if r["section"] == "embed" and r["anchor"] == anchor]
            agreement = sorted(float(r["sel_agreement"]) for r in e)
            unstable = [int(r["unstable_selected"]) for r in e if r.get("unstable_selected") not in (None, "")]
            print(
                f"{n} {anchor}: selection agreement mean {statistics.mean(agreement):.3f} p10 "
                f"{agreement[len(agreement) // 10]} >=0.9 {statistics.mean(a >= 0.9 for a in agreement):.3f}; votes planted "
                f"{statistics.mean(int(r['votes_planted']) for r in e):.1f}, detected {statistics.mean(int(r['det_votes']) for r in e):.1f}; "
                f"unstable selected {statistics.mean(unstable) if unstable else '-'}; set rate "
                f"{sum(int(r['set']) for r in e) / sum(int(r['targeted']) for r in e):.3f}"
            )


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    commands = parser.add_subparsers(dest="command", required=True)
    one = commands.add_parser("run")
    one.add_argument("output")
    one.add_argument("--rule-sets", nargs="+", default=["legacy", "extended"])
    one.add_argument("--pairs", default="")
    one.add_argument("--jobs", type=int, default=os.cpu_count() or 1)
    one.set_defaults(handler=run)
    other = commands.add_parser("compare")
    other.add_argument("tsv", nargs="+", help="NAME=PATH")
    other.set_defaults(handler=compare)
    args = parser.parse_args(argv)
    args.handler(args)


if __name__ == "__main__":
    main()
