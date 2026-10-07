"""Functional oracle of the CodeNet stdin/stdout cohorts (docs/CODENET.md), kept out of the protocol-fingerprinted files.

A unit is one complete program; its problem row (frozen `problems.jsonl`) lists test cases with input and expected
output. The program is built (Python and JavaScript only syntax-checked), run on every case with a wall-clock limit of
`time_limit_ms * time_factor`, and each output is judged by the problem's checker (token comparison, optionally
followed by a numeric comparison with a tolerance). `evaluate_utility` delegates every other oracle to
`utility.evaluate_utility` unchanged. Only configs with a "codenet" key carry this file's digest in their protocol
config, so default runs and their fingerprints are untouched.
"""

import copy
import json
import math
import os
import shutil
import subprocess
import sys
import time
from contextlib import ExitStack, redirect_stderr, redirect_stdout, suppress
from functools import cache
from pathlib import Path

from . import engine as engine_module
from . import utility
from .common import digest, unit_file_names, write_json
from .common import validate_config as validate_common_config

ORACLE = "codenet_stdio"
LANGUAGES = ("python", "c", "cpp", "javascript")
C_FLAGS = ["-std=c11", "-O2", "-pipe"]
CPP_FLAGS = ["-std=c++17", "-O2", "-pipe"]
INCLUDES = Path(__file__).resolve().parent / "include"
PROGRAMS = {"python": "prog.py", "c": "prog.c", "cpp": "prog.cpp", "javascript": "prog.js"}
DETAIL_LIMIT = 200
ARTIFACT_LOGS = 20


def protocol_config(config, root):
    """The config of a run: runs with a "codenet" section also carry the digest of this file."""
    if "codenet" not in config:
        return config
    return {**config, "codenet_oracle_sha256": digest((Path(root) / "benchmarks" / "codenet.py").read_bytes())}


def codenet_cohorts(config):
    return [cohort for cohort in config.get("cohorts", []) if cohort.get("oracle") == ORACLE]


def validate_config(config):
    """Check the codenet cohorts, then the rest with the common validator (which does not know this oracle)."""
    cohorts = codenet_cohorts(config)
    if cohorts:
        section = config.get("codenet")
        if not isinstance(section, dict):
            raise ValueError("codenet_stdio cohorts need a codenet section")
        factor = section.get("time_factor")
        if isinstance(factor, bool) or not isinstance(factor, (int, float)) or not factor > 0:
            raise ValueError("codenet.time_factor must be a positive number")
        if section.get("problem_file") not in config.get("problem_files", {}):
            raise ValueError("codenet.problem_file must be a key of problem_files")
        for cohort in cohorts:
            if cohort["level"] != "function" or cohort["language"] not in LANGUAGES:
                raise ValueError("codenet_stdio cohorts are function-level python/c/cpp/javascript cohorts")
    for cohort in config.get("cohorts", []):
        if "embed" in cohort and (not isinstance(cohort["embed"], bool) or cohort.get("oracle") != ORACLE):
            raise ValueError("embed is a boolean and only allowed on codenet_stdio cohorts")
    stand_in = copy.deepcopy(config)
    for cohort in stand_in.get("cohorts", []):
        if cohort.get("oracle") == ORACLE:
            cohort["oracle"] = "none"
            cohort.pop("embed", None)
    validate_common_config(stand_in)
    return config


# Detection-only units (cohorts with "embed": false).


def install(engine_instance):
    """Route units of "embed": false cohorts of a codenet run to `detect_only`; others keep the engine's `evaluate`."""
    config = getattr(engine_instance, "config", None)
    if not isinstance(config, dict) or "codenet" not in config:
        return
    original = engine_instance.evaluate

    def evaluate(unit):
        if unit.get("embed", True):
            return original(unit)
        return detect_only(engine_instance, unit)

    engine_instance.evaluate = evaluate


def detect_only(engine, unit):
    """The row of a unit that is not embedded: only the unmarked code is analyzed and read for the watermark.

    The row has the fields of `LegacyEngine.evaluate` (also the node engine's), with `embedded` False, no `marked`
    directory, no attacks and no rule properties. `eligible` is False (the unit is not a watermark candidate, and
    `metrics.summarize_group` reads `marked_extraction` of every eligible row); `capacity_sufficient` says whether
    its capacity reaches the codeword length. Unlike the embedding path, the unmarked code is read for every unit,
    also those with too little capacity, because a natural false match does not depend on room to embed.

    Extraction with capacity < 7 (checked on `cllmark.directories` and `cllmark.nodes`): both granularities still
    call `bch.decode`, with the bits of the `capacity` slots there are (at most 7; `watermark.slots` yields one slot
    per usable rule pair in file granularity, node granularity keeps the first 7 stored slots). `bch.decode` reads
    fewer bits as an integer right-aligned, so a short word decodes to whatever those bits imply and a capacity of 0
    decodes the empty word to the message 0000. The raw codeword can never match with fewer than 7 bits. A slot
    that reads as neither or both styles contributes a random bit (seeded per unit), a slot whose probe raised
    contributes no bit.
    """
    started = time.perf_counter()
    language = unit["language"]
    engine.parser(language)  # Exclude one-time parser creation from phase timings.
    work = engine.run_dir / "work" / digest(unit["id"].encode())[:20]
    if work.exists():
        shutil.rmtree(work)
    clean = work / "clean"
    clean.mkdir(parents=True)
    filenames = []
    for relative, name in unit_file_names(unit).items():
        blob = (engine.run_dir / "inputs" / relative).read_bytes()
        if digest(blob) != engine.manifest["input_files"][relative]["sha256"]:
            raise ValueError("Frozen input hash mismatch: " + relative)
        filenames.append(name)
        (clean / name).write_bytes(blob)
    log = engine_module.BoundedLog()
    result = {
        "id": unit["id"],
        "cohort": unit["id"].split("/", 1)[0],
        "language": language,
        "role": unit["role"],
        "level": unit["level"],
        "source_files": unit["source_files"],
        "status": "ok",
        "file_count": len(filenames),
        "watermark": engine.config["watermark"],
    }
    with redirect_stdout(log), redirect_stderr(log):
        phase = time.perf_counter()
        analyzer = engine.nodes if hasattr(engine, "nodes") else engine.directories
        capacity = analyzer.analyze_directory(clean, language, engine.parser(language))
        result["analysis_ms"] = (time.perf_counter() - phase) * 1000
        required = len(engine.bch.encode(engine.config["watermark"]))
        result.update(
            {
                "capacity": capacity,
                "required_capacity": required,
                "eligible": False,
                "capacity_sufficient": capacity >= required,
                "embedded": False,
                "properties": None,
                "embedding_slots": [],
            }
        )
        result["syntax_before"] = {
            name: engine.parser(language).check_syntax(engine.read_source(clean / name)) for name in filenames
        }
        try:
            result["original_extraction"] = engine.extract(clean, language, unit["id"], "original")
        except Exception as error:
            result["original_extraction"] = {"error": repr(error), "matched": False, "raw_matched": False, "bits": []}
        result["marked_extraction"] = None
        result["syntax_after"], result["attacks"] = {}, {}
        result["utility_before"] = engine_module.evaluate_utility(
            unit,
            clean,
            engine.problems,
            engine.config,
            engine.run_dir,
            engine.manifest["environment"],
            engine.manifest["utility_cache"],
        )
        result["utility_after"] = {"status": "NOT_EMBEDDED"}
    (work / "legacy.log").write_text(log.getvalue(), encoding="utf-8")
    result["elapsed_ms"] = (time.perf_counter() - started) * 1000
    result["artifacts"] = work.relative_to(engine.run_dir).as_posix()
    write_json(work / "result.json", result)
    return result


# Checkers (semantics of the dataset repository's lib/checker.py).


def check_token(expected, actual):
    a, b = expected.split(), actual.split()
    if a == b:
        return True, ""
    for index in range(min(len(a), len(b))):
        if a[index] != b[index]:
            return False, f"token #{index + 1}: expected {a[index]!r}, got {b[index]!r}"
    return False, f"token count: expected {len(a)}, got {len(b)}"


def check_float(expected, actual, eps=1e-6):
    a, b = expected.split(), actual.split()
    if len(a) != len(b):
        return False, f"token count: expected {len(a)}, got {len(b)}"
    for index, (x, y) in enumerate(zip(a, b, strict=True)):
        try:
            fx, fy = float(x), float(y)
        except ValueError:
            if x != y:
                return False, f"token #{index + 1}: expected {x!r}, got {y!r}"
            continue
        if not (math.isfinite(fx) and math.isfinite(fy)):
            if x != y:
                return False, f"token #{index + 1}: expected {x!r}, got {y!r}"
            continue
        if abs(fx - fy) > eps * max(1.0, abs(fx)):
            return False, f"token #{index + 1}: expected {x}, got {y} (eps={eps})"
    return True, ""


def check_token_float(expected, actual, eps=1e-6):
    """Token match, else numeric match."""
    ok, why = check_token(expected, actual)
    if ok:
        return True, ""
    ok_float, _ = check_float(expected, actual, eps)
    return (True, "") if ok_float else (False, why)


def check(checker, expected, actual):
    """Judge `actual` by the checker string of the problem: `token` or `token+float:<eps>`."""
    if checker == "token":
        return check_token(expected, actual)
    if isinstance(checker, str) and checker.startswith("token+float:"):
        return check_token_float(expected, actual, float(checker.partition(":")[2]))
    raise ValueError(f"unknown checker: {checker!r}")


# Execution.


def run_process(command, directory, timeout, stem, env=None, stdin_path=None):
    """`utility.run_process` with the program's stdin read from `stdin_path` (an empty stdin if none)."""
    directory = Path(directory)
    stdout_path, stderr_path = directory / (stem + ".stdout"), directory / (stem + ".stderr")
    started = time.perf_counter()
    timed_out = False
    with ExitStack() as files:
        stdout = files.enter_context(stdout_path.open("wb"))
        stderr = files.enter_context(stderr_path.open("wb"))
        stdin = files.enter_context(Path(stdin_path).open("rb")) if stdin_path else subprocess.DEVNULL
        process = subprocess.Popen(
            command,
            cwd=directory,
            stdin=stdin,
            stdout=stdout,
            stderr=stderr,
            env=env,
            start_new_session=True,
            preexec_fn=utility.subprocess_limits,
        )
        try:
            process.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            timed_out = True
        finally:
            with suppress(ProcessLookupError):
                os.killpg(process.pid, 9)
            process.wait()
    with stderr_path.open("rb") as handle:
        excerpt = handle.read(8192).decode("utf-8", errors="replace")
    return {
        "returncode": process.returncode,
        "timed_out": timed_out,
        "elapsed_ms": (time.perf_counter() - started) * 1000,
        "stderr_excerpt": excerpt,
    }


def run_case(command, directory, timeout, retries, env, stem, stdin_path):
    """One test case; a timeout is retried like `utility.run_test` does."""
    attempts = []
    for _ in range(retries + 1):
        result = run_process(command, directory, timeout, stem, env, stdin_path)
        attempts.append(result)
        if not result["timed_out"]:
            break
    return {
        **attempts[-1],
        "attempts": attempts,
        "recovered_after_timeout": len(attempts) > 1
        and not attempts[-1]["timed_out"]
        and attempts[-1]["returncode"] == 0,
    }


@cache
def needs_header_shim(compiler):
    """Whether the C++ compiler lacks <bits/stdc++.h> (libc++ on macOS); GNU libstdc++ keeps its own header."""
    probe = subprocess.run(
        [compiler, "-std=c++17", "-fsyntax-only", "-x", "c++", "-"],
        input="#include <bits/stdc++.h>\n",
        text=True,
        capture_output=True,
    )
    return probe.returncode != 0


@cache
def compiler_version(path):
    try:
        return subprocess.check_output([path, "--version"], text=True, stderr=subprocess.STDOUT).splitlines()[0]
    except (OSError, subprocess.CalledProcessError, IndexError):
        return "unknown"


def judge(case, checker, directory, stem):
    """Verdict and detail of one finished case run (stdout in `directory/<stem>.stdout`)."""
    if case["timed_out"]:
        return "TLE", "time limit exceeded"
    if case["returncode"] != 0:
        return "RE", f"exit code {case['returncode']}: {case['stderr_excerpt'][-150:]}"
    actual = (Path(directory) / (stem + ".stdout")).read_text(encoding="utf-8", errors="replace")
    ok, why = check(checker, case["expected"], actual)
    return ("AC", "") if ok else ("WA", why)


def build(language, source, cache, config, environment):
    """Prepare the program: (command, None) or (None, failure result fields)."""
    program = cache / PROGRAMS[language]
    program.write_bytes(source)
    timeout = config["compile_timeout_seconds"]
    if language == "python":
        try:
            compile(source, str(program), "exec")
        except (SyntaxError, ValueError) as error:
            return None, {"status": "COMPILE_ERROR", "error": str(error)}
        return [environment["python_executable"], str(program)], None
    if language == "javascript":
        node = environment["javascript"]["node"]
        command, run = [node, "--check", str(program)], [node, str(program)]
    else:
        compiler = shutil.which("cc") if language == "c" else environment["compiler"]
        if not compiler:
            return None, {"status": "COMPILE_ERROR", "error": "no C compiler found"}
        executable = cache / "exe"
        if language == "c":
            command = [compiler, *C_FLAGS, str(program), "-o", str(executable), "-lm"]
        else:
            shim = ["-I", str(INCLUDES)] if needs_header_shim(compiler) else []
            command = [compiler, *CPP_FLAGS, *shim, str(program), "-o", str(executable)]
        run = [str(executable)]
    compiled = utility.run_process(command, cache, timeout, "compile")
    if compiled["timed_out"] or compiled["returncode"] != 0:
        return None, {"status": "COMPILE_TIMEOUT" if compiled["timed_out"] else "COMPILE_ERROR", "compile": compiled}
    return run, None


def identity(language, source, problem, config, environment):
    section = config["codenet"]
    compiler = shutil.which("cc") if language == "c" else environment.get("compiler")
    return {
        "language": language,
        "source": digest(source),
        "problem": digest(problem),
        "compiler": [compiler, compiler_version(compiler)] if language in ("c", "cpp") and compiler else None,
        "flags": {"c": C_FLAGS, "cpp": CPP_FLAGS}.get(language),
        "cpp_header": digest((INCLUDES / "bits" / "stdc++.h").read_bytes())
        if language == "cpp" and compiler and needs_header_shim(compiler)
        else None,
        "time_factor": section["time_factor"],
        "retries": config.get("test_timeout_retries", 0),
        "node": environment["javascript"].get("node_version") if language == "javascript" else None,
        "python": [environment.get("python_executable"), environment.get("python")] if language == "python" else None,
        "seed": config["seed"],
        "harness_sha256": digest(Path(__file__).read_bytes()),
    }


def evaluate_utility(unit, directory, problems, config, run_dir, environment, cache_root):
    """Same signature and return shape as `utility.evaluate_utility`; other oracles are delegated unchanged."""
    if unit["oracle"] != ORACLE:
        return utility.evaluate_utility(unit, directory, problems, config, run_dir, environment, cache_root)
    result = evaluate_cached(unit, Path(directory), problems, config, environment, Path(cache_root))
    if result.get("artifacts"):
        target = Path(directory) / ".utility"
        target.mkdir(exist_ok=True)
        cached = Path(result["artifacts"])
        logs = sorted(p for p in cached.glob("case-*") if p.suffix in (".stdout", ".stderr"))[:ARTIFACT_LOGS]
        files = [cached / PROGRAMS[unit["language"]], *cached.glob("compile*.stdout"), *cached.glob("compile*.stderr")]
        for path in [*files, *logs]:
            if path.exists():
                shutil.copyfile(path, target / path.name)
        result = {**result, "local_artifacts": str(target)}
        write_json(target / "result.json", result)
    return result


def evaluate_cached(unit, directory, problems, config, environment, cache_root):
    language = unit["language"]
    source_path = directory / Path(unit["source_files"][0]).name
    task_id = Path(unit["source_files"][0]).stem
    problem = problems.get(config["codenet"]["problem_file"], {}).get(task_id)
    if not problem:
        return {"status": "NO_TEST_ORACLE", "task_id": task_id}
    source = source_path.read_bytes()
    key = digest(identity(language, source, problem, config, environment))
    root = cache_root / "codenet"
    root.mkdir(parents=True, exist_ok=True)
    with utility.cache_lock(root / (key + ".lock")):
        cache = root / key
        result_path = cache / "result.json"
        if result_path.exists():
            return {**json.loads(result_path.read_text()), "cache_hit": True}
        cache.mkdir(exist_ok=True)
        cases = problem["test_cases"]
        base = {
            "task_id": task_id,
            "test_kind": "codenet_stdio_cases",
            "cases_total": len(cases),
            "cases_passed": 0,
            "oracle_sha256": digest(problem),
            "cache_key": key,
            "cache_hit": False,
            "artifacts": str(cache),
        }
        command, failure = build(language, source, cache, config, environment)
        if failure:
            result = {**base, **failure}
            if failure["status"] != "COMPILE_TIMEOUT":
                write_json(result_path, result)
            return result
        env = {**os.environ, "PYTHONHASHSEED": str(config["seed"])}
        timeout = problem["time_limit_ms"] / 1000 * config["codenet"]["time_factor"]
        retries = config.get("test_timeout_retries", 0)
        records, counts, skipping = [], {}, False
        for index, case in enumerate(cases):
            name = f"case-{index}"
            record = {"name": name, "set": case.get("set")}
            if skipping:
                record.update(verdict="SKIPPED", elapsed_ms=0.0, attempts=0, detail="after a time limit exceeded")
            else:
                stdin_path = cache / (name + ".in")
                stdin_path.write_text(case["input"], encoding="utf-8")
                ran = run_case(command, cache, timeout, retries, env, name, stdin_path)
                verdict, detail = judge({**ran, "expected": case["expected"]}, problem["checker"], cache, name)
                skipping = verdict == "TLE"
                record.update(
                    verdict=verdict,
                    elapsed_ms=ran["elapsed_ms"],
                    attempts=len(ran["attempts"]),
                    detail=detail[:DETAIL_LIMIT],
                )
                if ran["recovered_after_timeout"]:
                    record["recovered_after_timeout"] = True
            records.append(record)
            counts[record["verdict"]] = counts.get(record["verdict"], 0) + 1
        if counts.get("WA") or counts.get("RE"):
            status = "FAIL"
        elif counts.get("TLE"):
            status = "TIMEOUT"
        else:
            status = "PASS"
        first = next((r for r in records if r["verdict"] not in ("AC", "SKIPPED")), None)
        result = {
            **base,
            "status": status,
            "cases_passed": counts.get("AC", 0),
            "verdict_counts": counts,
            "cases": records,
            "first_failure": first,
        }
        if status != "TIMEOUT":
            write_json(result_path, result)
        return result


if __name__ == "__main__":
    sys.exit("benchmarks.codenet is a library")
