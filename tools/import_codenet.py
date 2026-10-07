#!/usr/bin/env python3
"""Import the CodeNet generated/hand-written solutions of the pinned dataset repository into `external/codenet/`.

Usage: python tools/import_codenet.py [--source PATH]

Without --source the repository is cloned into `.benchmark-cache/codenet-src` and checked out at the locked commit
(`benchmarks/codenet.lock.json`); with --source the given checkout must already be at that commit. The output
(ignored by git, never `corpus/`) holds
  dataset/{Python,C,CPP,JS}_{G,H}/<pid>.<ext>   byte-exact copies of generated/<pid>/sol.<ext> and solutions/<pid>/ref.<ext>,
                                                 except Python_H adapters (see `unwrap_adapter`)
  problems.jsonl                                 one row per problem of hf/python.jsonl with its test cases
  import-report.json                             commit, group counts, exclusions and a digest of all output files
Running it again with unchanged input leaves the output untouched. See docs/CODENET.md.
"""

import argparse
import base64
import hashlib
import json
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GROUPS = [("Python", "py", "python"), ("C", "c", "c"), ("CPP", "cpp", "cpp"), ("JS", "js", "js")]
HF_FILES = {"python": "py", "c": "c", "cpp": "cpp", "js": "js"}


def sha256(blob):
    return hashlib.sha256(blob).hexdigest()


def git(directory, *arguments):
    return subprocess.check_output(["git", "-C", str(directory), *arguments], text=True).strip()


def prepare_source(source, lock, commit, root):
    """The dataset checkout at `commit`: the given one (verified) or a cache clone (created or verified)."""
    if source is None:
        source = root / ".benchmark-cache" / "codenet-src"
        if not source.exists():
            source.parent.mkdir(parents=True, exist_ok=True)
            subprocess.check_call(
                ["git", "clone", "--filter=blob:none", "--no-checkout", lock["repository"], str(source)]
            )
        if git(source, "rev-parse", "HEAD") != commit:
            subprocess.check_call(["git", "-C", str(source), "checkout", "--quiet", commit])
    source = Path(source).resolve()
    if not source.is_dir():
        raise SystemExit(f"Source is not a directory: {source}")
    try:
        head = git(source, "rev-parse", "HEAD")
    except (subprocess.CalledProcessError, OSError) as error:
        raise SystemExit(f"Source is not a git checkout: {source} ({error})") from error
    if head != commit:
        raise SystemExit(f"Source is at {head}, expected the locked commit {commit}")
    return source


def read_jsonl(path):
    rows = []
    for line in path.read_text(encoding="utf-8").splitlines():
        if line.strip():
            rows.append(json.loads(line))
    return rows


def load_problems(source):
    """pid -> hf/python.jsonl row; the test cases of the other three hf files must be identical."""
    rows = {row["problem_id"]: row for row in read_jsonl(source / "hf" / "python.jsonl")}
    languages = {}
    for language in ["c", "cpp", "js"]:
        other = {row["problem_id"]: row for row in read_jsonl(source / "hf" / f"{language}.jsonl")}
        for pid, row in other.items():
            if pid not in rows:
                raise SystemExit(f"hf/{language}.jsonl has {pid}, which is not in hf/python.jsonl")
            if row["test_cases"] != rows[pid]["test_cases"]:
                raise SystemExit(f"Test cases of {pid} differ between hf/python.jsonl and hf/{language}.jsonl")
        languages[language] = set(other)
    return rows, languages


ADAPTER = re.compile(
    rb'"""Run the reference submission for this task on one complete stdin\."""\n'
    rb"\s+import base64, os, subprocess, sys, tempfile\n"
    rb"\s+src = base64\.b64decode\('([A-Za-z0-9+/=]+)'\)\n"
)


def unwrap_adapter(blob):
    """The hand-written submission inside a Python reference adapter, or None for a plain program.

    Most Python references of the dataset are one fixed adapter that writes the base64-encoded CodeNet submission to
    a temporary file and runs it with stdin. Watermarking the adapter would measure the shared template, not
    hand-written code, so the submission itself (a standalone stdin/stdout program) is the unit."""
    match = ADAPTER.search(blob)
    return base64.b64decode(match.group(1)) if match else None


def checker_of(source, pid):
    meta = json.loads((source / "testdata" / pid / "meta.json").read_text(encoding="utf-8"))
    return meta["checker"]["type"]


def build(source, destination):
    """Write the whole output into `destination`; returns the report (without its own digest line)."""
    problems, hf_languages = load_problems(source)
    pids = sorted(problems)
    generated = sorted(p.name for p in (source / "generated").iterdir() if p.is_dir() and re.fullmatch(r"p\d+", p.name))
    report = {"groups": {}, "excluded": [], "unwrapped": {"group": "Python_H", "count": 0, "problems": []}}
    files = {}

    def copy(group, extension, pid, origin):
        target = destination / "dataset" / group / f"{pid}.{extension}"
        target.parent.mkdir(parents=True, exist_ok=True)
        blob = origin.read_bytes()
        if group == "Python_H":
            inner = unwrap_adapter(blob)
            if inner is not None:
                blob = inner
                report["unwrapped"]["count"] += 1
                report["unwrapped"]["problems"].append(pid)
        target.write_bytes(blob)
        files[target.relative_to(destination).as_posix()] = sha256(blob)

    for directory, extension, hf_name in GROUPS:
        for suffix, folder, name in [("G", "generated", "sol"), ("H", "solutions", "ref")]:
            group = f"{directory}_{suffix}"
            count, missing = 0, []
            for pid in pids:
                origin = source / folder / pid / f"{name}.{extension}"
                if origin.is_file():
                    copy(group, extension, pid, origin)
                    count += 1
                else:
                    missing.append(pid)
            report["groups"][group] = count
            if missing:
                reason = (
                    "problem has no code file in this group"
                    if suffix == "G" or hf_name != "js"
                    else "no hand-written JavaScript solution; the problem is not in hf/js.jsonl"
                )
                if suffix == "H" and hf_name == "js" and set(pids) - set(missing) != hf_languages["js"]:
                    raise SystemExit("JS_H does not match hf/js.jsonl")
                report["excluded"].append(
                    {"group": group, "count": len(missing), "problems": missing, "reason": reason}
                )
    for pid in generated:
        if pid not in problems:
            report["excluded"].append(
                {
                    "group": "generated",
                    "count": 1,
                    "problems": [pid],
                    "reason": "generated code exists but hf has no tests",
                }
            )
    rows = []
    for pid in pids:
        row = problems[pid]
        rows.append(
            {
                "task_id": pid,
                "title": row["title"],
                "source": row["source"],
                "time_limit_ms": row["time_limit_ms"],
                "memory_limit_mb": row["memory_limit_mb"],
                "checker": checker_of(source, pid),
                "test_cases": row["test_cases"],
            }
        )
    blob = "".join(json.dumps(row, ensure_ascii=False) + "\n" for row in rows).encode("utf-8")
    (destination / "problems.jsonl").write_bytes(blob)
    files["problems.jsonl"] = sha256(blob)
    report["problems"] = len(rows)
    report["output_sha256"] = sha256(json.dumps(sorted(files.items())).encode())
    return report


def output_digest(directory):
    files = {
        p.relative_to(directory).as_posix(): sha256(p.read_bytes())
        for p in directory.rglob("*")
        if p.is_file() and p.name != "import-report.json"
    }
    return sha256(json.dumps(sorted(files.items())).encode())


def main(argv=None, root=ROOT):
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--source", type=Path, help="existing checkout of the dataset repository at the locked commit")
    parser.add_argument("--commit", help=argparse.SUPPRESS)  # tests only: overrides the locked commit
    args = parser.parse_args(argv)
    root = Path(root)
    lock = json.loads((root / "benchmarks" / "codenet.lock.json").read_text())
    commit = args.commit or lock["commit"]
    source = prepare_source(args.source, lock, commit, root)
    output = root / lock["output"]
    temporary = output.with_name(output.name + ".tmp")
    if temporary.exists():
        shutil.rmtree(temporary)
    temporary.mkdir(parents=True)
    report = {"repository": lock["repository"], "commit": commit, **build(source, temporary)}
    (temporary / "import-report.json").write_text(
        json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
    )
    existing = output / "import-report.json"
    if existing.is_file() and output_digest(output) == report["output_sha256"] == output_digest(temporary):
        shutil.rmtree(temporary)
        print("Unchanged: " + str(output))
    else:
        if output.exists():
            shutil.rmtree(output)
        temporary.rename(output)
        print("Imported: " + str(output))
    print(json.dumps({"commit": commit, "groups": report["groups"], "problems": report["problems"]}, indent=2))
    return 0


if __name__ == "__main__":
    sys.exit(main())
