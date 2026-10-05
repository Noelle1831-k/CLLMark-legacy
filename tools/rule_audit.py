#!/usr/bin/env python3
"""Audit watermark rule pairs on the benchmark corpus.

For every pair (bit-0 style, bit-1 style) of rule_dict_bit_acc it reports, over the unique
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
"""

import argparse
import collections
import hashlib
import json
import os
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

STATE = {}


def corpus(language, limit):
    from benchmarks.common import discover_units
    config = json.loads((ROOT / 'benchmarks' / 'config.json').read_text())
    units, _ = discover_units(ROOT, config)
    seen, files = set(), []
    for unit in units:
        if unit['language'] != language:
            continue
        for relative in unit['source_files']:
            key = hashlib.sha256((ROOT / relative).read_bytes()).hexdigest()
            if key not in seen:
                seen.add(key)
                files.append(relative)
    return files[::max(1, len(files) // limit)] if limit else files


def initialize(language, audited, against):
    os.chdir(ROOT)
    from change_program_style import SCTS
    import rule_dict_bit_acc
    STATE.update(scts=SCTS(language), pairs=rule_dict_bit_acc.rule_dict[language], audited=audited, against=against)


def probe(style, code):
    import watermark_core
    return watermark_core.probe(STATE['scts'], style, code)


def change(style, code):
    return STATE['scts'].change_file_style(style, code)[0]


def errors(code):
    count, stack = 0, [STATE['scts'].parse(code).root_node]
    while stack:
        node = stack.pop()
        count += node.is_error or node.is_missing
        stack.extend(node.children)
    return count


def audit_file(relative):
    from code_io import read_source
    import watermark_core
    try:
        code = read_source(ROOT / relative)
    except ValueError:
        return {}
    pairs, result = STATE['pairs'], {}
    baseline_errors = errors(code)
    before = {style: probe(style, code) for name in STATE['against'] for style in pairs[name]}
    for name in STATE['audited']:
        zero, one = pairs[name]
        if zero in watermark_core.DETECT_ONLY or one in watermark_core.DETECT_ONLY:
            continue
        counts = collections.Counter()
        to_zero, to_one = change(zero, code), change(one, code)
        if to_zero == code and to_one == code:
            continue
        counts['applicable'] += 1
        counts['form0'] += to_zero == code
        counts['form1'] += to_one == code
        for style, rewritten in [(zero, to_zero), (one, to_one)]:
            counts['idempotence_trials'] += 1
            counts['idempotence_failures'] += change(style, rewritten) != rewritten
            counts['syntax_regressions'] += errors(rewritten) > baseline_errors
        counts['reversibility_trials'] += 2
        counts['reversibility_failures'] += (change(zero, to_one) != to_zero) + (change(one, to_zero) != to_one)
        interference = collections.Counter()
        for rewritten in {to_zero, to_one} - {code}:
            for other in STATE['against']:
                if other == name:
                    continue
                if any(probe(style, rewritten) != before[style] for style in pairs[other]):
                    interference[other] += 1
        result[name] = {'counts': counts, 'interference': interference, 'file': relative}
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--language', required=True, choices=['python', 'c', 'cpp', 'javascript'])
    parser.add_argument('--pairs', nargs='*', help='pairs to audit (default: all)')
    parser.add_argument('--against', choices=['all', 'audited'], default='all', help='pairs checked for interference')
    parser.add_argument('--limit', type=int, default=0, help='audit about this many files (default: all)')
    parser.add_argument('--jobs', type=int, default=8)
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    import rule_dict_bit_acc
    names = list(rule_dict_bit_acc.rule_dict[args.language])
    audited = args.pairs or names
    against = names if args.against == 'all' else audited
    files = corpus(args.language, args.limit)
    totals = {name: collections.Counter() for name in audited}
    interference = {name: collections.Counter() for name in audited}
    examples = collections.defaultdict(list)
    with ProcessPoolExecutor(args.jobs, initializer=initialize, initargs=(args.language, audited, against)) as pool:
        for result in pool.map(audit_file, files, chunksize=20):
            for name, value in result.items():
                totals[name].update(value['counts'])
                interference[name].update(value['interference'])
                for key in ['idempotence_failures', 'reversibility_failures', 'syntax_regressions']:
                    if value['counts'][key] and len(examples[name + ':' + key]) < 5:
                        examples[name + ':' + key].append(value['file'])
                for other in value['interference']:
                    if len(examples[name + ':interferes:' + other]) < 5:
                        examples[name + ':interferes:' + other].append(value['file'])
    report = {'language': args.language, 'files': len(files), 'pairs': {}}
    print(f"{args.language}: {len(files)} unique files")
    print(f"{'pair':28} {'applic.':>7} {'form0':>6} {'form1':>6} {'idem.fail':>9} {'rev.fail':>8} {'syntax':>6}  interference")
    for name in audited:
        c = totals[name]
        report['pairs'][name] = {'styles': rule_dict_bit_acc.rule_dict[args.language][name], **c,
                                 'interference': dict(interference[name])}
        worst = ', '.join(f'{other}:{count}' for other, count in interference[name].most_common(4))
        print(f"{name:28} {c['applicable']:7} {c['form0']:6} {c['form1']:6} {c['idempotence_failures']:9} "
              f"{c['reversibility_failures']:8} {c['syntax_regressions']:6}  {worst}")
    report['examples'] = examples
    if args.output:
        args.output.write_text(json.dumps(report, indent=1))


if __name__ == '__main__':
    main()
