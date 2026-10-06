"""Run actual legacy entry points on copies, with deterministic instrumentation."""

import hashlib
import importlib
import io
import json
import os
import random
import shutil
import signal
import time
import traceback
from contextlib import redirect_stderr, redirect_stdout
from pathlib import Path

from .common import digest, unit_file_names, write_json
from .utility import evaluate_utility, load_problems


class UnitTimeout(BaseException):
    pass


class BoundedLog(io.TextIOBase):
    def __init__(self, limit=65536):
        self.limit, self.parts, self.used, self.discarded = limit, [], 0, 0

    def write(self, value):
        remaining = max(0, self.limit - self.used)
        self.parts.append(value[:remaining]) if remaining else None
        self.used += min(len(value), remaining)
        self.discarded += max(0, len(value) - remaining)
        return len(value)

    def getvalue(self):
        return "".join(self.parts) + (f"\n[truncated {self.discarded} characters]\n" if self.discarded else "")


class LegacyEngine:
    def __init__(self, run_dir, manifest):
        self.run_dir, self.manifest = Path(run_dir), manifest
        self.config = manifest["config"]
        self.parsers = {}
        os.chdir(self.run_dir / "source")
        self.transform = importlib.import_module("cllmark.transform")
        self.directories = importlib.import_module("cllmark.directories")
        self.bch = importlib.import_module("cllmark.bch")
        self.rules = importlib.import_module("cllmark.rules.pairs").WATERMARK_PAIRS
        self.read_source = importlib.import_module("cllmark.source_io").read_source
        self.real_decode = self.bch.decode
        self.problems = load_problems(self.run_dir / "inputs", self.config)

    def parser(self, language):
        if language not in self.parsers:
            self.parsers[language] = self.transform.StyleTransformer(language)
        return self.parsers[language]

    def extract(self, directory, language, unit_id, stage):
        captured = {}

        def decode(bits):
            captured["bits"] = list(bits)
            captured["decoded"] = self.real_decode(bits)
            return captured["decoded"]

        seed = int(hashlib.sha256(f"{self.config['seed']}:{unit_id}:{stage}".encode()).hexdigest()[:16], 16)
        random.seed(seed)
        self.bch.decode = decode
        try:
            started = time.perf_counter()
            result = self.directories.extract_directory(
                directory, language, self.config["watermark"], self.parser(language)
            )
            elapsed = (time.perf_counter() - started) * 1000
        finally:
            self.bch.decode = self.real_decode
        if not isinstance(result, tuple) or len(result) != 2 or "bits" not in captured:
            raise ValueError("Legacy extraction protocol changed; update the benchmark adapter explicitly")
        expected = self.bch.encode(self.config["watermark"])
        return {
            "matched": bool(result[0]),
            "raw_matched": bool(result[1]),
            "bits": captured["bits"],
            "decoded": captured["decoded"],
            "correct_bits": sum(a == b for a, b in zip(captured["bits"], expected, strict=False)),
            "expected_bit_count": len(expected),
            "elapsed_ms": elapsed,
            "random_seed": seed,
        }

    def change(self, language, style, code):
        if style in ["11", "12"]:
            raise NotImplementedError("Legacy special sub-rule has no transformation implementation: " + style)
        return self.parser(language).apply(style, code)[0]

    def properties(self, clean, language, support, slots):
        result = {
            "idempotence": {"passed": 0, "trials": 0},
            "reversibility": {"passed": 0, "trials": 0},
            "independence": {"passed": 0, "trials": 0},
            "unsupported_pairs": 0,
            "errors": 0,
            "examples": [],
        }

        def check(kind, condition, filename, rule):
            result[kind]["trials"] += 1
            result[kind]["passed"] += bool(condition)
            if not condition and len(result["examples"]) < 20:
                result["examples"].append({"property": kind, "file": filename, "rule": rule})

        for filename, names in support.items():
            code = self.read_source(clean / filename)
            for name in names:
                pair = self.rules[language][name]
                if any(style in ["11", "12"] for style in pair):
                    result["unsupported_pairs"] += 1
                    continue
                try:
                    a, b = (self.change(language, style, code) for style in pair)
                    check("idempotence", self.change(language, pair[0], a) == a, filename, name)
                    check("idempotence", self.change(language, pair[1], b) == b, filename, name)
                    check("reversibility", self.change(language, pair[0], b) == a, filename, name)
                    check("reversibility", self.change(language, pair[1], a) == b, filename, name)
                except Exception as error:
                    result["errors"] += 1
                    if len(result["examples"]) < 20:
                        result["examples"].append({"file": filename, "rule": name, "error": repr(error)})
        for index, left in enumerate(slots):
            for right in slots[index + 1 :]:
                if left["file"] != right["file"] or any(item["style"] in ["11", "12"] for item in [left, right]):
                    continue
                code = self.read_source(clean / left["file"])
                try:
                    ab = self.change(language, left["style"], self.change(language, right["style"], code))
                    ba = self.change(language, right["style"], self.change(language, left["style"], code))
                    check("independence", ab == ba, left["file"], [left["rule"], right["rule"]])
                except Exception as error:
                    result["errors"] += 1
                    if len(result["examples"]) < 20:
                        result["examples"].append({"property": "independence", "error": repr(error)})
        return result

    def flip(self, source, target, language, slots, count):
        shutil.copytree(source, target)
        applied, unavailable = [], []
        for slot in slots:
            inverse = self.rules[language][slot["rule"]][1 - slot["bit"]]
            path = target / slot["file"]
            code = self.read_source(path)
            try:
                changed = self.change(language, inverse, code)
            except NotImplementedError:
                unavailable.append(slot)
                continue
            if code != changed:
                path.write_text(changed, encoding="utf-8")
                applied.append({"file": slot["file"], "rule": slot["rule"], "style": inverse})
            if len(applied) == count:
                break
        return {
            "requested_flips": count,
            "applied_transformations": applied,
            "effective_transformations": len(applied),
            "fully_applied": len(applied) == count,
            "unsupported": unavailable,
        }

    def evaluate(self, unit):
        started = time.perf_counter()
        language = unit["language"]
        self.parser(language)  # Exclude one-time parser creation from phase timings.
        work = self.run_dir / "work" / digest(unit["id"].encode())[:20]
        if work.exists():
            shutil.rmtree(work)
        clean = work / "clean"
        clean.mkdir(parents=True)
        filenames = []
        for relative, name in unit_file_names(unit).items():
            source = self.run_dir / "inputs" / relative
            blob = source.read_bytes()
            if digest(blob) != self.manifest["input_files"][relative]["sha256"]:
                raise ValueError("Frozen input hash mismatch: " + relative)
            filenames.append(name)
            (clean / name).write_bytes(blob)
        log = BoundedLog()
        result = {
            "id": unit["id"],
            "cohort": unit["id"].split("/", 1)[0],
            "language": language,
            "role": unit["role"],
            "level": unit["level"],
            "source_files": unit["source_files"],
            "status": "ok",
            "file_count": len(filenames),
            "watermark": self.config["watermark"],
        }
        with redirect_stdout(log), redirect_stderr(log):
            phase = time.perf_counter()
            capacity = self.directories.analyze_directory(clean, language, self.parser(language))
            result["analysis_ms"] = (time.perf_counter() - phase) * 1000
            support = json.loads((clean / "support_transform.json").read_text())
            expected = self.bch.encode(self.config["watermark"])
            result.update(
                {"capacity": capacity, "required_capacity": len(expected), "eligible": capacity >= len(expected)}
            )
            slots = []
            for filename, rules in support.items():
                for rule in rules:
                    if len(slots) < len(expected):
                        bit = expected[len(slots)]
                        slots.append(
                            {"file": filename, "rule": rule, "bit": bit, "style": self.rules[language][rule][bit]}
                        )
            result["embedding_slots"] = slots
            result["properties"] = (
                self.properties(clean, language, support, slots) if self.config["rule_properties"] else None
            )
            before_valid = {
                name: self.parser(language).check_syntax(self.read_source(clean / name)) for name in filenames
            }
            result["syntax_before"] = before_valid
            if result["eligible"]:
                result["original_extraction"] = self.extract(clean, language, unit["id"], "original")
                marked = work / "marked"
                shutil.copytree(clean, marked)
                phase = time.perf_counter()
                self.directories.embed_directory(marked, language, self.config["watermark"], self.parser(language))
                result["embedding_ms"] = (time.perf_counter() - phase) * 1000
                result["marked_extraction"] = self.extract(marked, language, unit["id"], "marked")
                result["syntax_after"] = {
                    name: self.parser(language).check_syntax(self.read_source(marked / name)) for name in filenames
                }
                result["changed_files"] = sum(
                    (clean / name).read_bytes() != (marked / name).read_bytes() for name in filenames
                )
                result["attacks"] = {}
                for count in self.config["attacks"]:
                    name = f"flip_{count}"
                    target = work / name
                    attack = self.flip(marked, target, language, slots, count)
                    if attack["fully_applied"]:
                        attack["extraction"] = self.extract(target, language, unit["id"], name)
                        attack["syntax_valid_files"] = sum(
                            self.parser(language).check_syntax(self.read_source(target / filename))
                            for filename in filenames
                        )
                    result["attacks"][name] = attack
            else:
                result["original_extraction"] = result["marked_extraction"] = None
                result["syntax_after"], result["attacks"] = {}, {}
            result["utility_before"] = evaluate_utility(
                unit,
                clean,
                self.problems,
                self.config,
                self.run_dir,
                self.manifest["environment"],
                self.manifest["utility_cache"],
            )
            result["utility_after"] = (
                evaluate_utility(
                    unit,
                    work / "marked",
                    self.problems,
                    self.config,
                    self.run_dir,
                    self.manifest["environment"],
                    self.manifest["utility_cache"],
                )
                if result["eligible"]
                else {"status": "NOT_EMBEDDED"}
            )
        (work / "legacy.log").write_text(log.getvalue(), encoding="utf-8")
        result["elapsed_ms"] = (time.perf_counter() - started) * 1000
        result["artifacts"] = work.relative_to(self.run_dir).as_posix()
        write_json(work / "result.json", result)
        return result


ENGINE = None


def initialize_worker(run_dir, manifest):
    global ENGINE
    os.environ.setdefault("MPLBACKEND", "Agg")
    ENGINE = LegacyEngine(run_dir, manifest)


def evaluate_unit(unit):
    def timeout(signum, frame):
        raise UnitTimeout("Unit deadline exceeded")

    signal.signal(signal.SIGALRM, timeout)
    signal.setitimer(signal.ITIMER_REAL, ENGINE.config["unit_timeout_seconds"], 1)
    try:
        return ENGINE.evaluate(unit)
    except (Exception, UnitTimeout) as error:
        return {
            "id": unit["id"],
            "cohort": unit["id"].split("/", 1)[0],
            "language": unit["language"],
            "role": unit["role"],
            "level": unit["level"],
            "status": "harness_error",
            "error": repr(error),
            "traceback": traceback.format_exc(),
        }
    finally:
        signal.setitimer(signal.ITIMER_REAL, 0)
