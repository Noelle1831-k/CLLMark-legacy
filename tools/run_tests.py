#!/usr/bin/env python3
"""Run the unit tests in parallel: test ids are dealt round-robin to one `unittest` process per hardware thread."""

import os
import subprocess
import sys
import time
import unittest
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from benchmarks.parallel import worker_count


def test_ids(start):
    """Every test method id, imported the way `unittest discover -s tests` does."""
    sys.path.insert(0, str(start))
    ids = []

    def flatten(suite):
        for item in suite:
            if isinstance(item, unittest.TestSuite):
                flatten(item)
            elif hasattr(item, "id"):
                ids.append(item.id())

    flatten(unittest.defaultTestLoader.discover(str(start), top_level_dir=str(start)))
    return sorted(ids)


def run_bucket(ids, start):
    env = {**os.environ, "PYTHONPATH": os.pathsep.join(filter(None, [str(start), os.environ.get("PYTHONPATH", "")]))}
    done = subprocess.run(
        [sys.executable, "-m", "unittest", "-v", *ids],
        cwd=ROOT,
        env=env,
        capture_output=True,
        text=True,
        check=False,
    )
    return done.returncode, done.stdout + done.stderr


def main():
    start = ROOT / "tests"
    ids = test_ids(start)
    processes = max(1, min(worker_count(), len(ids)))
    buckets = [ids[index::processes] for index in range(processes)]
    began, outputs, failed, finished = time.monotonic(), [], 0, 0
    with ThreadPoolExecutor(max_workers=processes) as pool:
        futures = {pool.submit(run_bucket, bucket, start): bucket for bucket in buckets}
        for future in as_completed(futures):
            code, output = future.result()
            finished += 1
            failed += bool(code)
            outputs.append(output)
            print(f"[tests] {finished}/{processes} processes finished, failures={failed}", flush=True)
    for output in outputs:
        print(output, end="")
    elapsed = time.monotonic() - began
    print("\n----------------------------------------------------------------------")
    print(f"Ran {len(ids)} tests in {elapsed:.3f}s on {processes} processes\n")
    print("FAILED" if failed else "OK")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
