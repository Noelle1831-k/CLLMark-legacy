"""Style transformations of source code, backed by the declarative rule engine.

A style id from `rules/styles.json` (e.g. "7.3") names one rule in the language's rule module
(`cllmark.rules.python`, `.c`, `.cpp`, `.javascript`). All rules of a language share one parser
and one compiled query, and parse results are cached per code version, so probing many styles
on the same file parses and matches it once.
"""

from __future__ import annotations

import importlib
from functools import cache
from pathlib import Path
from types import ModuleType

from .rules.engine import Grammar

LANGUAGES = ("python", "c", "cpp", "javascript")
REPOSITORY = Path(__file__).resolve().parents[1]


def library_path(language: str) -> str:
    """The compiled grammar: `./build` (frozen benchmark copies) first, then the pinned toolchain build."""
    name = f"{language}-languages.so"
    for candidate in (Path("build") / name, REPOSITORY / ".benchmark-cache" / "toolchain" / name):
        if candidate.exists():
            return str(candidate.resolve())
    raise FileNotFoundError(
        f"No {language} grammar library; build the pinned grammars with python3 tools/setup_benchmark.py"
    )


@cache
def load_rules(language: str) -> ModuleType:
    """The rule module of `language`."""
    if language not in LANGUAGES:
        raise NotImplementedError(language)
    return importlib.import_module(f"cllmark.rules.{language}")


@cache
def load_grammar(library: str, language: str) -> Grammar:
    """Parser and compiled query for every rule (and target-form matcher) of `language`."""
    rules = load_rules(language).RULES.values()
    return Grammar(library, language, [matcher for rule in rules for matcher in (rule, rule.target) if matcher])


class StyleTransformer:
    """Applies the style rules of one language to source text."""

    def __init__(self, language: str):
        self.language = language
        self.rules = load_rules(language).RULES
        self.grammar = load_grammar(library_path(language), language)

    def parse(self, code: str):
        """The (cached) tree-sitter tree of `code`."""
        return self.grammar.parse(code).tree

    def apply(self, styles: str | list[str], code: str) -> tuple[str, bool, int]:
        """Apply one style, or several in order.

        Returns the new code, whether it changed beyond spaces and line breaks, and the number of candidate nodes.
        """
        new_code, candidates = code, 0
        for style in [styles] if isinstance(styles, str) else styles:
            new_code, count = self.grammar.parse(new_code).rewrite(self.rules[style])
            candidates += count
        changed = new_code != code and code.replace(" ", "").replace("\n", "") != new_code.replace(" ", "").replace(
            "\n", ""
        )
        return new_code, changed, candidates

    def count_target_form(self, style: str, code: str) -> int:
        """Number of nodes already in the form that `style` produces (detect-only loop styles 7.7/7.8 of C and C++)."""
        target = self.rules[style].target
        if target is None:
            raise ValueError(f"{self.language} style {style} has no target-form matcher")
        return len(self.grammar.parse(code).candidates(target))

    def check_syntax(self, code: str) -> bool:
        """Whether `code` parses without errors."""
        return not self.parse(code).root_node.has_error
