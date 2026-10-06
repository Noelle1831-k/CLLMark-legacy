#!/usr/bin/env python3
"""Why did a benchmark run lose embedding capacity compared with a reference run?

For every unit that is eligible in the BASELINE rows but not in the CANDIDATE rows, and every
(file, rule) slot the baseline had and the candidate lacks, the rule pair is applied to the unit's
source with the code under --source-root (default: this repository):

* recovered  the pair applies now (either style changes the code, or the detect-only target form exists),
* rejected   it still does not; the reason lists, per style of the pair, the most common failed guard, the
             `Reject` message of the rewrite, or (declare 6.2) why a declaration may not join the first one.

Read-only: nothing is written into the run directories. Source files come from `<run>/inputs/` of the
candidate run (frozen copies), falling back to the baseline run, or --inputs.

Usage: tools/lost_capacity_report.py BASELINE_ROWS CANDIDATE_ROWS [--source-root DIR] [--inputs DIR] [--output FILE]
Output TSV columns: unit_id cohort rule style outcome reason first_line_of_matched_node
"""

import argparse
import collections
import json
import os
from pathlib import Path
import sys

REPOSITORY = Path(__file__).resolve().parents[1]
COLUMNS = ['unit_id', 'cohort', 'rule', 'style', 'outcome', 'reason', 'first_line_of_matched_node']


def load_rows(path):
    return {row['id']: row for row in map(json.loads, Path(path).read_text().splitlines()) if row}


def lost_units(baseline, candidate):
    return [name for name, row in baseline.items() if row['eligible'] and name in candidate and not candidate[name]['eligible']]


def missing_slots(base_row, candidate_row):
    """(file, rule) slots of the baseline unit the candidate lacks, with the baseline's style for each."""
    wanted = collections.Counter((slot['file'], slot['rule']) for slot in base_row['embedding_slots'])
    wanted.subtract(collections.Counter((slot['file'], slot['rule']) for slot in candidate_row['embedding_slots']))
    styles = {(slot['file'], slot['rule']): slot['style'] for slot in base_row['embedding_slots']}
    return [(key, styles[key]) for key, count in sorted(wanted.items()) for _ in range(max(count, 0))]


class Explainer:
    """Imports the rule code of one source tree and judges rule pairs on code."""

    def __init__(self, source_root):
        source_root = str(Path(source_root).resolve())
        sys.path.insert(0, source_root)
        os.chdir(source_root)
        import change_program_style
        import rule_dict_bit_acc
        import rule_engine
        import watermark_core
        self.change_program_style, self.rule_dict = change_program_style, rule_dict_bit_acc.rule_dict
        self.Reject, self.watermark_core = rule_engine.Reject, watermark_core
        self.transformers = {}

    def scts(self, language):
        if language not in self.transformers:
            self.transformers[language] = self.change_program_style.SCTS(language)
        return self.transformers[language]

    def resolve(self, scts, style):
        """(rule, detect-only?) behind a style: detect-only styles probe the target form of their partner."""
        detect = self.watermark_core.DETECT_ONLY.get(style)
        return scts.rules[detect or style], detect is not None

    @staticmethod
    def line_of(node):
        if node is None:
            return ''
        first = node.text.decode('utf-8', 'replace').split('\n', 1)[0].strip()
        return f'{node.start_point[0] + 1}:{first[:80]}'

    def accepted_node(self, scts, style, code):
        """The first node a rewrite of `style` changes (or, for a detect-only style, the target form)."""
        rule, detect = self.resolve(scts, style)
        parsed = scts.grammar.parse(code)
        if detect:
            nodes = parsed.candidates(rule.target)
            return nodes[0] if nodes else None
        for node in parsed.candidates(rule):
            try:
                if rule.rewrite(node, parsed.source):
                    return node
            except self.Reject:
                continue
        return None

    def declaration_reasons(self, parsed, rule):
        """declare 6.2: [(reason, declaration)] for each declaration that may not join the first one."""
        module = sys.modules[rule.rewrite.__module__]
        kinds_of, blocker = getattr(module, 'declaration_kinds', None), getattr(module, 'hoist_blocker', None)
        reasons = []
        for block in parsed.candidates(rule):
            if kinds_of is None or blocker is None:
                reasons.append(('no declaration may join the first one (reason not available in this source tree)', block))
                continue
            for kind, group in kinds_of(block).items():
                if len(group) < 2:
                    continue
                if module.untyped_kind(kind):
                    reasons.append(('auto/decltype declarations are not merged', group[1]))
                    continue
                kept = [group[0]]
                for declaration in group[1:]:
                    reason = blocker(block, group[0], declaration, kept)
                    if reason is None:
                        kept.append(declaration)
                    else:
                        reasons.append((reason, declaration))
        return reasons

    def rejections(self, scts, style, code):
        """[(reason, node)] why `style` leaves `code` alone."""
        rule, detect = self.resolve(scts, style)
        parsed = scts.grammar.parse(code)
        if detect:
            return [(f'detect-only style {style}: no loop in the form {self.watermark_core.DETECT_ONLY[style]} produces', None)]
        raw = parsed._captured.get(f'm{scts.grammar.matchers[rule]}', [])
        if not raw:
            return [('no syntactic candidate', None)]
        reasons = []
        for node in raw:
            failed = rule.explain(node)
            if failed:
                reasons.append(('guard failed: ' + ', '.join(failed), node))
                continue
            try:
                edits = rule.rewrite(node, parsed.source)
            except self.Reject as error:
                reasons.append(('rejected: ' + str(error), node))
                continue
            if edits:
                reasons.append(('accepted', node))
            elif rule.rewrite.__name__ == 'merge_declarations':
                reasons += self.declaration_reasons(parsed, rule) or [('no repeated declaration kind to merge', node)]
            else:
                reasons.append(('rewrite produced no edit', node))
        return reasons

    def diagnose(self, language, rule_name, baseline_style, code):
        """(style, outcome, reason, first line) of one rule pair on one file."""
        scts = self.scts(language)
        styles = self.rule_dict[language][rule_name]
        for style in styles:
            if self.watermark_core.probe(scts, style, code):
                return style, 'recovered', '', self.line_of(self.accepted_node(scts, style, code))
        verdicts = []
        for style in styles:
            found = self.rejections(scts, style, code)
            if all(reason == 'no syntactic candidate' or reason.startswith('detect-only') for reason, _ in found):
                continue
            # Reasons of candidates that passed every guard outrank guard failures (most nodes fail a guard).
            deep = [item for item in found if not item[0].startswith('guard failed')] or found
            common = collections.Counter(reason for reason, _ in deep).most_common(1)[0][0]
            # The closest style: most candidates that passed every guard (else most candidates).
            score = (sum(not reason.startswith('guard failed') for reason, _ in found), len(found))
            verdicts.append((score, style, common, next(node for reason, node in deep if reason == common)))
        if not verdicts:
            return baseline_style, 'rejected', 'no syntactic candidate for either style', ''
        closest = max(verdicts, key=lambda verdict: verdict[0])
        reason = ' || '.join(f'{style}: {common}' for _, style, common, _ in verdicts)
        return baseline_style, 'rejected', reason, self.line_of(closest[3])


def clean(value):
    return str(value).replace('\t', ' ').replace('\n', ' ')


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('baseline_rows')
    parser.add_argument('candidate_rows')
    parser.add_argument('--source-root', default=str(REPOSITORY), help='tree whose rule code explains the outcome')
    parser.add_argument('--inputs', help='directory holding the unit source files (default: <run>/inputs)')
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    baseline, candidate = load_rows(args.baseline_rows), load_rows(args.candidate_rows)
    input_roots = [Path(args.inputs)] if args.inputs else [Path(path).resolve().parent / 'inputs' for path in [args.candidate_rows, args.baseline_rows]]
    if args.output:
        args.output = args.output.resolve()
    explainer = Explainer(args.source_root)
    from code_io import read_source

    def source(relative):
        for root in input_roots:
            if (root / relative).is_file():
                return read_source(root / relative)
        raise FileNotFoundError(relative)

    lines, per_rule, recoverable, lost = [], collections.Counter(), [], lost_units(baseline, candidate)
    for name in lost:
        base_row, candidate_row = baseline[name], candidate[name]
        files = {Path(relative).name: relative for relative in base_row['source_files']}
        outcomes = []
        for (filename, rule_name), style in missing_slots(base_row, candidate_row):
            style, outcome, reason, line = explainer.diagnose(base_row['language'], rule_name, style, source(files[filename]))
            outcomes.append(outcome)
            per_rule[(rule_name, outcome)] += 1
            lines.append('\t'.join(clean(value) for value in [name, base_row['cohort'], rule_name, style, outcome, reason, line]))
        recovered = outcomes.count('recovered')
        if outcomes and recovered == len(outcomes) and candidate_row['capacity'] + recovered >= candidate_row['required_capacity']:
            recoverable.append(name)
    report = '\t'.join(COLUMNS) + '\n' + '\n'.join(lines) + '\n'
    if args.output:
        args.output.write_text(report)
    else:
        sys.stdout.write(report)
    print(f'lost eligible units: {len(lost)}; recoverable (every missing slot recovered, capacity reaches the requirement): {len(recoverable)}',
          file=sys.stderr)
    for (rule_name, outcome), count in sorted(per_rule.items()):
        print(f'  {rule_name:20} {outcome:10} {count}', file=sys.stderr)
    reasons = collections.Counter((fields[2], part) for fields in (line.split('\t') for line in lines) if fields[4] == 'rejected'
                                  for part in fields[5].split(' || '))
    for (rule_name, reason), count in reasons.most_common(12):
        print(f'  rejected {count:3} {rule_name} {reason}', file=sys.stderr)


if __name__ == '__main__':
    main()
