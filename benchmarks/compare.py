"""Compare only complete, compatible runs against an explicitly pinned baseline."""

from pathlib import Path

from .common import utc_now, write_json


def compare(candidate, baseline, gates):
    incompatibilities = []
    for label, value in [("candidate_full", candidate["full"]), ("candidate_complete", candidate["complete"]),
                         ("baseline_full", baseline["full"]), ("baseline_complete", baseline["complete"])]:
        if not value:
            incompatibilities.append(label + " is false")
    for key in ["dataset_fingerprint", "protocol_fingerprint", "environment_fingerprint"]:
        if candidate[key] != baseline[key]:
            incompatibilities.append(key + " differs")
    result = {"baseline_run_id": baseline["run_id"], "candidate_run_id": candidate["run_id"],
              "comparable": not incompatibilities, "incompatibilities": incompatibilities, "checks": [], "passed": False}
    if incompatibilities:
        return result
    checks = result["checks"]

    def scalar(name, current, previous, tolerance, higher=True):
        if previous is None:
            checks.append({"metric": name, "status": "unavailable_in_baseline", "passed": True,
                           "current": current, "baseline": previous})
            return
        passed = current is not None and (current >= previous - tolerance if higher else current <= previous + tolerance)
        checks.append({"metric": name, "current": current, "baseline": previous,
                       "delta": current - previous if current is not None else None,
                       "tolerance": tolerance, "passed": passed})

    current, previous = candidate["aggregate"], baseline["aggregate"]
    drop = gates["rate_drop_tolerance"]
    for name in ["capacity_coverage", "watermark_recovery_rate", "raw_codeword_recovery_rate", "raw_bit_accuracy"]:
        scalar(name, current[name], previous[name], drop)
    for name in ["tpr", "accuracy"]:
        scalar("detection." + name, current["detection"][name], previous["detection"][name], drop)
    scalar("detection.fpr", current["detection"]["fpr"], previous["detection"]["fpr"], gates["fpr_increase_tolerance"], False)
    scalar("utility.retention", current["utility"]["retention"], previous["utility"]["retention"], drop)
    scalar("syntax_retention", current["syntax_retention"]["rate"], previous["syntax_retention"]["rate"], drop)
    for name in ["idempotence", "reversibility", "independence"]:
        scalar("properties." + name, current["properties"][name]["rate"], previous["properties"][name]["rate"], drop)
    scalar("property_errors", current["property_errors"], previous["property_errors"], 0, False)
    for name, attack in previous["attacks"].items():
        other = current["attacks"].get(name, {})
        scalar("attacks." + name, other.get("recovery_rate"), attack["recovery_rate"], drop)
        scalar("attacks." + name + ".coverage", other.get("fully_applied"), attack["fully_applied"], 0)
    new_failures = sorted(set(current["utility"]["regression_ids"]) - set(previous["utility"]["regression_ids"]))
    lost = sorted(set(baseline["eligible_ids"]) - set(candidate["eligible_ids"]))
    for field in ["oracle_ids", "paired_ids", "before_pass_ids"]:
        removed = sorted(set(previous["utility"][field]) - set(current["utility"][field]))
        checks.append({"metric": "utility.lost_" + field, "count": len(removed), "sample_ids": removed, "passed": not removed})
    checks += [
        {"metric": "new_functional_regressions", "count": len(new_failures), "sample_ids": new_failures,
         "passed": len(new_failures) <= gates["new_functional_regressions"]},
        {"metric": "lost_eligible_units", "count": len(lost), "sample_ids": lost,
         "passed": len(lost) <= gates["lost_eligible_units"]},
        {"metric": "harness_errors", "count": current["harness_errors"],
         "passed": current["harness_errors"] <= gates["new_harness_errors"]},
    ]
    result["timing_comparable"] = candidate["jobs"] == baseline["jobs"]
    for name, old in baseline["cohorts"].items():
        group = candidate["cohorts"].get(name)
        if not group:
            checks.append({"metric": name + ".missing", "passed": False})
            continue
        for metric in ["capacity_coverage", "watermark_recovery_rate", "raw_bit_accuracy"]:
            scalar(name + "." + metric, group[metric], old[metric], drop)
        for metric in ["tpr", "accuracy"]:
            scalar(name + ".detection." + metric, group["detection"][metric], old["detection"][metric], drop)
        scalar(name + ".detection.fpr", group["detection"]["fpr"], old["detection"]["fpr"], gates["fpr_increase_tolerance"], False)
        scalar(name + ".utility.retention", group["utility"]["retention"], old["utility"]["retention"], drop)
    if result["timing_comparable"]:
        for name, group in candidate["cohorts"].items():
            old = baseline["cohorts"].get(name)
            if not old:
                continue
            for phase in ["embedding", "extraction"]:
                a, b = group["timing"][phase], old["timing"][phase]
                if min(a["count"], b["count"]) >= 50:
                    tolerance = max(gates["timing_absolute_tolerance_ms"], b["median_ms"] * gates["timing_relative_tolerance"])
                    scalar(name + "." + phase + ".median_ms", a["median_ms"], b["median_ms"], tolerance, False)
    result["passed"] = all(check["passed"] for check in checks)
    return result


def promote_baseline(summary, destination, run_dir):
    if not summary["full"] or not summary["complete"] or summary["aggregate"]["harness_errors"]:
        raise ValueError("Only a full, complete run without harness errors can become a baseline")
    destination = Path(destination)
    record = {**summary, "baseline_record": {"promoted_at": utc_now(), "local_run_directory": str(Path(run_dir).resolve())}}
    if destination.exists():
        import json
        previous = json.loads(destination.read_text())
        archive = destination.parent / "history" / (previous["run_id"] + ".json")
        if not archive.exists():
            write_json(archive, previous)
    write_json(destination, record)
    return destination
