#!/usr/bin/env python3
"""Build the JavaScript MBXP cohorts from MBJSP problems and LLM completions.

Each unit is a complete function: the signature line that ends the MBJSP prompt followed
by the completion (canonical solution -> corpus/dataset/MBJSP_H, generated completion ->
corpus/dataset/MBJSP_G). The problem file is copied to corpus/dataset/Jsonl for the functional oracle.
Running it twice produces identical files.

Usage: tools/import_mbjsp.py PROBLEMS.jsonl GENERATED.jsonl
"""

import argparse
import hashlib
import json
from pathlib import Path
import shutil

ROOT = Path(__file__).resolve().parents[1]


def signature(prompt):
    """The last non-empty prompt line, e.g. `function minCost(cost, m, n) {`."""
    return [line for line in prompt.splitlines() if line.strip()][-1]


def write_units(rows, problems, directory, field):
    directory.mkdir(parents=True, exist_ok=True)
    written = 0
    for row in rows:
        body = row.get(field) or ''
        problem = problems[row['task_id']]
        if not body.strip() or problem['entry_point'] not in signature(problem['prompt']):
            continue
        name = row['task_id'].replace('/', '_') + '.js'
        (directory / name).write_text(signature(problem['prompt']) + '\n' + body.rstrip() + '\n', encoding='utf-8')
        written += 1
    return written


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('problems', type=Path)
    parser.add_argument('generated', type=Path)
    args = parser.parse_args()
    problems = {row['task_id']: row for row in map(json.loads, args.problems.read_text(encoding='utf-8').splitlines()) if row}
    generated = [json.loads(line) for line in args.generated.read_text(encoding='utf-8').splitlines() if line.strip()]
    target = ROOT / 'corpus' / 'dataset' / 'Jsonl'
    shutil.copyfile(args.problems, target / args.problems.name)
    shutil.copyfile(args.generated, target / args.generated.name)
    human = write_units(sorted(problems.values(), key=lambda row: int(row['task_id'].split('/')[1])), problems,
                        ROOT / 'corpus' / 'dataset' / 'MBJSP_H', 'canonical_solution')
    machine = write_units(sorted(generated, key=lambda row: int(row['task_id'].split('/')[1])), problems,
                          ROOT / 'corpus' / 'dataset' / 'MBJSP_G', 'completion')
    provenance = {name: hashlib.sha256((target / name).read_bytes()).hexdigest() for name in [args.problems.name, args.generated.name]}
    print(json.dumps({'human_units': human, 'generated_units': machine, 'sources_sha256': provenance}, indent=2))


if __name__ == '__main__':
    main()
