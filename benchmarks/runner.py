"""Freeze each experiment, stream resumable rows, and produce comparable reports."""

import json
import multiprocessing
import os
import signal
import subprocess
import sys
import time
from concurrent.futures import FIRST_COMPLETED, ProcessPoolExecutor, ThreadPoolExecutor, wait
from datetime import UTC, datetime
from pathlib import Path

from .common import (
    digest,
    discover_units,
    git_version,
    lock_file,
    protocol_fingerprint,
    source_fingerprint,
    toolchain_environment,
    utc_now,
    write_json,
)
from .compare import compare, promote_baseline
from .metrics import save_reports, summarize
from .parallel import worker_count
from .progress import LOG_NAME, LiveLog, ProgressTracker, render_bar
from .rule_sets import annotate_report

FUNCTIONAL_ROWS = "functional.jsonl"


def freeze_run(root, config, output_root, limit=0, cohorts=None, baseline=None, tests_record=None, hypothesis=""):
    root, output_root = Path(root).resolve(), Path(output_root).resolve()
    environment = toolchain_environment(root)
    fingerprint, source_files = source_fingerprint(root)
    units, inventory = discover_units(root, config, limit, cohorts)
    if not units:
        raise ValueError("No selected benchmark units")
    git = git_version(root)
    stamp = datetime.now(UTC).strftime("%Y%m%dT%H%M%S%fZ")
    run_id = stamp + "_" + git["commit"][:8] + "_" + fingerprint[:8]
    run_dir = output_root / run_id
    run_dir.mkdir(parents=True, exist_ok=False)
    write_json(
        run_dir / "state.json",
        {
            "status": "freezing",
            "expected_units": len(units),
            "copied_inputs": 0,
            "expected_inputs": len({p for unit in units for p in unit["source_files"]}),
            "updated_at": utc_now(),
        },
    )
    source = run_dir / "source"
    inputs = run_dir / "inputs"
    for relative, expected in source_files.items():
        blob = (root / relative).read_bytes()
        if digest(blob) != expected:
            raise RuntimeError("Source changed while creating snapshot: " + relative)
        path = source / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(blob)
    if not (source / "benchmarks" / "config.json").exists():
        write_json(source / "benchmarks" / "config.json", config)
    libraries = source / "build"
    libraries.mkdir()
    for language, spec in environment["parser_toolchain"]["grammars"].items():
        blob = (root / ".benchmark-cache" / "toolchain" / f"{language}-languages.so").read_bytes()
        if digest(blob) != spec["library_sha256"]:
            raise RuntimeError("Parser library changed during snapshot")
        (libraries / f"{language}-languages.so").write_bytes(blob)
    relative_paths = sorted(
        {path for unit in units for path in unit["source_files"]} | set(config["problem_files"].values())
    )
    for relative in relative_paths:
        path = (root / relative).resolve()
        if not path.is_relative_to(root) or not path.is_file() or (root / relative).is_symlink():
            raise ValueError("Unsafe or missing experiment input: " + relative)

    def copy_input(relative):
        """Read once, hash and write in the same pass; the digest identifies the corpus for baseline comparability."""
        blob = (root / relative).read_bytes()
        target = inputs / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(blob)
        return relative, {"sha256": digest(blob), "bytes": len(blob)}

    input_files = {}
    with ThreadPoolExecutor(max_workers=worker_count()) as pool:
        for index, (relative, entry) in enumerate(pool.map(copy_input, relative_paths), 1):
            input_files[relative] = entry
            if index % 5000 == 0:
                print(f"Snapshot inputs {render_bar(index, len(relative_paths))}", flush=True)
                write_json(
                    run_dir / "state.json",
                    {
                        "status": "freezing",
                        "expected_units": len(units),
                        "copied_inputs": index,
                        "expected_inputs": len(relative_paths),
                        "updated_at": utc_now(),
                    },
                )
    signatures = {digest([(Path(p).name, input_files[p]["sha256"]) for p in unit["source_files"]]) for unit in units}
    dataset_fingerprint = digest({"units": units, "input_files": input_files})
    manifest = {
        "schema_version": 1,
        "run_id": run_id,
        "created_at": utc_now(),
        "workspace_root": str(root),
        "config": config,
        "config_fingerprint": digest(config),
        "protocol_fingerprint": protocol_fingerprint(config, root),
        "git": git,
        "source_fingerprint": fingerprint,
        "source_files": source_files,
        "dataset_fingerprint": dataset_fingerprint,
        "input_files": input_files,
        "environment": environment,
        "environment_fingerprint": digest(environment),
        "full": limit == 0 and not cohorts,
        "limit_per_cohort": limit,
        "inventory": inventory,
        "units": units,
        "unique_content_units": len(signatures),
        "utility_cache": str(root / ".benchmark-cache" / "utility"),
        "baseline_path": str(Path(baseline).resolve()) if baseline else None,
    }
    manifest["preflight_tests"] = tests_record or {"executed": False}
    manifest["hypothesis"] = hypothesis
    manifest["manifest_sha256"] = digest(manifest)
    write_json(run_dir / "manifest.json", manifest)
    if baseline and Path(baseline).exists():
        baseline_value = json.loads(Path(baseline).read_text())
        write_json(run_dir / "baseline.json", baseline_value)
    write_json(run_dir / "state.json", {"status": "prepared", "updated_at": utc_now()})
    return run_dir, manifest


def verify_frozen_run(run_dir, manifest):
    """The manifest must match its own digest. Frozen copies are not re-hashed: they were written by this run."""
    claimed = manifest["manifest_sha256"]
    if digest({key: value for key, value in manifest.items() if key != "manifest_sha256"}) != claimed:
        raise ValueError("Manifest integrity check failed")


def load_rows(path):
    """Only a torn final append may be discarded; earlier corruption is fatal."""
    path = Path(path)
    if not path.exists():
        return []
    blob = path.read_bytes()
    lines = blob.splitlines(keepends=True)
    rows, accepted = [], 0
    for index, line in enumerate(lines):
        try:
            row = json.loads(line)
        except (json.JSONDecodeError, UnicodeDecodeError):
            if index != len(lines) - 1 or line.endswith(b"\n"):
                raise ValueError("Corrupt experiment row; refusing silent data loss") from None
            path.write_bytes(blob[:accepted])
            break
        rows.append(row)
        accepted += len(line)
        if index == len(lines) - 1 and not line.endswith(b"\n"):
            path.write_bytes(blob + b"\n")
    ids = [row["id"] for row in rows]
    if len(ids) != len(set(ids)):
        raise ValueError("Duplicate experiment rows")
    return rows


def verified_summary(run_dir):
    """Recompute published metrics from verified inputs and raw rows before promotion."""
    run_dir = Path(run_dir).resolve()
    manifest = json.loads((run_dir / "manifest.json").read_text())
    verify_frozen_run(run_dir, manifest)
    computed = summarize(load_rows(run_dir / "rows.jsonl"), manifest)
    if computed != json.loads((run_dir / "summary.json").read_text()):
        raise ValueError("Saved summary differs from raw experiment rows")
    validation = run_dir / "validation.json"
    if not validation.exists() or not json.loads(validation.read_text())["valid"]:
        raise ValueError("Run lacks successful post-run source/input validation")
    return computed, manifest


def validate_workspace(root, run_dir, manifest):
    current = source_fingerprint(root)[0]
    valid = current == manifest["source_fingerprint"]
    value = {
        "valid": valid,
        "checked_at": utc_now(),
        "snapshot_source": manifest["source_fingerprint"],
        "current_source": current,
    }
    write_json(run_dir / "validation.json", value)
    report = run_dir / "report.md"
    if report.exists():
        with report.open("a", encoding="utf-8") as output:
            output.write(
                f"\n## Post-run validation\n\nSource unchanged: **{valid}**; input files were copied into the run snapshot and are not re-hashed.\n"
            )
    return valid


def error_row(item, error):
    return {
        "id": item["id"],
        "cohort": item["id"].split("/", 1)[0],
        "language": item["language"],
        "role": item["role"],
        "level": item["level"],
        "status": "harness_error",
        "error": repr(error),
    }


def functional_priority(manifest):
    """Sort key of the functional stage: longest kinds of test first, so they overlap with the many short ones.

    Suites that bind sockets run one at a time (`utility.exclusive_tests`); dispatched last, as in inventory order,
    they formed a serial tail after every other unit had finished. Then the other project suites, Exercism's jest
    runs and finally the compiled or interpreted MBXP tests. Order within a kind (and every result) is unchanged.
    """
    units = {unit["id"]: unit for unit in manifest["units"]}
    projects = manifest["config"].get("projects", {})

    def key(row):
        unit = units.get(row["id"], {})
        if unit.get("oracle") == "project_tests":
            return 0 if projects.get(unit.get("project", unit.get("name")), {}).get("exclusive") else 1
        return 2 if unit.get("oracle") == "exercism" else 3

    return key


def run_stage(run_dir, manifest, items, work, output, live, jobs, phase, on_result=None):
    """Run one stage on its own pool; the queue holds two items per worker, so a thread that finishes takes the next
    item at once and none idles before the stage's last items. Every result is appended to `output` as it arrives."""
    from .staged import initialize_worker

    results, last_update, iterator = [], time.monotonic(), iter(items)
    with ProcessPoolExecutor(
        max_workers=jobs,
        mp_context=multiprocessing.get_context("spawn"),
        initializer=initialize_worker,
        initargs=(str(run_dir), manifest),
    ) as pool:
        futures = {}

        def refill():
            while len(futures) < 2 * jobs and (item := next(iterator, None)) is not None:
                futures[pool.submit(work, item)] = item

        refill()
        while futures:
            completed, _ = wait(futures, timeout=1, return_when=FIRST_COMPLETED)
            for future in completed:
                item = futures.pop(future)
                try:
                    row = future.result()
                except Exception as error:
                    row = error_row(item, error)
                if row["id"] != item["id"]:
                    raise ValueError("Worker returned the wrong unit id")
                output.write(json.dumps(row, ensure_ascii=False) + "\n")
                output.flush()
                os.fsync(output.fileno())
                results.append(row)
                live.record(row, phase[0].upper())
            refill()
            live.show()
            if time.monotonic() - last_update >= 5:
                last_update = time.monotonic()
                write_json(
                    run_dir / "state.json",
                    {"status": "running", "phase": phase, **live.tracker.state(), "updated_at": utc_now()},
                )
    live.close()
    return results


def execute_run(run_dir, stage="all"):
    """Stage `watermark` measures every unit with the functional tests deferred, `functional` adds them to the saved
    rows, `all` does both one after the other. Each stage keeps every worker busy."""
    from .engine import evaluate_unit
    from .staged import functional_unit, load_functional, needs_functional

    run_dir = Path(run_dir).resolve()
    manifest = json.loads((run_dir / "manifest.json").read_text())
    jobs = int(manifest["config"]["jobs"])
    with lock_file(run_dir / ".run.lock"):
        verify_frozen_run(run_dir, manifest)
        rows_path, functional_path = run_dir / "rows.jsonl", run_dir / FUNCTIONAL_ROWS
        rows = load_rows(rows_path)
        known = {row["id"] for row in rows}
        expected = {unit["id"] for unit in manifest["units"]}
        if not known.issubset(expected):
            raise ValueError("Rows do not belong to this manifest")
        print(f"Run {manifest['run_id']}: full={manifest['full']}; jobs={jobs}; stage={stage}", flush=True)
        if stage != "functional":
            pending = [unit for unit in manifest["units"] if unit["id"] not in known]
            tracker = ProgressTracker(len(expected), done=len(rows))
            write_json(
                run_dir / "state.json",
                {"status": "running", "phase": "watermark", **tracker.state(), "updated_at": utc_now()},
            )
            print(f"Watermark stage: {len(rows)} measured, {len(pending)} pending", flush=True)
            with rows_path.open("a", encoding="utf-8") as output:
                rows += run_stage(
                    run_dir,
                    manifest,
                    pending,
                    evaluate_unit,
                    output,
                    LiveLog(run_dir / LOG_NAME, tracker),
                    jobs,
                    "watermark",
                )
        if stage == "watermark":
            write_json(
                run_dir / "state.json",
                {"status": "functional_pending", "completed_units": len(rows), "updated_at": utc_now()},
            )
            print(f"Watermark stage done; run `research_loop.py functional {run_dir}` for the functional tests.")
            return 0
        done = load_functional(functional_path)
        waiting = [row for row in rows if needs_functional(row)]
        todo = sorted((row for row in waiting if row["id"] not in done), key=functional_priority(manifest))
        tracker = ProgressTracker(len(waiting), done=len(waiting) - len(todo))
        write_json(
            run_dir / "state.json",
            {"status": "running", "phase": "functional", **tracker.state(), "updated_at": utc_now()},
        )
        print(f"Functional stage: {len(waiting) - len(todo)} done, {len(todo)} pending", flush=True)
        with functional_path.open("a", encoding="utf-8") as output:
            fresh = run_stage(
                run_dir,
                manifest,
                todo,
                functional_unit,
                output,
                LiveLog(run_dir / LOG_NAME, tracker),
                jobs,
                "functional",
            )
        done.update({row["id"]: row for row in fresh})
        rows = [done.get(row["id"], row) for row in rows]
        temporary = rows_path.with_suffix(".tmp")
        temporary.write_text("".join(json.dumps(row, ensure_ascii=False) + "\n" for row in rows), encoding="utf-8")
        os.replace(temporary, rows_path)
        rows.sort(key=lambda row: row["id"])
        summary = summarize(rows, manifest)
        baseline_path = run_dir / "baseline.json"
        comparison = (
            compare(summary, json.loads(baseline_path.read_text()), manifest["config"]["gates"])
            if baseline_path.exists()
            else None
        )
        save_reports(run_dir, summary, manifest, comparison)
        annotate_report(run_dir, manifest)
        failed = not summary["complete"] or bool(summary["aggregate"]["harness_errors"])
        passed = manifest["full"] and not failed and (comparison is None or comparison["passed"])
        write_json(
            run_dir / "state.json",
            {
                "status": "failed" if failed else "complete",
                "gate_passed": passed,
                "total_units": len(expected),
                "completed_units": len(rows),
                "updated_at": utc_now(),
            },
        )
        print(f"Report: {run_dir / 'report.md'}; complete={summary['complete']}; gate_passed={passed}", flush=True)
        return 2 if failed else 1 if manifest["full"] and comparison and not comparison["passed"] else 0


def launch_frozen(run_dir, stage="all"):
    command = [
        sys.executable,
        str(run_dir / "source" / "tools" / "research_loop.py"),
        "_execute",
        str(run_dir),
        "--stage",
        stage,
    ]
    manifest = json.loads((run_dir / "manifest.json").read_text())
    process = subprocess.Popen(
        command,
        start_new_session=True,
        env={**os.environ, "MPLBACKEND": "Agg", "PYTHONHASHSEED": str(manifest["config"]["seed"])},
    )
    try:
        return process.wait()
    except KeyboardInterrupt:
        os.killpg(process.pid, signal.SIGTERM)
        process.wait()
        write_json(run_dir / "state.json", {"status": "interrupted", "updated_at": utc_now()})
        raise


def run_experiment(
    root,
    config,
    output_root,
    limit=0,
    cohorts=None,
    baseline=None,
    initialize_baseline=False,
    tests=False,
    hypothesis="",
    stage="all",
):
    root, output_root = Path(root).resolve(), Path(output_root).resolve()
    if not limit and not cohorts and not initialize_baseline and (not baseline or not Path(baseline).exists()):
        raise ValueError("No pinned baseline for a full comparison; initialize one with make baseline first")
    with lock_file(output_root / ".loop.lock"):
        tests_record, test_output = None, ""
        if tests:
            tested_source = source_fingerprint(root)[0]
            command = [sys.executable, "tools/run_tests.py"]
            tested = subprocess.Popen(command, cwd=root, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
            lines = []
            for line in tested.stdout:
                lines.append(line)
                if line.startswith("[tests]"):
                    print(line, end="", flush=True)
            tested.wait()
            test_output = "".join(lines)
            print(test_output, end="", flush=True)
            tests_record = {
                "executed": True,
                "returncode": tested.returncode,
                "source_fingerprint": tested_source,
                "command": command,
                "output_sha256": digest(test_output.encode()),
            }
            if tested.returncode:
                write_json(output_root / "preflight-failed.json", {**tests_record, "output": test_output})
                raise RuntimeError("Unit tests failed; full benchmark was not started")
            if source_fingerprint(root)[0] != tested_source:
                raise RuntimeError("Source changed during unit tests; rerun the loop")
        run_dir, manifest = freeze_run(root, config, output_root, limit, cohorts, baseline, tests_record, hypothesis)
        if tests:
            (run_dir / "unit-tests.log").write_text(test_output, encoding="utf-8")
        print("Frozen source and input manifest: " + str(run_dir), flush=True)
        code = launch_frozen(run_dir, stage)
        if (run_dir / "summary.json").exists():
            summary = json.loads((run_dir / "summary.json").read_text())
            if not validate_workspace(root, run_dir, manifest):
                print("Source or original inputs changed during this run; a fresh run is required.", flush=True)
                write_json(run_dir / "state.json", {"status": "stale", "gate_passed": False, "updated_at": utc_now()})
                code = 2
            if initialize_baseline and code == 0:
                if not baseline:
                    raise ValueError("A baseline destination is required")
                if Path(baseline).exists():
                    raise ValueError("Initialization will not overwrite a baseline; use the explicit baseline command")
                promote_baseline(summary, baseline, run_dir)
                print("Pinned initial baseline: " + str(baseline), flush=True)
            if code == 0:
                pointer = "latest.json" if manifest["full"] else "latest-smoke.json"
                write_json(
                    output_root / pointer,
                    {
                        "run_id": manifest["run_id"],
                        "directory": str(run_dir),
                        "source_fingerprint": manifest["source_fingerprint"],
                        "full": manifest["full"],
                    },
                )
        return code, run_dir
