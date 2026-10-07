#!/usr/bin/env python3
"""Calibrate the stable rule pairs of the robust watermark (docs/plans/2026-10-07-robust-watermark.md, v4).

For every (rule set, language, anchor, rule pair) the tool counts, over a deterministic sample of the default
corpus, the usable sites and those whose anchor key survives the self-stability check of `cllmark.robust`
(`observe(..., stability=True)`). A pair enters the whitelist when its stable share is at least --min-ratio and it
has at least --min-usable usable sites. The whitelist is written to `cllmark/robust/stable_pairs.json`; selection
(embedding and detection) uses only those pairs, so detection needs no per-site stability check.

Corpus: the cohorts of `benchmarks/config.json` whose role is `generated` or `human`, without the CodeNet cohorts
(which are the evaluation data) and without the `_subset` duplicates and the whole-repository `js_repos` cohort (its
files appear as `js_repo_files`). Files above --max-bytes are skipped; at most --function-files (function level) or
--project-files (project and project-file level) files per cohort are taken, sampled with the config seed.

Usage: tools/robust_calibrate.py [--output cllmark/robust/stable_pairs.json] [--jobs N] [--limit-files N]
"""

import argparse
import collections
import json
import os
import random
import subprocess
import sys
import time
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

REPOSITORY = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPOSITORY))

ANCHORS = ("tok", "struct")
RULE_SETS = ("legacy", "extended")
LANGUAGES = ("python", "c", "cpp", "javascript")
ROLES = ("generated", "human")
SKIPPED_COHORTS = {"js_repos"}  # whole repositories; the same files are the js_repo_files cohort
_TRANSFORMERS = {}


def git_head(path):
    result = subprocess.run(["git", "-C", str(path), "rev-parse", "HEAD"], capture_output=True, text=True, check=False)
    return result.stdout.strip() or "unknown"


def calibration_files(config, root, function_files, project_files, max_bytes):
    """{language: [(cohort, relative path)]}: the sample of the default corpus, in a fixed order."""
    from benchmarks import common

    units, _ = common.discover_units(root, config)
    by_cohort = collections.OrderedDict()
    for unit in units:
        name = unit["id"].split("/", 1)[0]
        if (
            unit["role"] not in ROLES
            or name in SKIPPED_COHORTS
            or name.endswith("_subset")
            or "codenet" in name.lower()
            or "CodeNet" in unit["path"]
        ):
            continue
        for relative in unit["source_files"]:
            if (Path(root) / relative).stat().st_size <= max_bytes:
                by_cohort.setdefault((unit["language"], name, unit["level"]), []).append(relative)
    rng = random.Random(config["seed"])
    chosen = {language: [] for language in LANGUAGES}
    for (language, name, level), files in by_cohort.items():
        files = sorted(set(files))
        budget = function_files if level == "function" else project_files
        if len(files) > budget:
            files = sorted(rng.sample(files, budget))
        chosen[language] += [(name, relative) for relative in files]
    return chosen


def observe_file(job):
    """Per (rule set, anchor): {pair: [usable, stable]} of one file."""
    root, language, relative, rule_sets = job
    from cllmark.robust import observe
    from cllmark.source_io import read_source
    from cllmark.transform import StyleTransformer

    code = read_source(Path(root) / relative)
    result = {}
    for rule_set in rule_sets:
        transformer = _TRANSFORMERS.get((language, rule_set))
        if transformer is None:
            transformer = _TRANSFORMERS[(language, rule_set)] = StyleTransformer(language, rule_set=rule_set)
        for anchor in ANCHORS:
            counts = {}
            for site in observe(transformer, language, {"f": code}, anchor, stability=True):
                if site.usable:
                    entry = counts.setdefault(site.pair, [0, 0])
                    entry[0] += 1
                    entry[1] += bool(site.stable)
            result[(rule_set, anchor)] = counts
    return language, relative, result


def calibrate(args):
    config = json.loads((REPOSITORY / args.config).read_text())
    root = REPOSITORY
    files = calibration_files(config, root, args.function_files, args.project_files, args.max_bytes)
    if args.limit_files:
        files = {language: items[: args.limit_files] for language, items in files.items()}
    jobs = [(str(root), language, relative, RULE_SETS) for language, items in files.items() for _, relative in items]
    totals = {}
    started = time.time()
    with ProcessPoolExecutor(max_workers=args.jobs) as pool:
        for done, (language, _, result) in enumerate(pool.map(observe_file, jobs, chunksize=4), 1):
            for (rule_set, anchor), counts in result.items():
                table = totals.setdefault((rule_set, language, anchor), {})
                for pair, (usable, stable) in counts.items():
                    entry = table.setdefault(pair, [0, 0])
                    entry[0] += usable
                    entry[1] += stable
            if done % 100 == 0:
                print(f"{done}/{len(jobs)} files, {time.time() - started:.0f}s", file=sys.stderr, flush=True)
    from cllmark.rules.pairs import watermark_pairs

    pairs = {}
    for rule_set in RULE_SETS:
        for language in LANGUAGES:
            order = list(watermark_pairs(language, rule_set))
            for anchor in ANCHORS:
                stats = totals.get((rule_set, language, anchor), {})
                allowed, excluded = [], {}
                for pair in order:
                    usable, stable = stats.get(pair, [0, 0])
                    share = stable / usable if usable else 0.0
                    if usable >= args.min_usable and share >= args.min_ratio:
                        allowed.append(pair)
                    else:
                        excluded[pair] = (
                            f"{usable} usable sites (< {args.min_usable})"
                            if usable < args.min_usable
                            else f"stable share {share:.3f} (< {args.min_ratio})"
                        )
                pairs.setdefault(rule_set, {}).setdefault(language, {})[anchor] = {
                    "allowed": allowed,
                    "excluded": excluded,
                    "stats": {pair: stats.get(pair, [0, 0]) for pair in order},
                }
    return {
        "criteria": {"min_ratio": args.min_ratio, "min_usable": args.min_usable},
        "calibration": {
            "source_commit": git_head(REPOSITORY),
            "corpus_commit": git_head(REPOSITORY / "corpus"),
            "config": args.config,
            "seed": config["seed"],
            "max_bytes": args.max_bytes,
            "files": {language: len(items) for language, items in files.items()},
            "cohorts": {
                language: dict(collections.Counter(name for name, _ in items)) for language, items in files.items()
            },
        },
        "pairs": pairs,
    }


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("--config", default="benchmarks/config.json")
    parser.add_argument("--output", default="cllmark/robust/stable_pairs.json")
    parser.add_argument("--min-ratio", type=float, default=0.95)
    parser.add_argument("--min-usable", type=int, default=50)
    parser.add_argument("--function-files", type=int, default=1000, help="files per function-level cohort at most")
    parser.add_argument("--project-files", type=int, default=300, help="files per project-level cohort at most")
    parser.add_argument("--max-bytes", type=int, default=40000)
    parser.add_argument("--limit-files", type=int, default=0, help="files per language at most (debugging)")
    parser.add_argument("--jobs", type=int, default=os.cpu_count() or 1)
    args = parser.parse_args(argv)
    table = calibrate(args)
    output = Path(args.output)
    output.write_text(json.dumps(table, indent=1) + "\n", encoding="utf-8")
    for rule_set, languages in table["pairs"].items():
        for language, anchors in languages.items():
            for anchor, entry in anchors.items():
                print(
                    f"{rule_set:9} {language:10} {anchor:7} allowed {len(entry['allowed']):2}  excluded "
                    f"{len(entry['excluded']):2}  {' '.join(entry['excluded'])}"
                )
    print("wrote", output)


if __name__ == "__main__":
    main()
