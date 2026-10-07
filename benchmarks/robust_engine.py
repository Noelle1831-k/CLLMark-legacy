"""Evaluation engine of the robust-watermark comparison (docs/plans/2026-10-07-robust-watermark.md, sections 5 and 6.2).

A config with a `"robust"` section selects this engine (`staged.initialize_worker`). The section names one variant:

    "robust": {"scheme": "s1|s2|bch-file|bch-node", "bits": 4|8, "anchor": "tok|struct", "alpha": [1e-3, 1e-6],
               "attacks": [...], "null_messages": "all"|N, "min_votes": 1, "keep_attacked": false}

`s1`/`s2` embed with `cllmark.robust` (two keyed schemes over node sites, blind detection from the key alone); `bch-file`
and `bch-node` are the current method at the two granularities (BCH(7,4), position-addressed, supported by the stored
support file), measured under the same attacks. Everything that is not the scheme is shared, so the variants are
comparable row by row:

- every unit gets a message of `bits` bits drawn from the config seed and its id (not a fixed `1010`), and one key
  derived from the seed (the experiment's secret; a deployment keeps it private);
- units embed unless their cohort says `"embed": false` (hand-written CodeNet groups) or is human (`js_repos`); those
  are read as they are, and a robust reading of unmarked code is the null hypothesis;
- the same attacks (`benchmarks/attacks.py`) are applied to marked code and to hand-written code, and each attacked
  version is read once with the true message;
- rows keep the fields `metrics.summarize_group` reads (`marked_extraction.matched` is the decision at the first
  `alpha` for the known message) and carry everything else in `robust` (see `Engine.evaluate`).

The functional tests of marked code run in the usual functional stage (`staged`), not here.
"""

import hashlib
import importlib
import os
import random
import shutil
import time
from collections import Counter
from contextlib import redirect_stderr, redirect_stdout
from pathlib import Path

from . import attacks, engine, node_engine, rule_sets
from .common import digest, unit_file_names, write_json

SCHEMES = ("s1", "s2", "bch-file", "bch-node")
ANCHORS = ("tok", "struct")
DEFAULT_ALPHA = (1e-3, 1e-6)
SECTION_KEYS = {"scheme", "bits", "anchor", "alpha", "attacks", "null_messages", "min_votes", "keep_attacked"}
CDF_POINTS = (1e-6, 1e-5, 1e-4, 1e-3, 1e-2, 0.05, 0.1, 0.25, 0.5)
BCH_DECISION = "match"
NOT_APPLICABLE = {"status": "NOT_APPLICABLE"}
REPORT_NOTE = (
    "Robust watermark variant: **{scheme}** (see docs/plans/2026-10-07-robust-watermark.md; rows carry a `robust` "
    "field, summarize them with tools/robust_report.py; the aggregate recovery above is the decision at alpha = {alpha:g} "
    "for the known message)."
)


def settings(config):
    """The normalized `robust` section of a config; a malformed one raises ValueError."""
    section = config.get("robust")
    if not isinstance(section, dict):
        raise ValueError("robust must be an object")
    if unknown := set(section) - SECTION_KEYS:
        raise ValueError(f"unknown robust keys: {sorted(unknown)}")
    scheme = section.get("scheme")
    if scheme not in SCHEMES:
        raise ValueError(f"robust.scheme must be one of {SCHEMES}: {scheme!r}")
    keyed = scheme in ("s1", "s2")
    bits = section.get("bits", 4)
    if bits not in ((4, 8) if keyed else (4,)) or isinstance(bits, bool):
        raise ValueError(f"robust.bits of {scheme} must be {'4 or 8' if keyed else '4'}: {bits!r}")
    anchor = section.get("anchor", "tok") if keyed else None
    if keyed and anchor not in ANCHORS:
        raise ValueError(f"robust.anchor must be one of {ANCHORS}: {anchor!r}")
    if not keyed and "anchor" in section:
        raise ValueError(f"{scheme} has no anchors")
    alpha = list(section.get("alpha", DEFAULT_ALPHA))
    if (
        not alpha
        or any(isinstance(a, bool) or not isinstance(a, (int, float)) or not 0 < a < 1 for a in alpha)
        or alpha != sorted(alpha, reverse=True)
    ):
        raise ValueError("robust.alpha is a non-increasing list of probabilities in (0, 1)")
    names = list(section.get("attacks", attacks.DEFAULT_ATTACKS))
    if len(set(names)) != len(names):
        raise ValueError("robust.attacks has duplicates")
    for name in names:
        attacks.parse_name(name)
    null_messages = section.get("null_messages", "all")
    if null_messages != "all" and (
        isinstance(null_messages, bool) or not isinstance(null_messages, int) or null_messages < 1
    ):
        raise ValueError('robust.null_messages is "all" or a positive integer')
    min_votes = section.get("min_votes", 1)
    if isinstance(min_votes, bool) or not isinstance(min_votes, int) or min_votes < 1:
        raise ValueError("robust.min_votes is a positive integer")
    keep = section.get("keep_attacked", False)
    if not isinstance(keep, bool):
        raise ValueError("robust.keep_attacked is a boolean")
    return {
        "scheme": scheme,
        "bits": bits,
        "anchor": anchor,
        "alpha": alpha,
        "attacks": names,
        "null_messages": null_messages,
        "min_votes": min_votes,
        "keep_attacked": keep,
    }


def unit_limit(unit):
    """The number of messages a sweep of this unit's cohort covers when the cohort overrides `null_messages` (a
    cohort key, e.g. for large repositories under the 8-bit scheme 2, whose blind search costs 256 detections per
    reading); None keeps the config's value."""
    limit = unit.get("null_messages")
    if limit is not None and (isinstance(limit, bool) or not isinstance(limit, int) or limit < 1):
        raise ValueError(f"cohort null_messages is a positive integer: {limit!r}")
    return limit


def unit_attacks(unit, default):
    """The attacks of this unit's cohort: its `attacks` key (a list of attack names) or the config's list. Large
    repositories are read once per attacked version, and every distinct version costs the scheme a full observation."""
    names = unit.get("attacks")
    if names is None:
        return default
    if not isinstance(names, list) or len(set(names)) != len(names):
        raise ValueError(f"cohort attacks is a list of distinct attack names: {names!r}")
    for name in names:
        attacks.parse_name(name)
    return names


def is_robust(config):
    return "robust" in config


def core_digest(root):
    """Digest of `cllmark/robust/` (the scheme implementation the engine calls); 'absent' before it exists."""
    folder = Path(root) / "cllmark" / "robust"
    if not folder.is_dir():
        return "absent"
    return digest(
        {path.relative_to(folder).as_posix(): digest(path.read_bytes()) for path in sorted(folder.rglob("*.py"))}
    )


def protocol_config(config, root):
    """The config of a run: robust runs also carry the digests of the engine, the attacks and the scheme code (see the
    module docstring); configs without a `robust` section are returned unchanged, so their fingerprints do not move."""
    if not is_robust(config):
        return config
    settings(config)
    benchmarks = Path(root) / "benchmarks"
    return {
        **config,
        "robust_engine_sha256": digest((benchmarks / "robust_engine.py").read_bytes()),
        "robust_attacks_sha256": digest((benchmarks / "attacks.py").read_bytes()),
        "robust_core_sha256": core_digest(root),
    }


def annotate_report(run_dir, manifest):
    """State the variant under the title of a robust run's report."""
    config = manifest.get("config", {})
    if not is_robust(config):
        return
    report = Path(run_dir) / "report.md"
    if report.exists():
        chosen = settings(config)
        note = REPORT_NOTE.format(scheme=chosen["scheme"], alpha=chosen["alpha"][0])
        lines = report.read_text(encoding="utf-8").split("\n")
        if note not in lines:
            lines.insert(4, note)
            report.write_text("\n".join(lines), encoding="utf-8")


# ------------------------------------------------------------------------------------------------ derived values


def derive(seed, *parts):
    return hashlib.sha256(":".join(str(part) for part in (seed, *parts)).encode()).digest()


def message_for(seed, unit_id, bits):
    """The unit's message, uniform over the 2^bits messages."""
    value = int.from_bytes(derive(seed, "message", unit_id)[:8], "big") % (1 << bits)
    return [(value >> (bits - 1 - index)) & 1 for index in range(bits)]


def to_int(bits):
    return int("".join(str(bit) for bit in bits), 2) if bits else None


def from_int(value, bits):
    return [(value >> (bits - 1 - index)) & 1 for index in range(bits)]


def label(alpha):
    return f"{alpha:g}"


def summarize_p(p_values, alphas):
    """What the report needs of the p-values of one code version against many messages: the smallest, the messages
    that pass each alpha, and the counts below a fixed ladder of thresholds (an empirical CDF to compare with the
    diagonal)."""
    ranked = sorted(p_values.items(), key=lambda item: (item[1], item[0]))
    return {
        "messages": len(ranked),
        "min_p": ranked[0][1] if ranked else None,
        "min_message": ranked[0][0] if ranked else None,
        "hits": {label(a): sorted(m for m, p in ranked if p <= a) for a in alphas},
        "cdf": {label(t): sum(p <= t for _, p in ranked) for t in CDF_POINTS},
    }


def anchor_survival(reference, keys):
    """How many of the keys read in an attacked version are keys of the reference version (the embedded code, or the
    unattacked hand-written code), and how many reference keys remain."""
    shared = len(set(keys) & set(reference))
    return {
        "reference_keys": len(reference),
        "keys": len(keys),
        "shared": shared,
        "survival": shared / len(keys) if keys else None,
        "retained": shared / len(reference) if reference else None,
    }


def changed_lines(before, after):
    """Lines of `after` that `before` lacks (a multiset difference; cheap and independent of line order)."""
    added = Counter(line for code in after.values() for line in code.splitlines())
    added.subtract(Counter(line for code in before.values() for line in code.splitlines()))
    return sum(count for count in added.values() if count > 0)


# ------------------------------------------------------------------------------------------------ engine


class RobustEngine(rule_sets.ExtendedRules, node_engine.NodeEngine):
    def __init__(self, run_dir, manifest):
        super().__init__(run_dir, manifest)
        self.settings = settings(self.config)
        self.file_directories = importlib.import_module("cllmark.directories")
        self.source_io = importlib.import_module("cllmark.source_io")
        self.scheme = self.settings["scheme"]
        self.bits = self.settings["bits"]
        self.alphas = self.settings["alpha"]
        self.keyed = self.scheme in ("s1", "s2")
        self.key = derive(self.config["seed"], "key")
        self.robust = importlib.import_module("cllmark.robust") if self.keyed else None
        self.directories = self.nodes if self.scheme == "bch-node" else self.file_directories
        self.robust_scheme = (
            self.robust.Scheme(name=self.scheme, bits=self.bits, anchor=self.settings["anchor"]) if self.keyed else None
        )
        self.donor_units = self.find_donors(manifest["units"])

    # -- setup ------------------------------------------------------------------------------------

    @staticmethod
    def embeds(unit):
        """Whether a unit is embedded: explicit `embed`, else every cohort but the hand-written ones."""
        return bool(unit.get("embed", unit["role"] != "human"))

    @staticmethod
    def find_donors(units):
        """Per language the hand-written units that the `insert` attack takes unmarked code from: function-level ones
        when there are any (they are single programs), otherwise all."""
        donors = {}
        for unit in sorted(units, key=lambda item: item["id"]):
            if unit["role"] == "human":
                donors.setdefault(unit["language"], []).append(unit)
        return {language: [u for u in found if u["level"] == "function"] or found for language, found in donors.items()}

    def donors_of(self, unit):
        candidates = [other for other in self.donor_units.get(unit["language"], []) if other["id"] != unit["id"]]

        def donors(rng):
            order = list(candidates)
            rng.shuffle(order)
            for other in order:
                files = {}
                try:
                    for relative, name in unit_file_names(other).items():
                        files[name] = self.read_source(self.run_dir / "inputs" / relative)
                except (OSError, ValueError):
                    continue
                yield files

        return donors

    def seed_for(self, unit_id, *parts):
        return int.from_bytes(derive(self.config["seed"], unit_id, *parts)[:8], "big")

    # -- readings ---------------------------------------------------------------------------------

    def read_robust(self, language, files, message, sweep=None, exclude=False, limit=None):
        """Detection of `files` for the true `message`: the counts, p-values and decisions of the scheme, the keys that
        were read (for anchor survival, not stored in rows) and, when `sweep` is the id of a stage, the p-values against
        the other messages (all, or the configured number of them; `exclude` leaves the true message out)."""
        started = time.perf_counter()
        parser = self.parser(language)
        found = self.robust.detect(parser, language, files, self.robust_scheme, self.key, message)
        elapsed = (time.perf_counter() - started) * 1000
        decoded = list(found.decoded) if found.decoded is not None else None
        reading = {
            "votes": found.votes,
            "agree": found.agree,
            "p_known": found.p_known,
            "decoded": decoded,
            "p_blind": found.p_blind,
            "margin": found.margin,
            "p_all": getattr(
                found, "p_all", None
            ),  # informational (scheme 1: all votes); decisions use p_known/p_blind
            "errors": getattr(found, "errors", 0),  # (file, rule pair) combinations whose rules raised
            "decision": {label(a): found.p_known is not None and found.p_known <= a for a in self.alphas},
            "blind": {
                label(a): decoded == list(message) and found.p_blind is not None and found.p_blind <= a
                for a in self.alphas
            },
            "elapsed_ms": elapsed,
        }
        if sweep is not None:
            reading["sweep"] = self.sweep(found.keys, message, sweep, exclude, limit)
        return reading, dict(found.keys)

    def sweep(self, votes, message, stage, exclude, limit=None):
        """p-values of the cast `votes` ({anchor key: reading}, `Detection.keys`) against the messages of the sweep
        (see `summarize_p`). Only the known-message test runs per message: the code is observed once and the blind
        decision (2^bits PRF evaluations per vote) is not repeated for each of the 2^bits messages."""
        started = time.perf_counter()
        values = [value for value in range(1 << self.bits) if not (exclude and value == to_int(message))]
        limit = self.settings["null_messages"] if limit is None else limit
        if limit != "all" and limit < len(values):
            values = sorted(random.Random(self.seed_for(stage, "sweep")).sample(values, limit))
        p_values = {}
        for value in values:
            found = self.robust.score(self.robust_scheme, self.key, votes, from_int(value, self.bits), blind=False)
            p_values[value] = found.p_known if found.p_known is not None else 1.0
        summary = summarize_p(p_values, self.alphas)
        summary["elapsed_ms"] = (time.perf_counter() - started) * 1000
        return summary

    def read_bch(self, language, files, support, message, unit_id, stage, work):
        """The legacy expected-message extraction of `files` with the support file of `support` (a directory): position
        addressed, so the files are written next to a copy of the support file and read there."""
        directory = work / ("read-" + digest(stage.encode())[:12])
        if directory.exists():
            shutil.rmtree(directory)
        directory.mkdir(parents=True)
        try:
            for name, code in files.items():
                self.source_io.write_source(directory / name, code)
            shutil.copyfile(support / "support_transform.json", directory / "support_transform.json")
            captured, started = {}, time.perf_counter()
            seed = self.seed_for(unit_id, stage, "extraction")
            random.seed(seed)

            def decode(bits):
                captured["bits"] = list(bits)
                captured["decoded"] = self.real_decode(bits)
                return captured["decoded"]

            self.bch.decode = decode
            try:
                matched, raw = self.directories.extract_directory(directory, language, message, self.parser(language))
            except Exception as error:
                return {
                    "error": repr(error),
                    "decision": {BCH_DECISION: False},
                    "decoded": None,
                    "bits": [],
                    "elapsed_ms": (time.perf_counter() - started) * 1000,
                }
            finally:
                self.bch.decode = self.real_decode
            decoded = list(captured.get("decoded") or [])
            return {
                "decision": {BCH_DECISION: bool(matched)},
                "raw_matched": bool(raw),
                "bits": captured.get("bits", []),
                "decoded": decoded or None,
                "elapsed_ms": (time.perf_counter() - started) * 1000,
                "sweep": {
                    "messages": 1 << self.bits,
                    "min_p": None,
                    "min_message": None,
                    "hits": {BCH_DECISION: [to_int(decoded)] if decoded else []},
                    "cdf": {},
                },
            }
        finally:
            if not self.settings["keep_attacked"]:
                shutil.rmtree(directory, ignore_errors=True)

    def failed(self, error):
        """The reading of a version the detector could not read: kept in the row with its error, counted as no
        detection (an attacked or unusual file that makes a rule raise is a result, not a reason to drop the unit)."""
        names = [label(a) for a in self.alphas] if self.keyed else [BCH_DECISION]
        return {
            "error": repr(error),
            "votes": 0,
            "agree": None,
            "p_known": None,
            "decoded": None,
            "p_blind": None,
            "margin": None,
            "p_all": None,
            "errors": 0,
            "decision": dict.fromkeys(names, False),
            "blind": dict.fromkeys(names, False),
            "bits": [],
            "elapsed_ms": 0.0,
        }

    def read(self, unit, language, files, message, stage, work, support=None, sweep=False, exclude=False):
        """(reading, keys) of one code version; `sweep` adds the all-messages summary (robust schemes)."""
        try:
            if self.keyed:
                return self.read_robust(language, files, message, stage if sweep else None, exclude, unit_limit(unit))
            return self.read_bch(language, files, support, message, unit["id"], stage, work), {}
        except Exception as error:
            return self.failed(error), {}

    def extraction(self, reading, message):
        """The legacy-shaped extraction of a reading (`matched`, `raw_matched`, `bits`, ...); for BCH the raw bits
        are compared with the codeword, as `LegacyEngine.extract` does."""
        decoded = reading.get("decoded")
        if self.keyed:
            first = label(self.alphas[0])
            bits, expected = list(decoded or []), list(message)
            raw_matched = decoded == expected
        else:
            first = BCH_DECISION
            bits, expected = reading.get("bits", []), self.bch.encode(message)
            raw_matched = reading.get("raw_matched", False)
        return {
            "matched": reading["decision"][first],
            "raw_matched": raw_matched,
            "bits": bits,
            "decoded": decoded,
            "correct_bits": sum(a == b for a, b in zip(bits, expected, strict=False)),
            "expected_bit_count": len(expected),
            "elapsed_ms": reading["elapsed_ms"],
            "p_known": reading.get("p_known"),
            "votes": reading.get("votes"),
            **({"error": reading["error"]} if "error" in reading else {}),
        }

    # -- attacks ----------------------------------------------------------------------------------

    def attack_version(self, unit, language, files, message, reference_keys, name, work, support, sweep=False):
        """One attack on `files`: the attacked project is read once with the true message (and, for hand-written code,
        against the other messages: the attacked null hypothesis); returns the legacy-shaped entry (`fully_applied`,
        `extraction`, ...) and the `robust` entry."""
        parser = self.parser(language)
        rng = random.Random(self.seed_for(unit["id"], name))
        result = attacks.apply(name, parser, language, files, rng, self.donors_of(unit))
        entry = {
            "effective_transformations": result.effective,
            "fully_applied": result.effective > 0 and result.files != files,
            "details": result.details,
        }
        detail = {"effective": result.effective, "changed": result.files != files, "details": result.details}
        if entry["fully_applied"]:
            attacked = result.files
            entry["syntax_valid_files"] = sum(parser.check_syntax(code) for code in attacked.values())
            entry["files"] = len(attacked)
            reading, keys = self.read(unit, language, attacked, message, "attack:" + name, work, support, sweep=sweep)
            entry["extraction"] = self.extraction(reading, message)
            detail.update(reading)
            if self.keyed:
                detail["anchors"] = anchor_survival(reference_keys, keys)
            if self.settings["keep_attacked"]:
                target = work / ("attacked-" + name)
                for filename, code in attacked.items():
                    self.source_io.write_source(target / filename, code)
        return entry, detail

    # -- one unit ---------------------------------------------------------------------------------

    def evaluate(self, unit):
        """The row of a unit: the fields of `LegacyEngine.evaluate`, plus `robust`.

        `robust` = {scheme, bits, anchor, message, alpha, capacity, embed, original, marked, attacks}; `original` and
        `marked` are readings (counts, p-values, decisions per alpha, `sweep` over messages), `attacks[name]` a reading
        of the attacked code with `anchors` (survival of the embedding keys; hand-written code also gets a `sweep`) or
        `changed: false` when the attack did nothing to this unit. Hand-written (not embedded) units have `original` and `attacks` only: those are the null
        hypothesis. `eligible` is capacity >= `min_votes` (robust schemes; any positive number of votes can be tried) or
        >= the 7 codeword bits (BCH), as in the legacy rows; units that cannot be embedded are not attacked.
        """
        started = time.perf_counter()
        language = unit["language"]
        parser = self.parser(language)  # Exclude one-time parser creation from phase timings.
        work = self.run_dir / "work" / digest(unit["id"].encode())[:20]
        if work.exists():
            shutil.rmtree(work)
        clean = work / "clean"
        clean.mkdir(parents=True)
        filenames = []
        for relative, name in unit_file_names(unit).items():
            blob = (self.run_dir / "inputs" / relative).read_bytes()
            if digest(blob) != self.manifest["input_files"][relative]["sha256"]:
                raise ValueError("Frozen input hash mismatch: " + relative)
            filenames.append(name)
            (clean / name).write_bytes(blob)
        embed = self.embeds(unit)
        message = message_for(self.config["seed"], unit["id"], self.bits)
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
            "watermark": message,
            "embedded": False,
            "properties": None,
            "embedding_slots": [],
        }
        robust = result["robust"] = {
            "scheme": self.scheme,
            "bits": self.bits,
            "anchor": self.settings["anchor"],
            "message": message,
            "alpha": self.alphas,
        }
        with redirect_stdout(log), redirect_stderr(log):
            files = {name: self.read_source(clean / name) for name in filenames}
            phase = time.perf_counter()
            if self.keyed:
                # capacity = the sites that carry votes (calibrated pairs, non-overlapping: the selection embedding and
                # detection share); the stability counts come from the embedding (`details`), nothing is checked twice
                observed = self.robust.observe(parser, language, files, self.settings["anchor"], selected=True)
                votes = len({site.key for site in observed})
                capacity = len(observed)
                robust["capacity"] = {
                    "sites": len(observed),
                    "readable": sum(site.reading is not None for site in observed),
                    "usable": capacity,
                    "votes": votes,
                    "files": len(files),
                    "pairs": len({site.pair for site in observed}),
                }
                required = self.settings["min_votes"]
                sufficient = votes >= required
            else:
                capacity = self.directories.analyze_directory(clean, language, parser)
                required = len(self.bch.encode(message))
                sufficient = capacity >= required
                robust["capacity"] = {"usable": capacity, "votes": capacity, "files": len(files)}
            result["analysis_ms"] = (time.perf_counter() - phase) * 1000
            result.update({"capacity": capacity, "required_capacity": required, "eligible": embed and sufficient})
            if not embed:
                result["capacity_sufficient"] = sufficient
            result["syntax_before"] = {name: parser.check_syntax(code) for name, code in files.items()}
            result["attacks"], robust["attacks"] = {}, {}
            support = clean
            marked_files = None
            if embed and sufficient:
                result["embedded"] = True
                reading, _ = self.read(unit, language, files, message, "original", work, support, sweep=True)
                robust["original"] = reading
                result["original_extraction"] = self.extraction(reading, message)
                marked = work / "marked"
                shutil.copytree(clean, marked)
                phase = time.perf_counter()
                if self.keyed:
                    done = self.robust.embed(parser, language, files, self.robust_scheme, self.key, message)
                    for name, code in done.written.items():
                        self.source_io.write_source(marked / name, code)
                    details = dict(getattr(done, "details", None) or {})
                    if "selected_by_pair" in details:  # stable sites among the selected ones, per rule pair
                        unstable_by_pair = details["unstable_by_pair"]
                        robust["capacity"]["pair_stability"] = {
                            pair: [selected, selected - unstable_by_pair.get(pair, 0)]
                            for pair, selected in details["selected_by_pair"].items()
                        }
                        robust["capacity"]["stable"] = sum(
                            stable for _, stable in robust["capacity"]["pair_stability"].values()
                        )
                    embedded = {
                        "votes": done.votes,
                        "targeted_sites": done.targeted_sites,
                        "set_sites": done.set_sites,
                        "rounds": done.rounds,
                        "set_rate": done.set_sites / done.targeted_sites if done.targeted_sites else None,
                        "selection_agreement": getattr(done, "selection_agreement", None),
                        "errors": getattr(done, "errors", 0),
                        "unstable_selected": getattr(done, "unstable_selected", None),
                        "details": details,
                    }
                else:
                    self.directories.embed_directory(marked, language, message, parser)
                    embedded = {}
                result["embedding_ms"] = (time.perf_counter() - phase) * 1000
                marked_files = {name: self.read_source(marked / name) for name in filenames}
                result["changed_files"] = sum(
                    (clean / name).read_bytes() != (marked / name).read_bytes() for name in filenames
                )
                robust["embed"] = {
                    **embedded,
                    "changed_files": result["changed_files"],
                    "changed_lines": changed_lines(files, marked_files),
                }
                support = marked
                reading, reference = self.read(
                    unit, language, marked_files, message, "marked", work, support, sweep=True, exclude=True
                )
                robust["marked"] = reading
                result["marked_extraction"] = self.extraction(reading, message)
                result["syntax_after"] = {name: parser.check_syntax(code) for name, code in marked_files.items()}
                attacked_files = marked_files
            elif not embed:
                reading, reference = self.read(unit, language, files, message, "original", work, clean, sweep=True)
                robust["original"] = reading
                result["original_extraction"] = self.extraction(reading, message)
                result["marked_extraction"] = None
                result["syntax_after"] = {}
                attacked_files = files
            else:
                result["original_extraction"] = result["marked_extraction"] = None
                result["syntax_after"] = {}
                attacked_files = None
            if attacked_files is not None:
                for name in unit_attacks(unit, self.settings["attacks"]):
                    entry, detail = self.attack_version(
                        unit, language, attacked_files, message, reference, name, work, support, sweep=not embed
                    )
                    result["attacks"][name], robust["attacks"][name] = entry, detail
            arguments = (
                self.problems,
                self.config,
                self.run_dir,
                self.manifest["environment"],
                self.manifest["utility_cache"],
            )
            # Looked up on the module at call time: the staged runner replaces it with a stub during this stage.
            if embed and sufficient:
                result["utility_before"] = engine.evaluate_utility(unit, clean, *arguments)
                result["utility_after"] = engine.evaluate_utility(unit, work / "marked", *arguments)
            else:
                result["utility_before"] = dict(NOT_APPLICABLE)
                result["utility_after"] = {"status": "NOT_EMBEDDED"}
        (work / "legacy.log").write_text(log.getvalue(), encoding="utf-8")
        result["elapsed_ms"] = (time.perf_counter() - started) * 1000
        result["artifacts"] = work.relative_to(self.run_dir).as_posix()
        write_json(work / "result.json", result)
        return result


def initialize_worker(run_dir, manifest):
    """`engine.initialize_worker` with the robust engine; `engine.evaluate_unit` then measures the configured variant."""
    os.environ.setdefault("MPLBACKEND", "Agg")
    engine.ENGINE = RobustEngine(run_dir, manifest)
