"""Local MBXP test execution with bounded subprocesses and content-addressed caching."""

from contextlib import contextmanager
import fcntl
import json
import os
from pathlib import Path
import re
import resource
import shutil
import signal
import subprocess
import sys
import time

from .common import digest, project_paths, unit_file_names, write_json


def load_problems(inputs, config):
    result = {}
    for language, relative in config["problem_files"].items():
        rows = {}
        for line in (inputs / relative).read_text(encoding="utf-8").splitlines():
            if line.strip():
                row = json.loads(line)
                if row["task_id"] in rows:
                    raise ValueError("Duplicate test task id: " + row["task_id"])
                rows[row["task_id"]] = row
        result[language] = rows
    return result


def subprocess_limits():
    resource.setrlimit(resource.RLIMIT_CORE, (0, 0))
    resource.setrlimit(resource.RLIMIT_FSIZE, (16 * 1024 * 1024, 16 * 1024 * 1024))


def run_process(command, directory, timeout, stem, env=None, log_directory=None):
    """Run `command` in `directory`; stdout/stderr go to `log_directory` (default: `directory`)."""
    directory = Path(directory)
    logs = Path(log_directory) if log_directory is not None else directory
    stdout_path, stderr_path = logs / (stem + ".stdout"), logs / (stem + ".stderr")
    started = time.perf_counter()
    timed_out = False
    with stdout_path.open("wb") as stdout, stderr_path.open("wb") as stderr:
        process = subprocess.Popen(command, cwd=directory, stdin=subprocess.DEVNULL, stdout=stdout, stderr=stderr,
                                   env=env, start_new_session=True, preexec_fn=subprocess_limits)
        try:
            process.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            timed_out = True
        finally:
            # Also reap descendants left behind after the candidate exits.
            try:
                os.killpg(process.pid, signal.SIGKILL)
            except ProcessLookupError:
                pass
            process.wait()
    with stderr_path.open("rb") as handle:
        excerpt = handle.read(8192).decode("utf-8", errors="replace")
    return {"returncode": process.returncode, "timed_out": timed_out,
            "elapsed_ms": (time.perf_counter() - started) * 1000, "stderr_excerpt": excerpt,
            "stdout": str(stdout_path), "stderr": str(stderr_path)}


def run_test(command, directory, timeout, retries, env, log_directory=None):
    attempts = []
    for index in range(retries + 1):
        result = run_process(command, directory, timeout, f"test-attempt-{index + 1}", env, log_directory)
        attempts.append(result)
        if not result["timed_out"]:
            break
    return {**attempts[-1], "attempts": attempts,
            "recovered_after_timeout": len(attempts) > 1 and not attempts[-1]["timed_out"] and attempts[-1]["returncode"] == 0}


@contextmanager
def cache_lock(path):
    with path.open("a+") as handle:
        fcntl.flock(handle, fcntl.LOCK_EX)
        try:
            yield
        finally:
            fcntl.flock(handle, fcntl.LOCK_UN)


def assemble_test(language, code, problem, seed):
    if language == "python":
        return f"import random\nrandom.seed({seed})\n" + code + "\n" + problem["test"] + f"\ncheck({problem['entry_point']})\n"
    entry = re.escape(problem["entry_point"])
    if re.search(r"\b" + entry + r"\s*\([^;{}]*\)\s*\{", code):
        prompt = problem["prompt"]
        start = prompt.rfind("\n", 0, prompt.rfind(problem["entry_point"])) + 1
        source = prompt[:start] + "\n" + code
    else:
        source = problem["prompt"] + code
    return source + "\n" + problem["test"] + "\n"


PROGRAMS = {"python": "candidate.py", "cpp": "candidate.cpp", "javascript": "candidate.js"}


def evaluate_utility(unit, directory, problems, config, run_dir, environment, cache_root):
    result = _evaluate_cached_utility(unit, directory, problems, config, run_dir, environment, cache_root)
    if result.get("artifacts"):
        target = Path(directory) / ".utility"
        target.mkdir(exist_ok=True)
        cached = Path(result["artifacts"])
        files = [cached / name for name in PROGRAMS.values()]
        files += [p for pattern in ["compile*.stdout", "compile*.stderr", "test*.stdout", "test*.stderr"] for p in cached.glob(pattern)]
        for path in files:
            if path.exists():
                shutil.copyfile(path, target / path.name)
        result = {**result, "local_artifacts": str(target)}
        write_json(target / "result.json", result)
    return result


def _evaluate_cached_utility(unit, directory, problems, config, run_dir, environment, cache_root):
    if unit["oracle"] == "unmapped_codenet":
        return {"status": "NO_PROBLEM_MAPPING", "reason": "CNxxx filenames lack a verified CodeNet problem-id map"}
    if unit["oracle"] == "project_tests" and unit["level"] in ["project", "project_file"]:
        return _evaluate_project_tests(unit, Path(directory), config, environment, Path(cache_root))
    if unit["oracle"] == "exercism" and unit["level"] == "function":
        return _evaluate_exercism(unit, Path(directory), problems, config, environment, Path(cache_root))
    if unit["oracle"] != "mbxp" or unit["level"] != "function":
        return {"status": "NO_TEST_ORACLE", "reason": "No runnable local functional test harness is supplied for this unit"}
    language = unit["language"]
    source = directory / Path(unit["source_files"][0]).name
    task_id = source.stem.replace("_", "/", 1)
    problem = problems.get(language, {}).get(task_id)
    if not problem or not problem.get("test") or not problem.get("entry_point"):
        return {"status": "NO_TEST_ORACLE", "task_id": task_id}
    code = source.read_text(encoding="utf-8", errors="strict")
    assembled = assemble_test(language, code, problem, config["seed"])
    includes = Path(__file__).resolve().parent / "include"
    compatibility_header = includes / "bits" / "stdc++.h"
    identity = {"language": language, "assembled": assembled, "environment": environment,
                "compile_timeout": config["compile_timeout_seconds"], "test_timeout": config["test_timeout_seconds"],
                "test_timeout_retries": config.get("test_timeout_retries", 0),
                "cpp_header": digest(compatibility_header.read_bytes()), "compiler_flags": ["-std=c++17", "-O0"],
                "python_hash_seed": str(config["seed"]), "harness_sha256": digest(Path(__file__).read_bytes())}
    key = digest(identity)
    cache_root = Path(cache_root)
    cache_root.mkdir(parents=True, exist_ok=True)
    with cache_lock(cache_root / (key + ".lock")):
        cache = cache_root / key
        result_path = cache / "result.json"
        if result_path.exists():
            result = json.loads(result_path.read_text())
            return {**result, "cache_hit": True}
        cache.mkdir(exist_ok=True)
        program = cache / PROGRAMS[language]
        program.write_text(assembled, encoding="utf-8")
        base = {"task_id": task_id, "oracle_sha256": digest(problem), "cache_key": key, "cache_hit": False,
                "artifacts": str(cache), "test_kind": "supplied_MBXP_tests"}
        if language == "python":
            try:
                compile(assembled, str(program), "exec")
            except SyntaxError as error:
                result = {**base, "status": "COMPILE_ERROR", "error": str(error)}
                write_json(result_path, result)
                return result
            command = [sys.executable, str(program)]
        elif language == "javascript":
            checked = run_process([environment["javascript"]["node"], "--check", str(program)], cache, config["compile_timeout_seconds"], "compile")
            if checked["timed_out"] or checked["returncode"] != 0:
                result = {**base, "status": "COMPILE_TIMEOUT" if checked["timed_out"] else "COMPILE_ERROR", "compile": checked}
                if not checked["timed_out"]:
                    write_json(result_path, result)
                return result
            command = [environment["javascript"]["node"], str(program)]
        else:
            executable = cache / "candidate"
            command = [environment["compiler"], "-std=c++17", "-O0", "-I", str(includes), str(program), "-o", str(executable)]
            compiled = run_process(command, cache, config["compile_timeout_seconds"], "compile")
            if compiled["timed_out"] or compiled["returncode"] != 0:
                result = {**base, "status": "COMPILE_TIMEOUT" if compiled["timed_out"] else "COMPILE_ERROR", "compile": compiled}
                if not compiled["timed_out"]:
                    write_json(result_path, result)
                return result
            command = [str(executable)]
        env = {**os.environ, "PYTHONHASHSEED": str(config["seed"])}
        if language == "javascript":
            env["NODE_PATH"] = environment["javascript"]["node_path"]
        tested = run_test(command, cache, config["test_timeout_seconds"], config.get("test_timeout_retries", 0), env)
        status = "TIMEOUT" if tested["timed_out"] else "PASS" if tested["returncode"] == 0 else "FAIL"
        result = {**base, "status": status, "test": tested}
        if status != "TIMEOUT":
            write_json(result_path, result)
        return result


@contextmanager
def exclusive_tests(cache_root, enabled):
    """Serialize suites that bind sockets: concurrent copies of the same suite collide on fixed ports and
    sometimes on ephemeral ones, which would turn unrelated parallel units into spurious FAIL results."""
    if not enabled:
        yield
        return
    with cache_lock(cache_root / "exclusive-tests.lock"):
        yield


def _overlay(checkout, path, blob):
    target = checkout / path
    if target.is_symlink():
        target.unlink()  # never write through a link into the pinned checkout
    target.parent.mkdir(parents=True, exist_ok=True)
    target.write_bytes(blob)


def _evaluate_project_tests(unit, directory, config, environment, cache_root):
    """Run a project's own test suite with the unit's (possibly watermarked) sources in place.

    The pinned checkout (with its installed test dependencies) is copied without node_modules,
    which is linked instead; every unit file replaces the checkout file at the same project path.
    A project unit holds every source file of the project, a project_file unit one file of it. Files that equal the
    pinned checkout do not enter the cache key, so all clean runs of a project share one entry.
    """
    name = unit.get("project", unit["name"])
    project = config["projects"].get(name)
    if project is None:
        return {"status": "NO_TEST_ORACLE", "reason": "No pinned test suite configured for project " + name}
    pinned = environment["javascript"]["projects"][name]
    names = unit_file_names(unit)
    files = {path: (directory / names[relative]).read_bytes() for relative, path in project_paths(unit).items()}
    original = Path(pinned["checkout"])
    changed = {path: blob for path, blob in files.items()
               if not (original / path).is_file() or (original / path).read_bytes() != blob}
    identity = {"project": name, "pinned": pinned, "files": {path: digest(blob) for path, blob in sorted(changed.items())},
                "command": project["test"], "exclusive": bool(project.get("exclusive")),
                "timeout": config["project_test_timeout_seconds"], "retries": config.get("test_timeout_retries", 0),
                "node": environment["javascript"]["node_version"], "harness_sha256": digest(Path(__file__).read_bytes())}
    key = digest(identity)
    cache_root.mkdir(parents=True, exist_ok=True)
    with cache_lock(cache_root / (key + ".lock")):
        cache = cache_root / key
        result_path = cache / "result.json"
        if result_path.exists():
            return {**json.loads(result_path.read_text()), "cache_hit": True}
        checkout = cache / "project"
        if checkout.exists():
            shutil.rmtree(checkout)
        shutil.copytree(original, checkout, ignore=shutil.ignore_patterns("node_modules", ".git"), symlinks=True)
        if (original / "node_modules").exists():
            (checkout / "node_modules").symlink_to(original / "node_modules", target_is_directory=True)
        for path, blob in changed.items():
            _overlay(checkout, path, blob)
        base = {"project": name, "cache_key": key, "cache_hit": False, "artifacts": str(cache), "test_kind": "project_test_suite",
                "changed_files": sorted(changed)}
        # The suite runs inside the project copy, but its logs belong in the cache entry itself, where
        # evaluate_utility collects test*.stdout/stderr into the unit's .utility directory.
        with exclusive_tests(cache_root, project.get("exclusive")):
            tested = run_test(project["test"], checkout, config["project_test_timeout_seconds"], config.get("test_timeout_retries", 0),
                              {**os.environ, "NODE_ENV": "test"}, log_directory=cache)
        status = "TIMEOUT" if tested["timed_out"] else "PASS" if tested["returncode"] == 0 else "FAIL"
        result = {**base, "status": status, "test": tested}
        if status != "TIMEOUT":
            write_json(result_path, result)
        return result


EXERCISM_SKIP_MARKERS = [(re.compile(r"x(test|it)\("), "test("), (re.compile(r"xdescribe\("), "describe(")]


def enable_exercism_tests(text):
    """Exercism's CI (scripts/helpers.mjs `prepare`) turns xtest/xit/xdescribe into test/describe, line by line and
    first match per line. `.skip` calls stay skipped on purpose (platform-dependent or always-failing cases)."""
    lines = text.split("\n")
    for pattern, replacement in EXERCISM_SKIP_MARKERS:
        lines = [pattern.sub(replacement, line, count=1) for line in lines]
    return "\n".join(lines)


def exercism_solution(text):
    """The CI also rewrites imports of the .meta directory (`from '../x'` to `from './x'`) in the reference solution."""
    return "\n".join(re.sub(r"from '../", "from './", line, count=1) for line in text.split("\n"))


def _evaluate_exercism(unit, directory, problems, config, environment, cache_root):
    """Run the Exercism exercise's Jest spec against the unit code, in the pinned checkout's Jest/Babel setup.

    The spec, support files (editor/lib/data) and metadata come from the frozen problem file; the pinned
    checkout supplies jest.config.js, babel.config.js and the installed test dependencies.
    """
    source = directory / Path(unit["source_files"][0]).name
    slug = source.stem
    problem = problems.get("exercism", {}).get("Exercism/" + slug)
    pinned = environment["javascript"].get("exercism")
    if not problem or not problem.get("spec") or pinned is None:
        return {"status": "NO_TEST_ORACLE", "task_id": "Exercism/" + slug}
    code = source.read_text(encoding="utf-8", errors="strict")
    spec = enable_exercism_tests(problem["spec"])
    solution = exercism_solution(code)
    command = list(config["exercism"]["test"])
    identity = {"slug": slug, "solution": digest(solution.encode()), "spec": digest(spec.encode()), "support": digest(problem.get("support_files", {})),
                "pinned": pinned, "command": command, "timeout": config["project_test_timeout_seconds"],
                "retries": config.get("test_timeout_retries", 0), "node": environment["javascript"]["node_version"],
                "harness_sha256": digest(Path(__file__).read_bytes())}
    key = digest(identity)
    cache_root.mkdir(parents=True, exist_ok=True)
    with cache_lock(cache_root / (key + ".lock")):
        cache = cache_root / key
        result_path = cache / "result.json"
        if result_path.exists():
            return {**json.loads(result_path.read_text()), "cache_hit": True}
        workspace = cache / "workspace"
        if workspace.exists():
            shutil.rmtree(workspace)
        exercise = workspace / "exercise"
        exercise.mkdir(parents=True)
        original = Path(pinned["checkout"])
        for name in ["jest.config.js", "babel.config.js"]:
            shutil.copyfile(original / name, workspace / name)
        (workspace / "node_modules").symlink_to(original / "node_modules", target_is_directory=True)
        for path, text in problem.get("support_files", {}).items():
            _overlay(exercise, path, text.encode("utf-8"))
        (exercise / problem["spec_file"]).write_text(spec, encoding="utf-8")
        (exercise / (slug + ".js")).write_text(solution, encoding="utf-8")
        base = {"task_id": "Exercism/" + slug, "cache_key": key, "cache_hit": False, "artifacts": str(cache), "test_kind": "exercism_jest_spec",
                "oracle_sha256": digest(problem)}
        tested = run_test(command, workspace, config["project_test_timeout_seconds"], config.get("test_timeout_retries", 0),
                          {**os.environ, "NODE_ENV": "test", "CI": "true"}, log_directory=cache)
        status = "TIMEOUT" if tested["timed_out"] else "PASS" if tested["returncode"] == 0 else "FAIL"
        result = {**base, "status": status, "test": tested}
        if status != "TIMEOUT":
            write_json(result_path, result)
        return result
