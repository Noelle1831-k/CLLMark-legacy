"""Rule attribution of CodeNet functional regressions in a frozen robust-watermark run.

The keyed embedding rewrites many sites of many rule pairs at once. A regression is attributed like the phase-1 bisect
(`2026-10-07-codenet.bisect.py`): every style of every rule pair of the run's rule set is applied file-wide, alone, to
the clean source, and the CodeNet oracle judges the result. Styles that fail alone are the culprits; a regression no
single style reproduces is listed as combination-only. (Replaying line hunks of the clean -> marked diff is not used:
one rewrite such as an if/else branch swap spans several hunks, and a hunk alone is not a program the rule produces.)
Usage: python 2026-10-08-robust.bisect.py RUN_DIR OUT.json [JOBS]
"""

import collections
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
from cllmark.transform import StyleTransformer  # noqa: E402

MANIFEST = json.loads((RUN / "manifest.json").read_text())
CONFIG = MANIFEST["config"]
RULE_SET = CONFIG.get("rule_set", "legacy")
UNITS = {u["id"]: u for u in MANIFEST["units"]}
PROBLEMS = utility.load_problems(RUN / "inputs", CONFIG)
PARSERS = {}


def parser(language):
    if language not in PARSERS:
        PARSERS[language] = StyleTransformer(language, rule_set=RULE_SET)
    return PARSERS[language]


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


def bisect(unit_id):
    unit, row = UNITS[unit_id], ROWS[unit_id]
    name = Path(unit["source_files"][0]).name
    clean = (RUN / row["artifacts"] / "clean" / name).read_text(encoding="utf-8")
    transformer = parser(unit["language"])
    culprits, trials = [], []
    for pair, styles in transformer.pairs.items():
        for style in styles:
            try:
                changed = transformer.apply(style, clean)[0]
            except Exception as error:  # recorded: the pair has no sites for the embedding either
                trials.append({"pair": pair, "style": style, "status": "TRANSFORM_ERROR", "detail": repr(error)[:120]})
                continue
            if changed == clean:
                continue
            status, detail = judge(unit, changed)
            trials.append({"pair": pair, "style": style, "status": status, "detail": detail})
            if status != "PASS":
                culprits.append(f"{pair}/{style}")
    return {"id": unit_id, "after": row["utility_after"]["status"], "culprits": culprits, "trials": trials}


with open(RUN / "rows.jsonl", encoding="utf-8") as stream:
    ROWS = {row["id"]: row for row in map(json.loads, stream)}


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
    by_style = collections.Counter(c for r in results for c in r["culprits"])
    combination = [r["id"] for r in results if not r["culprits"]]
    print(f"{RUN.name} rule_set={RULE_SET}: {len(results)} regressions, {len(combination)} only in combination")
    for style, count in by_style.most_common():
        print(f"  {count:4d}  {style}")
    if combination:
        print("  combination-only:", " ".join(combination))
