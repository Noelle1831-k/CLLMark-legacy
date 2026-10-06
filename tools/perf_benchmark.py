#!/usr/bin/env python3
"""Performance benchmark of the watermarking pipeline: startup, per-phase CPU time and peak memory.

The workload mirrors the per-unit work of the evaluation loop without functional tests: analysis, rule properties
(idempotence, reversibility, independence), syntax checks, embedding, and four extractions (original, marked and two
flip attacks), on a fixed random sample of every cohort of benchmarks/config.json.

Usage:
    tools/perf_benchmark.py [--per-cohort 12] [--repeat 3] [--json results.json] [--profile profile.txt]

Run it with the interpreter under test (for example .venv-benchmark/bin/python). Results report the interpreter, the
wall time per phase (best of --repeat), process startup (fresh interpreter: import and one transformer per language)
and peak resident memory. PYTHONHASHSEED is fixed so that rule outputs are reproducible.
"""

import argparse
import contextlib
import json
import os
import platform
import random
import subprocess
import sys
import time
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

SEED = "20261005"
DETECT_ONLY = ("11", "12")
STARTUP = (
    "import time; t = time.perf_counter(); import cllmark; from cllmark.transform import StyleTransformer; "
    "i = time.perf_counter(); [StyleTransformer(l) for l in ('python', 'c', 'cpp', 'javascript')]; "
    "e = time.perf_counter(); print(f'{(i - t) * 1000:.1f} {(e - i) * 1000:.1f}')"
)


def sample_units(per_cohort, seed):
    from benchmarks.common import discover_units

    config = json.loads((ROOT / "benchmarks" / "config.json").read_text())
    units, _ = discover_units(ROOT, config)
    rng, sample = random.Random(seed), []
    for cohort in sorted({unit["id"].split("/")[0] for unit in units}):
        members = [unit for unit in units if unit["id"].split("/")[0] == cohort]
        sample += rng.sample(members, min(per_cohort, len(members)))
    return sample


class Workload:
    def __init__(self, units):
        from benchmarks.common import unit_file_names
        from cllmark import source_io
        from cllmark.transform import StyleTransformer

        self.units = units
        self.transformers = {language: StyleTransformer(language) for language in {unit["language"] for unit in units}}
        self.files = []
        for unit in units:
            names = unit_file_names(unit)
            self.files.append({names[path]: source_io.read_source(ROOT / path) for path in unit["source_files"]})
        self.phases = Counter()

    def timed(self, phase, function, *arguments):
        started = time.perf_counter()
        result = function(*arguments)
        self.phases[phase] += time.perf_counter() - started
        return result

    def run(self):
        for unit, files in zip(self.units, self.files, strict=True):
            self.evaluate(unit["language"], files)

    def evaluate(self, language, files):
        from cllmark import bch, source_io, watermark
        from cllmark.rules.pairs import WATERMARK_PAIRS

        transformer, bits = self.transformers[language], [1, 0, 1, 0]
        pairs = WATERMARK_PAIRS[language]
        support = self.timed("analysis", watermark.analyze, transformer, language, files)
        slots = [(name, pair, bit, pairs[pair][bit]) for name, pair, bit in watermark.slots(support, bch.encode(bits))]
        self.timed("properties", self.properties, transformer, pairs, files, support, slots)
        self.timed("syntax", lambda: [transformer.check_syntax(code) for code in files.values()])
        if sum(len(usable) for usable in support.values()) < bch.CODE_LENGTH:
            return
        random.seed(1)
        self.timed("extraction", watermark.extract, transformer, language, files, support, bits)
        written = self.timed("embedding", watermark.embed, transformer, language, files, support, bits)
        marked = {
            name: source_io.reload_written(written[name]) if name in written else code for name, code in files.items()
        }
        self.timed("extraction", watermark.extract, transformer, language, marked, support, bits)
        self.timed("syntax", lambda: [transformer.check_syntax(code) for code in marked.values()])
        for count in (1, 2):
            attacked, applied = dict(marked), 0
            for name, pair, bit, _ in slots:
                inverse = pairs[pair][1 - bit]
                if inverse in DETECT_ONLY:
                    continue
                new_code = self.timed("attacks", lambda: transformer.apply(inverse, attacked[name])[0])
                if new_code != attacked[name]:
                    attacked[name], applied = new_code, applied + 1
                if applied == count:
                    break
            self.timed("extraction", watermark.extract, transformer, language, attacked, support, bits)

    @staticmethod
    def properties(transformer, pairs, files, support, slots):
        def change(style, code):
            return transformer.apply(style, code)[0]

        for name, usable in support.items():
            for pair in usable:
                zero, one = pairs[pair]
                if zero in DETECT_ONLY or one in DETECT_ONLY:
                    continue
                try:
                    a, b = change(zero, files[name]), change(one, files[name])
                    change(zero, a), change(one, b), change(zero, b), change(one, a)
                except Exception:
                    pass
        for index, left in enumerate(slots):
            for right in slots[index + 1 :]:
                if left[0] != right[0] or left[3] in DETECT_ONLY or right[3] in DETECT_ONLY:
                    continue
                with contextlib.suppress(Exception):
                    change(left[3], change(right[3], files[left[0]])), change(right[3], change(left[3], files[left[0]]))


def startup(repeat):
    """Best of `repeat` fresh interpreters: (import ms, four transformers ms)."""
    runs = []
    for _ in range(repeat):
        output = subprocess.check_output([sys.executable, "-c", STARTUP], cwd=ROOT, text=True)
        runs.append(tuple(map(float, output.split())))
    return min(runs, key=sum)


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("--per-cohort", type=int, default=12, help="units sampled per cohort")
    parser.add_argument("--seed", type=int, default=7, help="sampling seed")
    parser.add_argument("--repeat", type=int, default=3, help="workload repetitions (best is reported)")
    parser.add_argument("--json", type=Path, help="write the results as JSON")
    parser.add_argument("--profile", type=Path, help="write a cProfile report of one repetition")
    args = parser.parse_args()
    if os.environ.get("PYTHONHASHSEED") != SEED:
        os.execve(sys.executable, [sys.executable, *sys.argv], {**os.environ, "PYTHONHASHSEED": SEED})

    import resource

    os.chdir(ROOT)
    units = sample_units(args.per_cohort, args.seed)
    best = None
    for repetition in range(args.repeat):
        workload = Workload(units)
        started = time.perf_counter()
        if args.profile and repetition == 0:
            import cProfile
            import io
            import pstats

            profiler = cProfile.Profile()
            profiler.runcall(workload.run)
            report = io.StringIO()
            pstats.Stats(profiler, stream=report).sort_stats("tottime").print_stats(40)
            args.profile.write_text(report.getvalue())
            continue
        workload.run()
        total = time.perf_counter() - started
        if best is None or total < best[0]:
            best = (total, dict(workload.phases))
    import_ms, transformers_ms = startup(max(1, args.repeat))
    result = {
        "python": f"{platform.python_implementation()} {platform.python_version()}",
        "units": len(units),
        "seconds": round(best[0], 2) if best else None,
        "phases": {
            name: round(value, 2) for name, value in sorted((best or (0, {}))[1].items(), key=lambda kv: -kv[1])
        },
        "startup_ms": {"import": import_ms, "transformers": transformers_ms},
        "peak_rss_mb": round(resource.getrusage(resource.RUSAGE_SELF).ru_maxrss / 1024, 1),
    }
    text = json.dumps(result, indent=2)
    print(text)
    if args.json:
        args.json.write_text(text + "\n")


if __name__ == "__main__":
    main()
