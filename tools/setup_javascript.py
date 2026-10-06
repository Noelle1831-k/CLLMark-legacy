#!/usr/bin/env python3
"""Prepare the JavaScript oracles pinned in benchmarks/javascript.lock.json.

* lodash (required by the MBJSP tests) in .benchmark-cache/node;
* the four small projects (git checkouts at their pinned commits) with the packages their test suites need,
  and their library sources copied to corpus/dataset/JS_projects/<name>;
* the medium-size repositories ("repositories" in the lock): the GitHub tarball of the pinned commit is downloaded,
  verified against its SHA-256, unpacked to .benchmark-cache/js-projects/<name> and its dependencies are installed
  from the pinned lockfile with --ignore-scripts. A clean copy runs the test suite once (time recorded in
  .benchmark-cache/js-projects/<name>.pin.json); the hand-written source files are copied to corpus/dataset/JS_repos/<name>;
* the Exercism JavaScript track (pnpm lockfile, Jest): every practice exercise whose reference solution is a single
  file of at least `min_solution_lines` lines and passes its own spec is written to corpus/dataset/Exercism_JS and
  corpus/dataset/Jsonl/exercism_javascript.jsonl; the others are listed with their reason in
  corpus/dataset/Jsonl/exercism_javascript_excluded.jsonl.

Network access: npm registry (pnpm for Exercism) and GitHub. The script is idempotent: verified checkouts,
installed dependencies and recorded clean-test results are reused, nothing is downloaded or rewritten a second time.
No package script ever runs (--ignore-scripts); the downloaded repositories are only read and their tests executed.

    python tools/setup_javascript.py [--only NAME ...] [--rerun-clean-tests] [--stress N]
"""

import argparse
import fnmatch
import hashlib
import json
import os
import shutil
import statistics
import subprocess
import sys
import tarfile
import tempfile
import time
import urllib.request
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from benchmarks.common import digest, install_digest, line_count, write_json
from benchmarks.utility import _evaluate_exercism, run_test

NPM = ["npm", "install", "--no-save", "--no-package-lock", "--ignore-scripts", "--no-audit", "--no-fund"]
CACHE = ROOT / ".benchmark-cache" / "js-projects"
CRITERIA = {"min_source_lines": 1000, "max_source_lines": 20000}
LICENSE_NAMES = ["LICENSE", "LICENSE.md", "LICENSE.txt", "LICENCE", "LICENCE.md", "LICENSE.BSD"]


def run(command, **kwargs):
    subprocess.run(command, check=True, **kwargs)


def legacy_projects(lock):
    """lodash for MBJSP and the four git-cloned small projects (unchanged behaviour)."""
    node = ROOT / ".benchmark-cache" / "node"
    node.mkdir(parents=True, exist_ok=True)
    installed = node / "node_modules" / "lodash" / "package.json"
    if not installed.is_file() or json.loads(installed.read_text())["version"] != lock["lodash"]:
        run([*NPM, "--prefix", str(node), "lodash@" + lock["lodash"]])
    CACHE.mkdir(parents=True, exist_ok=True)
    for name, spec in lock["projects"].items():
        checkout = CACHE / name
        if not checkout.exists():
            run(["git", "clone", "--depth", "1", "--branch", spec["tag"], spec["repository"], str(checkout)])
        commit = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=checkout, text=True).strip()
        if commit != spec["commit"]:
            raise SystemExit(f"{name}: checkout is at {commit}, expected {spec['commit']}")
        if not (checkout / "node_modules").exists():
            run(NPM + spec["test_dependencies"], cwd=checkout)
        target = ROOT / "corpus" / "dataset" / "JS_projects" / name
        for source in spec["sources"]:
            origin = checkout / source
            files = sorted(origin.rglob("*.js")) if origin.is_dir() else [origin]
            for path in files:
                destination = target / path.relative_to(checkout)
                destination.parent.mkdir(parents=True, exist_ok=True)
                shutil.copyfile(path, destination)
        print(f"{name}: {commit}", flush=True)


# ----------------------------------------------------------------------------- pinned tarball checkouts


def read_pin(name):
    path = CACHE / (name + ".pin.json")
    return json.loads(path.read_text()) if path.is_file() else {}


def write_pin(name, pin):
    write_json(CACHE / (name + ".pin.json"), pin)


def download_checkout(name, spec):
    """Download the tarball of the pinned commit, verify its SHA-256 and unpack it; no-op when already verified."""
    checkout = CACHE / name
    pin = read_pin(name)
    if (
        checkout.is_dir()
        and pin.get("commit") == spec["commit"]
        and pin.get("tarball_sha256") == spec["tarball_sha256"]
    ):
        return pin
    owner_repo = spec["repository"].removeprefix("https://github.com/")
    url = f"https://codeload.github.com/{owner_repo}/tar.gz/{spec['commit']}"
    print(f"{name}: downloading {url}", flush=True)
    with urllib.request.urlopen(url, timeout=180) as response:
        blob = response.read()
    actual = hashlib.sha256(blob).hexdigest()
    if actual != spec["tarball_sha256"]:
        raise SystemExit(f"{name}: tarball digest {actual} differs from the pinned {spec['tarball_sha256']}")
    CACHE.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(dir=CACHE, prefix=name + ".unpack-") as temporary:
        archive = Path(temporary) / "archive.tar.gz"
        archive.write_bytes(blob)
        with tarfile.open(archive) as tar:
            tops = {member.name.split("/")[0] for member in tar.getmembers()}
            if len(tops) != 1:
                raise SystemExit(f"{name}: unexpected tarball layout")
            tar.extractall(Path(temporary) / "x", filter="data")
        if checkout.exists():
            shutil.rmtree(checkout)
        (Path(temporary) / "x" / tops.pop()).rename(checkout)
    pin = {
        "repository": spec["repository"],
        "tag": spec.get("tag"),
        "commit": spec["commit"],
        "tarball_sha256": spec["tarball_sha256"],
    }
    write_pin(name, pin)
    return pin


def install_dependencies(name, spec):
    """Install test dependencies from the pinned lockfile, without running any package script."""
    checkout = CACHE / name
    install = spec["install"]
    pin = read_pin(name)
    if install["mode"] == "none":
        pin["install"] = install
        write_pin(name, pin)
        return
    done = pin.get("install", {})
    if done.get("lockfile_sha256") == install["lockfile_sha256"] and done.get("installed_sha256"):
        try:
            if install_digest(checkout, install["mode"]) == done["installed_sha256"]:
                return
        except RuntimeError:
            pass
    lockfile = checkout / ("package-lock.json" if install["mode"] == "npm-ci" else "pnpm-lock.yaml")
    if install["lockfile"] != "repository":
        shutil.copyfile(ROOT / install["lockfile"], lockfile)
    if hashlib.sha256(lockfile.read_bytes()).hexdigest() != install["lockfile_sha256"]:
        raise SystemExit(f"{name}: lockfile differs from the pinned digest")
    shutil.rmtree(checkout / "node_modules", ignore_errors=True)
    print(f"{name}: installing dependencies ({install['mode']})", flush=True)
    if install["mode"] == "npm-ci":
        run(["npm", "ci", "--package-lock=true", "--ignore-scripts", "--no-audit", "--no-fund"], cwd=checkout)
        manager = subprocess.check_output(["npm", "--version"], text=True).strip()
    else:
        env = {**os.environ, "npm_config_manage_package_manager_versions": "false"}
        run(["pnpm", "install", "--frozen-lockfile", "--ignore-scripts"], cwd=checkout, env=env)
        manager = subprocess.check_output(["pnpm", "--version"], text=True, env=env).strip()
    pin = read_pin(name)
    pin["install"] = {
        **install,
        "installed_sha256": install_digest(checkout, install["mode"]),
        "manager_version": manager,
    }
    write_pin(name, pin)


# ----------------------------------------------------------------------------- clean test runs


def clean_copy(checkout, destination):
    shutil.copytree(checkout, destination, ignore=shutil.ignore_patterns("node_modules", ".git"), symlinks=True)
    if (checkout / "node_modules").exists():
        (destination / "node_modules").symlink_to(checkout / "node_modules", target_is_directory=True)


def run_clean(name, project, config, directory, extra_env=None):
    env = {**os.environ, "NODE_ENV": "test", **(extra_env or {})}
    with tempfile.TemporaryDirectory(prefix=f"clean-{name}-") as logs:
        result = run_test(
            project["test"],
            directory,
            config["project_test_timeout_seconds"],
            config.get("test_timeout_retries", 0),
            env,
            log_directory=logs,
        )
        tail = (
            Path(result["stdout"]).read_text(errors="replace") + Path(result["stderr"]).read_text(errors="replace")
        )[-1500:]
    return result, tail


def v8_coverage(directory, selected):
    """Fraction of each selected source file's bytes that V8 executed during the suite (0.0 when never loaded)."""
    seen = {}
    for report in directory.glob("*.json"):
        for script in json.loads(report.read_text()).get("result", []):
            url = script["url"]
            path = url.removeprefix("file://")
            try:
                relative = Path(path).resolve().relative_to(directory.parent.resolve() / "project").as_posix()
            except ValueError:
                continue
            if relative not in selected:
                continue
            ranges = [r for function in script["functions"] for r in function["ranges"]]
            size = max((r["endOffset"] for r in ranges), default=0)
            counts = [0] * size
            for function in script["functions"]:
                for r in function["ranges"]:
                    for index in range(r["startOffset"], min(r["endOffset"], size)):
                        counts[index] = r["count"]
            seen[relative] = max(seen.get(relative, 0.0), sum(c > 0 for c in counts) / size if size else 0.0)
    return {relative: round(seen.get(relative, 0.0), 3) for relative in sorted(selected)}


def clean_test(name, spec, config, selected, rerun=False):
    """Run the project's suite once on a clean copy: it must pass, and its duration is recorded."""
    project = config["projects"][name]
    pin = read_pin(name)
    command_digest = digest(project["test"])
    recorded = pin.get("clean_test", {})
    if (
        not rerun
        and recorded.get("command_sha256") == command_digest
        and recorded.get("returncode") == 0
        and recorded.get("installed_sha256") == pin.get("install", {}).get("installed_sha256")
    ):
        print(f"{name}: clean test recorded ({recorded['seconds']:.1f} s), not rerun", flush=True)
        return recorded
    with tempfile.TemporaryDirectory(prefix=f"clean-{name}-") as temporary:
        directory = Path(temporary) / "project"
        clean_copy(CACHE / name, directory)
        result, tail = run_clean(name, project, config, directory)
        if result["returncode"] != 0 or result["timed_out"]:
            print(tail, file=sys.stderr)
            raise SystemExit(
                f"{name}: the clean test suite does not pass (returncode {result['returncode']}, timed out {result['timed_out']})"
            )
        coverage = Path(temporary) / "coverage"
        coverage.mkdir()
        # Separate pass without the harness' file-size limits: V8 coverage reports can exceed them.
        covered = subprocess.run(
            project["test"],
            cwd=directory,
            env={**os.environ, "NODE_ENV": "test", "NODE_V8_COVERAGE": str(coverage)},
            stdin=subprocess.DEVNULL,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
            timeout=600,
        )
        record = {
            "returncode": 0,
            "seconds": round(result["elapsed_ms"] / 1000, 2),
            "command_sha256": command_digest,
            "installed_sha256": pin.get("install", {}).get("installed_sha256"),
            "node": subprocess.check_output(["node", "--version"], text=True).strip(),
            "coverage_pass_returncode": covered.returncode,
            "v8_coverage": v8_coverage(coverage, selected),
        }
    pin = read_pin(name)
    pin["clean_test"] = record
    write_pin(name, pin)
    print(f"{name}: clean test passed in {record['seconds']:.1f} s", flush=True)
    return record


def stress(name, config, count):
    """Run `count` clean copies of the suite at the same time (the harness runs `jobs` units concurrently)."""
    project = config["projects"][name]
    with tempfile.TemporaryDirectory(prefix=f"stress-{name}-") as temporary:
        directories = []
        for index in range(count):
            directory = Path(temporary) / f"p{index}" / "project"
            directory.parent.mkdir()
            clean_copy(CACHE / name, directory)
            directories.append(directory)
        with ThreadPoolExecutor(count) as pool:
            results = list(pool.map(lambda d: run_clean(name, project, config, d)[0], directories))
    seconds = [r["elapsed_ms"] / 1000 for r in results]
    failures = sum(r["returncode"] != 0 for r in results)
    print(
        f"{name}: {count} concurrent clean runs: max {max(seconds):.1f} s, median {statistics.median(seconds):.1f} s, failures {failures}",
        flush=True,
    )
    return failures == 0


# ----------------------------------------------------------------------------- corpus of repository sources


def select_sources(name, spec):
    checkout = CACHE / name
    suffixes = tuple(spec.get("extensions") or [".js"])
    chosen = {}
    for pattern in spec["sources"]:
        for path in checkout.glob(pattern):
            relative = path.relative_to(checkout).as_posix()
            if not path.is_file() or path.suffix not in suffixes:
                continue
            if any(fnmatch.fnmatchcase(relative, excluded) for excluded in spec.get("exclude", [])):
                continue
            chosen[relative] = path
    result = {}
    for relative, path in sorted(chosen.items()):
        if path.is_symlink():
            raise SystemExit(f"{name}: {relative} is a symlink")
        if ".json" in relative.replace("/", "__"):
            raise SystemExit(f'{name}: {relative} would be skipped by the legacy pipeline (".json" in the name)')
        if path.stat().st_size == 0:
            print(f"{name}: skipping empty file {relative}", flush=True)
            continue
        result[relative] = path
    lines = sum(line_count(path) for path in result.values())
    if not CRITERIA["min_source_lines"] <= lines <= CRITERIA["max_source_lines"]:
        raise SystemExit(
            f"{name}: {lines} source lines outside {CRITERIA['min_source_lines']}-{CRITERIA['max_source_lines']}"
        )
    return result


def copy_corpus(name, files):
    target = ROOT / "corpus" / "dataset" / "JS_repos" / name
    checkout = CACHE / name
    copies = dict(files)
    for license_name in LICENSE_NAMES:
        if (checkout / license_name).is_file():
            copies[license_name] = checkout / license_name
            break
    else:
        raise SystemExit(f"{name}: no license file found")
    written = 0
    for relative, path in copies.items():
        destination = target / relative
        blob = path.read_bytes()
        if destination.exists():
            if destination.read_bytes() != blob:
                raise SystemExit(
                    f"{destination} differs from the pinned checkout; remove corpus/dataset/JS_repos/{name} and rerun"
                )
            continue
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(blob)
        written += 1
    stale = sorted(
        p.relative_to(target).as_posix()
        for p in target.rglob("*")
        if p.is_file() and p.relative_to(target).as_posix() not in copies
    )
    if stale:
        raise SystemExit(f"{name}: corpus files not selected by the lock: {stale}")
    return written


def setup_repository(name, spec, config, rerun, stress_count):
    download_checkout(name, spec)
    install_dependencies(name, spec)
    files = select_sources(name, spec)
    clean_test(name, spec, config, set(files), rerun)
    written = copy_corpus(name, files)
    print(
        f"{name}: {spec['tag']} {spec['commit'][:10]}; {len(files)} sources, {sum(line_count(p) for p in files.values())} lines; {written} corpus files written",
        flush=True,
    )
    if stress_count:
        stress(name, config, stress_count)


# ----------------------------------------------------------------------------- Exercism


def exercise_files(exercise, default):
    """The CI's file configuration for an exercise: .meta/config.json when it names tests, else the track default."""
    config_path = exercise / ".meta" / "config.json"
    files = None
    if config_path.is_file():
        candidate = json.loads(config_path.read_text()).get("files") or {}
        if candidate.get("test"):
            files = candidate
    files = files or default["files"]
    return {key: [value.replace("%{kebab_slug}", exercise.name) for value in values] for key, values in files.items()}


def exercism_support(exercise, files):
    """Files the CI copies next to the spec: `editor` files, lib/*.js and data/*."""
    support = {}
    for relative in files.get("editor", []):
        support[relative] = (exercise / relative).read_text(encoding="utf-8")
    for folder, pattern in [("lib", "*.js"), ("data", "*")]:
        if (exercise / folder).is_dir():
            for path in sorted((exercise / folder).glob(pattern)):
                if path.is_file():
                    support[f"{folder}/{path.name}"] = path.read_text(encoding="utf-8")
    return support


def setup_exercism(spec, config, rerun):
    name = "exercism"
    download_checkout(name, spec)
    install_dependencies(name, spec)
    checkout = CACHE / name
    pin = read_pin(name)
    corpus = ROOT / "corpus" / "dataset" / "Exercism_JS"
    problems = ROOT / config["problem_files"]["exercism"]
    excluded_path = problems.with_name("exercism_javascript_excluded.jsonl")
    marker = {
        "commit": spec["commit"],
        "min_solution_lines": spec["min_solution_lines"],
        "installed_sha256": pin["install"]["installed_sha256"],
        "command_sha256": digest(config["exercism"]["test"]),
    }
    if not rerun and pin.get("exercism_corpus", {}).get("marker") == marker and problems.is_file() and corpus.is_dir():
        print(f"exercism: corpus up to date ({pin['exercism_corpus']['kept']} exercises kept)", flush=True)
        return
    default = json.loads((checkout / "config.json").read_text())
    polyglot = set(spec["aider_polyglot"]["exercises"])
    node_version = subprocess.check_output(["node", "--version"], text=True).strip()
    environment = {
        "javascript": {
            "node_version": node_version,
            "exercism": {
                "checkout": str(checkout),
                "commit": spec["commit"],
                "tarball_sha256": spec["tarball_sha256"],
                "node_modules_sha256": pin["install"]["installed_sha256"],
            },
        }
    }
    candidates, excluded = [], []
    for exercise in sorted((checkout / spec["exercises"]).iterdir()):
        if not exercise.is_dir():
            continue
        slug = exercise.name
        files = exercise_files(exercise, default)
        proof = exercise / ".meta" / "proof.ci.js"
        lines = line_count(proof) if proof.is_file() else 0
        reason = None
        if (
            files.get("example") != [".meta/proof.ci.js"]
            or len(files.get("solution", [])) != 1
            or len(files.get("test", [])) != 1
        ):
            reason = "the reference solution, stub or spec is not a single file"
        elif not proof.is_file():
            reason = "no reference solution"
        elif lines < spec["min_solution_lines"]:
            reason = f"reference solution has {lines} lines (< {spec['min_solution_lines']})"
        elif not (exercise / files["test"][0]).is_file():
            reason = "spec file missing"
        if reason:
            excluded.append({"slug": slug, "proof_lines": lines, "reason": reason})
            continue
        candidates.append((slug, exercise, files, proof, lines))

    def check(candidate):
        slug, exercise, files, proof, lines = candidate
        row = {
            "task_id": "Exercism/" + slug,
            "slug": slug,
            "spec_file": files["test"][0],
            "spec": (exercise / files["test"][0]).read_text(encoding="utf-8"),
            "support_files": exercism_support(exercise, files),
            "solution_file": files["solution"][0],
            "proof_lines": lines,
            "aider_polyglot": slug in polyglot,
            "source": {
                "repository": spec["repository"],
                "commit": spec["commit"],
                "path": f"{spec['exercises']}/{slug}/.meta/proof.ci.js",
            },
        }
        with tempfile.TemporaryDirectory(prefix="exercism-clean-") as temporary:
            directory = Path(temporary) / "unit"
            directory.mkdir()
            (directory / (slug + ".js")).write_bytes(proof.read_bytes())
            unit = {"source_files": [f"corpus/dataset/Exercism_JS/{slug}.js"]}
            started = time.perf_counter()
            result = _evaluate_exercism(
                unit, directory, {"exercism": {row["task_id"]: row}}, config, environment, Path(temporary) / "cache"
            )
            seconds = time.perf_counter() - started
            log = ""
            if result["status"] != "PASS":
                log = (
                    Path(result["test"]["stdout"]).read_text(errors="replace")
                    + Path(result["test"]["stderr"]).read_text(errors="replace")
                )[-600:]
        return row, result["status"], round(seconds, 2), log

    with ThreadPoolExecutor(4) as pool:
        outcomes = list(pool.map(check, candidates))
    kept, seconds = [], {}
    for row, status, elapsed, log in outcomes:
        if status == "PASS":
            kept.append(row)
            seconds[row["slug"]] = elapsed
        else:
            excluded.append(
                {
                    "slug": row["slug"],
                    "proof_lines": row["proof_lines"],
                    "reason": f"the reference solution does not pass its own spec in the pinned Jest setup ({status}): "
                    + " ".join(log.split())[-300:],
                }
            )
    corpus.mkdir(parents=True, exist_ok=True)
    for row in kept:
        proof = (checkout / spec["exercises"] / row["slug"] / ".meta" / "proof.ci.js").read_bytes()
        target = corpus / (row["slug"] + ".js")
        if target.exists() and target.read_bytes() != proof:
            raise SystemExit(f"{target} differs from the pinned reference solution")
        target.write_bytes(proof)
    stale = sorted(p.name for p in corpus.glob("*.js") if p.stem not in {row["slug"] for row in kept})
    if stale:
        raise SystemExit(f"corpus/dataset/Exercism_JS holds files that are not kept exercises: {stale}")
    problems.parent.mkdir(parents=True, exist_ok=True)
    problems.write_text(
        "".join(
            json.dumps(row, ensure_ascii=False, sort_keys=True) + "\n" for row in sorted(kept, key=lambda r: r["slug"])
        ),
        encoding="utf-8",
    )
    excluded_path.write_text(
        "".join(
            json.dumps(row, ensure_ascii=False, sort_keys=True) + "\n"
            for row in sorted(excluded, key=lambda r: r["slug"])
        ),
        encoding="utf-8",
    )
    pin = read_pin(name)
    pin["exercism_corpus"] = {"marker": marker, "kept": len(kept), "excluded": len(excluded), "clean_seconds": seconds}
    write_pin(name, pin)
    print(
        f"exercism: {len(kept)} exercises kept, {len(excluded)} excluded; Aider Polyglot overlap {sum(r['aider_polyglot'] for r in kept)}",
        flush=True,
    )


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument(
        "--only",
        nargs="+",
        metavar="NAME",
        help='only these repositories ("exercism" for the Exercism track); skips lodash and the small projects',
    )
    parser.add_argument(
        "--rerun-clean-tests", action="store_true", help="ignore recorded clean-test results and corpus markers"
    )
    parser.add_argument(
        "--stress",
        type=int,
        default=0,
        metavar="N",
        help="additionally run N concurrent clean copies of each repository suite",
    )
    args = parser.parse_args(argv)
    lock = json.loads((ROOT / "benchmarks" / "javascript.lock.json").read_text())
    config = json.loads((ROOT / "benchmarks" / "config.json").read_text())
    names = set(args.only or [])
    unknown = names - set(lock["repositories"]) - {"exercism"}
    if unknown:
        raise SystemExit("Unknown repositories: " + ", ".join(sorted(unknown)))
    if not names:
        legacy_projects(lock)
    for name, spec in lock["repositories"].items():
        if not names or name in names:
            setup_repository(name, spec, config, args.rerun_clean_tests, args.stress)
    if not names or "exercism" in names:
        setup_exercism(lock["exercism"], config, args.rerun_clean_tests)


if __name__ == "__main__":
    main()
