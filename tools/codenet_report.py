#!/usr/bin/env python3
"""Cross-variant report of the CodeNet runs (docs/CODENET.md).

Usage: python tools/codenet_report.py RUN_DIR [RUN_DIR ...] --output PATH.md

Reads `manifest.json` and `rows.jsonl` of each run (the variant name comes from `slot_granularity` and `rule_set` of
its config) and writes a Markdown report plus the same data as JSON next to it. Fields that a row type lacks are skipped
and shown as N/A.
"""

import argparse
import json
import statistics
import sys
from collections import Counter, defaultdict
from pathlib import Path

TESTED = {"PASS", "FAIL", "COMPILE_ERROR", "COMPILE_TIMEOUT", "TIMEOUT"}
LANGUAGE_ORDER = {"python": 0, "c": 1, "cpp": 2, "javascript": 3}
ROLE_ORDER = {"generated": 0, "human": 1}
LETTER = {"generated": "G", "human": "H"}


def variant_name(config):
    return f"{config.get('slot_granularity', 'file')}/{config.get('rule_set', 'legacy')}"


def load_run(directory):
    directory = Path(directory)
    manifest = json.loads((directory / "manifest.json").read_text())
    rows = [json.loads(line) for line in (directory / "rows.jsonl").read_text(encoding="utf-8").splitlines() if line]
    return {
        "directory": str(directory),
        "run_id": manifest.get("run_id"),
        "variant": variant_name(manifest.get("config", {})),
        "rows": rows,
    }


def rate(numerator, denominator):
    return numerator / denominator if denominator else None


def median(values):
    return statistics.median(values) if values else None


def mean(values):
    return statistics.fmean(values) if values else None


def get(row, *path):
    """Nested value or None; any missing or non-dict step gives None."""
    value = row
    for key in path:
        if not isinstance(value, dict) or key not in value:
            return None
        value = value[key]
    return value


def status(row, stage):
    return get(row, stage, "status")


def tested(row, stage):
    return status(row, stage) in TESTED


def is_regression(row):
    return (
        status(row, "utility_before") == "PASS"
        and tested(row, "utility_after")
        and status(row, "utility_after") != "PASS"
    )


def group_summary(rows):
    ok = [r for r in rows if r.get("status") == "ok"]
    eligible = [r for r in ok if r.get("eligible")]
    attacks = {}
    for name in ["flip_1", "flip_2"]:
        tried = [get(r, "attacks", name) for r in eligible]
        tried = [a for a in tried if isinstance(a, dict)]
        applied = [a for a in tried if a.get("fully_applied") and "extraction" in a]
        attacks[name] = {
            "applied": rate(len(applied), len(tried)),
            "recovered": rate(sum(a["extraction"].get("matched", False) for a in applied), len(applied)),
        }
    properties = {}
    for name in ["idempotence", "reversibility", "independence"]:
        passed = sum(get(r, "properties", name, "passed") or 0 for r in ok)
        trials = sum(get(r, "properties", name, "trials") or 0 for r in ok)
        properties[name] = rate(passed, trials)
    syntax_total = sum(len(r.get("syntax_after") or {}) for r in eligible)
    syntax_valid = sum(sum((r.get("syntax_after") or {}).values()) for r in eligible)
    before = [r for r in ok if tested(r, "utility_before")]
    pairs = [r for r in before if tested(r, "utility_after")]
    before_pass = [r for r in pairs if status(r, "utility_before") == "PASS"]
    regressions = [r for r in before_pass if status(r, "utility_after") != "PASS"]
    return {
        "units": len(rows),
        "ok": len(ok),
        "harness_errors": len(rows) - len(ok),
        "eligible": len(eligible),
        "embeddable": rate(len(eligible), len(rows)),
        "capacity_median": median([r["capacity"] for r in ok if "capacity" in r]),
        "capacity_mean": mean([r["capacity"] for r in ok if "capacity" in r]),
        "recovery": rate(sum(bool(get(r, "marked_extraction", "matched")) for r in eligible), len(eligible)),
        "original_match": rate(sum(bool(get(r, "original_extraction", "matched")) for r in eligible), len(eligible)),
        "correct_bits_mean": mean(
            [
                get(r, "marked_extraction", "correct_bits")
                for r in eligible
                if get(r, "marked_extraction", "correct_bits") is not None
            ]
        ),
        "attacks": attacks,
        "syntax_after": rate(syntax_valid, syntax_total),
        "properties": properties,
        "before_pass": rate(sum(status(r, "utility_before") == "PASS" for r in before), len(before)),
        "preservation": rate(len(before_pass) - len(regressions), len(before_pass)),
        "regressions": len(regressions),
        "analysis_ms": median([r["analysis_ms"] for r in ok if "analysis_ms" in r]),
        "embedding_ms": median([r["embedding_ms"] for r in eligible if "embedding_ms" in r]),
    }


def ordered_groups(rows):
    groups = defaultdict(list)
    for row in rows:
        groups[(row["language"], row["role"], row["cohort"])].append(row)
    return sorted(groups.items(), key=lambda item: (LANGUAGE_ORDER.get(item[0][0], 9), ROLE_ORDER.get(item[0][1], 9)))


def rules_of(row):
    return sorted({slot.get("rule") for slot in row.get("embedding_slots") or [] if slot.get("rule")})


def first_failure_text(result):
    failure = (result or {}).get("first_failure") or {}
    if not failure:
        return (result or {}).get("error") or "-"
    return f"{failure.get('name')} {failure.get('verdict')}: {failure.get('detail', '')}"[:160]


def analyse(runs):
    report = {
        "runs": [],
        "groups": [],
        "comparison": [],
        "regressions": [],
        "rules": [],
        "cases": [],
        "human_failures": [],
    }
    for run in runs:
        variant, rows = run["variant"], run["rows"]
        report["runs"].append({"variant": variant, "run_id": run["run_id"], "units": len(rows)})
        summaries = {}
        for (language, role, cohort), group in ordered_groups(rows):
            summary = group_summary(group)
            summaries[(language, role)] = summary
            report["groups"].append(
                {"variant": variant, "language": language, "role": role, "cohort": cohort, **summary}
            )
            for row in group:
                if is_regression(row):
                    report["regressions"].append(
                        {
                            "variant": variant,
                            "id": row["id"],
                            "before": status(row, "utility_before"),
                            "after": status(row, "utility_after"),
                            "first_failure": first_failure_text(row.get("utility_after")),
                            "rules": rules_of(row),
                        }
                    )
                if role == "human" and tested(row, "utility_before") and status(row, "utility_before") != "PASS":
                    report["human_failures"].append(
                        {
                            "variant": variant,
                            "id": row["id"],
                            "status": status(row, "utility_before"),
                            "first_failure": first_failure_text(row.get("utility_before")),
                        }
                    )
        for language in sorted({k[0] for k in summaries}, key=lambda name: LANGUAGE_ORDER.get(name, 9)):
            g, h = summaries.get((language, "generated")), summaries.get((language, "human"))
            if g and h:
                diff = lambda key: None if g[key] is None or h[key] is None else g[key] - h[key]
                report["comparison"].append(
                    {
                        "variant": variant,
                        "language": language,
                        "capacity_median": [g["capacity_median"], h["capacity_median"]],
                        "embeddable": [g["embeddable"], h["embeddable"]],
                        "recovery": [g["recovery"], h["recovery"]],
                        "capacity_median_diff": diff("capacity_median"),
                        "embeddable_diff": diff("embeddable"),
                        "recovery_diff": diff("recovery"),
                    }
                )
        paired = [
            r for r in rows if r.get("status") == "ok" and tested(r, "utility_before") and tested(r, "utility_after")
        ]
        appearing, regressing = Counter(), Counter()
        for row in paired:
            for rule in rules_of(row):
                appearing[rule] += 1
                regressing[rule] += is_regression(row)
        for rule in sorted(appearing, key=lambda name: (-regressing[name], name)):
            report["rules"].append(
                {"variant": variant, "rule": rule, "regressed_units": regressing[rule], "paired_units": appearing[rule]}
            )
        for (_language, _role, cohort), group in ordered_groups(rows):
            pairs = [
                r
                for r in group
                if r.get("status") == "ok" and tested(r, "utility_before") and tested(r, "utility_after")
            ]
            counted = [
                r
                for r in pairs
                if get(r, "utility_before", "cases_total") is not None
                and get(r, "utility_after", "cases_total") is not None
            ]
            before_cases = sum(r["utility_before"].get("cases_passed", 0) for r in counted)
            after_cases = sum(r["utility_after"].get("cases_passed", 0) for r in counted)
            total = sum(r["utility_before"]["cases_total"] for r in counted)
            fewer = [
                r
                for r in counted
                if r["utility_after"].get("cases_passed", 0) < r["utility_before"].get("cases_passed", 0)
            ]
            report["cases"].append(
                {
                    "variant": variant,
                    "cohort": cohort,
                    "paired_units": len(counted),
                    "cases_total": total,
                    "before_passed": before_cases,
                    "after_passed": after_cases,
                    "units_with_fewer_cases": len(fewer),
                    "units_partially_regressed": sum(r["utility_after"].get("cases_passed", 0) > 0 for r in fewer),
                }
            )
    return report


def pct(value):
    return "N/A" if value is None else f"{value * 100:.1f}%"


def num(value, digits=1):
    return "N/A" if value is None else f"{value:.{digits}f}"


def signed(value, scale=1.0, suffix=""):
    return "N/A" if value is None else f"{value * scale:+.1f}{suffix}"


def table(headers, rows):
    lines = ["| " + " | ".join(headers) + " |", "|" + "|".join("---" for _ in headers) + "|"]
    lines += ["| " + " | ".join(str(cell) for cell in row) + " |" for row in rows]
    return lines


def render(report):
    lines = ["# CodeNet evaluation report", ""]
    lines += [f"- {run['variant']}: run `{run['run_id']}`, {run['units']} units" for run in report["runs"]]
    lines += ["", "## 1. Variant x group", ""]
    headers = [
        "variant", "group", "units", "embeddable", "cap med", "cap mean", "recovery", "orig match", "correct bits",
        "flip_1 applied", "flip_1 recovered", "flip_2 applied", "flip_2 recovered", "syntax ok", "idempotent",
        "reversible", "independent", "before pass", "preserved", "regressions", "harness err", "analysis ms", "embed ms",
    ]  # fmt: skip
    rows = []
    for g in report["groups"]:
        a = g["attacks"]
        rows.append(
            [
                g["variant"], f"{g['language']}_{LETTER.get(g['role'], g['role'])}", g["units"], pct(g["embeddable"]),
                num(g["capacity_median"]), num(g["capacity_mean"]), pct(g["recovery"]), pct(g["original_match"]),
                num(g["correct_bits_mean"], 2), pct(a["flip_1"]["applied"]), pct(a["flip_1"]["recovered"]),
                pct(a["flip_2"]["applied"]), pct(a["flip_2"]["recovered"]), pct(g["syntax_after"]),
                pct(g["properties"]["idempotence"]), pct(g["properties"]["reversibility"]),
                pct(g["properties"]["independence"]), pct(g["before_pass"]), pct(g["preservation"]), g["regressions"],
                g["harness_errors"], num(g["analysis_ms"], 2), num(g["embedding_ms"], 2),
            ]
        )  # fmt: skip
    lines += table(headers, rows)
    lines += [
        "",
        "Original match is the rate of matching the expected message on unmarked code (FPR for the H groups).",
        "",
    ]
    lines += ["## 2. Generated vs human", ""]
    rows = [
        [
            c["variant"], c["language"], f"{num(c['capacity_median_diff'])}", signed(c["embeddable_diff"], 100, " pt"),
            signed(c["recovery_diff"], 100, " pt"),
        ]
        for c in report["comparison"]
    ]  # fmt: skip
    lines += table(["variant", "language", "capacity median G-H", "embeddable G-H", "recovery G-H"], rows)
    lines += ["", "## 3. Functional regressions", ""]
    lines += [f"{len(report['regressions'])} units passed before and did not pass after embedding.", ""]
    rows = [
        [r["variant"], r["id"], r["before"], r["after"], r["first_failure"], ", ".join(r["rules"])]
        for r in report["regressions"]
    ]
    lines += table(["variant", "unit", "before", "after", "first failure", "rules in embedding_slots"], rows)
    lines += ["", "Regressions per rule (units with the rule that regressed / paired units with the rule):", ""]
    lines += table(
        ["variant", "rule", "regressed", "paired"],
        [[r["variant"], r["rule"], r["regressed_units"], r["paired_units"]] for r in report["rules"]],
    )
    lines += ["", "## 4. Test cases", ""]
    rows = [
        [
            c["variant"], c["cohort"], c["paired_units"], c["cases_total"], c["before_passed"], c["after_passed"],
            c["units_with_fewer_cases"], c["units_partially_regressed"],
        ]
        for c in report["cases"]
    ]  # fmt: skip
    lines += table(
        [
            "variant",
            "group",
            "paired units",
            "cases",
            "passed before",
            "passed after",
            "units with fewer after",
            "of which partial",
        ],
        rows,
    )
    lines += ["", "## 5. Human solutions that do not pass before embedding", ""]
    lines += [
        f"{len(report['human_failures'])} entries (the reference answers should all pass; others point to judging differences).",
        "",
    ]
    lines += table(
        ["variant", "unit", "status", "first failure"],
        [[r["variant"], r["id"], r["status"], r["first_failure"]] for r in report["human_failures"]],
    )
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
