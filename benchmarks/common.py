"""Shared provenance, configuration and atomic-output helpers."""

import fcntl
import hashlib
import importlib.metadata
import json
import os
import platform
import shutil
import subprocess
import sys
import tempfile
from contextlib import contextmanager
from datetime import UTC, datetime
from pathlib import Path

EXTENSIONS = {"python": ".py", "c": ".c", "cpp": ".cpp", "javascript": ".js"}
SMOKE_SOURCES = {
    "python": "def f(x):\n    return x + 1\n",
    "c": "int main(){return 0;}",
    "cpp": "int main(){return 0;}",
    "javascript": "function f(x) { return x + 1; }",
}


def digest(value):
    if not isinstance(value, bytes):
        value = json.dumps(value, sort_keys=True, separators=(",", ":")).encode()
    return hashlib.sha256(value).hexdigest()


def utc_now():
    return datetime.now(UTC).isoformat()


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
    retries = config.get("test_timeout_retries", 0)
    if not isinstance(retries, int) or not 0 <= retries <= 3:
        raise ValueError("test_timeout_retries must be an integer between zero and three")
    if any(not isinstance(n, int) or n <= 0 for n in config.get("attacks", [])):
        raise ValueError("Attack counts must be positive integers")
    seen = set()
    for cohort in config["cohorts"]:
        if cohort["name"] in seen or "/" in cohort["name"] or cohort["name"] in ["", ".", ".."]:
            raise ValueError("Cohort names must be unique safe names")
        seen.add(cohort["name"])
        if cohort["language"] not in EXTENSIONS or cohort["level"] not in ["function", "project", "project_file"]:
            raise ValueError("Invalid cohort language or level")
        extensions = cohort.get("extensions", [])
        if not isinstance(extensions, list) or any(not isinstance(e, str) or not e.startswith(".") for e in extensions):
            raise ValueError("Cohort extensions must be a list of dotted suffixes")
        if cohort.get("layout", "flat") not in ["flat", "tree"] or (
            cohort.get("layout") == "tree" and cohort["level"] != "project"
        ):
            raise ValueError("Only project-level cohorts may use the tree layout")
        if "min_lines" in cohort and (
            cohort["level"] != "project_file" or not isinstance(cohort["min_lines"], int) or cohort["min_lines"] < 1
        ):
            raise ValueError("min_lines is a positive integer for project_file cohorts")
        if cohort["role"] not in ["generated", "human", "historical", "unknown"]:
            raise ValueError("Invalid cohort ground-truth role")
        if cohort["oracle"] not in ["mbxp", "none", "unmapped_codenet", "project_tests", "exercism"]:
            raise ValueError("Invalid cohort oracle")
        if cohort["oracle"] == "project_tests" and (
            cohort["level"] not in ["project", "project_file"] or config.get("project_test_timeout_seconds", 0) <= 0
        ):
            raise ValueError(
                "Project test oracles need project-level cohorts and a positive project_test_timeout_seconds"
            )
        if cohort["level"] == "project_file" and cohort["oracle"] not in ["project_tests", "none"]:
            raise ValueError("project_file cohorts use the project test oracle")
        if cohort["oracle"] == "exercism" and (
            cohort["level"] != "function"
            or cohort["language"] != "javascript"
            or "exercism" not in config.get("problem_files", {})
            or not config.get("exercism", {}).get("test")
            or config.get("project_test_timeout_seconds", 0) <= 0
        ):
            raise ValueError(
                "The exercism oracle needs function-level JavaScript cohorts, problem_files.exercism, an exercism test command and project_test_timeout_seconds"
            )
    return config


def source_paths(root):
    root = Path(root)
    paths = []
    for folder in ["cllmark", "tools", "benchmarks", "tests"]:
        paths.extend((root / folder).rglob("*.py"))
    paths += list((root / "benchmarks" / "include").rglob("*.h"))
    paths += [
        root / "cllmark" / "rules" / "styles.json",
        root / "pyproject.toml",
        root / "Makefile",
        root / "AGENTS.md",
        root / "benchmarks" / "config.json",
        root / "benchmarks" / "requirements.lock",
        root / "benchmarks" / "toolchain.lock.json",
    ]
    return sorted(
        {p for p in paths if p.is_file() and "__pycache__" not in p.parts}, key=lambda p: p.relative_to(root).as_posix()
    )


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
        "javascript": javascript_environment(root),
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


INSTALLED_LOCKFILES = {"npm-ci": "node_modules/.package-lock.json", "pnpm-frozen": "node_modules/.pnpm/lock.yaml"}


def install_digest(checkout, mode):
    """Digest of what the package manager recorded as installed (the effective, fully resolved dependency tree)."""
    if mode == "none":
        return digest(b"none")
    recorded = Path(checkout) / INSTALLED_LOCKFILES[mode]
    if not recorded.is_file():
        raise RuntimeError(f"Dependencies of {Path(checkout).name} are not installed; rerun tools/setup_javascript.py")
    return digest(recorded.read_bytes())


def javascript_environment(root):
    """Node runtime, the lodash used by MBJSP tests, each pinned project/repository checkout with its test dependencies,
    and the pinned Exercism checkout."""
    node = shutil.which("node")
    if node is None:
        raise RuntimeError("Node.js is required for the JavaScript cohorts")
    modules = Path(root) / ".benchmark-cache" / "node" / "node_modules"
    lodash = json.loads((modules / "lodash" / "package.json").read_text())["version"]
    projects = {}
    base = Path(root) / ".benchmark-cache" / "js-projects"
    lock = json.loads((Path(root) / "benchmarks" / "javascript.lock.json").read_text())
    for name, spec in lock["projects"].items():
        checkout = base / name
        commit = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=checkout, text=True).strip()
        if commit != spec["commit"]:
            raise RuntimeError(
                f"JavaScript project {name} is not at its pinned commit; rerun tools/setup_javascript.py"
            )
        installed = checkout / "node_modules" / ".package-lock.json"
        projects[name] = {
            "checkout": str(checkout),
            "commit": commit,
            "node_modules_sha256": digest(installed.read_bytes()),
        }
    downloads = {
        **dict(lock.get("repositories", {}).items()),
        **({"exercism": lock["exercism"]} if "exercism" in lock else {}),
    }
    pinned = {}
    for name, spec in downloads.items():
        checkout = base / name
        pin_path = base / (name + ".pin.json")
        pin = json.loads(pin_path.read_text()) if pin_path.is_file() else {}
        if (
            pin.get("commit") != spec["commit"]
            or pin.get("tarball_sha256") != spec["tarball_sha256"]
            or not checkout.is_dir()
        ):
            raise RuntimeError(
                f"JavaScript repository {name} is not at its pinned commit/tarball; rerun tools/setup_javascript.py"
            )
        if pin.get("install", {}).get("lockfile_sha256") != spec["install"].get("lockfile_sha256"):
            raise RuntimeError(
                f"JavaScript repository {name} was installed from a different lockfile; rerun tools/setup_javascript.py"
            )
        pinned[name] = {
            "checkout": str(checkout),
            "commit": spec["commit"],
            "tarball_sha256": spec["tarball_sha256"],
            "node_modules_sha256": install_digest(checkout, spec["install"]["mode"]),
        }
    exercism = pinned.pop("exercism", None)
    return {
        "node": node,
        "node_version": subprocess.check_output([node, "--version"], text=True).strip(),
        "node_path": str(modules),
        "lodash": lodash,
        "projects": {**projects, **pinned},
        "exercism": exercism,
    }


def git_version(root):
    revision = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=root, text=True).strip()
    status = subprocess.check_output(
        ["git", "status", "--porcelain=v1", "--untracked-files=normal"], cwd=root, text=True
    )
    return {"commit": revision, "dirty": bool(status), "status": status.splitlines()}


def parser_smoke(root):
    """Load actual language registries using pinned libraries, without rebuilding."""
    from cllmark.transform import StyleTransformer

    root = Path(root).resolve()
    previous = Path.cwd()
    loaded = []
    with tempfile.TemporaryDirectory(prefix="cllmark-parser-") as temporary:
        directory = Path(temporary)
        (directory / "build").mkdir()
        for language in EXTENSIONS:
            shutil.copyfile(
                root / ".benchmark-cache" / "toolchain" / f"{language}-languages.so",
                directory / "build" / f"{language}-languages.so",
            )
        try:
            os.chdir(directory)
            for language in EXTENSIONS:
                parser = StyleTransformer(language)
                if not parser.check_syntax(SMOKE_SOURCES[language]):
                    raise RuntimeError("Parser smoke failed: " + language)
                loaded.append(language)
        finally:
            os.chdir(previous)
    return loaded


def line_count(path):
    return len(Path(path).read_bytes().splitlines())


def unit_file_names(unit):
    """Name of each unit input in the flat directory the legacy pipeline works on.

    Legacy cohorts keep basenames. Project cohorts with `layout: tree` keep their directory structure
    (`lib/a.js` becomes `lib__a.js`) so that repositories with repeated basenames such as index.js can be processed."""
    if unit.get("layout") == "tree" and unit["level"] == "project":
        prefix = unit["path"].rstrip("/") + "/" + unit["name"] + "/"
        names = {p: p[len(prefix) :].replace("/", "__") for p in unit["source_files"]}
    else:
        names = {p: Path(p).name for p in unit["source_files"]}
    if len(set(names.values())) != len(names):
        raise ValueError("Legacy flat-directory adapter cannot handle duplicate file names")
    return names


def project_paths(unit):
    """Path of each unit input inside the pinned project checkout: the corpus path below <cohort path>/<project>/."""
    prefix = unit["path"].rstrip("/") + "/" + unit.get("project", unit["name"]) + "/"
    return {p: p[len(prefix) :] for p in unit["source_files"]}


def cohort_files(directory, cohort):
    suffixes = cohort.get("extensions") or [EXTENSIONS[cohort["language"]]]
    return sorted({p for suffix in suffixes for p in directory.rglob("*" + suffix) if p.is_file()})


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
        extra = {}
        if cohort["level"] == "function":
            groups = [(p.stem, [p]) for p in sorted(directory.glob("*" + extension))]
        elif cohort["level"] == "project":
            groups = [(p.name, cohort_files(p, cohort)) for p in sorted(directory.iterdir()) if p.is_dir()]
            groups = [(name, files) for name, files in groups if files]
        else:
            # One unit per sufficiently long source file; the project (checkout) is the first directory.
            groups = []
            for project in sorted(p for p in directory.iterdir() if p.is_dir()):
                for path in cohort_files(project, cohort):
                    if line_count(path) >= cohort.get("min_lines", 1):
                        groups.append((project.name + "/" + path.relative_to(project).as_posix(), [path]))
                        extra[project.name + "/" + path.relative_to(project).as_posix()] = {"project": project.name}
        if not groups:
            raise ValueError("Dataset is empty: " + cohort["path"])
        chosen = groups[:limit] if limit else groups
        if selected and cohort["name"] not in selected:
            chosen = []
        inventory.append({**cohort, "available_units": len(groups), "selected_units": len(chosen)})
        for name, files in chosen:
            if any(p.is_symlink() or not p.resolve().is_relative_to(root) for p in files):
                raise ValueError("Dataset source symlinks are not supported")
            units.append(
                {
                    **cohort,
                    **extra.get(name, {}),
                    "id": cohort["name"] + "/" + name,
                    "name": name,
                    "source_files": [p.relative_to(root).as_posix() for p in files],
                }
            )
    return units, inventory
