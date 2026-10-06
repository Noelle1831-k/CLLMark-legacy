#!/usr/bin/env python3
"""Audit watermark rule pairs on the benchmark corpus.

For every pair (bit-0 style, bit-1 style) of cllmark.rules.pairs it reports, over the unique
files of the configured cohorts:

* applicable    files where either direction changes the code (the pair's capacity),
* forms         files already entirely in the bit-0 form / bit-1 form (bit 0 should be the
                usual form, which keeps unmarked code from matching a codeword),
* idempotence   applying a direction twice equals applying it once,
* reversibility to0(to1(code)) == to0(code) and to1(to0(code)) == to1(code),
* syntax        rewrites that add parse errors,
* interference  probes of *other* pairs that change after applying this pair (watermark
                extraction assumes pairs do not affect each other).

Usage: tools/rule_audit.py --language python [--pairs name ...] [--against all|audited] [--limit N]
                           [--extra-root DIR ...] [--examples N] [--rule-set legacy|extended]

For JavaScript the pinned project checkouts of the benchmark cache (.benchmark-cache/js-projects, without
node_modules, test and dist directories) are audited in addition to the configured cohorts; their files
that equal a cohort file are counted once. --extra-root adds more source trees for any language.
"""

import argparse
import collections
import hashlib
import json
import os
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

STATE = {}


EXCLUDED_DIRECTORIES = {"node_modules", "test", "tests", "dist", ".git"}
DEFAULT_EXTRA_ROOTS = {"javascript": [".benchmark-cache/js-projects"]}


def extra_sources(language, roots):
    """Source files below `roots` (relative to the repository), skipping dependency, test and build output."""
    from benchmarks.common import EXTENSIONS

    found = []
    for root in roots:
        for directory, names, filenames in os.walk(ROOT / root):
            names[:] = sorted(name for name in names if name not in EXCLUDED_DIRECTORIES)
            found += [
                os.path.relpath(os.path.join(directory, name), ROOT)
                for name in sorted(filenames)
                if name.endswith(EXTENSIONS[language])
            ]
    return found


def corpus(language, limit, extra_roots=()):
    from benchmarks.common import discover_units

    config = json.loads((ROOT / "benchmarks" / "config.json").read_text())
    units, _ = discover_units(ROOT, config)
    seen, files = set(), []
    candidates = [relative for unit in units if unit["language"] == language for relative in unit["source_files"]]
    candidates += extra_sources(language, extra_roots)
    for relative in candidates:
        key = hashlib.sha256((ROOT / relative).read_bytes()).hexdigest()
        if key not in seen:
            seen.add(key)
            files.append(relative)
    return files[:: max(1, len(files) // limit)] if limit else files


def initialize(language, audited, against, rule_set="legacy"):
    os.chdir(ROOT)
    from cllmark.transform import StyleTransformer

    transformer = StyleTransformer(language, rule_set=rule_set)
    STATE.update(transformer=transformer, pairs=transformer.pairs, audited=audited, against=against)


def probe(style, code):
    from cllmark.watermark import probe as probe_style

    return probe_style(STATE["transformer"], style, code)


def change(style, code):
    return STATE["transformer"].apply(style, code)[0]


def errors(code):
    count, stack = 0, [STATE["transformer"].parse(code).root_node]
    while stack:
        node = stack.pop()
        count += node.is_error or node.is_missing
        stack.extend(node.children)
    return count


def audit_file(relative):
    from cllmark.source_io import read_source
    from cllmark.watermark import DETECT_ONLY

    try:
        code = read_source(ROOT / relative)
    except ValueError:
        return {}
    pairs, result = STATE["pairs"], {}
    baseline_errors = errors(code)
    before = {style: probe(style, code) for name in STATE["against"] for style in pairs[name]}
    for name in STATE["audited"]:
        zero, one = pairs[name]
        if zero in DETECT_ONLY or one in DETECT_ONLY:
            continue
        counts = collections.Counter()
        to_zero, to_one = change(zero, code), change(one, code)
        if to_zero == code and to_one == code:
            continue
        counts["applicable"] += 1
        counts["form0"] += to_zero == code
        counts["form1"] += to_one == code
        for style, rewritten in [(zero, to_zero), (one, to_one)]:
            counts["idempotence_trials"] += 1
            counts["idempotence_failures"] += change(style, rewritten) != rewritten
            counts["syntax_regressions"] += errors(rewritten) > baseline_errors
        counts["reversibility_trials"] += 2
        counts["reversibility_failures"] += (change(zero, to_one) != to_zero) + (change(one, to_zero) != to_one)
        interference = collections.Counter()
        for rewritten in {to_zero, to_one} - {code}:
            for other in STATE["against"]:
                if other == name:
                    continue
                if any(probe(style, rewritten) != before[style] for style in pairs[other]):
                    interference[other] += 1
        result[name] = {"counts": counts, "interference": interference, "file": relative}
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--language", required=True, choices=["python", "c", "cpp", "javascript"])
    parser.add_argument("--pairs", nargs="*", help="pairs to audit (default: all)")
    parser.add_argument("--against", choices=["all", "audited"], default="all", help="pairs checked for interference")
    parser.add_argument("--limit", type=int, default=0, help="audit about this many files (default: all)")
    parser.add_argument("--jobs", type=int, default=8)
    parser.add_argument(
        "--extra-root",
        action="append",
        default=None,
        metavar="DIR",
        help="additional source tree (relative to the repository); default for javascript: .benchmark-cache/js-projects",
    )
    parser.add_argument("--examples", type=int, default=5, help="files listed per failure kind in the report")
    parser.add_argument(
        "--rule-set", choices=["legacy", "extended"], default="legacy", help="audit the pairs of this rule set"
    )
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    from cllmark.rules.pairs import watermark_pairs

    pairs = watermark_pairs(args.language, args.rule_set)
    names = list(pairs)
    audited = args.pairs or names
    against = names if args.against == "all" else audited
    extra = DEFAULT_EXTRA_ROOTS.get(args.language, []) if args.extra_root is None else args.extra_root
    files = corpus(args.language, args.limit, [root for root in extra if (ROOT / root).is_dir()])
    totals = {name: collections.Counter() for name in audited}
    interference = {name: collections.Counter() for name in audited}
    examples = collections.defaultdict(list)
    with ProcessPoolExecutor(
        args.jobs, initializer=initialize, initargs=(args.language, audited, against, args.rule_set)
    ) as pool:
        for result in pool.map(audit_file, files, chunksize=20):
            for name, value in result.items():
                totals[name].update(value["counts"])
                interference[name].update(value["interference"])
                for key in ["idempotence_failures", "reversibility_failures", "syntax_regressions"]:
                    if value["counts"][key] and len(examples[name + ":" + key]) < args.examples:
                        examples[name + ":" + key].append(value["file"])
                for other in value["interference"]:
                    if len(examples[name + ":interferes:" + other]) < args.examples:
                        examples[name + ":interferes:" + other].append(value["file"])
    report = {"language": args.language, "rule_set": args.rule_set, "files": len(files), "pairs": {}}
    print(f"{args.language}: {len(files)} unique files")
    print(
        f"{'pair':28} {'applic.':>7} {'form0':>6} {'form1':>6} {'idem.fail':>9} {'rev.fail':>8} {'syntax':>6}  interference"
    )
    for name in audited:
        c = totals[name]
        report["pairs"][name] = {
            "styles": list(pairs[name]),
            **c,
            "interference": dict(interference[name]),
        }
        worst = ", ".join(f"{other}:{count}" for other, count in interference[name].most_common(4))
        print(
            f"{name:28} {c['applicable']:7} {c['form0']:6} {c['form1']:6} {c['idempotence_failures']:9} "
            f"{c['reversibility_failures']:8} {c['syntax_regressions']:6}  {worst}"
        )
    report["examples"] = examples
    if args.output:
        args.output.write_text(json.dumps(report, indent=1))


if __name__ == "__main__":
    main()
