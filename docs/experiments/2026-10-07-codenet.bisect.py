"""Single-rule attribution of CodeNet functional regressions in a frozen file-granularity run.

For every unit that passed before and not after embedding, apply each embedding slot's style alone to the clean
source (frozen run code, same rule set) and judge it with the CodeNet oracle. Usage: python codenet_bisect.py RUN_DIR
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
PARSERS = {}
PROBLEMS = utility.load_problems(RUN / "inputs", CONFIG)


def parser(language):
    if language not in PARSERS:
        PARSERS[language] = StyleTransformer(language, rule_set=RULE_SET)
    return PARSERS[language]


def judge(unit, code, scratch):
    directory = Path(scratch)
    name = Path(unit["source_files"][0]).name
    (directory / name).write_text(code, encoding="utf-8")
    result = codenet.evaluate_cached(
        unit, directory, PROBLEMS, CONFIG, MANIFEST["environment"], Path(MANIFEST["utility_cache"])
    )
    first = result.get("first_failure") or {}
    detail = f"{first.get('verdict', '')} {first.get('detail', '')}" if first else ""
    if result["status"].startswith("COMPILE"):
        stderr = (result.get("compile") or {}).get("stderr_excerpt", "") or result.get("error", "")
        detail = next((line for line in stderr.splitlines() if "error" in line), stderr[:200])
    return result["status"], detail[:200]


def bisect(row):
    unit = UNITS[row["id"]]
    clean = (RUN / row["artifacts"] / "clean" / Path(unit["source_files"][0]).name).read_text(encoding="utf-8")
    culprits, trials = [], []
    with tempfile.TemporaryDirectory() as scratch:
        for slot in row["embedding_slots"]:
            try:
                changed = parser(unit["language"]).apply(slot["style"], clean)[0]
            except Exception as error:
                trials.append(
                    {
                        "rule": slot["rule"],
                        "style": slot["style"],
                        "status": "TRANSFORM_ERROR",
                        "detail": repr(error)[:120],
                    }
                )
                continue
            if changed == clean:
                trials.append({"rule": slot["rule"], "style": slot["style"], "status": "UNCHANGED"})
                continue
            status, detail = judge(unit, changed, scratch)
            trials.append({"rule": slot["rule"], "style": slot["style"], "status": status, "detail": detail})
            if status != "PASS":
                culprits.append(slot["rule"] + "/" + slot["style"])
    return {"id": row["id"], "after": row["utility_after"]["status"], "culprits": culprits, "trials": trials}


def main():
    rows = [json.loads(line) for line in (RUN / "rows.jsonl").open()]
    regressions = [
        r
        for r in rows
        if r.get("status") == "ok"
        and r.get("eligible")
        and r["utility_before"].get("status") == "PASS"
        and r["utility_after"].get("status") != "PASS"
    ]
    with ProcessPoolExecutor(32) as pool:
        results = list(pool.map(bisect, regressions))
    (RUN / "bisect.json").write_text(json.dumps(results, indent=1))
    by_style = collections.Counter(c for r in results for c in r["culprits"])
    combo = [r["id"] for r in results if not r["culprits"]]
    print(f"{RUN.name} rule_set={RULE_SET}: {len(results)} regressions, {len(combo)} only in combination")
    for style, count in by_style.most_common():
        print(f"  {count:4d}  {style}")
    if combo:
        print("  combination-only:", " ".join(combo[:20]))


if __name__ == "__main__":
    main()
