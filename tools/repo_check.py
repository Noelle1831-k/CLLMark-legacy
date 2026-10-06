#!/usr/bin/env python3
"""Functional preservation on real repositories: watermark or rewrite pinned ~100k-line projects, build, run their tests.

The benchmark measures many small units; this check adds large real code bases with their own test suites
(benchmarks/real_repos.json). Every variant is a fresh copy of the prepared checkout:

* clean                         unchanged sources (the suite must pass, else the repository is not usable),
* watermark/<rule set>/<gran.>  the message embedded in the repository's sources as one project, with
                                expected-message extraction checked on the result,
* stress/<rule set>/<style>     one style applied to every source file: each rule's semantic preservation over the
                                whole code base, far beyond the seven files a watermark touches. The default
                                quick mode stresses only the config's critical styles (the extension styles and
                                legacy styles that broke these repositories before); --mode all stresses every style.

A variant passes when its build and test commands exit 0. A failing test command is run once more (flaky
tests); a variant that fails both times is bisected over its changed files, when --bisect is given, down to
the files that alone make the suite fail. Results go to benchmark-results/real-repos/<run id>/ (report.md,
results.json, the diff of each failing variant).

Usage:
    tools/repo_check.py setup [--repo NAME ...]
    tools/repo_check.py instant [--repo NAME ...]       # seconds: syntax of every style, extraction, smoke tests
    tools/repo_check.py run [--repo NAME ...] [--mode quick|watermark|stress|all] [--rule-set legacy|extended|all]
                            [--styles 7.1 ...] [--parallel N] [--bisect] [--keep]
"""

import argparse
import concurrent.futures
import difflib
import json
import os
import random
import shutil
import subprocess
import sys
import threading
import time
from datetime import UTC, datetime
from fnmatch import fnmatch
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

CONFIG = ROOT / "benchmarks" / "real_repos.json"
CACHE = ROOT / ".benchmark-cache" / "real-repos"
RESULTS = ROOT / "benchmark-results" / "real-repos"
RULE_SETS = ("legacy", "extended")
GRANULARITIES = ("file", "node")
DETECT_ONLY = {"11", "12"}
OUTPUT_LIMIT = 4000


def load_config():
    return json.loads(CONFIG.read_text())


def selected(config, names):
    repositories = config["repositories"]
    unknown = set(names or []) - {repository["name"] for repository in repositories}
    if unknown:
        raise SystemExit(f"unknown repositories: {sorted(unknown)}")
    return [repository for repository in repositories if not names or repository["name"] in names]


def expand(command, repository, threads):
    """A command of the config with its placeholders filled in."""
    values = {
        "python": sys.executable,
        "env": str(CACHE / repository["name"] / "env"),
        "threads": str(threads),
    }
    return [part.format(**values) for part in command]


def run_command(command, cwd, timeout, environment=None):
    started = time.perf_counter()
    try:
        process = subprocess.run(
            command,
            cwd=cwd,
            capture_output=True,
            text=True,
            errors="replace",
            timeout=timeout,
            env={**os.environ, **(environment or {})},
        )
        status, output = process.returncode, process.stdout + process.stderr
    except subprocess.TimeoutExpired as error:
        status = "timeout"
        output = (error.stdout or b"").decode("utf-8", "replace") if isinstance(error.stdout, bytes) else ""
    return {
        "command": command,
        "status": status,
        "seconds": round(time.perf_counter() - started, 1),
        "output": output[-OUTPUT_LIMIT:],
    }


# ---------------------------------------------------------------- setup


def checkout_directory(repository):
    return CACHE / repository["name"] / "checkout"


def setup(repository, threads):
    """Clone the pinned commit, install the dependencies and build once (variants copy this prepared tree)."""
    checkout = checkout_directory(repository)
    if checkout.exists():
        shutil.rmtree(checkout)
    checkout.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run(
        ["git", "clone", "-q", "--depth", "1", "--branch", repository["tag"], repository["url"], str(checkout)],
        check=True,
    )
    head = subprocess.run(
        ["git", "rev-parse", "HEAD"], cwd=checkout, check=True, capture_output=True, text=True
    ).stdout.strip()
    if head != repository["commit"]:
        raise SystemExit(f"{repository['name']}: tag {repository['tag']} is {head}, pinned {repository['commit']}")
    shutil.rmtree(checkout / ".git")
    for command in repository.get("setup", []) + repository.get("build", []):
        result = run_command(expand(command, repository, threads), checkout, repository["timeout_seconds"])
        if result["status"] != 0:
            raise SystemExit(f"{repository['name']}: {command} failed:\n{result['output']}")
    sources = source_files(repository, checkout)
    lines = sum(len((checkout / path).read_bytes().splitlines()) for path in sources)
    print(f"{repository['name']}: {head[:12]}, {len(sources)} source files, {lines} lines")


def source_files(repository, checkout):
    """Paths (relative, POSIX) of the files the watermark may rewrite: the includes minus the excludes."""
    include, exclude = repository["sources"]["include"], repository["sources"].get("exclude", [])
    found = []
    for path in sorted(checkout.rglob("*")):
        relative = path.relative_to(checkout).as_posix()
        if (
            path.is_file()
            and not path.is_symlink()
            and any(fnmatch(relative, pattern) for pattern in include)
            and not any(fnmatch(relative, pattern) for pattern in exclude)
        ):
            found.append(relative)
    return found


# ---------------------------------------------------------------- source rewriting

_TRANSFORMERS = {}


def transformer(language, rule_set):
    from cllmark.transform import StyleTransformer

    key = (language, rule_set)
    if key not in _TRANSFORMERS:
        _TRANSFORMERS[key] = StyleTransformer(language, rule_set=rule_set)
    return _TRANSFORMERS[key]


def rewrite_file(arguments):
    """{style: rewritten text} of one file for the styles that change it, and the styles whose output stops
    parsing (stress mode writes those too: a watermark would)."""
    path, language, rule_set, styles = arguments
    from cllmark import source_io

    code = source_io.read_source(path)
    rewriter = transformer(language, rule_set)
    parsed_before = rewriter.check_syntax(code)
    changed, broken, errors = {}, [], {}
    for style in styles:
        try:
            new_code = rewriter.apply(style, code)[0]
        except Exception as error:  # a raising rule is reported, the file stays as it is
            errors[style] = repr(error)
            continue
        if new_code != code:
            changed[style] = new_code
            if parsed_before and not rewriter.check_syntax(new_code):
                broken.append(style)
    return path, changed, broken, errors


def stress_rewrites(repository, rule_set, styles, jobs):
    """style -> {relative path: text} over the repository's sources, plus syntax regressions and rule errors."""
    checkout = checkout_directory(repository)
    paths = source_files(repository, checkout)
    work = [(str(checkout / path), repository["language"], rule_set, styles) for path in paths]
    rewrites = {style: {} for style in styles}
    broken = {style: [] for style in styles}
    errors = {style: {} for style in styles}
    with concurrent.futures.ProcessPoolExecutor(jobs) as pool:
        for absolute, changed, bad, failed in pool.map(rewrite_file, work, chunksize=4):
            relative = Path(absolute).relative_to(checkout).as_posix()
            for style, code in changed.items():
                rewrites[style][relative] = code
            for style in bad:
                broken[style].append(relative)
            for style, error in failed.items():
                errors[style][relative] = error
    return rewrites, broken, errors


def flat_name(relative):
    return relative.replace("/", "__")


def watermark(repository, rule_set, granularity, bits):
    """Embed `bits` into the repository's sources as one project; returns the variant's rewrites and its record."""
    from cllmark import bch, nodes, source_io
    from cllmark import watermark as file_slots

    random.seed(20261007)  # extraction fills undecidable bits at random
    checkout = checkout_directory(repository)
    language = repository["language"]
    paths = {flat_name(path): path for path in source_files(repository, checkout)}
    files = {name: source_io.read_source(checkout / paths[name]) for name in file_slots.project_order(paths)}
    rewriter = transformer(language, rule_set)
    started = time.perf_counter()
    if granularity == "node":
        slots = nodes.analyze(rewriter, language, files)
        capacity = len(slots)
    else:
        support = file_slots.analyze(rewriter, language, files)
        capacity = sum(len(pairs) for pairs in support.values())
    record = {"capacity": capacity, "analysis_seconds": round(time.perf_counter() - started, 1)}
    if capacity < bch.CODE_LENGTH:
        return {}, {**record, "embedded": False}
    if granularity == "node":
        written, carried, dropped = nodes.embed(rewriter, language, files, slots, bits)
    else:
        written = file_slots.embed(rewriter, language, files, support, bits)
    marked = {**files, **{name: source_io.reload_written(code) for name, code in written.items()}}
    if granularity == "node":
        matched, codeword = nodes.extract(rewriter, language, marked, carried[: bch.CODE_LENGTH], bits)
        record["dropped_slots"] = dropped
    else:
        matched, codeword = file_slots.extract(rewriter, language, marked, support, bits)
    record.update({"embedded": True, "message_matches": matched, "codeword_matches": codeword})
    record["syntax_regressions"] = [
        paths[name]
        for name, code in written.items()
        if rewriter.check_syntax(files[name]) and not rewriter.check_syntax(code)
    ]
    return {paths[name]: code for name, code in written.items()}, record


# ---------------------------------------------------------------- variants


class Runner:
    def __init__(self, repository, run_dir, threads, keep, parallel):
        self.repository, self.run_dir, self.threads, self.keep = repository, run_dir, threads, keep
        self.counter, self.lock = 0, threading.Lock()
        self.parallel = parallel
        self.slots = threading.Semaphore(parallel)  # copies built and tested at once, bisection included

    def copy(self, label):
        with self.lock:
            self.counter += 1
            target = self.run_dir / "work" / self.repository["name"] / f"{self.counter:04d}-{label.replace('/', '_')}"
        shutil.copytree(checkout_directory(self.repository), target, symlinks=True)
        return target

    def attempt(self, rewrites, label):
        """Build and test a copy carrying `rewrites`; the test command runs twice before a failure counts."""
        with self.slots:
            return self._attempt(rewrites, label)

    def _attempt(self, rewrites, label):
        from cllmark import source_io

        directory = self.copy(label)
        try:
            for relative, code in rewrites.items():
                path = directory / relative
                path.unlink()  # a new file, so a copied hard link or the checkout is never written through
                source_io.write_source(path, code)
            timeout = self.repository["timeout_seconds"]
            # Concurrent variants must not share temporary files (test suites write fixed names there).
            environment = {"TMPDIR": str(directory / ".tmp")}
            (directory / ".tmp").mkdir()
            steps = []
            for command in self.repository.get("build", []):
                steps.append(
                    run_command(expand(command, self.repository, self.threads), directory, timeout, environment)
                )
                if steps[-1]["status"] != 0:
                    return {"passed": False, "stage": "build", "steps": steps}
            for retry in range(2):
                steps.append(
                    run_command(
                        expand(self.repository["test"], self.repository, self.threads), directory, timeout, environment
                    )
                )
                if steps[-1]["status"] == 0:
                    return {"passed": True, "stage": "test", "steps": steps, "flaky": retry > 0}
            return {"passed": False, "stage": "test", "steps": steps}
        finally:
            if not self.keep:
                shutil.rmtree(directory, ignore_errors=True)

    def bisect(self, rewrites, label, limit=3):
        """Up to `limit` sets of changed files that alone fail the suite: single files, or a group whose files only
        fail together. Each round tests `parallel` chunks of the suspects at once and keeps a failing chunk."""
        culprits, remaining = [], dict(sorted(rewrites.items()))
        while remaining and len(culprits) < limit:
            if self.attempt(remaining, label + "-bisect")["passed"]:
                break
            suspects = list(remaining)
            while len(suspects) > 1:
                count = min(max(2, self.parallel), len(suspects))
                chunks = [suspects[index::count] for index in range(count)]
                with concurrent.futures.ThreadPoolExecutor(count) as pool:
                    results = list(
                        pool.map(
                            lambda chunk: self.attempt({path: remaining[path] for path in chunk}, label + "-bisect"),
                            chunks,
                        )
                    )
                failing = [chunk for chunk, result in zip(chunks, results, strict=True) if not result["passed"]]
                if not failing:
                    break  # the suspects only fail together
                suspects = min(failing, key=len)
            culprits.append(suspects)
            for path in suspects:
                remaining.pop(path)
        return culprits


def summarize_attempt(result):
    return {
        "passed": result["passed"],
        "failed_stage": None if result["passed"] else result["stage"],
        "flaky": result.get("flaky", False),
        "seconds": round(sum(step["seconds"] for step in result["steps"]), 1),
        "failed_steps": [
            {"command": step["command"], "status": step["status"], "output": step["output"]}
            for step in result["steps"]
            if step["status"] != 0
        ],
    }


def diff_text(repository, rewrites, paths):
    from cllmark import source_io

    checkout = checkout_directory(repository)
    parts = []
    for path in paths:
        before = source_io.read_source(checkout / path).splitlines(keepends=True)
        after = rewrites[path].splitlines(keepends=True)
        parts += difflib.unified_diff(before, after, f"a/{path}", f"b/{path}", n=2)
    return "".join(parts)


def check_repository(repository, arguments, run_dir):
    from cllmark.rules.pairs import watermark_pairs

    name, language = repository["name"], repository["language"]
    threads = max(1, (os.cpu_count() or 8) // arguments.parallel)
    runner = Runner(repository, run_dir, threads, arguments.keep, arguments.parallel)
    report = {"name": name, "language": language, "commit": repository["commit"], "variants": {}}
    print(f"[{name}] clean build and tests", flush=True)
    clean = runner.attempt({}, "clean")
    report["clean"] = summarize_attempt(clean)
    if not clean["passed"]:
        print(f"[{name}] the unchanged repository fails its suite; skipped", flush=True)
        return report
    rule_sets = RULE_SETS if arguments.rule_set == "all" else (arguments.rule_set,)
    tasks = []
    if arguments.mode in ["quick", "watermark", "all"]:
        for rule_set in rule_sets:
            for granularity in GRANULARITIES:
                rewrites, record = watermark(repository, rule_set, granularity, arguments.bits)
                label = f"watermark/{rule_set}/{granularity}"
                print(f"[{name}] {label}: {record}", flush=True)
                tasks.append((label, rewrites, record))
    if arguments.mode in ["quick", "stress", "all"]:
        for rule_set in rule_sets:
            legacy = {style for pair in watermark_pairs(language, "legacy").values() for style in pair}
            styles = sorted(
                {style for pair in watermark_pairs(language, rule_set).values() for style in pair}
                - DETECT_ONLY
                - (legacy if rule_set != "legacy" else set()),
                key=lambda style: [int(part) for part in style.split(".")],
            )
            if arguments.styles:
                styles = [style for style in styles if style in arguments.styles]
            elif arguments.mode == "quick":
                styles = [style for style in styles if style in arguments.critical.get(language, [])]
            started = time.perf_counter()
            rewrites, broken, errors = stress_rewrites(repository, rule_set, styles, os.cpu_count() or 8)
            print(
                f"[{name}] rewrote {len(styles)} {rule_set} styles in {time.perf_counter() - started:.0f}s", flush=True
            )
            for style in styles:
                record = {
                    "changed_files": len(rewrites[style]),
                    "syntax_regressions": broken[style],
                    "rule_errors": errors[style],
                }
                if rewrites[style]:
                    tasks.append((f"stress/{rule_set}/{style}", rewrites[style], record))
                else:
                    report["variants"][f"stress/{rule_set}/{style}"] = {**record, "passed": None}

    def run(task):
        label, rewrites, record = task
        if not rewrites:
            return label, {**record, "passed": None}
        result = summarize_attempt(runner.attempt(rewrites, label))
        record = {**record, **result, "changed_files": len(rewrites)}
        if not result["passed"]:
            culprits = runner.bisect(rewrites, label) if arguments.bisect else []
            record["culprits"] = culprits
            diff = diff_text(
                repository, rewrites, sorted({path for group in culprits for path in group}) or sorted(rewrites)
            )
            diff_path = run_dir / "diffs" / name / (label.replace("/", "_") + ".diff")
            diff_path.parent.mkdir(parents=True, exist_ok=True)
            diff_path.write_text(diff, encoding="utf-8")
            record["diff"] = diff_path.relative_to(run_dir).as_posix()
        print(f"[{name}] {label}: {'pass' if record['passed'] else 'FAIL'} ({record['seconds']}s)", flush=True)
        return label, record

    with concurrent.futures.ThreadPoolExecutor(arguments.parallel) as pool:
        for label, record in pool.map(run, tasks):
            report["variants"][label] = record
    return report


# ---------------------------------------------------------------- instant check


def compiles(repository, path, code):
    """Whether the repository's compiler accepts `code` as the file at `path` (syntax_check reads it from stdin)."""
    checkout = checkout_directory(repository)
    command = [part.format(dir=str(Path(path).parent)) for part in repository["syntax_check"]]
    process = subprocess.run(command, cwd=checkout, input=code, capture_output=True, text=True, timeout=300)
    return process.returncode == 0


def confirm_syntax(repository, regressions):
    """The tree-sitter grammars misread some valid C++ (`a.first < b` as a template): keep only the (style, file)
    regressions whose file the compiler accepts before the rewrite and rejects after it."""
    if "syntax_check" not in repository:
        return regressions, {}
    from cllmark import source_io

    rewriter = transformer(repository["language"], "extended")
    pairs = [(style, path) for style, paths in regressions.items() for path in paths]
    originals = {path: source_io.read_source(checkout_directory(repository) / path) for _, path in pairs}

    def check(pair):
        style, path = pair
        rewritten = rewriter.apply(style, originals[path])[0]
        return compiles(repository, path, originals[path]) and not compiles(repository, path, rewritten)

    with concurrent.futures.ThreadPoolExecutor(32) as pool:
        verdicts = list(pool.map(check, pairs))
    confirmed, parser_only = {}, {}
    for (style, path), broken in zip(pairs, verdicts, strict=True):
        (confirmed if broken else parser_only).setdefault(style, []).append(path)
    return confirmed, parser_only


def watermark_job(name, rule_set, granularity, bits):
    """One watermark variant of one repository (a process pool job)."""
    repository = selected(load_config(), [name])[0]
    rewrites, record = watermark(repository, rule_set, granularity, bits)
    return name, rule_set, granularity, rewrites if (rule_set, granularity) == ("extended", "file") else {}, record


def instant(repositories, run_dir, bits):
    """Seconds, not minutes. One process pool runs, for all repositories at once: every style of the extended set
    (which holds the legacy styles) on every source file, which must keep parsing, and the four watermark variants,
    whose message must be extracted. Meanwhile each clean copy runs the repository's smoke tests, and the extended
    file-granular watermark runs them as soon as it is embedded."""
    from cllmark.rules.pairs import watermark_pairs

    started = time.perf_counter()
    cores = os.cpu_count() or 8
    threads = max(1, cores // (2 * len(repositories)))
    records, runners, marked = {}, {}, {}
    for repository in repositories:
        styles = sorted(
            {style for pair in watermark_pairs(repository["language"], "extended").values() for style in pair}
            - DETECT_ONLY
        )
        records[repository["name"]] = {"styles": styles, "syntax_regressions": {}, "rule_errors": {}, "watermark": {}}
        smoke = {**repository, "test": repository["smoke_test"]}
        runners[repository["name"]] = Runner(smoke, run_dir, threads, False, 2)
    with (
        concurrent.futures.ThreadPoolExecutor(2 * len(repositories)) as smoke_pool,
        concurrent.futures.ProcessPoolExecutor(cores) as pool,
    ):
        clean = {
            name: smoke_pool.submit(lambda runner: summarize_attempt(runner.attempt({}, "clean")), runner)
            for name, runner in runners.items()
        }
        jobs = []
        for repository in repositories:
            name, language = repository["name"], repository["language"]
            checkout = checkout_directory(repository)
            for path in source_files(repository, checkout):
                arguments = (str(checkout / path), language, "extended", records[name]["styles"])
                jobs.append(pool.submit(rewrite_file, arguments))
            for rule_set in RULE_SETS:
                for granularity in GRANULARITIES:
                    jobs.append(pool.submit(watermark_job, name, rule_set, granularity, bits))
        owner = {str(checkout_directory(repository)): repository["name"] for repository in repositories}
        embedded = {}
        for job in concurrent.futures.as_completed(jobs):
            result = job.result()
            if len(result) == 4:  # rewrite_file
                path, _, broken, errors = result
                name = next(name for root, name in owner.items() if path.startswith(root + os.sep))
                relative = os.path.relpath(path, next(root for root, other in owner.items() if other == name))
                for style in broken:
                    records[name]["syntax_regressions"].setdefault(style, []).append(relative)
                for style, error in errors.items():
                    records[name]["rule_errors"].setdefault(style, {})[relative] = error
            else:
                name, rule_set, granularity, rewrites, record = result
                records[name]["watermark"][f"{rule_set}/{granularity}"] = record
                if rewrites:
                    marked[name] = rewrites
                    embedded[name] = smoke_pool.submit(
                        lambda runner, rewrites: summarize_attempt(runner.attempt(rewrites, "watermark")),
                        runners[name],
                        rewrites,
                    )
        repositories_by_name = {repository["name"]: repository for repository in repositories}
        for name, record in records.items():
            record["syntax_regressions"], record["parser_only_regressions"] = confirm_syntax(
                repositories_by_name[name], record["syntax_regressions"]
            )
            record["styles"] = len(record["styles"])
            record["clean_smoke"] = clean[name].result()
            record["watermark_smoke"] = embedded[name].result() if name in embedded else {"passed": False}
            record["passed"] = (
                not record["syntax_regressions"]
                and not record["rule_errors"]
                and all(outcome.get("message_matches") for outcome in record["watermark"].values())
                and record["clean_smoke"]["passed"]
                and record["watermark_smoke"]["passed"]
            )
    (run_dir / "instant.json").write_text(json.dumps(records, indent=1), encoding="utf-8")
    print(f"{'repository':10} {'styles':>6} {'syntax':>6} {'parser':>6} {'errors':>6} {'extracted':>9} {'smoke':>12}")
    for name, record in records.items():
        extracted = sum(bool(outcome.get("message_matches")) for outcome in record["watermark"].values())
        clean_text = "ok" if record["clean_smoke"]["passed"] else "CLEAN FAIL"
        smoke = f"{clean_text}/{'ok' if record['watermark_smoke']['passed'] else 'FAIL'}"
        print(
            f"{name:10} {record['styles']:6} {len(record['syntax_regressions']):6} "
            f"{len(record['parser_only_regressions']):6} {len(record['rule_errors']):6} "
            f"{extracted:>7}/4 {smoke:>12}"
        )
        for style, paths in sorted(record["syntax_regressions"].items()):
            print(f"    syntax regression {style}: {sorted(paths)[:3]}")
    print(f"{time.perf_counter() - started:.1f}s")
    return all(record["passed"] for record in records.values())


# ---------------------------------------------------------------- report


def verdict(record):
    if record.get("passed") is None:
        return "not applicable"
    if not record["passed"]:
        return f"**FAIL** ({record['failed_stage']})"
    return "pass (flaky test retried)" if record.get("flaky") else "pass"


def write_report(run_dir, reports, arguments, lines_of):
    results = {"arguments": vars(arguments) | {"bits": arguments.bits}, "repositories": reports}
    (run_dir / "results.json").write_text(json.dumps(results, indent=1, default=str), encoding="utf-8")
    out = ["# Real-repository functional preservation", ""]
    out.append(
        f"Run `{run_dir.name}`; message {''.join(map(str, arguments.bits))}; mode {arguments.mode}; "
        f"rule sets {arguments.rule_set}."
    )
    out.append("")
    out.append("| Repository | Language | Commit | Source lines | Clean suite | Variants | Passed | Failed |")
    out.append("| --- | --- | --- | ---: | --- | ---: | ---: | ---: |")
    for report in reports:
        variants = [record for record in report["variants"].values() if record.get("passed") is not None]
        out.append(
            f"| {report['name']} | {report['language']} | `{report['commit'][:12]}` | {lines_of[report['name']]} | "
            f"{verdict(report['clean'])} | {len(variants)} | {sum(r['passed'] for r in variants)} | "
            f"{sum(not r['passed'] for r in variants)} |"
        )
    for report in reports:
        out += ["", f"## {report['name']}", ""]
        watermark_rows = {
            label: record for label, record in report["variants"].items() if label.startswith("watermark")
        }
        if watermark_rows:
            out.append(
                "| Variant | Capacity | Message extracted | Changed files | Syntax regressions | Build and tests |"
            )
            out.append("| --- | ---: | --- | ---: | ---: | --- |")
            for label, record in watermark_rows.items():
                extracted = record.get("message_matches") if record.get("embedded") else "not embedded"
                out.append(
                    f"| {label} | {record['capacity']} | {extracted} | {record.get('changed_files', 0)} | "
                    f"{len(record.get('syntax_regressions', []))} | {verdict(record)} |"
                )
            out.append("")
        stress_rows = {label: record for label, record in report["variants"].items() if label.startswith("stress")}
        if stress_rows:
            out.append("| Style | Changed files | Syntax regressions | Rule errors | Build and tests | Culprit files |")
            out.append("| --- | ---: | ---: | ---: | --- | --- |")
            for label, record in stress_rows.items():
                culprits = "; ".join(" + ".join(f"`{path}`" for path in group) for group in record.get("culprits", []))
                out.append(
                    f"| {label} | {record['changed_files']} | {len(record['syntax_regressions'])} | "
                    f"{len(record['rule_errors'])} | {verdict(record)} | {culprits} |"
                )
    (run_dir / "report.md").write_text("\n".join(out) + "\n", encoding="utf-8")


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    commands = parser.add_subparsers(dest="command", required=True)
    for command in ["setup", "run", "instant"]:
        child = commands.add_parser(command)
        child.add_argument("--repo", action="append", help="repository name (default: all)")
    run = commands.choices["run"]
    run.add_argument(
        "--mode",
        choices=["quick", "watermark", "stress", "all"],
        default="quick",
        help="quick (default): watermark variants and the critical styles of the config; all: every style",
    )
    run.add_argument("--rule-set", choices=[*RULE_SETS, "all"], default="all")
    run.add_argument("--styles", nargs="*", help="stress only these styles")
    run.add_argument("--bits", default="1010", help="4-bit message for watermark variants")
    run.add_argument("--parallel", type=int, default=8, help="variants built and tested at once")
    run.add_argument("--bisect", action="store_true", help="find the culprit files of failing variants")
    run.add_argument("--keep", action="store_true", help="keep the variant copies")
    arguments = parser.parse_args()
    os.chdir(ROOT)
    config = load_config()
    repositories = selected(config, arguments.repo)
    arguments.critical = config.get("critical_styles", {})
    if arguments.command == "setup":
        for repository in repositories:
            setup(repository, os.cpu_count() or 8)
        return 0
    stamp = datetime.now(UTC).strftime("%Y%m%dT%H%M%SZ")
    run_dir = RESULTS / stamp
    run_dir.mkdir(parents=True)
    if arguments.command == "instant":
        passed = instant(repositories, run_dir, [1, 0, 1, 0])
        shutil.rmtree(run_dir / "work", ignore_errors=True)
        print(f"result: {run_dir / 'instant.json'}")
        return 0 if passed else 1
    arguments.bits = [int(bit) for bit in arguments.bits]
    reports, lines_of = [], {}
    for repository in repositories:
        if not checkout_directory(repository).is_dir():
            raise SystemExit(f"{repository['name']} is not set up; run tools/repo_check.py setup")
        checkout = checkout_directory(repository)
        lines_of[repository["name"]] = sum(
            len((checkout / path).read_bytes().splitlines()) for path in source_files(repository, checkout)
        )
        reports.append(check_repository(repository, arguments, run_dir))
        write_report(run_dir, reports, arguments, lines_of)
    if not arguments.keep:
        shutil.rmtree(run_dir / "work", ignore_errors=True)
    failed = any(
        not report["clean"]["passed"] or any(record.get("passed") is False for record in report["variants"].values())
        for report in reports
    )
    print(f"report: {run_dir / 'report.md'}")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
