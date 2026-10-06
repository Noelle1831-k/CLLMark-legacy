#!/usr/bin/env python3
"""Run the research loop with the run directory and temporary files on a RAM disk, then copy the results back.

macOS: an `hdiutil` RAM volume. Linux: a directory under /dev/shm. The RAM copy is volatile, so the run directory is
copied to `benchmark-results/` before the volume is detached; `inputs/` and `work/` stay behind (the manifest keeps the
list of input files) unless --keep-inputs is given. If copying fails the volume is left mounted.
"""

import argparse
import json
import os
import platform
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
VOLUME = "CLLMarkRAM"
SKIPPED = ("inputs", "work")
POINTERS = ("latest.json", "latest-smoke.json", "preflight-failed.json")


def create_disk(size_gb):
    if platform.system() == "Darwin":
        mount = Path("/Volumes") / VOLUME
        if mount.exists():
            raise SystemExit(f"{mount} already exists; eject it first: hdiutil detach {mount}")
        sectors = int(size_gb * 1024**3 // 512)
        device = subprocess.check_output(["hdiutil", "attach", "-nomount", f"ram://{sectors}"], text=True).split()[0]
        try:
            subprocess.run(["diskutil", "erasevolume", "HFS+", VOLUME, device], check=True, stdout=subprocess.DEVNULL)
        except subprocess.CalledProcessError:
            subprocess.run(["hdiutil", "detach", device], check=False)
            raise
        return mount, device
    mount = Path("/dev/shm") / "cllmark-ram"
    mount.mkdir(parents=True, exist_ok=True)
    return mount, None


def copy_back(source_root, destination_root, keep_inputs):
    destination_root.mkdir(parents=True, exist_ok=True)
    ignore = None if keep_inputs else shutil.ignore_patterns(*SKIPPED)
    copied = []
    for run_dir in sorted(p for p in source_root.iterdir() if p.is_dir() and p.name[:1].isdigit()):
        target = destination_root / run_dir.name
        if target.exists():
            raise FileExistsError(f"{target} already exists; refusing to overwrite a saved run")
        shutil.copytree(run_dir, target, ignore=ignore)
        copied.append((run_dir, target))
    for name in POINTERS:
        pointer = source_root / name
        if pointer.exists():
            value = json.loads(pointer.read_text())
            if "directory" in value:
                value["directory"] = str(destination_root / Path(value["directory"]).name)
            (destination_root / name).write_text(json.dumps(value, indent=2, sort_keys=True))
    return copied


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--size-gb", type=float, default=3)
    parser.add_argument("--keep-inputs", action="store_true", help="Also copy the frozen inputs back (slow)")
    parser.add_argument("--output-root", type=Path, default=ROOT / "benchmark-results")
    parser.add_argument("loop_args", nargs="*", help="Arguments after -- go to `research_loop.py loop`")
    args = parser.parse_args()
    mount, device = create_disk(args.size_gb)
    ram_results = mount / "benchmark-results"
    ram_results.mkdir(exist_ok=True)
    (mount / "tmp").mkdir(exist_ok=True)
    print(f"RAM disk: {mount} ({args.size_gb} GB)", flush=True)
    command = [
        sys.executable,
        str(ROOT / "tools" / "research_loop.py"),
        "loop",
        "--output-root",
        str(ram_results),
        *args.loop_args,
    ]
    code = 1
    try:
        code = subprocess.run(
            command, cwd=ROOT, env={**os.environ, "TMPDIR": str(mount / "tmp")}, check=False
        ).returncode
    finally:
        try:
            copied = copy_back(ram_results, args.output_root, args.keep_inputs)
        except Exception as error:
            print(f"Copy-back failed ({error!r}); the RAM disk stays mounted at {mount}", file=sys.stderr)
            return code or 1
        for _, target in copied:
            print("Saved run: " + str(target), flush=True)
        if device:
            subprocess.run(["hdiutil", "detach", device], check=False, stdout=subprocess.DEVNULL)
            print("RAM disk detached", flush=True)
        else:
            shutil.rmtree(mount, ignore_errors=True)
    return code


if __name__ == "__main__":
    raise SystemExit(main())
