"""Two separate stages: the watermark measurement of every unit, then the functional tests of every unit.

The watermark stage runs the unchanged `LegacyEngine` with `evaluate_utility` replaced by a stub, so its row carries the
DEFERRED placeholder. The functional stage calls the real `evaluate_utility` with exactly the arguments the engine would have used
on the unit's saved `clean` and `marked` directories, and puts the results into the same row. The measurement code
itself (engine, utility, metrics) is not modified, so results stay comparable with a single-stage baseline.
"""

import json
import signal
import time
import traceback
from pathlib import Path

from . import engine
from .common import digest, write_json
from .utility import evaluate_utility

DEFERRED = {"status": "DEFERRED"}


UNITS = {}


def initialize_worker(run_dir, manifest):
    """Worker of both stages: the engine measures watermarks with functional tests deferred; `functional_unit` runs them."""
    engine.initialize_worker(run_dir, manifest)
    engine.evaluate_utility = lambda *args, **kwargs: dict(DEFERRED)
    UNITS.update({unit["id"]: unit for unit in manifest["units"]})


def needs_functional(row):
    """Rows whose watermark measurement is done and whose functional tests are still missing."""
    return row.get("status") == "ok" and row.get("utility_before") == DEFERRED


def work_directory(run_dir, unit_id):
    return Path(run_dir) / "work" / digest(unit_id.encode())[:20]


def functional_unit(row):
    """The row with its functional results, or a harness_error row exactly as the single-stage engine would report."""
    unit, current = UNITS[row["id"]], engine.ENGINE

    def timeout(signum, frame):
        raise engine.UnitTimeout("Unit deadline exceeded")

    signal.signal(signal.SIGALRM, timeout)
    signal.setitimer(signal.ITIMER_REAL, current.config["unit_timeout_seconds"], 1)
    try:
        work = work_directory(current.run_dir, unit["id"])
        arguments = (
            current.problems,
            current.config,
            current.run_dir,
            current.manifest["environment"],
            current.manifest["utility_cache"],
        )
        started = time.perf_counter()
        before = evaluate_utility(unit, work / "clean", *arguments)
        after = evaluate_utility(unit, work / "marked", *arguments) if row["eligible"] else {"status": "NOT_EMBEDDED"}
        merged = {**row, "utility_before": before, "utility_after": after}
        merged["functional_ms"] = (time.perf_counter() - started) * 1000
        write_json(work / "result.json", merged)
        return merged
    except (Exception, engine.UnitTimeout) as error:
        return {
            "id": unit["id"],
            "cohort": unit["id"].split("/", 1)[0],
            "language": unit["language"],
            "role": unit["role"],
            "level": unit["level"],
            "status": "harness_error",
            "error": repr(error),
            "traceback": traceback.format_exc(),
        }
    finally:
        signal.setitimer(signal.ITIMER_REAL, 0)


def load_functional(path):
    """Functional results already on disk (it resumes); a torn final line is dropped."""
    path = Path(path)
    results = {}
    if path.exists():
        for line in path.read_text(encoding="utf-8").splitlines():
            try:
                row = json.loads(line)
            except json.JSONDecodeError:
                continue
            results[row["id"]] = row
    return results
