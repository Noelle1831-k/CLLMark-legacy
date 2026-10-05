"""In-memory watermark analysis, embedding and extraction for one project.

A project is a mapping {file name: decoded text}. Rule probes and rewrites run on
that text (with the transformer's parse cache), so a file is read once and the
embedded result is written once by the caller. Slot order, the bit-to-sub-rule
mapping and the random choice for undecidable slots follow the original folder
scripts.
"""

from collections import deque
import hashlib
import random

import bch_utils
import rule_dict_bit_acc
from code_io import reload_written

# Legacy loop sub-rules without a rewrite: a file "has" them when the matcher of the
# paired style finds a node. Embedding them leaves the code unchanged.
DETECT_ONLY = {'11': '7.7', '12': '7.8'}


def project_order(names):
    """Slot order: SHA-256 of the file name (not of its content); JSON side files are skipped."""
    return sorted((name for name in names if '.json' not in name),
                  key=lambda name: hashlib.sha256(name.encode('utf-8')).hexdigest())


def probe(scts, style, code):
    """Whether `style` changes `code` beyond whitespace; None when the rule raised."""
    try:
        if style in DETECT_ONLY:
            return scts.get_file_popularity(DETECT_ONLY[style], code) > 0
        new_code, success, _ = scts.change_file_style(style, code)
        return bool(success and new_code != code)
    except Exception:
        return None


def analyze(scts, language, files):
    """Rule pairs usable on each file, in slot order: a pair counts when either sub-rule applies."""
    return {name: [rule for rule, styles in rule_dict_bit_acc.rule_dict[language].items()
                   if any(probe(scts, style, files[name]) for style in styles)]
            for name in project_order(files)}


def slots(support, codeword):
    """(file, rule, bit) assignments: codeword bits consume rules file by file."""
    queue = deque(codeword)
    for name, rules in support.items():
        for rule in rules:
            if not queue:
                return
            yield name, rule, queue.popleft()


def slot_files(support, bits):
    return {name for name, _, _ in slots(support, bch_utils.encode_bch_7_4(bits))}


def embed(scts, language, files, support, bits):
    """Apply the sub-rule selected by each codeword bit; returns {file: text to write} for changed files."""
    current, written = dict(files), {}
    for name, rule, bit in slots(support, bch_utils.encode_bch_7_4(bits)):
        style = rule_dict_bit_acc.rule_dict[language][rule][bit]
        if style in DETECT_ONLY:
            continue
        code = reload_written(written[name]) if name in written else current[name]
        try:
            new_code, success, _ = scts.change_file_style(style, code)
        except Exception:
            continue
        if success and code != new_code:
            written[name] = new_code
    return written


def extract(scts, language, files, support, bits):
    """Expected-message extraction: (BCH-decoded message matches, raw codeword matches).

    A slot reads bit b when only the sub-rule for b no longer applies; when both or
    neither apply the bit is drawn at random, and a slot whose probe raised yields no bit.
    """
    codeword = bch_utils.encode_bch_7_4(bits)
    extracted = []
    for name, rule, bit in slots(support, codeword):
        styles = rule_dict_bit_acc.rule_dict[language][rule]
        positive = probe(scts, styles[bit], files[name])
        negative = probe(scts, styles[1 - bit], files[name])
        if positive == False and negative == True:
            extracted.append(bit)
        elif positive == True and negative == False:
            extracted.append(1 - bit)
        elif positive == negative and positive is not None:
            extracted.append(random.choice([0, 1]))
    return bch_utils.decode(extracted) == bits, extracted == codeword
