"""Shared provenance, configuration and atomic-output helpers."""

from contextlib import contextmanager
from datetime import datetime, timezone
import fcntl
import hashlib
import importlib.metadata
import json
import os
from pathlib import Path
import platform
import shutil
import subprocess
import sys
import tempfile


EXTENSIONS = {"python": ".py", "c": ".c", "cpp": ".cpp"}


def digest(value):
    if not isinstance(value, bytes):
        value = json.dumps(value, sort_keys=True, separators=(",", ":")).encode()
    return hashlib.sha256(value).hexdigest()


def utc_now():
    return datetime.now(timezone.utc).isoformat()


def write_json(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(path.name + ".tmp")
    with temporary.open("w", encoding="utf-8") as output:
        json.dump(value, output, ensure_ascii=False, indent=2)
        output.write("\n")
        output.flush()
        os.fsync(output.fileno())
    temporary.replace(path)


@contextmanager
def lock_file(path):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a+") as handle:
        try:
            fcntl.flock(handle, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except BlockingIOError:
            raise RuntimeError("Another benchmark process holds " + str(path)) from None
        handle.seek(0)
        handle.truncate()
        handle.write(str(os.getpid()) + "\n")
        handle.flush()
        try:
            yield
        finally:
            fcntl.flock(handle, fcntl.LOCK_UN)


def validate_config(config):
    if not isinstance(config.get("seed"), int) or not 0 <= config["seed"] <= 4294967295:
        raise ValueError("Seed must be a 32-bit nonnegative integer")
    if len(config.get("watermark", [])) != 4 or any(bit not in [0, 1] for bit in config["watermark"]):
        raise ValueError("Legacy BCH requires exactly four binary watermark bits")
    for field in ["jobs", "unit_timeout_seconds", "compile_timeout_seconds", "test_timeout_seconds"]:
        if not isinstance(config.get(field), (float, int)) or config[field] <= 0:
            raise ValueError(field + " must be positive")
    if not isinstance(config["jobs"], int):
        raise ValueError("jobs must be an integer")
    if any(not isinstance(n, int) or n <= 0 for n in config.get("attacks", [])):
        raise ValueError("Attack counts must be positive integers")
    seen = set()
    for cohort in config["cohorts"]:
        if cohort["name"] in seen or "/" in cohort["name"] or cohort["name"] in ["", ".", ".."]:
            raise ValueError("Cohort names must be unique safe names")
        seen.add(cohort["name"])
        if cohort["language"] not in EXTENSIONS or cohort["level"] not in ["function", "project"]:
            raise ValueError("Invalid cohort language or level")
        if cohort["role"] not in ["generated", "human", "historical", "unknown"]:
            raise ValueError("Invalid cohort ground-truth role")
    return config


def source_paths(root):
    root = Path(root)
    paths = list(root.glob("*.py"))
    for folder in ["c", "cpp", "python", "tools", "benchmarks", "tests"]:
        paths.extend((root / folder).rglob("*.py"))
    paths += list((root / "benchmarks" / "include").rglob("*.h"))
    paths += [root / "styleList.json", root / "Makefile", root / "AGENTS.md", root / "benchmarks" / "config.json",
              root / "benchmarks" / "requirements.lock", root / "benchmarks" / "toolchain.lock.json"]
    return sorted({p for p in paths if p.is_file() and "__pycache__" not in p.parts}, key=lambda p: p.relative_to(root).as_posix())


def source_fingerprint(root):
    files = {p.relative_to(root).as_posix(): digest(p.read_bytes()) for p in source_paths(root)}
    return digest(files), files


def protocol_fingerprint(config, root=None):
    evaluation = {key: value for key, value in config.items() if key not in ["gates", "jobs"]}
    measurement = {}
    if root is not None:
        for name in ["common.py", "engine.py", "utility.py", "metrics.py", "include/bits/stdc++.h"]:
            measurement[name] = digest((Path(root) / "benchmarks" / name).read_bytes())
    return digest({"evaluation": evaluation, "measurement": measurement})


def toolchain_environment(root):
    root = Path(root)
    stamp_path = root / ".benchmark-cache" / "toolchain" / "stamp.json"
    if not stamp_path.exists():
        raise RuntimeError("Missing pinned parser libraries; run python3 tools/setup_benchmark.py")
    stamp = json.loads(stamp_path.read_text())
    pinned = json.loads((root / "benchmarks" / "toolchain.lock.json").read_text())
    if stamp["tree_sitter"] != pinned["tree_sitter"] or set(stamp["grammars"]) != set(pinned["grammars"]):
        raise RuntimeError("Parser stamp differs from toolchain lock; rerun setup")
    for language, spec in stamp["grammars"].items():
        if spec["commit"] != pinned["grammars"][language]["commit"]:
            raise RuntimeError("Parser commit differs from toolchain lock; rerun setup")
        path = stamp_path.parent / f"{language}-languages.so"
        if not path.is_file() or digest(path.read_bytes()) != spec["library_sha256"]:
            raise RuntimeError("Parser library changed; rerun setup: " + language)
    packages = {}
    for line in (root / "benchmarks" / "requirements.lock").read_text().splitlines():
        name, expected = line.split("==")
        actual = importlib.metadata.version(name)
        if actual != expected:
            raise RuntimeError(f"Expected {name}=={expected}; found {actual}")
        packages[name] = actual
    compiler = shutil.which("c++")
    if not compiler:
        raise RuntimeError("C++ compiler is required for MBXP utility evaluation")
    compiler_version = subprocess.check_output([compiler, "--version"], text=True).splitlines()[0]
    return {
        "python": sys.version,
        "python_executable": sys.executable,
        "platform": platform.platform(),
        "machine": platform.machine(),
        "cpu_count": os.cpu_count(),
        "compiler": compiler,
        "compiler_version": compiler_version,
        "dependencies": packages,
        "parser_toolchain": stamp,
    }


def git_version(root):
    revision = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=root, text=True).strip()
    status = subprocess.check_output(["git", "status", "--porcelain=v1", "--untracked-files=normal"], cwd=root, text=True)
    return {"commit": revision, "dirty": bool(status), "status": status.splitlines()}


def parser_smoke(root):
    """Load actual language registries using pinned libraries, without rebuilding."""
    from change_program_style import SCTS
    root = Path(root).resolve()
    previous = Path.cwd()
    loaded = []
    with tempfile.TemporaryDirectory(prefix="cllmark-parser-") as temporary:
        directory = Path(temporary)
        (directory / "build").mkdir()
        shutil.copyfile(root / "styleList.json", directory / "styleList.json")
        for language in EXTENSIONS:
            shutil.copyfile(root / ".benchmark-cache" / "toolchain" / f"{language}-languages.so",
                            directory / "build" / f"{language}-languages.so")
        try:
            os.chdir(directory)
            for language in EXTENSIONS:
                parser = SCTS(language)
                source = "def f(x):\n    return x + 1\n" if language == "python" else "int main(){return 0;}"
                if not parser.check_syntax(source):
                    raise RuntimeError("Parser smoke failed: " + language)
                loaded.append(language)
        finally:
            os.chdir(previous)
    return loaded


def discover_units(root, config, limit=0, cohorts=None):
    root = Path(root).resolve()
    selected = set(cohorts) if cohorts else None
    if selected and not selected.issubset({c["name"] for c in config["cohorts"]}):
        raise ValueError("Unknown selected cohort")
    units, inventory = [], []
    for cohort in config["cohorts"]:
        directory = (root / cohort["path"]).resolve()
        if not directory.is_relative_to(root) or not directory.is_dir():
            raise ValueError("Missing or unsafe dataset path: " + cohort["path"])
        extension = EXTENSIONS[cohort["language"]]
        if cohort["level"] == "function":
            groups = [(p.stem, [p]) for p in sorted(directory.glob("*" + extension))]
        else:
            groups = [(p.name, sorted(p.rglob("*" + extension))) for p in sorted(directory.iterdir()) if p.is_dir()]
            groups = [(name, files) for name, files in groups if files]
        if not groups:
            raise ValueError("Dataset is empty: " + cohort["path"])
        chosen = groups[:limit] if limit else groups
        if selected and cohort["name"] not in selected:
            chosen = []
        inventory.append({**cohort, "available_units": len(groups), "selected_units": len(chosen)})
        for name, files in chosen:
            if any(p.is_symlink() or not p.resolve().is_relative_to(root) for p in files):
                raise ValueError("Dataset source symlinks are not supported")
            units.append({**cohort, "id": cohort["name"] + "/" + name, "name": name,
                          "source_files": [p.relative_to(root).as_posix() for p in files]})
    return units, inventory
