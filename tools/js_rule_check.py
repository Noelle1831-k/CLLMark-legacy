#!/usr/bin/env python3
"""Read-only statistics and functional checks of the JavaScript rewrite rules.

  forms           per rule pair, how many sites of the corpus are in each of the two forms (decides which form
                  is bit 0: the usual one, so that unmarked code reads as all zeros)
  functional      rewrite every MBJSP problem with every style that applies to it, run the MBXP test on the
                  original and the rewritten solution with the benchmark's own JavaScript oracle
                  (benchmarks/utility.py) and count solutions that pass before and fail after
  capacity        per MBJSP unit, which rule pairs apply (a unit embeds only with 7 slots), as JSON
  capacity-table  join two `capacity` outputs (before / after a change) into a TSV

The corpora are never written: rewrites live in temporary directories.
"""

import argparse
import collections
import json
import os
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / "tools"))

MBJSP = {"MBJSP_H": "corpus/dataset/MBJSP_H", "MBJSP_G": "corpus/dataset/MBJSP_G"}
SLOTS = 7


def transformer():
    from cllmark.transform import StyleTransformer

    return StyleTransformer("javascript")


def read(path):
    from cllmark.source_io import read_source

    return read_source(path)


def pairs():
    from cllmark.rules.pairs import WATERMARK_PAIRS

    return WATERMARK_PAIRS["javascript"]


def project_files():
    """Unique project sources as the audit sees them (dataset copy plus the pinned checkouts without tests)."""
    import rule_audit

    files = rule_audit.corpus("javascript", 0, rule_audit.DEFAULT_EXTRA_ROOTS["javascript"])
    return [
        relative
        for relative in files
        if relative.startswith(("corpus/dataset/JS_projects", ".benchmark-cache/js-projects"))
    ]


def mbjsp_files(cohort):
    return sorted((ROOT / MBJSP[cohort]).glob("*.js"))


def write_table(output, header, rows):
    lines = ["\t".join(header)] + ["\t".join(str(cell) for cell in row) for row in rows]
    if output:
        Path(output).write_text("\n".join(lines) + "\n")
    print("\n".join(lines))


# ------------------------------------------------------------------ forms


def command_forms(args):
    """Sites per form. A style rewrites the form the pair does not list for it, so the candidates of style[1]
    are the sites already in the form style[0] produces (form 0) and vice versa."""
    parser = transformer()
    corpora = {name: mbjsp_files(name) for name in MBJSP}
    corpora["JS_projects"] = [ROOT / relative for relative in project_files()]
    sites = {pair: {name: [0, 0] for name in corpora} for pair in pairs()}
    files = {pair: {name: [0, 0] for name in corpora} for pair in pairs()}
    detect_only = {"11", "12"}
    for name, paths in corpora.items():
        for path in paths:
            parsed = parser.grammar.parse(read(path))
            for pair, styles in pairs().items():
                if any(style in detect_only for style in styles):
                    continue
                for form in [0, 1]:
                    count = len(parsed.candidates(parser.rules[styles[1 - form]]))
                    sites[pair][name][form] += count
                    files[pair][name][form] += count > 0
    names = list(corpora)
    header = (
        ["pair", "style0", "style1"]
        + [f"{name}_{kind}{form}" for name in names for kind in ["sites", "files"] for form in [0, 1]]
        + ["total_sites0", "total_sites1", "total_files0", "total_files1", "bit0_form_is_more_common", "note"]
    )
    rows = []
    for pair, styles in pairs().items():
        total0 = sum(sites[pair][name][0] for name in names)
        total1 = sum(sites[pair][name][1] for name in names)
        file0 = sum(files[pair][name][0] for name in names)
        file1 = sum(files[pair][name][1] for name in names)
        notes = []
        if total0 + total1 < 5:
            notes.append("fewer than 5 sites in the whole corpus")
        if total0 < total1:
            notes.append("bit 0 is the rarer form")
        rows.append(
            [pair, *styles]
            + [value for name in names for kind in [sites, files] for value in kind[pair][name]]
            + [total0, total1, file0, file1, total0 >= total1, "; ".join(notes)]
        )
    write_table(args.output, header, rows)


# ------------------------------------------------------------------ functional


def functional_context(cache):
    from benchmarks.common import javascript_environment
    from benchmarks.utility import load_problems

    config = json.loads((ROOT / "benchmarks" / "config.json").read_text())
    return {
        "config": config,
        "environment": {"javascript": javascript_environment(ROOT)},
        "problems": load_problems(ROOT, config),
        "cache": Path(cache),
    }


def run_oracle(context, name, code):
    """Status of the MBXP test for `code` as the solution of problem file `name` (MBJSP_17.js)."""
    from benchmarks.utility import evaluate_utility

    unit = {"oracle": "mbxp", "level": "function", "language": "javascript", "source_files": [name]}
    with tempfile.TemporaryDirectory(prefix="js-rule-check-") as temporary:
        directory = Path(temporary)
        (directory / name).write_text(code, encoding="utf-8")
        return evaluate_utility(
            unit, directory, context["problems"], context["config"], directory, context["environment"], context["cache"]
        )["status"]


def command_functional(args):
    parser = transformer()
    context = functional_context(args.cache or tempfile.mkdtemp(prefix="js-rule-check-cache-"))
    work = []
    for cohort in args.cohorts:
        for path in mbjsp_files(cohort):
            code = read(path)
            for style in [style for styles in pairs().values() for style in styles if args.style in [None, style]]:
                rewritten = parser.apply(style, code)[0]
                if rewritten != code:
                    work.append((cohort, style, path.name, code, rewritten))
    originals = {}

    def execute(item):
        cohort, _style, name, code, rewritten = item
        if (cohort, name) not in originals:
            originals[(cohort, name)] = run_oracle(context, name, code)
        return item, originals[(cohort, name)], run_oracle(context, name, rewritten)

    stats = collections.defaultdict(collections.Counter)
    examples = collections.defaultdict(list)
    with ThreadPoolExecutor(args.jobs) as pool:
        for (cohort, style, name, _, _), before, after in pool.map(execute, work):
            row = stats[(cohort, style)]
            row["applicable"] += 1
            row["original_pass"] += before == "PASS"
            row["rewritten_pass"] += after == "PASS"
            if before == "PASS" and after != "PASS":
                row["regressions"] += 1
                examples[(cohort, style)].append(f"{name}:{after}")
            row["fixed"] += before != "PASS" and after == "PASS"
            row["harness_status"] += before == "PASS" and after not in ["PASS", "FAIL"]
    header = [
        "cohort",
        "style",
        "pair",
        "applicable",
        "original_pass",
        "rewritten_pass",
        "regressions",
        "fixed",
        "harness_status",
        "regression_examples",
    ]
    pair_of = {style: pair for pair, styles in pairs().items() for style in styles}
    rows = [
        [
            cohort,
            style,
            pair_of[style],
            row["applicable"],
            row["original_pass"],
            row["rewritten_pass"],
            row["regressions"],
            row["fixed"],
            row["harness_status"],
            " ".join(examples[(cohort, style)][:5]),
        ]
        for (cohort, style), row in sorted(
            stats.items(), key=lambda item: (item[0][0], [int(part) for part in item[0][1].split(".")])
        )
    ]
    write_table(args.output, header, rows)
    print("rewritten solutions:", len(work), " regressions:", sum(row[6] for row in rows), file=sys.stderr)


# ------------------------------------------------------------------ capacity


def command_capacity(args):
    """Rule pairs applicable to each MBJSP unit (cllmark.watermark.analyze probes every pair)."""
    from cllmark import watermark

    parser = transformer()
    result = {
        cohort: {
            path.name: watermark.analyze(parser, "javascript", {path.name: read(path)})[path.name]
            for path in mbjsp_files(cohort)
        }
        for cohort in MBJSP
    }
    json.dump({"label": args.label, "pairs": list(pairs()), "cohorts": result}, sys.stdout, indent=1)


def command_capacity_table(args):
    before, after = json.loads(Path(args.before).read_text()), json.loads(Path(args.after).read_text())
    rows = []
    for cohort in after["cohorts"]:
        units = {"before": before["cohorts"][cohort], "after": after["cohorts"][cohort]}
        histogram = {when: collections.Counter(len(rules) for rules in units[when].values()) for when in units}
        rows.append(["summary", cohort, "units", len(units["before"]), len(units["after"])])
        rows.append(
            [
                "summary",
                cohort,
                f"units_with_capacity>={SLOTS}",
                *[sum(n for size, n in histogram[when].items() if size >= SLOTS) for when in units],
            ]
        )
        for size in range(max(max(histogram["before"]), max(histogram["after"])) + 1):
            rows.append(["units_by_capacity", cohort, size, histogram["before"][size], histogram["after"][size]])
        for pair in after["pairs"]:
            rows.append(
                [
                    "units_where_pair_applies",
                    cohort,
                    pair,
                    *[sum(pair in rules for rules in units[when].values()) for when in units],
                ]
            )
        eligible = {name for name, rules in units["after"].items() if len(rules) >= SLOTS}
        gained = {name for name in eligible if len(units["before"].get(name, [])) < SLOTS}
        for pair in after["pairs"]:
            rows.append(
                ["pair_in_eligible_units", cohort, pair, "", sum(pair in units["after"][name] for name in eligible)]
            )
            rows.append(
                ["pair_in_newly_eligible_units", cohort, pair, "", sum(pair in units["after"][name] for name in gained)]
            )
    write_table(args.output, ["section", "cohort", "key", "before", "after"], rows)


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    commands = parser.add_subparsers(dest="command", required=True)
    forms = commands.add_parser("forms")
    forms.add_argument("--output")
    forms.set_defaults(run=command_forms)
    functional = commands.add_parser("functional")
    functional.add_argument("--output")
    functional.add_argument("--cohorts", nargs="+", default=["MBJSP_H"], choices=list(MBJSP))
    functional.add_argument("--style", help="check only this style")
    functional.add_argument("--cache", help="directory for the oracle cache (default: a temporary one)")
    functional.add_argument("--jobs", type=int, default=8)
    functional.set_defaults(run=command_functional)
    capacity = commands.add_parser("capacity")
    capacity.add_argument("--label", default="")
    capacity.set_defaults(run=command_capacity)
    table = commands.add_parser("capacity-table")
    table.add_argument("--before", required=True)
    table.add_argument("--after", required=True)
    table.add_argument("--output")
    table.set_defaults(run=command_capacity_table)
    args = parser.parse_args()
    os.chdir(ROOT)
    args.run(args)


if __name__ == "__main__":
    main()
