"""Node-granular watermark slots (`cllmark.nodes`) in the benchmark: a standalone engine for "slot_granularity": "node".

The file-granular measurement (engine, common, utility, metrics) stays exactly as it is, so normal runs and their
protocol fingerprint do not change. `NodeEngine` measures the same row fields with node slots: analysis, embedding and
extraction through `cllmark.nodes`, site-level rule properties on the embedding slots, the slots that carry the
codeword after read-back repair, and two attacks: flip_k rewrites k slot nodes, normalize_k rewrites whole files
with the slots' inverse styles (what flip_k does under file granularity). Runs select it by the config key, and
`research_loop` adds this file's digest to the config, so the node protocol fingerprint follows its measurement code.
"""

import importlib
import json
import os
import shutil
import time
from contextlib import redirect_stderr, redirect_stdout

from . import engine
from .common import digest, unit_file_names, write_json

GRANULARITIES = ("file", "node")
REPORT_NOTE = (
    "Slot granularity: **node** (one slot per rewritable syntax node, see docs/NODE_SLOTS.md; slots are read back and "
    "repaired after embedding; flip_k rewrites k slot nodes, normalize_k rewrites whole files with the slots' inverse "
    "styles)."
)


def granularity(config):
    value = config.get("slot_granularity", "file")
    if value not in GRANULARITIES:
        raise ValueError(f"slot_granularity must be one of {GRANULARITIES}: {value!r}")
    return value


def protocol_config(config, root):
    """The config of a run: node runs also carry the digest of this measurement code (see the module docstring)."""
    if granularity(config) != "node":
        return config
    source = (root / "benchmarks" / "node_engine.py").read_bytes()
    return {**config, "node_engine_sha256": digest(source)}


def annotate_report(run_dir, manifest):
    """State the granularity under the title of a node run's report."""
    if granularity(manifest.get("config", {})) != "node":
        return
    report = run_dir / "report.md"
    if report.exists():
        lines = report.read_text(encoding="utf-8").split("\n")
        if REPORT_NOTE not in lines:
            lines.insert(4, REPORT_NOTE)
            report.write_text("\n".join(lines), encoding="utf-8")


class NodeEngine(engine.LegacyEngine):
    def __init__(self, run_dir, manifest):
        super().__init__(run_dir, manifest)
        self.nodes = importlib.import_module("cllmark.nodes")
        self.reload_written = importlib.import_module("cllmark.source_io").reload_written
        self.directories = self.nodes  # analyze/embed/extract_directory of node slots, also for the inherited `extract`

    def node_slots(self, language, available, expected):
        pairs = self.rules[language]
        return [
            {"file": name, "rule": pair, "index": index, "bit": bit, "style": pairs[pair][bit]}
            for (name, pair, index), bit in zip(available, expected, strict=False)
        ]

    def node_properties(self, clean, language, slots):
        """Site-level counterparts of `properties` on the embedding slots.

        idempotence: after rewriting a site to its other reading, it reads that bit (the style no longer applies to
        it); reversibility: rewriting it back restores the file exactly; independence: two slots of one file give the
        same code in either order.
        """
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

        def flip(code, slot):
            changed = self.nodes.flip(self.parser(language), language, code, slot["rule"], slot["index"])
            return None if changed is None else self.reload_written(changed)

        codes = {slot["file"]: self.read_source(clean / slot["file"]) for slot in slots}
        for slot in slots:
            code, styles = codes[slot["file"]], self.rules[language][slot["rule"]]
            try:
                reading = self.nodes.sites(self.parser(language), styles, code)[slot["index"]].reading
                flipped = flip(code, slot)
                if flipped is None:
                    result["unsupported_pairs"] += 1
                    continue
                after = self.nodes.sites(self.parser(language), styles, flipped)
                check(
                    "idempotence",
                    slot["index"] < len(after) and after[slot["index"]].reading == 1 - reading,
                    slot["file"],
                    [slot["rule"], slot["index"]],
                )
                check("reversibility", flip(flipped, slot) == code, slot["file"], [slot["rule"], slot["index"]])
            except Exception as error:
                result["errors"] += 1
                if len(result["examples"]) < 20:
                    result["examples"].append({"file": slot["file"], "rule": slot["rule"], "error": repr(error)})
        for index, left in enumerate(slots):
            for right in slots[index + 1 :]:
                if left["file"] != right["file"]:
                    continue
                code = codes[left["file"]]
                try:
                    first = flip(code, left)
                    second = flip(code, right)
                    ab = flip(first, right) if first is not None else None
                    ba = flip(second, left) if second is not None else None
                    names = [[left["rule"], left["index"]], [right["rule"], right["index"]]]
                    check("independence", ab is not None and ab == ba, left["file"], names)
                except Exception as error:
                    result["errors"] += 1
                    if len(result["examples"]) < 20:
                        result["examples"].append({"property": "independence", "error": repr(error)})
        return result

    def flip_nodes(self, source, target, language, slots, count):
        """Node-granular attack: rewrite the sites of the first `count` slots that can be rewritten (one node each)."""
        shutil.copytree(source, target)
        applied, unavailable = [], []
        for slot in slots:
            path = target / slot["file"]
            code = self.read_source(path)
            changed = self.nodes.flip(self.parser(language), language, code, slot["rule"], slot["index"])
            if changed is None:
                unavailable.append(slot)
                continue
            if changed != code:
                path.write_text(changed, encoding="utf-8")
                applied.append({"file": slot["file"], "rule": slot["rule"], "index": slot["index"]})
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
        """`LegacyEngine.evaluate` with node slots; the steps, timings and row fields are the same."""
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
        log = engine.BoundedLog()
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
            capacity = self.nodes.analyze_directory(clean, language, self.parser(language))
            result["analysis_ms"] = (time.perf_counter() - phase) * 1000
            support = json.loads((clean / "support_transform.json").read_text())
            expected = self.bch.encode(self.config["watermark"])
            result.update(
                {"capacity": capacity, "required_capacity": len(expected), "eligible": capacity >= len(expected)}
            )
            slots = result["embedding_slots"] = self.node_slots(language, support["slots"], expected)
            result["properties"] = (
                self.node_properties(clean, language, slots) if self.config["rule_properties"] else None
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
                self.nodes.embed_directory(marked, language, self.config["watermark"], self.parser(language))
                result["embedding_ms"] = (time.perf_counter() - phase) * 1000
                carried = json.loads((marked / "support_transform.json").read_text())
                result["dropped_slots"] = carried["dropped"]
                slots = result["embedding_slots"] = self.node_slots(language, carried["slots"], expected)
                result["marked_extraction"] = self.extract(marked, language, unit["id"], "marked")
                result["syntax_after"] = {
                    name: self.parser(language).check_syntax(self.read_source(marked / name)) for name in filenames
                }
                result["changed_files"] = sum(
                    (clean / name).read_bytes() != (marked / name).read_bytes() for name in filenames
                )
                result["attacks"] = {}
                for prefix, attack_function in [("flip", self.flip_nodes), ("normalize", self.flip)]:
                    for count in self.config["attacks"]:
                        name = f"{prefix}_{count}"
                        target = work / name
                        attack = attack_function(marked, target, language, slots, count)
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
            arguments = (
                self.problems,
                self.config,
                self.run_dir,
                self.manifest["environment"],
                self.manifest["utility_cache"],
            )
            # Looked up on the module at call time: the staged runner replaces it with a stub during this stage.
            result["utility_before"] = engine.evaluate_utility(unit, clean, *arguments)
            result["utility_after"] = (
                engine.evaluate_utility(unit, work / "marked", *arguments)
                if result["eligible"]
                else {"status": "NOT_EMBEDDED"}
            )
        (work / "legacy.log").write_text(log.getvalue(), encoding="utf-8")
        result["elapsed_ms"] = (time.perf_counter() - started) * 1000
        result["artifacts"] = work.relative_to(self.run_dir).as_posix()
        write_json(work / "result.json", result)
        return result


def initialize_worker(run_dir, manifest):
    """`engine.initialize_worker` with the node engine; `engine.evaluate_unit` then measures node slots."""
    os.environ.setdefault("MPLBACKEND", "Agg")
    engine.ENGINE = NodeEngine(run_dir, manifest)
