#!/usr/bin/env python3
"""Prepare the JavaScript oracles pinned in benchmarks/javascript.lock.json.

* lodash (required by the MBJSP tests) in .benchmark-cache/node;
* each project checkout at its pinned commit in .benchmark-cache/js-projects, with only the
  packages its test suite needs (installed with --ignore-scripts);
* the project library sources copied to dataset/JS_projects/<name> (the watermarked corpus).

Network access: npm registry and GitHub. Existing checkouts are verified, not re-downloaded.
"""

import json
from pathlib import Path
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[1]
NPM = ['npm', 'install', '--no-save', '--no-package-lock', '--ignore-scripts', '--no-audit', '--no-fund']


def main():
    lock = json.loads((ROOT / 'benchmarks' / 'javascript.lock.json').read_text())
    node = ROOT / '.benchmark-cache' / 'node'
    node.mkdir(parents=True, exist_ok=True)
    subprocess.run(NPM + ['--prefix', str(node), 'lodash@' + lock['lodash']], check=True)
    projects = ROOT / '.benchmark-cache' / 'js-projects'
    projects.mkdir(parents=True, exist_ok=True)
    for name, spec in lock['projects'].items():
        checkout = projects / name
        if not checkout.exists():
            subprocess.run(['git', 'clone', '--depth', '1', '--branch', spec['tag'], spec['repository'], str(checkout)], check=True)
        commit = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=checkout, text=True).strip()
        if commit != spec['commit']:
            raise SystemExit(f'{name}: checkout is at {commit}, expected {spec["commit"]}')
        if not (checkout / 'node_modules').exists():
            subprocess.run(NPM + spec['test_dependencies'], cwd=checkout, check=True)
        target = ROOT / 'dataset' / 'JS_projects' / name
        for source in spec['sources']:
            origin = checkout / source
            files = sorted(origin.rglob('*.js')) if origin.is_dir() else [origin]
            for path in files:
                destination = target / path.relative_to(checkout)
                destination.parent.mkdir(parents=True, exist_ok=True)
                shutil.copyfile(path, destination)
        print(f'{name}: {commit}', flush=True)


if __name__ == '__main__':
    main()
