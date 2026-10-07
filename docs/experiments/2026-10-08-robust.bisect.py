"""Hunk attribution of CodeNet functional regressions in a frozen robust-watermark run.

The keyed embedding rewrites many sites at once, so a regression is attributed by replaying the line hunks of the
clean -> marked diff on the clean source: first every hunk alone, then (if no single hunk fails) a greedy reduction of
the full hunk set to a minimal failing subset. The CodeNet oracle of the run judges every candidate.
Usage: python 2026-10-08-robust.bisect.py RUN_DIR OUT.json [JOBS]
"""

import difflib
import json
import os
import sys
import tempfile
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

RUN = Path(sys.argv[1]).resolve()
sys.path.insert(0, str(RUN / "source"))
os.chdir(RUN / "source")

from benchmarks import codenet, utility  # noqa: E402

MANIFEST = json.loads((RUN / "manifest.json").read_text())
CONFIG = MANIFEST["config"]
UNITS = {u["id"]: u for u in MANIFEST["units"]}
PROBLEMS = utility.load_problems(RUN / "inputs", CONFIG)


def judge(unit, code):
    with tempfile.TemporaryDirectory() as scratch:
        name = Path(unit["source_files"][0]).name
        (Path(scratch) / name).write_text(code, encoding="utf-8")
        result = codenet.evaluate_cached(
            unit, Path(scratch), PROBLEMS, CONFIG, MANIFEST["environment"], Path(MANIFEST["utility_cache"])
        )
    first = result.get("first_failure") or {}
    detail = f"{first.get('verdict', '')} {first.get('detail', '')}" if first else ""
    if result["status"].startswith("COMPILE"):
        stderr = (result.get("compile") or {}).get("stderr_excerpt", "") or result.get("error", "")
        detail = next((line for line in stderr.splitlines() if "error" in line), stderr[:200])
    return result["status"], detail[:200]


def hunks(clean, marked):
    a, b = clean.splitlines(keepends=True), marked.splitlines(keepends=True)
    return a, [op for op in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes() if op[0] != "equal"], b


def apply(a, b, chosen):
    out, at = [], 0
    for _, i1, i2, j1, j2 in sorted(chosen, key=lambda op: op[1]):
        out += a[at:i1] + b[j1:j2]
        at = i2
    return "".join(out + a[at:])


def bisect(unit_id):
    unit = UNITS[unit_id]
    row = ROWS[unit_id]
    name = Path(unit["source_files"][0]).name
    clean = (RUN / row["artifacts"] / "clean" / name).read_text(encoding="utf-8")
    marked = (RUN / row["artifacts"] / "marked" / name).read_text(encoding="utf-8")
    a, ops, b = hunks(clean, marked)
    status, detail = judge(unit, marked)
    singles = []
    for op in ops:
        verdict = judge(unit, apply(a, b, [op]))
        if verdict[0] != "PASS":
            singles.append({"clean": "".join(a[op[1] : op[2]]), "marked": "".join(b[op[3] : op[4]]), "status": verdict})
    minimal = []
    if not singles and status != "PASS":
        keep = list(ops)
        for op in list(ops):
            trial = [o for o in keep if o is not op]
            if judge(unit, apply(a, b, trial))[0] != "PASS":
                keep = trial
        minimal = [{"clean": "".join(a[o[1] : o[2]]), "marked": "".join(b[o[3] : o[4]])} for o in keep]
    return {
        "id": unit_id,
        "marked_status": [status, detail],
        "hunks": len(ops),
        "failing_single_hunks": singles,
        "minimal_set": minimal,
    }


ROWS = {}
for line in open(RUN / "rows.jsonl", encoding="utf-8"):
    row = json.loads(line)
    ROWS[row["id"]] = row


def regressed(row):
    before, after = row.get("utility_before") or {}, row.get("utility_after") or {}
    return (
        row.get("cohort", "").startswith("codenet_")
        and before.get("status") == "PASS"
        and after.get("status") not in (None, "PASS", "NOT_EMBEDDED")
    )


if __name__ == "__main__":
    targets = sorted(unit_id for unit_id, row in ROWS.items() if regressed(row))
    jobs = int(sys.argv[3]) if len(sys.argv) > 3 else 8
    with ProcessPoolExecutor(max_workers=jobs) as pool:
        results = list(pool.map(bisect, targets))
    Path(sys.argv[2]).write_text(json.dumps(results, indent=1) + "\n", encoding="utf-8")
    print(len(targets), "regressions;", sum(bool(r["failing_single_hunks"]) for r in results), "with a single failing hunk")
