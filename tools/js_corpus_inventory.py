#!/usr/bin/env python3
"""Inventory of the JavaScript cohorts: unit counts, code-size and slot-capacity distributions.

Capacity is measured with the pipeline's own analysis step (`cllmark.directories.analyze_directory`) on a flat copy of each unit,
exactly as the benchmark engine prepares it, so it describes the rule set of the current checkout. The output is a
TSV with one row per cohort, per repository and per unit of the new cohorts (see docs/plans/2026-10-06-javascript-corpus.md).

    python tools/js_corpus_inventory.py [--output docs/plans/2026-10-06-javascript-corpus.inventory.tsv] [--jobs 8]
"""

import argparse
import contextlib
import csv
import io
import json
import statistics
import sys
import tempfile
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from benchmarks.common import discover_units, line_count, unit_file_names

COHORTS = ["mbjsp_generated", "mbjsp_human", "js_projects", "js_repos", "js_repo_files", "exercism_js"]
UNIT_ROWS = ["js_repos", "js_repo_files", "exercism_js"]
FIELDS = [
    "scope",
    "name",
    "units",
    "files",
    "lines_total",
    "lines_min",
    "lines_median",
    "lines_p90",
    "lines_max",
    "capacity_median",
    "capacity_p90",
    "eligible_units",
    "eligible_fraction",
    "clean_test_seconds",
    "tested_fraction_median",
    "extra",
]
REQUIRED_CAPACITY = 7


def percentile(values, fraction):
    values = sorted(values)
    return values[min(len(values) - 1, int(len(values) * fraction))] if values else ""


def median(values):
    return statistics.median(values) if values else ""


def capacity(unit):
    from cllmark.directories import analyze_directory

    with tempfile.TemporaryDirectory(prefix="inventory-") as temporary:
        for relative, name in unit_file_names(unit).items():
            (Path(temporary) / name).write_bytes((ROOT / relative).read_bytes())
        with contextlib.redirect_stdout(io.StringIO()):  # the legacy analysis prints a count
            return unit["id"], analyze_directory(temporary, "javascript")


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument(
        "--output", type=Path, default=ROOT / "docs" / "plans" / "2026-10-06-javascript-corpus.inventory.tsv"
    )
    parser.add_argument("--jobs", type=int, default=8)
    args = parser.parse_args(argv)
    config = json.loads((ROOT / "benchmarks" / "config.json").read_text())
    lock = json.loads((ROOT / "benchmarks" / "javascript.lock.json").read_text())
    units, _ = discover_units(ROOT, config, cohorts=COHORTS)
    sys.path.insert(0, str(ROOT))
    with ProcessPoolExecutor(args.jobs) as pool:
        capacities = dict(pool.map(capacity, units, chunksize=4))
    pins = {
        name: json.loads((ROOT / ".benchmark-cache" / "js-projects" / (name + ".pin.json")).read_text())
        for name in lock["repositories"]
    }

    def tested(unit):
        if unit["id"].split("/", 1)[0] not in ("js_repos", "js_repo_files"):
            return None
        project = unit.get("project", unit["name"])
        coverage = pins[project].get("clean_test", {}).get("v8_coverage", {})
        values = [coverage.get(path) for path in project_files(unit)]
        return median([v for v in values if v is not None])

    def project_files(unit):
        prefix = unit["path"].rstrip("/") + "/" + unit.get("project", unit["name"]) + "/"
        return [p[len(prefix) :] for p in unit["source_files"]]

    for unit in units:
        unit["cohort_name"] = unit["id"].split("/", 1)[0]
        unit["lines"] = sum(line_count(ROOT / p) for p in unit["source_files"])
        unit["capacity"] = capacities[unit["id"]]
        unit["tested"] = tested(unit)

    def row(scope, name, group, **extra):
        lines, caps = [u["lines"] for u in group], [u["capacity"] for u in group]
        eligible = sum(c >= REQUIRED_CAPACITY for c in caps)
        tested_values = [u["tested"] for u in group if u["tested"] is not None]
        return {
            "scope": scope,
            "name": name,
            "units": len(group),
            "files": sum(len(u["source_files"]) for u in group),
            "lines_total": sum(lines),
            "lines_min": min(lines),
            "lines_median": median(lines),
            "lines_p90": percentile(lines, 0.9),
            "lines_max": max(lines),
            "capacity_median": median(caps),
            "capacity_p90": percentile(caps, 0.9),
            "eligible_units": eligible,
            "eligible_fraction": round(eligible / len(group), 3),
            "clean_test_seconds": "",
            "tested_fraction_median": round(median(tested_values), 3) if tested_values else "",
            "extra": "",
            **extra,
        }

    rows = []
    for cohort in COHORTS:
        group = [u for u in units if u["cohort_name"] == cohort]
        rows.append(row("cohort", cohort, group))
    for name, spec in lock["repositories"].items():
        group = [u for u in units if u["cohort_name"] == "js_repo_files" and u["project"] == name]
        whole = next(u for u in units if u["id"] == "js_repos/" + name)
        value = (
            row("repository", name, group)
            if group
            else dict.fromkeys(FIELDS, "") | {"scope": "repository", "name": name, "units": 0}
        )
        value.update(
            {
                "files": len(whole["source_files"]),
                "lines_total": whole["lines"],
                "clean_test_seconds": pins[name].get("clean_test", {}).get("seconds", ""),
                "tested_fraction_median": round(whole["tested"], 3) if whole["tested"] != "" else "",
                "extra": f"{spec['tag']} {spec['commit'][:12]} {spec['license']}; project capacity {whole['capacity']}; file units {len(group)}",
            }
        )
        rows.append(value)
    for cohort in UNIT_ROWS:
        for unit in [u for u in units if u["cohort_name"] == cohort]:
            rows.append(
                row("unit", unit["id"], [unit])
                | {
                    "eligible_units": int(unit["capacity"] >= REQUIRED_CAPACITY),
                    "tested_fraction_median": round(unit["tested"], 3) if unit["tested"] is not None else "",
                }
            )
    args.output.parent.mkdir(parents=True, exist_ok=True)
    with args.output.open("w", newline="", encoding="utf-8") as output:
        writer = csv.DictWriter(output, fieldnames=FIELDS, delimiter="\t", lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)
    for value in rows:
        if value["scope"] == "cohort":
            print(
                {
                    key: value[key]
                    for key in [
                        "name",
                        "units",
                        "lines_median",
                        "lines_p90",
                        "capacity_median",
                        "eligible_units",
                        "eligible_fraction",
                    ]
                }
            )


if __name__ == "__main__":
    main()
