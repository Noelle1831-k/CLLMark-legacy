"""Explicit denominators for coverage, detection, recovery and utility metrics."""

from collections import Counter, defaultdict
import csv
import json
from pathlib import Path
import statistics

from .common import write_json


TESTED = {"PASS", "FAIL", "COMPILE_ERROR", "COMPILE_TIMEOUT", "TIMEOUT"}


def rate(numerator, denominator):
    return numerator / denominator if denominator else None


def timing(values):
    values = sorted(values)
    return {"count": len(values), "median_ms": statistics.median(values) if values else None,
            "p95_ms": values[min(len(values) - 1, int(len(values) * 0.95))] if values else None}


def summarize_group(rows):
    ok = [r for r in rows if r["status"] == "ok"]
    eligible = [r for r in ok if r["eligible"]]
    positives = [r for r in eligible if r["role"] == "generated"]
    negatives = [r for r in eligible if r["role"] == "human"]
    tp = sum(r["marked_extraction"]["matched"] for r in positives)
    fp = sum(r["original_extraction"]["matched"] for r in negatives)
    fn, tn = len(positives) - tp, len(negatives) - fp
    oracle_rows = [r for r in ok if r["utility_before"]["status"] in TESTED]
    utility_pairs = [r for r in oracle_rows if r["utility_after"]["status"] in TESTED]
    before_pass = [r for r in utility_pairs if r["utility_before"]["status"] == "PASS"]
    regressions = sorted(r["id"] for r in before_pass if r["utility_after"]["status"] != "PASS")
    syntax_trials = sum(sum(r["syntax_before"].values()) for r in eligible)
    syntax_retained = sum(sum(valid and r["syntax_after"].get(name, False) for name, valid in r["syntax_before"].items()) for r in eligible)
    properties = {}
    for name in ["idempotence", "reversibility", "independence"]:
        passed = sum((r.get("properties") or {}).get(name, {}).get("passed", 0) for r in ok)
        trials = sum((r.get("properties") or {}).get(name, {}).get("trials", 0) for r in ok)
        properties[name] = {"passed": passed, "trials": trials, "rate": rate(passed, trials)}
    attacks = {}
    for name in sorted({name for r in eligible for name in r["attacks"]}):
        attempted = [r["attacks"][name] for r in eligible if name in r["attacks"]]
        applied = [a for a in attempted if a["fully_applied"] and "extraction" in a]
        matched = sum(a["extraction"]["matched"] for a in applied)
        attacks[name] = {"attempted": len(attempted), "fully_applied": len(applied), "matched": matched,
                         "recovery_rate": rate(matched, len(applied))}
    utility_statuses = Counter(r["utility_before"]["status"] for r in ok)
    return {
        "units": len(rows), "ok_units": len(ok), "harness_errors": len(rows) - len(ok),
        "eligible_units": len(eligible), "capacity_coverage": rate(len(eligible), len(rows)),
        "insufficient_capacity": sum(not r["eligible"] for r in ok),
        "watermark_recovery_rate": rate(sum(r["marked_extraction"]["matched"] for r in eligible), len(eligible)),
        "raw_codeword_recovery_rate": rate(sum(r["marked_extraction"]["raw_matched"] for r in eligible), len(eligible)),
        "raw_bit_accuracy": rate(sum(r["marked_extraction"]["correct_bits"] for r in eligible),
                                 sum(r["marked_extraction"]["expected_bit_count"] for r in eligible)),
        "detection": {"tp": tp, "fp": fp, "tn": tn, "fn": fn,
                      "positive_units": len(positives), "negative_units": len(negatives),
                      "tpr": rate(tp, tp + fn), "fpr": rate(fp, fp + tn), "accuracy": rate(tp + tn, tp + tn + fp + fn)},
        "utility": {"oracle_units": len(oracle_rows), "oracle_coverage": rate(len(oracle_rows), len(rows)),
                    "oracle_ids": sorted(r["id"] for r in oracle_rows), "paired_ids": sorted(r["id"] for r in utility_pairs),
                    "before_pass_ids": sorted(r["id"] for r in oracle_rows if r["utility_before"]["status"] == "PASS"),
                    "paired_units": len(utility_pairs), "before_pass_units": sum(r["utility_before"]["status"] == "PASS" for r in oracle_rows),
                    "before_pass_rate": rate(sum(r["utility_before"]["status"] == "PASS" for r in oracle_rows), len(oracle_rows)),
                    "after_pass_rate": rate(sum(r["utility_after"]["status"] == "PASS" for r in utility_pairs), len(utility_pairs)),
                    "retention_denominator": len(before_pass), "retention": rate(len(before_pass) - len(regressions), len(before_pass)),
                    "regression_ids": regressions, "before_status_counts": dict(utility_statuses)},
        "syntax_retention": {"retained": syntax_retained, "trials": syntax_trials, "rate": rate(syntax_retained, syntax_trials)},
        "properties": properties,
        "property_errors": sum((r.get("properties") or {}).get("errors", 0) for r in ok),
        "unsupported_rule_pairs": sum((r.get("properties") or {}).get("unsupported_pairs", 0) for r in ok),
        "attacks": attacks,
        "timing": {"analysis": timing([r["analysis_ms"] for r in ok]),
                   "embedding": timing([r["embedding_ms"] for r in eligible]),
                   "extraction": timing([r["marked_extraction"]["elapsed_ms"] for r in eligible])},
    }


def summarize(rows, manifest):
    cohorts = defaultdict(list)
    for row in rows:
        cohorts[row["cohort"]].append(row)
    ids = [row["id"] for row in rows]
    expected = {unit["id"] for unit in manifest["units"]}
    complete = len(ids) == len(set(ids)) and set(ids) == expected
    return {
        "schema_version": 1, "run_id": manifest["run_id"], "manifest_sha256": manifest["manifest_sha256"],
        "git": manifest["git"], "source_fingerprint": manifest["source_fingerprint"],
        "dataset_fingerprint": manifest["dataset_fingerprint"], "protocol_fingerprint": manifest["protocol_fingerprint"],
        "environment_fingerprint": manifest["environment_fingerprint"], "jobs": manifest["config"]["jobs"],
        "full": manifest["full"], "complete": complete, "expected_units": len(expected),
        "eligible_ids": sorted(r["id"] for r in rows if r.get("eligible") and r["status"] == "ok"),
        "error_ids": sorted(r["id"] for r in rows if r["status"] != "ok"),
        "aggregate": summarize_group(rows),
        "cohorts": {name: summarize_group(group) for name, group in sorted(cohorts.items())},
    }


def percent(value):
    return "N/A" if value is None else f"{value * 100:.2f}%"


def save_reports(run_dir, summary, manifest, comparison=None):
    run_dir = Path(run_dir)
    write_json(run_dir / "summary.json", summary)
    if comparison is not None:
        write_json(run_dir / "comparison.json", comparison)
    fields = ["cohort", "units", "eligible", "capacity_coverage", "recovery", "tpr", "fpr", "utility_oracles", "utility_pairs", "utility_retention", "embed_median_ms", "extract_median_ms", "harness_errors"]
    lines = ["# Local CLLMark benchmark", "", f"Run: `{summary['run_id']}`; commit: `{summary['git']['commit']}`; dirty: `{summary['git']['dirty']}`.",
             f"Full inventory: **{summary['full']}**; complete: **{summary['complete']}**; rows: **{summary['aggregate']['units']}/{summary['expected_units']}**.", "",
             "| Cohort | Units | Eligible | Recovery | TPR | FPR | Functional oracles | Utility retention | Harness errors |",
             "| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |"]
    with (run_dir / "metrics.csv").open("w", newline="", encoding="utf-8") as output:
        writer = csv.DictWriter(output, fieldnames=fields)
        writer.writeheader()
        for name, m in summary["cohorts"].items():
            writer.writerow({"cohort": name, "units": m["units"], "eligible": m["eligible_units"], "capacity_coverage": m["capacity_coverage"],
                             "recovery": m["watermark_recovery_rate"], "tpr": m["detection"]["tpr"], "fpr": m["detection"]["fpr"],
                             "utility_oracles": m["utility"]["oracle_units"], "utility_pairs": m["utility"]["paired_units"],
                             "utility_retention": m["utility"]["retention"], "embed_median_ms": m["timing"]["embedding"]["median_ms"],
                             "extract_median_ms": m["timing"]["extraction"]["median_ms"], "harness_errors": m["harness_errors"]})
            lines.append(f"| {name} | {m['units']} | {m['eligible_units']} | {percent(m['watermark_recovery_rate'])} | {percent(m['detection']['tpr'])} | {percent(m['detection']['fpr'])} | {m['utility']['oracle_units']} | {percent(m['utility']['retention'])} | {m['harness_errors']} |")
    m = summary["aggregate"]
    lines += ["", "## Measurement contract", "",
              "- Eligibility requires at least seven applicable file/rule slots. Capacity failures remain in the inventory and coverage denominator.",
              "- Detection positives are freshly embedded generated cohorts; negatives are eligible human cohorts. Unknown/historical provenance is excluded from the confusion matrix.",
              "- Cohorts overlap and include historical variants. Aggregate results are a local regression suite, not estimates over independent paper samples; use individual cohorts for scientific analysis.",
              "- Extraction invokes the legacy expected-message API, with per-unit/stage deterministic random seeds. Recovery is expected-message matching, not independent source-model identification.",
              "- Rule reversibility compares canonical endpoints; independence probes same-file pairs used by the seven selected embedding slots. These structural probes do not prove semantic equivalence.",
              "- Utility uses supplied MBXP tests on reconstructed full functions. Missing oracles, unmapped CodeNet IDs and split project functions are N/A; they are never counted as passing.",
              "- Syntax metrics use the stored snippets as parsed by Tree-sitter; incomplete C++ function bodies may already have parse errors before watermarking.",
              "- Rule-flip attacks report actual successful transformations. Recovery after one/two transforms is not assumed to correspond to exactly one/two changed codeword bits.",
              "- Parser initialization is excluded from phase timing. Functional-test cache hits are recorded and excluded from watermark timing measurements.",
              "- Original dataset hashes, source snapshot, environment, seed, config and all per-unit failures are preserved in this run.", "",
              "## Aggregate results", "", f"Capacity coverage: {percent(m['capacity_coverage'])}; recovery: {percent(m['watermark_recovery_rate'])}; raw bit accuracy: {percent(m['raw_bit_accuracy'])}.",
              f"Detection TPR: {percent(m['detection']['tpr'])}; FPR: {percent(m['detection']['fpr'])}; accuracy: {percent(m['detection']['accuracy'])}.",
              f"Functional oracle coverage: {percent(m['utility']['oracle_coverage'])}; paired utility retention: {percent(m['utility']['retention'])}.",
              f"Functional regressions: {len(m['utility']['regression_ids'])}; harness errors: {m['harness_errors']}; property probe errors: {m['property_errors']}."]
    for name, attack in m["attacks"].items():
        lines.append(f"{name}: applied {attack['fully_applied']}/{attack['attempted']}; recovery {percent(attack['recovery_rate'])}.")
    if comparison:
        lines += ["", "## Baseline comparison", "", f"Comparable: **{comparison['comparable']}**; gate passed: **{comparison['passed']}**.",
                  "```json", json.dumps(comparison, ensure_ascii=False, indent=2), "```"]
    (run_dir / "report.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    try:
        import matplotlib
        matplotlib.use("Agg")
        import matplotlib.pyplot as plt
        labels = ["Capacity", "Recovery", "Raw bits", "TPR", "FPR", "Utility retention"]
        values = [m["capacity_coverage"], m["watermark_recovery_rate"], m["raw_bit_accuracy"], m["detection"]["tpr"], m["detection"]["fpr"], m["utility"]["retention"]]
        fig, ax = plt.subplots(figsize=(10, 4))
        ax.bar(labels, [100 * x if x is not None else 0 for x in values], color=["#4361ee"] * 4 + ["#f77f00", "#2a9d8f"])
        for index, value in enumerate(values):
            ax.text(index, (100 * value if value is not None else 0) + 1, percent(value), ha="center", fontsize=9)
        ax.set_ylim(0, 110)
        ax.set_ylabel("Percent (see report for each denominator)")
        ax.set_title("Legacy CLLMark - " + summary["run_id"])
        fig.tight_layout()
        fig.savefig(run_dir / "metrics.png", dpi=160)
        plt.close(fig)
    except Exception as error:
        write_json(run_dir / "plot-error.json", {"error": repr(error)})
