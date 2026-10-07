#!/usr/bin/env python3
"""Cross-variant report of the robust-watermark runs (docs/plans/2026-10-07-robust-watermark.md, section 5).

Usage: python tools/robust_report.py RUN_DIR [RUN_DIR ...] --output PATH.md

Reads `manifest.json` and `rows.jsonl` of each run (one variant per run: scheme, bits and anchor come from the config's
`robust` section) and writes a Markdown report plus the same data as JSON next to it. Rows are the rows of
`benchmarks/robust_engine.py`; fields a row lacks (harness errors, units that were not embedded) are skipped.

Strata. `codenet`: the function-level CodeNet groups (generated = positives, hand-written = the null hypothesis, read
unmarked). `projects`: the generated project-level groups (positives; their nulls are the hand-written units of the
same run, see section 4). `js_repos`: hand-written repositories (null only). `stress`: the group that is embedded to test
that repository tests still pass; it takes part in the functional table only, never in detection statistics.

Decisions. A robust scheme decides at each `alpha` of its config (p of the known message <= alpha; blind: the decoded
message is the true one and its p <= alpha). BCH baselines decide once ("match": the legacy expected-message
extraction). Rates have the denominators named in the tables; attacks that did not change a unit are not counted in
that attack's rates (the applied share is shown).
"""

import argparse
import json
import statistics
import sys
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict
from pathlib import Path

TESTED = {"PASS", "FAIL", "COMPILE_ERROR", "COMPILE_TIMEOUT", "TIMEOUT"}
STRATA = ("codenet", "projects", "js_repos", "stress")
LANGUAGE_ORDER = {"python": 0, "c": 1, "cpp": 2, "javascript": 3}
BINS = (("<10", 0, 10), ("10-30", 10, 30), ("30-100", 30, 100), (">=100", 100, float("inf")))
CDF_POINTS = ("1e-06", "1e-05", "0.0001", "0.001", "0.01", "0.05", "0.1", "0.25", "0.5")
ATTACK_ORDER = [
    "flip_0.1",
    "flip_0.2",
    "flip_0.3",
    "normalize_1",
    "normalize_3",
    "normalize_all",
    "delete_0.25",
    "delete_0.5",
    "insert_1",
    "rename",
    "reformat",
    "reorder",
    "combo",
]
BCH = "match"


# ------------------------------------------------------------------------------------------------ loading


def variant_label(config):
    section = config.get("robust") or {}
    scheme = section.get("scheme", "?")
    if scheme.startswith("bch"):
        return scheme
    return f"{scheme}-{section.get('bits', 4)}-{section.get('anchor', 'tok')}"


def decision_names(config):
    section = config.get("robust") or {}
    if str(section.get("scheme", "")).startswith("bch"):
        return [BCH]
    return [f"{a:g}" for a in section.get("alpha", [1e-3, 1e-6])]


def load_run(directory):
    directory = Path(directory)
    manifest = json.loads((directory / "manifest.json").read_text())
    config = manifest.get("config", {})
    if "robust" not in config:
        raise ValueError(f"{directory} is not a robust-watermark run")
    rows = [json.loads(line) for line in (directory / "rows.jsonl").read_text(encoding="utf-8").splitlines() if line]
    return {
        "directory": str(directory),
        "run_id": manifest.get("run_id"),
        "variant": variant_label(config),
        "scheme": config["robust"]["scheme"],
        "decisions": decision_names(config),
        "bits": config["robust"].get("bits", 4),
        "full": manifest.get("full"),
        "source": (manifest.get("source_fingerprint") or "")[:8],
        "rows": rows,
    }


# ------------------------------------------------------------------------------------------------ helpers


def rate(numerator, denominator):
    return numerator / denominator if denominator else None


def mean(values):
    values = list(values)
    return statistics.fmean(values) if values else None


def median(values):
    values = list(values)
    return statistics.median(values) if values else None


def get(value, *path):
    for key in path:
        if not isinstance(value, dict) or key not in value:
            return None
        value = value[key]
    return value


def wilson_upper(successes, trials, z=1.96):
    """Upper end of the Wilson 95% interval of a rate (the usual bound when nothing was observed)."""
    if not trials:
        return None
    p = successes / trials
    centre = p + z * z / (2 * trials)
    spread = z * ((p * (1 - p) / trials + z * z / (4 * trials * trials)) ** 0.5)
    return min(1.0, (centre + spread) / (1 + z * z / trials))


def stratum(row):
    if row["cohort"].endswith("_stress") or row["role"] not in ("generated", "human"):
        return "stress"
    if row["level"] == "project":
        return "projects" if row["role"] == "generated" else "js_repos"
    return "codenet"


def usable(rows):
    return [row for row in rows if row.get("status") == "ok" and isinstance(row.get("robust"), dict)]


def positives(rows):
    return [r for r in usable(rows) if r.get("embedded") and r["role"] == "generated" and stratum(r) != "stress"]


def nulls(rows):
    return [r for r in usable(rows) if not r.get("embedded") and r["role"] == "human" and "original" in r["robust"]]


def decided(reading, name):
    return bool(get(reading, "decision", name))


def blind(reading, name):
    return bool(get(reading, "blind", name))


def auc(positive, negative):
    """P[p_pos < p_null] + half the ties: the area under the ROC curve of "small p means marked"."""
    positive = [p for p in positive if p is not None]
    negative = sorted(p for p in negative if p is not None)
    if not positive or not negative:
        return None
    score = 0.0
    for p in positive:
        score += (
            len(negative) - bisect_right(negative, p) + 0.5 * (bisect_right(negative, p) - bisect_left(negative, p))
        )
    return score / (len(positive) * len(negative))


def message_text(value, bits):
    return None if value is None else format(value, f"0{bits}b")


def capacity_bin(votes):
    for name, low, high in BINS:
        if low <= votes < high:
            return name
    return BINS[-1][0]


def group_key(row):
    return (stratum(row), row["language"], row["cohort"])


def ordered(groups):
    return sorted(
        groups.items(), key=lambda item: (STRATA.index(item[0][0]), LANGUAGE_ORDER.get(item[0][1], 9), item[0][2])
    )


# ------------------------------------------------------------------------------------------------ analysis


def detection_rates(rows, decisions, version="marked"):
    """Decision rates of the readings `version` of `rows`: known message, blind (robust schemes only), the share of
    units whose decoded message is the true one and the mean share of correct bits."""
    pairs = [(r, get(r, "robust", version)) for r in rows]
    pairs = [(r, x) for r, x in pairs if x]
    readings = [x for _, x in pairs]
    keyed = any("blind" in x for x in readings)
    decoded = [(r["robust"]["message"], x["decoded"]) for r, x in pairs if x.get("decoded")]
    return {
        "n": len(readings),
        "known": {name: rate(sum(decided(x, name) for x in readings), len(readings)) for name in decisions},
        "blind": {
            name: rate(sum(blind(x, name) for x in readings), len(readings)) if keyed else None for name in decisions
        },
        "decoded_correct": rate(sum(x.get("decoded") == r["robust"]["message"] for r, x in pairs), len(readings)),
        "bit_accuracy": mean(
            sum(a == b for a, b in zip(got, message, strict=False)) / len(message) for message, got in decoded
        ),
        "errors": sum("error" in x for x in readings),
    }


def sweep_rates(rows, versions, decisions, bits, exclude_true=False):
    """Rates over the all-messages sweeps of the readings `versions(row)` yields: per decision the share of
    (unit, message) pairs accepted, the share of units that accept at least one message, the busiest single message and
    the empirical CDF of the p-values at the fixed ladder of thresholds."""
    totals = dict.fromkeys(decisions, 0)
    units = dict.fromkeys(decisions, 0)
    per_message = {name: Counter() for name in decisions}
    pairs, n = 0, 0
    cdf = Counter()
    for row in rows:
        for reading in versions(row):
            sweep = get(reading, "sweep")
            if not sweep:
                continue
            n += 1
            true = to_int(row["robust"]["message"])
            # robust sweeps of marked code already leave the true message out; the BCH sweep is just the decoded message
            pairs += sweep["messages"] - (1 if exclude_true and BCH in decisions else 0)
            for name in decisions:
                hits = [m for m in sweep["hits"].get(name, []) if not (exclude_true and m == true)]
                totals[name] += len(hits)
                units[name] += bool(hits)
                per_message[name].update(hits)
            for point in CDF_POINTS:
                cdf[point] += sweep.get("cdf", {}).get(point, 0)
    result = {"n": n, "pairs": pairs, "decisions": {}}
    for name in decisions:
        top = per_message[name].most_common(1)
        result["decisions"][name] = {
            "pair_rate": rate(totals[name], pairs),
            "unit_rate": rate(units[name], n),
            "max_message": message_text(top[0][0], bits) if top else None,
            "max_message_rate": rate(top[0][1], n) if top else None,
        }
    result["cdf"] = {point: rate(cdf[point], pairs) for point in CDF_POINTS} if cdf else {}
    return result


def to_int(bits):
    return int("".join(str(b) for b in bits), 2)


def analyse_run(run):
    rows, decisions, bits, variant = run["rows"], run["decisions"], run["bits"], run["variant"]
    out = {"variant": variant, "run_id": run["run_id"], "scheme": run["scheme"], "bits": bits, "decisions": decisions}
    ok = [r for r in rows if r.get("status") == "ok"]
    out["units"] = {"total": len(rows), "ok": len(ok), "harness_errors": len(rows) - len(ok)}
    out["capacity"], out["embedding"], out["detection"], out["null"], out["cross"], out["attacks"] = (
        [],
        [],
        [],
        [],
        [],
        [],
    )
    groups = defaultdict(list)
    for row in ok:
        groups[group_key(row)].append(row)
    for (kind, language, cohort), group in ordered(groups):
        capacities = [get(r, "robust", "capacity") or {} for r in group]
        votes = [c.get("votes", 0) for c in capacities]
        out["capacity"].append(
            {
                "stratum": kind,
                "language": language,
                "cohort": cohort,
                "units": len(group),
                "usable_median": median(c.get("usable", 0) for c in capacities),
                "votes_median": median(votes),
                "votes_mean": mean(votes),
                "stable_share": rate(
                    sum(c.get("stable", 0) for c in capacities), sum(c.get("usable", 0) for c in capacities)
                )
                if any("stable" in c for c in capacities)
                else None,
                "bins": {name: sum(low <= v < high for v in votes) for name, low, high in BINS},
            }
        )
        embedded = [r for r in group if r.get("embedded")]
        if embedded:
            before = [r for r in embedded if get(r, "utility_before", "status") in TESTED]
            pairs = [r for r in before if get(r, "utility_after", "status") in TESTED]
            passed = [r for r in pairs if r["utility_before"]["status"] == "PASS"]
            regressions = [r["id"] for r in passed if r["utility_after"]["status"] != "PASS"]
            embeds = [get(r, "robust", "embed") or {} for r in embedded]
            targeted = sum(e.get("targeted_sites", 0) for e in embeds)
            syntax_before = sum(sum(r["syntax_before"].values()) for r in embedded)
            syntax_kept = sum(
                sum(ok_ and r["syntax_after"].get(name, False) for name, ok_ in r["syntax_before"].items())
                for r in embedded
            )
            out["embedding"].append(
                {
                    "stratum": kind,
                    "language": language,
                    "cohort": cohort,
                    "units": len(group),
                    "embedded": len(embedded),
                    "set_rate": rate(sum(e.get("set_sites", 0) for e in embeds), targeted) if targeted else None,
                    "rounds_mean": mean(e["rounds"] for e in embeds if "rounds" in e),
                    "changed_files_median": median(e.get("changed_files", 0) for e in embeds),
                    "changed_lines_median": median(e.get("changed_lines", 0) for e in embeds),
                    "embedding_ms_median": median(r["embedding_ms"] for r in embedded if "embedding_ms" in r),
                    "syntax_retained": rate(syntax_kept, syntax_before),
                    "functional_tested": len(pairs),
                    "before_pass": len(passed),
                    "regressions": len(regressions),
                    "regression_ids": regressions[:20],
                    "preservation": rate(len(passed) - len(regressions), len(passed)),
                }
            )
        if kind in ("codenet", "projects") and embedded and group[0]["role"] == "generated":
            rates = detection_rates(embedded, decisions)
            by_bin = {}
            for name, low, high in BINS:
                binned = [r for r in embedded if low <= (get(r, "robust", "capacity", "votes") or 0) < high]
                by_bin[name] = {
                    "n": len(binned),
                    "known": {
                        d: rate(sum(decided(get(r, "robust", "marked"), d) for r in binned), len(binned))
                        for d in decisions
                    },
                }
            peers = [r for r in nulls(rows) if r["language"] == language and stratum(r) == "codenet"]
            out["detection"].append(
                {
                    "stratum": kind,
                    "language": language,
                    "cohort": cohort,
                    "units": len(group),
                    "eligible_share": rate(len(embedded), len(group)),
                    **rates,
                    "by_capacity": by_bin,
                    "auc": auc(
                        [get(r, "robust", "marked", "p_known") for r in embedded],
                        [get(r, "robust", "original", "p_known") for r in peers],
                    ),
                    "elapsed_ms_median": median(get(r, "robust", "marked", "elapsed_ms") or 0 for r in embedded),
                }
            )
            cross = sweep_rates(embedded, lambda r: [get(r, "robust", "marked")], decisions, bits, exclude_true=True)
            if cross["n"]:
                out["cross"].append({"stratum": kind, "language": language, "cohort": cohort, **cross})
    # nulls: hand-written units read as they are, and the unmarked code of the generated units (a second null)
    null_groups = defaultdict(list)
    for row in nulls(rows):
        null_groups[group_key(row)].append(row)
    for (kind, language, cohort), group in ordered(null_groups):
        out["null"].append(
            {
                "source": "hand-written",
                "stratum": kind,
                "language": language,
                "cohort": cohort,
                "units": len(group),
                "capacity_votes_median": median(get(r, "robust", "capacity", "votes") or 0 for r in group),
                **null_row(group, decisions, bits),
            }
        )
    generated = defaultdict(list)
    for row in positives(rows):
        generated[group_key(row)].append(row)
    for (kind, language, cohort), group in ordered(generated):
        out["null"].append(
            {
                "source": "generated, unmarked",
                "stratum": kind,
                "language": language,
                "cohort": cohort,
                "units": len(group),
                "capacity_votes_median": median(get(r, "robust", "capacity", "votes") or 0 for r in group),
                **null_row(group, decisions, bits),
            }
        )
    out["attacks"] = attack_rows(rows, decisions, bits)
    out["auc_attacks"] = attack_auc(rows)
    out["readings_with_errors"] = sum(
        "error" in x
        for r in usable(rows)
        for x in [
            get(r, "robust", "original"),
            get(r, "robust", "marked"),
            *(r["robust"].get("attacks") or {}).values(),
        ]
        if isinstance(x, dict)
    )
    out["headline"] = headline(out, rows)
    return out


def null_row(group, decisions, bits):
    known = detection_rates(group, decisions, version="original")
    sweeps = sweep_rates(group, lambda r: [get(r, "robust", "original")], decisions, bits)
    return {
        "known": known["known"],
        "known_upper95": {
            name: wilson_upper(round(known["known"][name] * known["n"]), known["n"]) if known["n"] else None
            for name in decisions
        },
        "known_hits": {name: round((known["known"][name] or 0) * known["n"]) for name in decisions},
        "read": known["n"],
        "sweep": sweeps,
    }


def attack_names(rows):
    seen = {name for r in usable(rows) for name in (r["robust"].get("attacks") or {})}
    return [n for n in ATTACK_ORDER if n in seen] + sorted(seen - set(ATTACK_ORDER))


def attack_rows(rows, decisions, bits):
    result = []
    names = attack_names(rows)
    for kind in ("codenet", "projects"):
        pos = [r for r in positives(rows) if stratum(r) == kind]
        null = [r for r in nulls(rows) if stratum(r) == "codenet"] if kind == "codenet" else []
        null += [r for r in nulls(rows) if stratum(r) == "js_repos"] if kind == "projects" else []
        for name in names:
            applied = [r for r in pos if get(r, "robust", "attacks", name, "changed")]
            readings = [get(r, "robust", "attacks", name) for r in applied]
            applied_null = [r for r in null if get(r, "robust", "attacks", name, "changed")]
            null_readings = [get(r, "robust", "attacks", name) for r in applied_null]
            anchors = [get(x, "anchors") for x in readings if get(x, "anchors")]
            result.append(
                {
                    "stratum": kind,
                    "attack": name,
                    "positives": len(pos),
                    "applied": len(applied),
                    "applied_share": rate(len(applied), len(pos)),
                    "tpr": {d: rate(sum(decided(x, d) for x in readings), len(readings)) for d in decisions},
                    "blind": {
                        d: rate(sum(blind(x, d) for x in readings), len(readings))
                        if any("blind" in x for x in readings)
                        else None
                        for d in decisions
                    },
                    "decoded_correct": rate(
                        sum(x.get("decoded") == r["robust"]["message"] for r, x in zip(applied, readings, strict=True)),
                        len(readings),
                    ),
                    "errors": sum("error" in x for x in readings),
                    "anchor_retained": mean(a["retained"] for a in anchors if a.get("retained") is not None),
                    "anchor_survival": mean(a["survival"] for a in anchors if a.get("survival") is not None),
                    "null_units": len(null),
                    "null_applied": len(applied_null),
                    "null_fpr": {
                        d: rate(sum(decided(x, d) for x in null_readings), len(null_readings)) for d in decisions
                    },
                    "null_sweep": sweep_rates(
                        applied_null, lambda r, name=name: [get(r, "robust", "attacks", name)], decisions, bits
                    ),
                    "null_anchor_survival": mean(
                        get(x, "anchors", "survival")
                        for x in null_readings
                        if get(x, "anchors", "survival") is not None
                    ),
                }
            )
    return result


def attack_auc(rows):
    result = {}
    pos = [r for r in positives(rows) if stratum(r) == "codenet"]
    null = [r for r in nulls(rows) if stratum(r) == "codenet"]
    result["none"] = auc(
        [get(r, "robust", "marked", "p_known") for r in pos], [get(r, "robust", "original", "p_known") for r in null]
    )
    for name in attack_names(rows):
        result[name] = auc(
            [get(r, "robust", "attacks", name, "p_known") for r in pos if get(r, "robust", "attacks", name, "changed")],
            [
                get(r, "robust", "attacks", name, "p_known")
                for r in null
                if get(r, "robust", "attacks", name, "changed")
            ],
        )
    return result


def headline(analysis, rows):
    """One line per variant for the comparison table: the CodeNet strata pooled over languages."""
    decisions = analysis["decisions"]
    pos = [r for r in positives(rows) if stratum(r) == "codenet"]
    null = [r for r in nulls(rows) if stratum(r) == "codenet"]
    clean = detection_rates(pos, decisions)
    null_read = null_row(null, decisions, analysis["bits"]) if null else None
    attacks = [a for a in analysis["attacks"] if a["stratum"] == "codenet"]
    first = decisions[0]
    mean_tpr = mean(a["tpr"][first] for a in attacks if a["tpr"][first] is not None and a["attack"] != "normalize_all")
    worst = min(
        (a for a in attacks if a["tpr"][first] is not None and a["attack"] != "normalize_all"),
        key=lambda a: a["tpr"][first],
        default=None,
    )
    normalize_all = next((a for a in attacks if a["attack"] == "normalize_all"), None)
    embedding = [e for e in analysis["embedding"] if e["stratum"] == "codenet"]
    return {
        "positives": len(pos),
        "nulls": len(null),
        "votes_median": median(get(r, "robust", "capacity", "votes") or 0 for r in pos),
        "tpr_clean": clean["known"],
        "blind_clean": clean["blind"],
        "decoded_correct": clean["decoded_correct"],
        "null_known": null_read["known"] if null_read else None,
        "null_pair_rate": {d: null_read["sweep"]["decisions"][d]["pair_rate"] for d in decisions}
        if null_read
        else None,
        "null_max_message": {
            d: (
                null_read["sweep"]["decisions"][d]["max_message"],
                null_read["sweep"]["decisions"][d]["max_message_rate"],
            )
            for d in decisions
        }
        if null_read
        else None,
        "auc": analysis["auc_attacks"].get("none"),
        "mean_attack_tpr": mean_tpr,
        "worst_attack": (worst["attack"], worst["tpr"][first]) if worst else None,
        "normalize_all_tpr": normalize_all["tpr"][first] if normalize_all else None,
        "preservation": rate(
            sum(e["before_pass"] - e["regressions"] for e in embedding), sum(e["before_pass"] for e in embedding)
        ),
        "regressions": sum(e["regressions"] for e in embedding),
        "harness_errors": analysis["units"]["harness_errors"],
    }


def analyse(runs):
    report = {"runs": [], "variants": {}}
    for run in runs:
        analysis = analyse_run(run)
        report["runs"].append(
            {
                "variant": run["variant"],
                "run_id": run["run_id"],
                "units": len(run["rows"]),
                "full": run["full"],
                "source": run["source"],
            }
        )
        report["variants"][run["variant"]] = analysis
    return report


# ------------------------------------------------------------------------------------------------ rendering


def pct(value, digits=1):
    return "N/A" if value is None else f"{value * 100:.{digits}f}%"


def sci(value):
    return "N/A" if value is None else f"{value:.2e}"


def num(value, digits=1):
    return "N/A" if value is None else f"{value:.{digits}f}"


def table(headers, rows):
    lines = ["| " + " | ".join(headers) + " |", "|" + "|".join("---" for _ in headers) + "|"]
    lines += ["| " + " | ".join(str(cell) for cell in row) + " |" for row in rows]
    return lines


def per(values, names, formatter=pct):
    return " / ".join(formatter(values.get(name)) for name in names)


def render(report):
    variants = report["variants"]
    lines = ["# Robust watermark evaluation report", ""]
    lines += [
        f"- {run['variant']}: run `{run['run_id']}`, {run['units']} units, full={run['full']}, source `{run['source']}`"
        for run in report["runs"]
    ]
    lines += [
        "",
        "Decisions: robust schemes decide at alpha 1e-3 and 1e-6 (shown `a / b`); BCH baselines decide once (`match`). "
        "Hand-written groups are the null hypothesis; the `js_repos_stress` group is embedded only to run the repository "
        "tests and is excluded from detection statistics.",
        "",
        "## 1. Headline (CodeNet, all languages pooled)",
        "",
    ]
    rows = []
    for name, v in variants.items():
        h = v["headline"]
        d = v["decisions"]
        max_message = (
            " / ".join(f"{m} {pct(r)}" for m, r in (h["null_max_message"] or {}).values())
            if h["null_max_message"]
            else "N/A"
        )
        rows.append(
            [
                name, h["positives"], h["nulls"], num(h["votes_median"]), per(h["tpr_clean"], d), per(h["blind_clean"], d),
                pct(h["decoded_correct"]), per(h["null_known"] or {}, d), per(h["null_pair_rate"] or {}, d, sci), max_message,
                num(h["auc"], 4), pct(h["mean_attack_tpr"]), "N/A" if not h["worst_attack"] else f"{h['worst_attack'][0]} {pct(h['worst_attack'][1])}",
                pct(h["normalize_all_tpr"]), pct(h["preservation"]), h["regressions"], h["harness_errors"],
            ]
        )  # fmt: skip
    lines += table(
        [
            "variant", "positives", "nulls", "votes med", "TPR clean", "blind TPR", "msg correct", "null FPR (known m)",
            "null FPR (all m, per pair)", "busiest message (null)", "AUC", "mean TPR under attacks (no normalize_all)",
            "worst attack", "normalize_all TPR", "functional preservation", "regressions", "harness errors",
        ],
        rows,
    )  # fmt: skip
    lines += ["", "## 2. Capacity", ""]
    rows = []
    for name, v in variants.items():
        for c in v["capacity"]:
            rows.append(
                [
                    name, c["stratum"], c["cohort"], c["units"], num(c["usable_median"]), num(c["votes_median"]),
                    num(c["votes_mean"]), pct(c["stable_share"]), *(c["bins"][b[0]] for b in BINS),
                ]
            )  # fmt: skip
    lines += table(
        ["variant", "stratum", "group", "units", "usable med", "votes med", "votes mean", "stable/usable"]
        + [f"votes {b[0]}" for b in BINS],
        rows,
    )
    lines += ["", "Votes are sites with distinct anchor keys among the usable, stable ones (BCH: usable slots).", ""]
    lines += ["## 3. Embedding and functional preservation", ""]
    rows = []
    for name, v in variants.items():
        for e in v["embedding"]:
            rows.append(
                [
                    name, e["stratum"], e["cohort"], e["embedded"], pct(e["set_rate"]), num(e["rounds_mean"], 2),
                    num(e["changed_files_median"]), num(e["changed_lines_median"]), pct(e["syntax_retained"]),
                    e["functional_tested"], e["before_pass"], e["regressions"], pct(e["preservation"]),
                    num(e["embedding_ms_median"], 1),
                ]
            )  # fmt: skip
    lines += table(
        [
            "variant", "stratum", "group", "embedded", "set rate", "rounds", "files changed (med)", "lines changed (med)",
            "syntax kept", "tested pairs", "before pass", "regressions", "preserved", "embed ms (med)",
        ],
        rows,
    )  # fmt: skip
    regressions = [
        (n, e["cohort"], e["regression_ids"]) for n, v in variants.items() for e in v["embedding"] if e["regressions"]
    ]
    lines += ["", f"Groups with regressions: {len(regressions)}."]
    lines += [f"- {n} {cohort}: {', '.join(ids)}" for n, cohort, ids in regressions]
    lines += ["", "## 4. Detection of marked code (no attack)", ""]
    rows = []
    for name, v in variants.items():
        d = v["decisions"]
        for e in v["detection"]:
            rows.append(
                [
                    name, e["cohort"], e["n"], pct(e["eligible_share"]), per(e["known"], d), per(e["blind"], d),
                    pct(e["decoded_correct"]), pct(e["bit_accuracy"]), num(e["auc"], 4), e["errors"],
                ]
            )  # fmt: skip
    lines += table(
        [
            "variant",
            "group",
            "read",
            "embedded share",
            "TPR known m",
            "TPR blind",
            "msg correct",
            "bit accuracy",
            "AUC",
            "errors",
        ],
        rows,
    )
    lines += ["", "TPR by capacity (votes) bin, first decision:", ""]
    rows = []
    for name, v in variants.items():
        for e in v["detection"]:
            first = v["decisions"][0]
            rows.append(
                [
                    name,
                    e["cohort"],
                    *(f"{pct(e['by_capacity'][b[0]]['known'][first])} ({e['by_capacity'][b[0]]['n']})" for b in BINS),
                ]
            )
    lines += table(["variant", "group", *(f"votes {b[0]}" for b in BINS)], rows)
    lines += ["", "## 5. Null hypothesis (unmarked code)", ""]
    lines += [
        "`known m`: one random message per unit (the unit's own), rate of units accepted; `all m`: share of (unit, message) "
        "pairs accepted over every message of the sweep; `unit any`: units that accept at least one message; `busiest`: "
        "the message accepted for most units. A calibrated robust scheme has known-m and all-m rates at or below alpha. "
        "The BCH baselines have no alpha: their `known m` is the legacy false-match rate of one message and `busiest` shows "
        "the message the code decodes to most often.",
        "",
    ]
    rows = []
    for name, v in variants.items():
        d = v["decisions"]
        for n in v["null"]:
            decisions = n["sweep"]["decisions"]
            rows.append(
                [
                    name, n["source"], n["cohort"], n["read"], num(n["capacity_votes_median"]), per(n["known"], d),
                    per(n["known_upper95"], d), per({k: x["pair_rate"] for k, x in decisions.items()}, d, sci),
                    per({k: x["unit_rate"] for k, x in decisions.items()}, d),
                    " / ".join(f"{x['max_message']} {pct(x['max_message_rate'])}" for x in decisions.values()),
                ]
            )  # fmt: skip
    lines += table(
        [
            "variant",
            "null",
            "group",
            "read",
            "votes med",
            "FPR known m",
            "95% upper bound",
            "all m (pair)",
            "unit any",
            "busiest message",
        ],
        rows,
    )
    lines += ["", "Empirical CDF of the p-values against all messages (expected: equal to the threshold):", ""]
    rows = []
    for name, v in variants.items():
        for n in v["null"]:
            cdf = n["sweep"]["cdf"]
            if cdf:
                rows.append([name, n["source"], n["cohort"], *(sci(cdf.get(point)) for point in CDF_POINTS)])
    lines += table(["variant", "null", "group", *(f"p<={point}" for point in CDF_POINTS)], rows)
    lines += ["", "## 6. Wrong messages on marked code (cross-message acceptance)", ""]
    lines += [
        "Marked code tested against every other message: share of (unit, wrong message) pairs accepted, and units that "
        "accept at least one wrong message. For BCH the only candidate is the decoded message, so a unit counts when it "
        "decodes to a message other than the embedded one.",
        "",
    ]
    rows = []
    for name, v in variants.items():
        d = v["decisions"]
        for c in v["cross"]:
            decisions = c["decisions"]
            rows.append(
                [
                    name, c["cohort"], c["n"], per({k: x["pair_rate"] for k, x in decisions.items()}, d, sci),
                    per({k: x["unit_rate"] for k, x in decisions.items()}, d),
                ]
            )  # fmt: skip
    lines += table(["variant", "group", "units", "accepted pairs", "units with a wrong acceptance"], rows)
    lines += ["", "## 7. Attacks", ""]
    lines += [
        "Rates are over the units the attack changed (applied share first). TPR and blind TPR are on marked generated code; "
        "FPR on the attacked hand-written code (known m / all messages, per pair); anchor columns are the share of embedded "
        "keys still present after the attack and the share of attacked-code keys that are embedded ones.",
        "",
    ]
    rows = []
    for name, v in variants.items():
        d = v["decisions"]
        for a in v["attacks"]:
            rows.append(
                [
                    name, a["stratum"], a["attack"], f"{a['applied']}/{a['positives']}", per(a["tpr"], d), per(a["blind"], d),
                    pct(a["decoded_correct"]), pct(a["anchor_retained"]), pct(a["anchor_survival"]),
                    f"{a['null_applied']}/{a['null_units']}", per(a["null_fpr"], d),
                    per({k: x["pair_rate"] for k, x in a["null_sweep"]["decisions"].items()}, d, sci), a["errors"],
                ]
            )  # fmt: skip
    lines += table(
        [
            "variant", "stratum", "attack", "applied", "TPR known m", "TPR blind", "msg correct", "anchors retained",
            "anchor survival", "null applied", "FPR known m", "FPR all m", "errors",
        ],
        rows,
    )  # fmt: skip
    lines += ["", "AUC (CodeNet, p-values of known-message detection, marked vs hand-written) under each attack:", ""]
    names = ["none", *ATTACK_ORDER]
    rows = [[name, *(num(v["auc_attacks"].get(attack), 4) for attack in names)] for name, v in variants.items()]
    lines += table(["variant", *names], rows)
    lines += [
        "",
        "`normalize_all` sets every public rule pair to a random side and so erases all style evidence: after whitening it "
        "is equivalent to flipping half of the bits at random. It is reported as it is and is not a pass condition.",
        "",
    ]
    return "\n".join(lines) + "\n"


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("runs", nargs="+", type=Path)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args(argv)
    report = analyse([load_run(directory) for directory in args.runs])
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(render(report), encoding="utf-8")
    args.output.with_suffix(".json").write_text(
        json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
    )
    print(f"Wrote {args.output}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
