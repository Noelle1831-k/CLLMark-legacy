#!/usr/bin/env python3
"""Install an isolated benchmark environment and compile pinned grammars."""

import argparse
import hashlib
import json
import os
import shutil
import subprocess
import sys
import tarfile
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--python", default="python3.11")
    parser.add_argument("--build-only", action="store_true")
    args = parser.parse_args()
    environment = ROOT / ".venv-benchmark"
    python = environment / "bin" / "python"
    if not args.build_only:
        uv = shutil.which("uv")
        if not python.exists():
            command = (
                [uv, "venv", str(environment), "--python", args.python]
                if uv
                else [args.python, "-m", "venv", str(environment)]
            )
            subprocess.run(command, check=True)
        command = [uv, "pip", "install", "--python", str(python)] if uv else [str(python), "-m", "pip", "install"]
        subprocess.run([*command, "-r", str(ROOT / "benchmarks" / "requirements.lock")], check=True)
        subprocess.run([str(python), str(Path(__file__).resolve()), "--build-only"], check=True)
        return
    from importlib.metadata import version

    from tree_sitter import Language

    lock = json.loads((ROOT / "benchmarks" / "toolchain.lock.json").read_text())
    if version("tree-sitter") != lock["tree_sitter"]:
        parser.error("Run this command using .venv-benchmark/bin/python.")
    cache = ROOT / ".benchmark-cache" / "toolchain"
    cache.mkdir(parents=True, exist_ok=True)
    stamp = {
        "platform": sys.platform,
        "architecture": os.uname().machine,
        "tree_sitter": version("tree-sitter"),
        "grammars": {},
    }
    for language, reference in lock["grammars"].items():
        commit = reference["commit"]
        archive = cache / (language + "-" + commit + ".tar.gz")
        url = f"https://codeload.github.com/tree-sitter/tree-sitter-{language}/tar.gz/{commit}"
        if not archive.exists():
            request = urllib.request.Request(url, headers={"User-Agent": "CLLMark-local-benchmark"})
            with urllib.request.urlopen(request, timeout=60) as response:
                temporary = archive.with_suffix(".download")
                temporary.write_bytes(response.read())
                temporary.replace(archive)
        source = cache / f"tree-sitter-{language}-{commit}"
        if not source.exists():
            with tarfile.open(archive) as bundle:
                for member in bundle.getmembers():
                    target = (cache / member.name).resolve()
                    if not target.is_relative_to(cache.resolve()) or member.issym() or member.islnk():
                        raise ValueError("Unsafe grammar archive member")
                bundle.extractall(cache)
        library = cache / f"{language}-languages.so"
        Language.build_library(str(library), [str(source)])
        Language(str(library), language)
        stamp["grammars"][language] = {
            **reference,
            "archive_sha256": hashlib.sha256(archive.read_bytes()).hexdigest(),
            "library_sha256": hashlib.sha256(library.read_bytes()).hexdigest(),
        }
        print(f"Compiled and loaded pinned {language} grammar.", flush=True)
    (cache / "stamp.json").write_text(json.dumps(stamp, indent=2) + "\n")
    print("Ready: .venv-benchmark/bin/python tools/research_loop.py doctor")


if __name__ == "__main__":
    main()
