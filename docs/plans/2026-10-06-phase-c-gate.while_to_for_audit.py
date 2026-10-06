"""while_to_for (7.8 rewrite; 12 is detect-only) audit: rule_audit.py skips pairs with a detect-only side.

Usage: agentab_wtf_audit.py ROOT LANGUAGE OUTPUT   (run with PYTHONHASHSEED=20261005)
Measures, over the unique corpus files of the language: applicable (7.8 changes the code),
idempotence (7.8 twice == once), syntax regressions, detection (style 12 sees the output),
interference (other pairs' probes change after the rewrite).
"""
import collections, json, sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

ROOT, LANG, OUT = Path(sys.argv[1]).resolve(), sys.argv[2], Path(sys.argv[3])
sys.path.insert(0, str(ROOT))
import tools.rule_audit as ra

def init(language):
    ra.initialize(language, ['while_to_for'], list(__import__('rule_dict_bit_acc').rule_dict[language]))

def one(relative):
    from code_io import read_source
    import watermark_core
    try:
        code = read_source(ROOT / relative)
    except ValueError:
        return None
    pairs, scts = ra.STATE['pairs'], ra.STATE['scts']
    new = ra.change('7.8', code)
    if new == code:
        return None
    c = collections.Counter(applicable=1)
    c['idempotence_failures'] += ra.change('7.8', new) != new
    c['syntax_regressions'] += ra.errors(new) > ra.errors(code)
    c['detected_by_12'] += watermark_core.probe(scts, '12', new) is True
    c['empty_update_clause'] += '; )' in new and '; )' not in code
    inter = collections.Counter()
    for other in ra.STATE['against']:
        if other == 'while_to_for':
            continue
        if any(ra.probe(s, new) != ra.probe(s, code) for s in pairs[other]):
            inter[other] += 1
    return c, inter, relative

if __name__ == '__main__':
    import os
    os.chdir(ROOT)
    files = ra.corpus(LANG, 0)
    total, inter, ex = collections.Counter(), collections.Counter(), collections.defaultdict(list)
    with ProcessPoolExecutor(8, initializer=init, initargs=(LANG,)) as pool:
        for r in pool.map(one, files, chunksize=20):
            if r is None:
                continue
            c, i, rel = r
            total.update(c); inter.update(i)
            for k in ['idempotence_failures', 'syntax_regressions']:
                if c[k] and len(ex[k]) < 5:
                    ex[k].append(rel)
            for k in i:
                if len(ex['interferes:' + k]) < 5:
                    ex['interferes:' + k].append(rel)
    OUT.write_text(json.dumps({'language': LANG, 'files': len(files), 'pair': 'while_to_for (7.8 only)',
                               **total, 'interference': dict(inter), 'examples': ex}, indent=1))
    print(OUT.read_text())
