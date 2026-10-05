"""Freeze each experiment, stream resumable rows, and produce comparable reports."""

from concurrent.futures import ProcessPoolExecutor, wait, FIRST_COMPLETED
from datetime import datetime, timezone
import json
import multiprocessing
import os
from pathlib import Path
import shutil
import signal
import subprocess
import sys
import time

from .common import (digest, discover_units, git_version, lock_file, protocol_fingerprint,
                     source_fingerprint, source_paths, toolchain_environment, utc_now, write_json)
from .compare import compare, promote_baseline
from .metrics import save_reports, summarize


def freeze_run(root, config, output_root, limit=0, cohorts=None, baseline=None, tests_record=None, hypothesis=""):
    root, output_root = Path(root).resolve(), Path(output_root).resolve()
    environment = toolchain_environment(root)
    fingerprint, source_files = source_fingerprint(root)
    units, inventory = discover_units(root, config, limit, cohorts)
    if not units:
        raise ValueError("No selected benchmark units")
    git = git_version(root)
    stamp = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S%fZ")
    run_id = stamp + "_" + git["commit"][:8] + "_" + fingerprint[:8]
    run_dir = output_root / run_id
    run_dir.mkdir(parents=True, exist_ok=False)
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
    relative_paths = {path for unit in units for path in unit["source_files"]} | set(config["problem_files"].values())
    input_files = {}
    for relative in sorted(relative_paths):
        path = (root / relative).resolve()
        if not path.is_relative_to(root) or not path.is_file() or (root / relative).is_symlink():
            raise ValueError("Unsafe or missing experiment input: " + relative)
        blob = path.read_bytes()
        input_files[relative] = {"sha256": digest(blob), "bytes": len(blob)}
        target = inputs / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(blob)
    signatures = {digest([(Path(p).name, input_files[p]["sha256"]) for p in unit["source_files"]]) for unit in units}
    dataset_fingerprint = digest({"units": units, "input_files": input_files})
    manifest = {"schema_version": 1, "run_id": run_id, "created_at": utc_now(), "workspace_root": str(root),
                "config": config, "config_fingerprint": digest(config), "protocol_fingerprint": protocol_fingerprint(config, root),
                "git": git, "source_fingerprint": fingerprint, "source_files": source_files,
                "dataset_fingerprint": dataset_fingerprint, "input_files": input_files,
                "environment": environment, "environment_fingerprint": digest(environment),
                "full": limit == 0 and not cohorts, "limit_per_cohort": limit,
                "inventory": inventory, "units": units, "unique_content_units": len(signatures),
                "utility_cache": str(root / ".benchmark-cache" / "utility"),
                "baseline_path": str(Path(baseline).resolve()) if baseline else None}
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
    claimed = manifest["manifest_sha256"]
    if digest({key: value for key, value in manifest.items() if key != "manifest_sha256"}) != claimed:
        raise ValueError("Manifest integrity check failed")
    for relative, expected in manifest["source_files"].items():
        if digest((run_dir / "source" / relative).read_bytes()) != expected:
            raise ValueError("Frozen source modified: " + relative)
    for relative, spec in manifest["input_files"].items():
        if digest((run_dir / "inputs" / relative).read_bytes()) != spec["sha256"]:
            raise ValueError("Frozen input modified: " + relative)
    for language, spec in manifest["environment"]["parser_toolchain"]["grammars"].items():
        if digest((run_dir / "source" / "build" / f"{language}-languages.so").read_bytes()) != spec["library_sha256"]:
            raise ValueError("Frozen parser modified")


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
    changed_inputs = [relative for relative, spec in manifest["input_files"].items()
                      if not (root / relative).is_file() or digest((root / relative).read_bytes()) != spec["sha256"]]
    valid = current == manifest["source_fingerprint"] and not changed_inputs
    value = {"valid": valid, "checked_at": utc_now(), "snapshot_source": manifest["source_fingerprint"],
             "current_source": current, "checked_inputs": len(manifest["input_files"]), "changed_inputs": changed_inputs}
    write_json(run_dir / "validation.json", value)
    report = run_dir / "report.md"
    if report.exists():
        with report.open("a", encoding="utf-8") as output:
            output.write(f"\n## Post-run validation\n\nSource and original inputs unchanged: **{valid}**; checked input files: **{len(manifest['input_files'])}**.\n")
    return valid


def execute_run(run_dir):
    run_dir = Path(run_dir).resolve()
    manifest = json.loads((run_dir / "manifest.json").read_text())
    with lock_file(run_dir / ".run.lock"):
        verify_frozen_run(run_dir, manifest)
        rows_path = run_dir / "rows.jsonl"
        rows = load_rows(rows_path)
        known = {row["id"] for row in rows}
        expected = {unit["id"] for unit in manifest["units"]}
        if not known.issubset(expected):
            raise ValueError("Rows do not belong to this manifest")
        pending = [unit for unit in manifest["units"] if unit["id"] not in known]
        write_json(run_dir / "state.json", {"status": "running", "completed_units": len(rows), "updated_at": utc_now()})
        print(f"Run {manifest['run_id']}: {len(rows)} completed, {len(pending)} pending; full={manifest['full']}", flush=True)
        from .engine import evaluate_unit, initialize_worker
        last_update = time.monotonic()
        iterator = iter(pending)
        with rows_path.open("a", encoding="utf-8") as output:
            with ProcessPoolExecutor(max_workers=int(manifest["config"]["jobs"]), mp_context=multiprocessing.get_context("spawn"),
                                     initializer=initialize_worker, initargs=(str(run_dir), manifest)) as pool:
                futures = {}
                for _ in range(int(manifest["config"]["jobs"])):
                    unit = next(iterator, None)
                    if unit:
                        futures[pool.submit(evaluate_unit, unit)] = unit
                while futures:
                    completed, _ = wait(futures, timeout=1, return_when=FIRST_COMPLETED)
                    for future in completed:
                        unit = futures.pop(future)
                        try:
                            row = future.result()
                        except Exception as error:
                            row = {"id": unit["id"], "cohort": unit["id"].split("/", 1)[0], "language": unit["language"],
                                   "role": unit["role"], "level": unit["level"], "status": "harness_error", "error": repr(error)}
                        if row["id"] != unit["id"]:
                            raise ValueError("Worker returned the wrong unit id")
                        output.write(json.dumps(row, ensure_ascii=False) + "\n")
                        output.flush()
                        os.fsync(output.fileno())
                        rows.append(row)
                        next_unit = next(iterator, None)
                        if next_unit:
                            futures[pool.submit(evaluate_unit, next_unit)] = next_unit
                    if len(rows) % 100 == 0 and completed or time.monotonic() - last_update >= 20:
                        last_update = time.monotonic()
                        failures = sum(row["status"] != "ok" for row in rows)
                        print(f"Progress {len(rows)}/{len(expected)}; harness errors={failures}", flush=True)
                        write_json(run_dir / "state.json", {"status": "running", "completed_units": len(rows), "updated_at": utc_now()})
        rows.sort(key=lambda row: row["id"])
        summary = summarize(rows, manifest)
        baseline_path = run_dir / "baseline.json"
        comparison = compare(summary, json.loads(baseline_path.read_text()), manifest["config"]["gates"]) if baseline_path.exists() else None
        save_reports(run_dir, summary, manifest, comparison)
        failed = not summary["complete"] or bool(summary["aggregate"]["harness_errors"])
        passed = manifest["full"] and not failed and (comparison is None or comparison["passed"])
        write_json(run_dir / "state.json", {"status": "failed" if failed else "complete", "gate_passed": passed,
                                           "completed_units": len(rows), "updated_at": utc_now()})
        print(f"Report: {run_dir / 'report.md'}; complete={summary['complete']}; gate_passed={passed}", flush=True)
        return 2 if failed else 1 if manifest["full"] and comparison and not comparison["passed"] else 0


def launch_frozen(run_dir):
    command = [sys.executable, str(run_dir / "source" / "tools" / "research_loop.py"), "_execute", str(run_dir)]
    process = subprocess.Popen(command, start_new_session=True, env={**os.environ, "MPLBACKEND": "Agg"})
    try:
        return process.wait()
    except KeyboardInterrupt:
        os.killpg(process.pid, signal.SIGTERM)
        process.wait()
        write_json(run_dir / "state.json", {"status": "interrupted", "updated_at": utc_now()})
        raise


def run_experiment(root, config, output_root, limit=0, cohorts=None, baseline=None, initialize_baseline=False, tests=False, hypothesis=""):
    root, output_root = Path(root).resolve(), Path(output_root).resolve()
    if not limit and not cohorts and not initialize_baseline and (not baseline or not Path(baseline).exists()):
        raise ValueError("No pinned baseline for a full comparison; initialize one with make baseline first")
    with lock_file(output_root / ".loop.lock"):
        tests_record, test_output = None, ""
        if tests:
            tested_source = source_fingerprint(root)[0]
            command = [sys.executable, "-m", "unittest", "discover", "-s", "tests", "-v"]
            tested = subprocess.run(command, cwd=root, capture_output=True, text=True)
            test_output = tested.stdout + tested.stderr
            print(test_output, end="", flush=True)
            tests_record = {"executed": True, "returncode": tested.returncode, "source_fingerprint": tested_source,
                            "command": command, "output_sha256": digest(test_output.encode())}
            if tested.returncode:
                write_json(output_root / "preflight-failed.json", {**tests_record, "output": test_output})
                raise RuntimeError("Unit tests failed; full benchmark was not started")
            if source_fingerprint(root)[0] != tested_source:
                raise RuntimeError("Source changed during unit tests; rerun the loop")
        run_dir, manifest = freeze_run(root, config, output_root, limit, cohorts, baseline, tests_record, hypothesis)
        if tests:
            (run_dir / "unit-tests.log").write_text(test_output, encoding="utf-8")
        print("Frozen source and input manifest: " + str(run_dir), flush=True)
        code = launch_frozen(run_dir)
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
                write_json(output_root / pointer, {"run_id": manifest["run_id"], "directory": str(run_dir),
                                                        "source_fingerprint": manifest["source_fingerprint"], "full": manifest["full"]})
        return code, run_dir
