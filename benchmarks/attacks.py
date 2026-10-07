"""Attacks on (watermarked or unmarked) code for the robust-watermark comparison (docs/plans/2026-10-07-robust-watermark.md, section 4).

The attacker knows the public rule set but no key. Every attack takes a project `{file name: decoded text}` and returns a
new project; attacked code is only read by detectors, it is not required to compile (rename and reorder in particular
may break references the declaration analysis does not see, such as macros or other files). All randomness comes from
the `random.Random` the caller passes (the engine seeds it from the config seed, the unit id and the attack name), so an
attack replays exactly.

| name           | content                                                                                              |
| -------------- | ---------------------------------------------------------------------------------------------------- |
| `flip_P`       | every usable site of every rule pair is rewritten to its other reading with probability P            |
| `normalize_R`  | R random rule pairs (among those with a readable site; `all`: every pair) are rewritten file-wide to a random side |
| `delete_Q`     | a fraction Q of the top-level functions of every file (projects: also of the files) is removed        |
| `insert_K`     | K times the amount of unmarked code of other hand-written units is appended (projects: as new files)  |
| `rename`       | declared locals, parameters and functions get fresh names (tree-sitter declarations, all references)  |
| `reformat`     | comments and blank lines removed; C/C++/JS also get one indentation scheme and spaces around operators |
| `reorder`      | top-level functions are shuffled (projects: file names too, within one extension)                    |
| `combo`        | rename, then flip_0.2, then delete_0.25                                                              |

`flip` and `normalize` use the sites of `cllmark.nodes`; the other attacks need only the language's tree-sitter grammar
(`StyleTransformer.parse`). Decisions the plan leaves open are marked "choice" below and listed in the engine docs.
"""

from __future__ import annotations

import builtins
import keyword
import random
import re
from collections.abc import Callable, Iterable, Iterator, Mapping
from dataclasses import dataclass, field

from cllmark import nodes
from cllmark.rules.engine import apply_groups
from cllmark.source_io import reload_written
from cllmark.watermark import DETECT_ONLY

KINDS = ("flip", "normalize", "delete", "insert", "rename", "reformat", "reorder", "combo")
DEFAULT_ATTACKS = (
    "flip_0.1",
    "flip_0.2",
    "flip_0.3",
    "normalize_1",
    "normalize_3",
    "normalize_all",
    "delete_0.25",
    "delete_0.5",
    "insert_1",
    "rename",
    "reformat",
    "reorder",
    "combo",
)
COMBO = ("rename", "flip_0.2", "delete_0.25")
EXTENSIONS = {"python": ".py", "c": ".c", "cpp": ".cpp", "javascript": ".js"}

Donors = Callable[[random.Random], Iterator[Mapping[str, str]]]
"""Donor units of the `insert` attack: given the attack's random generator, yields the files of other units in the order
they should be used (the engine draws them from the hand-written units of the run)."""


@dataclass
class Result:
    files: dict[str, str]
    effective: int = 0  # units the attack changed: sites flipped, pairs normalized, functions or files removed, ...
    details: dict = field(default_factory=dict)


def parse_name(name: str) -> tuple[str, float | int | str | None]:
    """(kind, parameter) of an attack name such as `flip_0.2`, `normalize_all`, `insert_1` or `rename`."""
    kind, _, text = name.partition("_")
    if kind not in KINDS:
        raise ValueError(f"unknown attack {name!r}; kinds are {KINDS}")
    if kind in ("rename", "reformat", "reorder", "combo"):
        if text:
            raise ValueError(f"attack {kind} takes no parameter: {name!r}")
        return kind, None
    if kind in ("flip", "delete"):
        try:
            value = float(text)
        except ValueError:
            raise ValueError(f"attack {name!r} needs a fraction in (0, 1]") from None
        if not 0 < value <= 1:
            raise ValueError(f"attack {name!r} needs a fraction in (0, 1]")
        return kind, value
    if kind == "normalize" and text == "all":
        return kind, "all"
    if not text.isdigit() or int(text) < 1:
        raise ValueError(f"attack {name!r} needs a positive integer")
    return kind, int(text)


def apply(
    name: str,
    transformer,
    language: str,
    files: Mapping[str, str],
    rng: random.Random,
    donors: Donors | None = None,
) -> Result:
    """The attacked project; `files` is not modified."""
    kind, parameter = parse_name(name)
    files = dict(files)
    if kind == "flip":
        return flip(transformer, language, files, rng, parameter)
    if kind == "normalize":
        return normalize(transformer, language, files, rng, parameter)
    if kind == "delete":
        return delete(transformer, language, files, rng, parameter)
    if kind == "insert":
        return insert(language, files, rng, parameter, donors)
    if kind == "rename":
        return rename(transformer, language, files, rng)
    if kind == "reformat":
        return reformat(transformer, language, files)
    if kind == "reorder":
        return reorder(transformer, language, files, rng)
    result = Result(files)
    for step in COMBO:
        part = apply(step, transformer, language, result.files, rng, donors)
        result = Result(part.files, result.effective + part.effective, {**result.details, step: part.details})
    return result


# ------------------------------------------------------------------------------------------------ text and trees


def apply_edits(data: bytes, edits: Iterable[tuple[int, int, bytes]]) -> bytes:
    """`data` with the (start, end, replacement) byte edits applied; an edit starting inside an earlier one is skipped."""
    parts, position = [], 0
    for start, end, text in sorted(edits, key=lambda edit: (edit[0], edit[1])):
        if start < position:
            continue
        parts += [data[position:start], text]
        position = end
    parts.append(data[position:])
    return b"".join(parts)


def walk(node) -> Iterator:
    """The nodes below `node` (itself included) in pre-order."""
    stack = [node]
    while stack:
        current = stack.pop()
        yield current
        stack.extend(reversed(current.children))


def tree_of(transformer, code: str):
    return transformer.parse(code).root_node


def field_is(parent, name: str, node) -> bool:
    child = parent.child_by_field_name(name)
    return child is not None and child.id == node.id


def ancestors(node) -> Iterator:
    node = node.parent
    while node is not None:
        yield node
        node = node.parent


JS_FUNCTION_VALUES = {"function", "function_expression", "arrow_function", "generator_function"}


def function_spans(root, language: str) -> list[tuple[int, int]]:
    """Byte spans of the top-level functions of a file (a decorated or exported function includes its wrapper)."""
    spans = []
    for child in root.children:
        kind = child.type
        if language == "python":
            found = kind == "function_definition" or (
                kind == "decorated_definition"
                and child.child_by_field_name("definition") is not None
                and child.child_by_field_name("definition").type == "function_definition"
            )
        elif language == "javascript":
            declaration = child.child_by_field_name("declaration") if kind == "export_statement" else child
            found = declaration is not None and (
                declaration.type in ("function_declaration", "generator_function_declaration")
                or (
                    declaration.type in ("lexical_declaration", "variable_declaration")
                    and (declarators := [c for c in declaration.named_children if c.type == "variable_declarator"])
                    and all(
                        d.child_by_field_name("value") is not None
                        and d.child_by_field_name("value").type in JS_FUNCTION_VALUES
                        for d in declarators
                    )
                )
            )
        else:
            found = kind == "function_definition" or (
                kind == "template_declaration" and any(c.type == "function_definition" for c in child.named_children)
            )
        if found:
            spans.append((child.start_byte, child.end_byte))
    return spans


def with_line_end(data: bytes, start: int, end: int) -> tuple[int, int]:
    """The span widened over the blanks after it and one line break, so removing it leaves no empty line behind."""
    line_start = data.rfind(b"\n", 0, start) + 1
    alone_before = not data[line_start:start].strip()
    stop = end
    while stop < len(data) and data[stop : stop + 1] in (b" ", b"\t"):
        stop += 1
    if alone_before and data[stop : stop + 1] == b"\n":
        return start, stop + 1
    return start, end


# ------------------------------------------------------------------------------------------------ flip, normalize


def flip(transformer, language: str, files: dict[str, str], rng: random.Random, probability: float) -> Result:
    """Each usable site (a readable site whose rule can rewrite it; choice) flips with `probability`, pair by pair."""
    out, flipped, seen = {}, 0, 0
    for name in sorted(files):
        code = files[name]
        for styles in transformer.pairs.values():
            try:
                usable = [site for site in nodes.sites(transformer, styles, code) if site.usable]
                chosen = [site for site in usable if rng.random() < probability]
                if not chosen:
                    seen += len(usable)
                    continue
                data, taken = apply_groups(code.encode("utf-8"), [site.group for site in chosen])
            except Exception:  # a rule that raises on this version leaves the pair alone
                continue
            seen += len(usable)
            flipped += len(taken)
            code = reload_written(data.decode("utf-8"))
        out[name] = code
    return Result(out, flipped, {"usable_sites": seen, "flipped_sites": flipped, "probability": probability})


def normalize(transformer, language: str, files: dict[str, str], rng: random.Random, pairs) -> Result:
    """`pairs` random rule pairs (`all`: every pair; choice: among the pairs with a readable site) are applied to
    every file in one random style. A detect-only style (C/C++ loops 11/12) cannot be applied; the pair then takes its
    other side."""
    table = transformer.pairs
    present = []
    for pair, styles in table.items():
        try:
            if any(
                site.reading is not None for code in files.values() for site in nodes.sites(transformer, styles, code)
            ):
                present.append(pair)
        except Exception:
            continue
    chosen = (
        list(table) if pairs == "all" else sorted(rng.sample(present, min(pairs, len(present))), key=list(table).index)
    )
    out, normalized, sides = dict(files), 0, {}
    for pair in chosen:
        side = rng.randrange(2)
        if table[pair][side] in DETECT_ONLY:
            side = 1 - side
        sides[pair] = side
        changed = False
        for name in sorted(out):
            try:
                text = reload_written(transformer.apply(table[pair][side], out[name])[0])
            except Exception:
                continue
            if text != out[name]:
                out[name], changed = text, True
        normalized += changed
    return Result(out, normalized, {"candidate_pairs": len(present), "chosen_pairs": len(chosen), "sides": sides})


# ------------------------------------------------------------------------------------------------ delete, reorder, insert


def half_up(value: float) -> int:
    return int(value + 0.5)


def delete(transformer, language: str, files: dict[str, str], rng: random.Random, fraction: float) -> Result:
    """Remove round(fraction * n) of the n top-level functions of each file and, in projects of several files,
    round(fraction * files) files (always keeping one)."""
    names = sorted(files)
    dropped = []
    if len(names) > 1:
        count = min(half_up(fraction * len(names)), len(names) - 1)
        dropped = sorted(rng.sample(names, count))
    out, removed = {}, 0
    for name in names:
        if name in dropped:
            continue
        data = files[name].encode("utf-8")
        spans = function_spans(tree_of(transformer, files[name]), language)
        count = half_up(fraction * len(spans))
        victims = sorted(rng.sample(spans, count)) if count else []
        out[name] = apply_edits(data, [(*with_line_end(data, s, e), b"") for s, e in victims]).decode("utf-8")
        removed += len(victims)
    return Result(out, removed + len(dropped), {"functions_removed": removed, "files_removed": len(dropped)})


def reorder(transformer, language: str, files: dict[str, str], rng: random.Random) -> Result:
    """Shuffle the top-level functions of each file among the places the functions occupy; in projects also permute the
    file names within each extension (the contents stay)."""
    out, moved = {}, 0
    for name in sorted(files):
        code, data = files[name], files[name].encode("utf-8")
        spans = function_spans(tree_of(transformer, code), language)
        order = list(range(len(spans)))
        for _ in range(8):
            rng.shuffle(order)
            if order != sorted(order) or len(order) < 2:
                break
        edits = [(spans[i][0], spans[i][1], data[spans[j][0] : spans[j][1]]) for i, j in enumerate(order)]
        out[name] = apply_edits(data, edits).decode("utf-8") if len(order) > 1 else code
        moved += sum(i != j for i, j in enumerate(order)) if len(order) > 1 else 0
    renamed = 0
    if len(out) > 1:
        by_extension: dict[str, list[str]] = {}
        for name in sorted(out):
            by_extension.setdefault(name[name.rfind(".") :] if "." in name else "", []).append(name)
        permuted = {}
        for group in by_extension.values():
            targets = list(group)
            for _ in range(8):
                rng.shuffle(targets)
                if targets != group or len(group) < 2:
                    break
            permuted.update(zip(group, targets, strict=True))
        renamed = sum(old != new for old, new in permuted.items())
        out = {permuted[name]: code for name, code in out.items()}
    return Result(out, moved + renamed, {"functions_moved": moved, "files_renamed": renamed})


def insert(language: str, files: dict[str, str], rng: random.Random, factor: int, donors: Donors | None) -> Result:
    """Append `factor` times the project's line count of code from donor units: at the end of the only file, or, in a
    project, as new files `inserted_<k>` (choice; the plan says "at the end")."""
    if donors is None:
        return Result(files, 0, {"reason": "no donors"})
    wanted = factor * sum(len(code.splitlines()) for code in files.values())
    taken: list[tuple[str, str]] = []
    lines = 0
    for donor in donors(rng):
        for name in sorted(donor):
            taken.append((name, donor[name]))
            lines += len(donor[name].splitlines())
        if lines >= wanted:
            break
    if not taken:
        return Result(files, 0, {"reason": "no donors"})
    out = dict(files)
    if len(files) == 1:
        (name,) = files
        out[name] = files[name].rstrip("\n") + "\n" + "\n".join(code.rstrip("\n") for _, code in taken) + "\n"
    else:
        for index, (donor_name, code) in enumerate(taken):
            suffix = donor_name[donor_name.rfind(".") :] if "." in donor_name else EXTENSIONS[language]
            out[f"inserted_{index}{suffix}"] = code
    return Result(out, len(taken), {"donor_files": len(taken), "donor_lines": lines, "target_lines": wanted})


# ------------------------------------------------------------------------------------------------ rename


def word_set(text: str) -> frozenset[str]:
    return frozenset(text.split())


C_NAMES = word_set(
    """main argc argv printf scanf fprintf fscanf sprintf snprintf sscanf puts gets fgets fputs getchar putchar putc getc
    fopen fclose fread fwrite fflush malloc calloc realloc free exit abort atexit abs labs llabs fabs sqrt cbrt pow exp log
    log2 log10 sin cos tan asin acos atan atan2 sinh cosh tanh floor ceil round trunc fmod hypot memset memcpy memmove memcmp
    memchr strlen strcpy strncpy strcat strncat strcmp strncmp strchr strrchr strstr strtok strdup atoi atol atoll atof
    strtol strtoll strtoul strtod qsort bsearch rand srand time clock difftime isalpha isdigit isalnum isspace isupper islower
    toupper tolower stdin stdout stderr NULL EOF RAND_MAX INT_MAX INT_MIN LLONG_MAX LLONG_MIN UINT_MAX DBL_MAX FLT_MAX
    size_t ssize_t int8_t int16_t int32_t int64_t uint8_t uint16_t uint32_t uint64_t bool true false assert errno
    setjmp longjmp va_start va_end va_arg swap min max"""
)
CPP_NAMES = C_NAMES | word_set(
    """std cin cout cerr clog endl ends flush ios ios_base string wstring vector list deque queue stack map set multimap
    multiset unordered_map unordered_set priority_queue pair make_pair tuple make_tuple tie get array bitset begin end rbegin
    rend size empty push_back pop_back push pop front back top insert erase find count lower_bound upper_bound sort stable_sort
    reverse unique accumulate iota fill copy move forward getline stoi stol stoll stod to_string setw setprecision fixed
    ceil floor numeric_limits nullptr this new delete sizeof template typename class struct namespace using auto decltype
    cin_tie sync_with_stdio gcd lcm"""
)
JS_NAMES = word_set(
    """main undefined NaN Infinity arguments globalThis window document console require module exports process Buffer Math Object
    Array String Number Boolean Symbol BigInt JSON Promise Date RegExp Error TypeError RangeError SyntaxError Map Set WeakMap
    WeakSet Reflect Proxy Intl parseInt parseFloat isNaN isFinite setTimeout setInterval clearTimeout clearInterval
    setImmediate queueMicrotask encodeURIComponent decodeURIComponent encodeURI decodeURI escape unescape eval fetch
    Uint8Array Int8Array Uint16Array Int16Array Uint32Array Int32Array Float32Array Float64Array ArrayBuffer DataView
    TextEncoder TextDecoder URL URLSearchParams AbortController async await of let var const static get set from as
    constructor prototype"""
)
PYTHON_NAMES = frozenset(dir(builtins)) | frozenset(keyword.kwlist) | {"main", "self", "cls", "__name__", "__file__"}
STOP_NAMES = {"python": PYTHON_NAMES, "c": C_NAMES, "cpp": CPP_NAMES, "javascript": JS_NAMES}

PYTHON_PATTERNS = {"pattern_list", "tuple_pattern", "list_pattern", "list_splat_pattern", "expression_list", "tuple"}
C_DECLARATORS = {
    "pointer_declarator",
    "array_declarator",
    "reference_declarator",
    "init_declarator",
    "function_declarator",
    "parenthesized_declarator",
    "attributed_declarator",
}
JS_PATTERNS = {"object_pattern", "array_pattern", "rest_pattern", "assignment_pattern", "object_assignment_pattern"}


def in_class_body(node) -> bool:
    """Whether a statement is directly in the body of a class (its names are class attributes)."""
    statement = node.parent
    block = statement.parent if statement is not None else None
    owner = block.parent if block is not None and block.type == "block" else None
    return owner is not None and owner.type == "class_definition"


def python_names(root) -> tuple[set[str], set[str], list]:
    """(declared names, names never renamed, variable-position identifier nodes) of a Python file."""
    declared: set[str] = set()
    protected: set[str] = set()
    sites = []

    def collect(node):
        if node is None:
            return
        if node.type == "identifier":
            declared.add(node.text.decode())
        elif node.type in PYTHON_PATTERNS or node.type in ("as_pattern_target", "parenthesized_expression"):
            for child in node.named_children:
                collect(child)

    def parameter(node):
        if node.type == "identifier":
            declared.add(node.text.decode())
        elif node.type in ("default_parameter", "typed_default_parameter"):
            collect(node.child_by_field_name("name"))
        elif node.type in ("typed_parameter", "list_splat_pattern", "dictionary_splat_pattern", "tuple_pattern"):
            for child in node.named_children[:1] if node.type == "typed_parameter" else node.named_children:
                parameter(child)

    for node in walk(root):
        kind, parent = node.type, node.parent
        if kind in ("assignment", "augmented_assignment") and in_class_body(node):
            pass  # class attributes are members
        elif kind in ("assignment", "augmented_assignment", "for_statement", "for_in_clause"):
            collect(node.child_by_field_name("left"))
        elif kind == "named_expression":
            collect(node.child_by_field_name("name"))
        elif kind in ("parameters", "lambda_parameters"):
            for child in node.named_children:
                parameter(child)
        elif kind == "as_pattern":
            for child in node.named_children:
                if child.type == "as_pattern_target":
                    collect(child)
        if kind != "identifier" or parent is None:
            continue
        text, parent_kind = node.text.decode(), parent.type
        if (
            (parent_kind == "attribute" and field_is(parent, "attribute", node))
            or (parent_kind == "keyword_argument" and field_is(parent, "name", node))
            or parent_kind in ("global_statement", "nonlocal_statement")
        ):
            if parent_kind in ("global_statement", "nonlocal_statement"):
                protected.add(text)
            continue
        if any(
            a.type in ("import_statement", "import_from_statement", "future_import_statement") for a in ancestors(node)
        ):
            protected.add(text)
            continue
        if parent_kind == "class_definition" and field_is(parent, "name", node):
            protected.add(text)
            continue
        if parent_kind == "function_definition" and field_is(parent, "name", node):
            owner = parent.parent.parent if parent.parent is not None and parent.parent.type == "block" else None
            if owner is not None and owner.type == "class_definition":
                protected.add(text)  # a method: member names are not renamed
                continue
            declared.add(text)
        sites.append(node)
    return declared, protected, sites


def declarator_name(node, leaf: str = "identifier"):
    """The `leaf` node a C/C++ declarator declares, or None (qualified or operator names are not variables)."""
    while node is not None:
        if node.type == leaf:
            return node
        if node.type not in C_DECLARATORS:
            return None
        inner = node.child_by_field_name("declarator")
        if inner is None:
            inner = next((c for c in reversed(node.named_children) if c.type in C_DECLARATORS | {leaf}), None)
        node = inner
    return None


SCOPES = ("namespace_definition", "class_specifier", "struct_specifier", "union_specifier")


def c_names(root, language: str = "c") -> tuple[set[str], set[str], list]:
    """Declarations of a C/C++ file. Functions inside a namespace or class (reached by qualified names) and, in C++,
    the data members of classes (used without a qualifier inside methods) are not renamed."""
    declared: set[str] = set()
    protected: set[str] = set()
    sites = []
    for node in walk(root):
        kind = node.type
        if kind == "function_definition" and any(a.type in SCOPES for a in ancestors(node)):
            found = []
        elif kind in (
            "function_definition",
            "parameter_declaration",
            "optional_parameter_declaration",
            "for_range_loop",
        ):
            found = [declarator_name(node.child_by_field_name("declarator"))]
        elif kind == "declaration":
            found = [declarator_name(child) for child in node.children_by_field_name("declarator")]
        else:
            found = []
        declared.update(name.text.decode() for name in found if name is not None)
        if kind == "field_declaration" and language == "cpp":
            for child in node.children_by_field_name("declarator"):
                member = declarator_name(child, "field_identifier")
                if member is not None:
                    protected.add(member.text.decode())
        if kind != "identifier" or node.parent is None:
            continue
        if node.parent.type in ("qualified_identifier", "using_declaration", "namespace_alias_definition") or any(
            a.type.startswith("preproc") for a in ancestors(node)
        ):
            continue
        sites.append(node)
    return declared, protected, sites


def js_names(root) -> tuple[set[str], set[str], list]:
    declared: set[str] = set()
    protected: set[str] = set()
    sites = []

    def collect(node):
        if node is None:
            return
        if node.type in ("identifier", "shorthand_property_identifier_pattern"):
            declared.add(node.text.decode())
        elif node.type == "pair_pattern":
            collect(node.child_by_field_name("value"))
        elif node.type in ("assignment_pattern", "object_assignment_pattern"):
            collect(node.child_by_field_name("left"))
        elif node.type in JS_PATTERNS:
            for child in node.named_children:
                collect(child)

    for node in walk(root):
        kind = node.type
        if kind == "variable_declarator":
            collect(node.child_by_field_name("name"))
        elif kind == "formal_parameters":
            for child in node.named_children:
                collect(child)
        elif kind == "arrow_function":
            collect(node.child_by_field_name("parameter"))
        elif kind in ("function_declaration", "generator_function_declaration"):
            collect(node.child_by_field_name("name"))
        elif kind == "catch_clause":
            collect(node.child_by_field_name("parameter"))
        elif kind == "for_in_statement" and node.child_by_field_name("kind") is not None:
            collect(node.child_by_field_name("left"))
        if kind in ("identifier", "shorthand_property_identifier", "shorthand_property_identifier_pattern"):
            if any(a.type in ("import_statement", "export_clause") for a in ancestors(node)):
                protected.add(node.text.decode())
                continue
            sites.append(node)
    return declared, protected, sites


NAME_ANALYSIS = {
    "python": python_names,
    "c": c_names,
    "cpp": lambda root: c_names(root, "cpp"),
    "javascript": js_names,
}


def rename(transformer, language: str, files: dict[str, str], rng: random.Random) -> Result:
    """Consistently rename the names each file declares (locals, parameters, functions, module-level variables) to fresh
    names, at every variable-position identifier of the file. One mapping serves the whole project, so a name shared
    by two files gets the same new name; names of imports, members, methods, classes, keyword arguments, the
    language's built-ins and library names, and `main` are left alone (choice: a name-level bijection, not a scope
    resolver, so two declarations of one name in different scopes are renamed together)."""
    stop = STOP_NAMES[language]
    analysed = {}
    taken: set[str] = set()
    for name, code in files.items():
        root = tree_of(transformer, code)
        analysed[name] = (code.encode("utf-8"), *NAME_ANALYSIS[language](root))
        taken.update(re.findall(r"[A-Za-z_$][\w$]*", code))
    mapping: dict[str, str] = {}

    def fresh(old: str) -> str:
        if old not in mapping:
            while True:
                new = ("v_" if old[:1].islower() or old[:1] == "_" else "V_") + f"{rng.randrange(16**6):06x}"
                if new not in taken:
                    break
            taken.add(new)
            mapping[old] = new
        return mapping[old]

    out, edits_made = {}, 0
    for name in sorted(files):
        data, declared, protected, sites = analysed[name]
        targets = {n for n in declared - protected if n not in stop and not n.startswith("__")}
        edits = []
        for node in sites:
            text = node.text.decode()
            if text not in targets:
                continue
            new = fresh(text)
            if node.type.startswith("shorthand_property_identifier"):
                new = f"{text}: {new}"
            edits.append((node.start_byte, node.end_byte, new.encode("utf-8")))
        out[name] = apply_edits(data, edits).decode("utf-8")
        edits_made += len(edits)
    return Result(out, len({*mapping}), {"names": len(mapping), "occurrences": edits_made})


# ------------------------------------------------------------------------------------------------ reformat

INDENT = "    "
STRING_TYPES = {"string", "string_literal", "raw_string_literal", "template_string", "concatenated_string"}
BLOCKS = {
    "c": {"compound_statement", "field_declaration_list", "initializer_list", "enumerator_list"},
    "javascript": {"statement_block", "class_body", "object", "object_pattern", "switch_body", "array"},
}
BLOCKS["cpp"] = BLOCKS["c"] | {"declaration_list"}
BINARY = {
    "binary_expression",
    "assignment_expression",
    "augmented_assignment_expression",
    "init_declarator",
    "variable_declarator",
    "assignment_pattern",
    "conditional_expression",
    "ternary_expression",
}
OPERATORS = {"=", "+", "-", "*", "/", "%", "&", "|", "^", "<<", ">>", "&&", "||", "==", "!=", "<", ">", "<=", ">="}
OPERATORS |= {"+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=", "===", "!==", "??", "?", ":", "**", "=>"}
CLOSERS = {")", "]", "}"}


def strip_comments(transformer, code: str) -> str:
    data = code.encode("utf-8")
    edits = []
    for node in walk(tree_of(transformer, code)):
        if node.type != "comment":
            continue
        start, end = node.start_byte, node.end_byte
        before, after = data[start - 1 : start], data[end : end + 1]
        glued = start > 0 and before not in (b" ", b"\t", b"\n") and after not in (b"", b" ", b"\t", b"\n", b"\r")
        edits.append((start, end, b" " if glued else b""))
    return apply_edits(data, edits).decode("utf-8")


def string_interiors(transformer, code: str) -> list[tuple[int, int]]:
    """Byte ranges of strings that span several lines: their line breaks and blanks are content."""
    return [
        (node.start_byte, node.end_byte)
        for node in walk(tree_of(transformer, code))
        if node.type in STRING_TYPES and node.start_point[0] != node.end_point[0]
    ]


def tidy_lines(transformer, code: str) -> str:
    """Trailing blanks and empty lines removed outside multi-line strings."""
    data = code.encode("utf-8")
    inside = string_interiors(transformer, code)
    protected = lambda position: any(start < position < end for start, end in inside)
    kept, position = [], 0
    for line in data.split(b"\n"):
        start, end = position, position + len(line)
        position = end + 1
        if not protected(start) and not line.strip():
            continue
        kept.append(line if protected(end) else line.rstrip())
    result = b"\n".join(kept)
    if data.endswith(b"\n") or not result:
        result += b"\n"
    return result.decode("utf-8")


def style_edits(transformer, language: str, code: str) -> bytes:
    """One indentation scheme (four spaces per enclosing block) and single spaces around operators and after commas."""
    data = code.encode("utf-8")
    root = tree_of(transformer, code)
    edits: dict[tuple[int, int], bytes] = {}
    blocks = BLOCKS[language]
    inside = string_interiors(transformer, code)

    def gap(start: int, end: int, text: bytes):
        between = data[start:end]
        if b"\n" not in between and not between.strip():
            edits[(start, end)] = text

    position = 0
    for line in data.split(b"\n"):
        start, position = position, position + len(line) + 1
        first = start + (len(line) - len(line.lstrip()))
        if first >= start + len(line) or any(a < start < b for a, b in inside):
            continue
        leaf = root.descendant_for_byte_range(first, first + 1)
        chain = [leaf, *ancestors(leaf)]
        if line.lstrip().startswith(b"#") or any(n.type.startswith("preproc") for n in chain):
            continue
        row = leaf.start_point[0]
        depth = 0
        for ancestor in chain[1:]:
            if ancestor.type not in blocks or ancestor.start_point[0] >= row:
                continue
            closer = ancestor.children[-1] if ancestor.children else None
            if closer is not None and closer.start_byte == first and closer.type in CLOSERS:
                continue
            depth += 1
        edits[(start, first)] = (INDENT * depth).encode()
    for node in walk(root):
        if node.type in BINARY:
            for index, child in enumerate(node.children):
                if child.type in OPERATORS and child.child_count == 0 and 0 < index < len(node.children) - 1:
                    left, right = node.children[index - 1], node.children[index + 1]
                    gap(left.end_byte, child.start_byte, b" ")
                    gap(child.end_byte, right.start_byte, b" ")
        elif node.type == "," and node.next_sibling is not None and node.next_sibling.type not in CLOSERS:
            if node.prev_sibling is not None:
                gap(node.prev_sibling.end_byte, node.start_byte, b"")
            gap(node.end_byte, node.next_sibling.start_byte, b" ")
    return apply_edits(data, [(start, end, text) for (start, end), text in edits.items()])


def reformat(transformer, language: str, files: dict[str, str]) -> Result:
    """Remove comments and empty lines; C/C++/JavaScript additionally get one indentation scheme and operator spacing
    (Python: comments and empty lines only, as its layout is syntax)."""
    out, changed = {}, 0
    for name in sorted(files):
        code = tidy_lines(transformer, strip_comments(transformer, files[name]))
        if language != "python":
            code = style_edits(transformer, language, code).decode("utf-8")
        out[name] = code
        changed += code != files[name]
    return Result(out, changed, {"files_changed": changed})
