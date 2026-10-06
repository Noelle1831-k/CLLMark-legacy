#!/usr/bin/env python3
"""Local CLLMark research loop: tests, frozen full benchmark, comparison and baseline."""

import argparse
import json
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from benchmarks.common import (
    digest,
    discover_units,
    lock_file,
    parser_smoke,
    source_fingerprint,
    toolchain_environment,
    validate_config,
    write_json,
)
from benchmarks.compare import compare, promote_baseline
from benchmarks.parallel import worker_count
from benchmarks.progress import describe, follow, latest_run
from benchmarks.runner import execute_run, launch_frozen, run_experiment, validate_workspace, verified_summary


def read_config(path, jobs=None):
    config = json.loads(Path(path).read_text())
    config["jobs"] = jobs if jobs and jobs > 0 else worker_count()
    return validate_config(config)


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    for command in ["doctor", "inventory", "run", "loop", "watch"]:
        child = commands.add_parser(command)
        child.add_argument("--config", type=Path, default=ROOT / "benchmarks" / "config.json")
        child.add_argument("--jobs", type=int)
        if command in ["run", "loop", "watch"]:
            child.add_argument("--output-root", type=Path, default=ROOT / "benchmark-results")
            child.add_argument("--baseline", type=Path, default=ROOT / "benchmarks" / "baselines" / "current.json")
        if command in ["run", "loop"]:
            child.add_argument("--limit", type=int, default=0, help="Smoke limit per cohort; zero means all units")
            child.add_argument("--cohort", action="append")
            child.add_argument("--initialize-baseline", action="store_true")
            child.add_argument(
                "--skip-functional",
                action="store_true",
                help="Measure watermarks only; finish later with the `functional` command (the run cannot pass gates before)",
            )
            child.add_argument(
                "--hypothesis", default="", help="Research hypothesis recorded in the immutable manifest"
            )
        if command == "watch":
            child.add_argument("--debounce", type=float, default=15)
            child.add_argument("--poll", type=float, default=2)
    child = commands.add_parser("progress", help="Show the bar, ETA and recent unit log of a run")
    child.add_argument("run_dir", type=Path, nargs="?", help="Default: newest run under --output-root")
    child.add_argument("--output-root", type=Path, default=ROOT / "benchmark-results")
    child.add_argument("--follow", "-f", action="store_true", help="Refresh until the run ends")
    child.add_argument("--tail", type=int, default=10, help="Recent unit lines to show")
    child.add_argument("--interval", type=float, default=2)
    for command in ["resume", "functional", "baseline", "compare", "_execute"]:
        child = commands.add_parser(command)
        child.add_argument("run_dir", type=Path)
        if command == "_execute":
            child.add_argument("--stage", choices=["all", "watermark", "functional"], default="all")
        if command in ["baseline", "compare"]:
            child.add_argument("--baseline", type=Path, default=ROOT / "benchmarks" / "baselines" / "current.json")
    args = parser.parse_args(argv)
    if args.command == "progress":
        run_dir = args.run_dir or latest_run(args.output_root)
        if run_dir is None:
            parser.error("No run found under " + str(args.output_root))
        if args.follow:
            follow(run_dir, args.interval, args.tail)
        else:
            print(describe(run_dir, args.tail))
        return 0
    if args.command == "_execute":
        return execute_run(args.run_dir, args.stage)
    if args.command in ["baseline", "compare"]:
        summary, manifest = verified_summary(args.run_dir)
        if args.command == "baseline":
            path = promote_baseline(summary, args.baseline, args.run_dir)
            print("Baseline promoted explicitly: " + str(path))
            return 0
        result = compare(summary, json.loads(args.baseline.read_text()), manifest["config"]["gates"])
        write_json(args.run_dir / "comparison.json", result)
        print(json.dumps(result, ensure_ascii=False, indent=2))
        return 0 if result["passed"] else 1
    if args.command in ["resume", "functional"]:
        run_dir = args.run_dir.resolve()
        manifest = json.loads((run_dir / "manifest.json").read_text())
        if digest(toolchain_environment(ROOT)) != manifest["environment_fingerprint"]:
            parser.error("Resume environment differs from the recorded environment")
        with lock_file(run_dir.parent / ".loop.lock"):
            code = launch_frozen(run_dir, "functional" if args.command == "functional" else "all")
            if not validate_workspace(ROOT, run_dir, manifest):
                print("Resumed frozen run differs from the current checkout; retained for historical analysis.")
                return 2
            return code
    config = read_config(args.config, args.jobs)
    if args.command == "doctor":
        environment = toolchain_environment(ROOT)
        from tree_sitter import Language

        for language in ["c", "cpp", "python"]:
            Language(str(ROOT / ".benchmark-cache" / "toolchain" / f"{language}-languages.so"), language)
        loaded = parser_smoke(ROOT)
        print(json.dumps({"ready": True, "operators_loaded": loaded, "environment": environment}, indent=2))
        return 0
    if args.command == "inventory":
        units, inventory = discover_units(ROOT, config)
        print(json.dumps({"units": len(units), "cohorts": inventory}, ensure_ascii=False, indent=2))
        return 0
    if args.command in ["run", "loop"]:
        if args.limit < 0:
            parser.error("--limit must be nonnegative")
        if args.initialize_baseline and (args.limit or args.cohort):
            parser.error("Smoke/subset runs cannot initialize a full baseline")
        if args.initialize_baseline and args.baseline.exists():
            parser.error("Baseline already exists; use baseline RUN only when intentionally promoting a new reference")
        code, run_dir = run_experiment(
            ROOT,
            config,
            args.output_root,
            args.limit,
            args.cohort,
            args.baseline,
            args.initialize_baseline,
            tests=args.command == "loop",
            hypothesis=args.hypothesis,
            stage="watermark" if args.skip_functional else "all",
        )
        print("Result directory: " + str(run_dir))
        return code
    if args.command == "watch":
        if args.debounce <= 0 or args.poll <= 0:
            parser.error("Watch intervals must be positive")
        print(
            "Watching source, benchmark config and commits; each stable change triggers a full loop. Ctrl-C stops.",
            flush=True,
        )
        last_finished, pending, changed_at = None, None, time.monotonic()
        latest = args.output_root / "latest.json"
        if latest.exists():
            value = json.loads(latest.read_text())
            if value.get("full"):
                manifest = json.loads((Path(value["directory"]) / "manifest.json").read_text())
                last_finished = (
                    manifest["source_fingerprint"],
                    manifest["config_fingerprint"],
                    manifest["git"]["commit"],
                )
        while True:
            try:
                config = read_config(args.config, args.jobs)
                revision = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip()
                current = (source_fingerprint(ROOT)[0], digest(config), revision)
            except (OSError, ValueError):
                time.sleep(args.poll)
                continue
            if current != pending:
                pending, changed_at = current, time.monotonic()
            if current != last_finished and time.monotonic() - changed_at >= args.debounce:
                try:
                    code, directory = run_experiment(ROOT, config, args.output_root, baseline=args.baseline, tests=True)
                    print(f"Watch run finished: exit={code}; {directory}", flush=True)
                except Exception as error:
                    print("Watch run failed: " + repr(error), flush=True)
                last_finished = current
            time.sleep(args.poll)


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except KeyboardInterrupt:
        raise SystemExit(130) from None
    except Exception as error:
        print("Research loop failed: " + repr(error), file=sys.stderr)
        raise SystemExit(2) from error
