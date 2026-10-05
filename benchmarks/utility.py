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

from .common import digest, write_json


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


def run_process(command, directory, timeout, stem, env=None):
    directory = Path(directory)
    stdout_path, stderr_path = directory / (stem + ".stdout"), directory / (stem + ".stderr")
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


def evaluate_utility(unit, directory, problems, config, run_dir, environment, cache_root):
    result = _evaluate_cached_utility(unit, directory, problems, config, run_dir, environment, cache_root)
    if result.get("artifacts"):
        target = Path(directory) / ".utility"
        target.mkdir(exist_ok=True)
        cached = Path(result["artifacts"])
        for name in ["candidate.py", "candidate.cpp", "compile.stdout", "compile.stderr", "test.stdout", "test.stderr"]:
            if (cached / name).exists():
                shutil.copyfile(cached / name, target / name)
        result = {**result, "local_artifacts": str(target)}
        write_json(target / "result.json", result)
    return result


def _evaluate_cached_utility(unit, directory, problems, config, run_dir, environment, cache_root):
    if unit["oracle"] == "unmapped_codenet":
        return {"status": "NO_PROBLEM_MAPPING", "reason": "CNxxx filenames lack a verified CodeNet problem-id map"}
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
        program = cache / ("candidate.py" if language == "python" else "candidate.cpp")
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
        tested = run_process(command, cache, config["test_timeout_seconds"], "test", env)
        status = "TIMEOUT" if tested["timed_out"] else "PASS" if tested["returncode"] == 0 else "FAIL"
        result = {**base, "status": status, "test": tested}
        if status != "TIMEOUT":
            write_json(result_path, result)
        return result
