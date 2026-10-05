#!/usr/bin/env python3
"""Build a deterministic source index without importing research scripts."""

import argparse
import ast
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
DESTINATION = ROOT / "docs" / "code-index.json"
SOURCE_DIRECTORIES = ("c", "cpp", "python", "tools", "benchmarks", "tests")


def source_paths():
    paths = list(ROOT.glob("*.py"))
    for directory in SOURCE_DIRECTORIES:
        paths.extend(p for p in (ROOT / directory).rglob("*.py") if "__pycache__" not in p.parts)
    return sorted(paths, key=lambda path: path.relative_to(ROOT).as_posix())


def module_name(path):
    return ".".join(path.relative_to(ROOT).with_suffix("").parts)


def symbols(nodes, prefix=""):
    result = []
    for node in nodes:
        if isinstance(node, (ast.ClassDef, ast.FunctionDef, ast.AsyncFunctionDef)):
            name = prefix + node.name
            result.append({
                "name": name,
                "kind": "class" if isinstance(node, ast.ClassDef) else "function",
                "line": node.lineno,
                "end_line": node.end_lineno,
            })
            result.extend(symbols(node.body, name + "."))
    return result


def imports(tree, module):
    result = []
    package = module.split(".")[:-1]
    for node in ast.walk(tree):
        if isinstance(node, ast.Import):
            for alias in node.names:
                result.append({"module": alias.name, "names": [], "line": node.lineno})
        elif isinstance(node, ast.ImportFrom):
            if node.level:
                base = package[:len(package) - node.level + 1]
                if node.module:
                    base.extend(node.module.split("."))
                imported_module = ".".join(base)
            else:
                imported_module = node.module or ""
            result.append({
                "module": imported_module,
                "names": [alias.name for alias in node.names],
                "line": node.lineno,
            })
    return sorted(result, key=lambda item: (item["line"], item["module"]))


def build_index():
    paths = source_paths()
    modules = {module_name(path): path.relative_to(ROOT).as_posix() for path in paths}
    files = []
    for path in paths:
        blob = path.read_bytes()
        tree = ast.parse(blob, filename=path.relative_to(ROOT).as_posix())
        module = module_name(path)
        imported = imports(tree, module)
        dependencies = set()
        for entry in imported:
            candidates = [entry["module"]]
            candidates.extend(entry["module"] + "." + name for name in entry["names"])
            dependencies.update(modules[name] for name in candidates if name in modules)
        files.append({
            "path": path.relative_to(ROOT).as_posix(),
            "module": module,
            "sha256": hashlib.sha256(blob).hexdigest(),
            "line_count": len(blob.splitlines()),
            "symbols": symbols(tree.body),
            "imports": imported,
            "local_dependencies": sorted(dependencies),
            "has_main_guard": any(
                isinstance(node, ast.If)
                and isinstance(node.test, ast.Compare)
                and isinstance(node.test.left, ast.Name)
                and node.test.left.id == "__name__"
                and len(node.test.ops) == 1
                and isinstance(node.test.ops[0], ast.Eq)
                and len(node.test.comparators) == 1
                and isinstance(node.test.comparators[0], ast.Constant)
                and node.test.comparators[0].value == "__main__"
                for node in tree.body
            ),
        })
    return {
        "schema_version": 1,
        "implementation_version": "legacy",
        "source_scope": ["root Python scripts", *SOURCE_DIRECTORIES],
        "excluded_scope": ["data snapshot", "corpora", "environments", "build products"],
        "generation_command": "python3 tools/build_code_index.py",
        "file_count": len(files),
        "symbol_count": sum(len(item["symbols"]) for item in files),
        "files": files,
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true", help="Fail if the saved index is stale.")
    args = parser.parse_args()
    index = build_index()
    content = json.dumps(index, ensure_ascii=False, indent=2) + "\n"
    if args.check:
        if not DESTINATION.is_file() or DESTINATION.read_text(encoding="utf-8") != content:
            parser.exit(1, "Code index is stale; run python3 tools/build_code_index.py\n")
        print("Code index is current.")
    else:
        DESTINATION.parent.mkdir(parents=True, exist_ok=True)
        DESTINATION.write_text(content, encoding="utf-8")
        print(f"Indexed {index['file_count']} files and {index['symbol_count']} symbols.")


if __name__ == "__main__":
    main()
