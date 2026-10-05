"""SCTS: style transformations of source code, backed by the declarative rule engine.

A style id from styleList.json (e.g. "7.3") names one rule in the language's rule module
(python/rules.py, c/rules.py, cpp/rules.py). The language's rules share one parser and one
compiled query; parse results are cached per code version, so probing many styles on the
same file parses and matches it once.
"""

from functools import lru_cache
import importlib
from pathlib import Path
import subprocess
from typing import Dict, List, Tuple, Union

from rule_engine import Grammar, text

ROOT = Path(__file__).resolve().parent
LANGUAGES = ['python', 'c', 'cpp', 'javascript']


def library_path(language: str) -> str:
    """The compiled grammar: ./build (frozen benchmark copies) or the pinned toolchain build."""
    for candidate in [Path('build') / f'{language}-languages.so',
                      ROOT / '.benchmark-cache' / 'toolchain' / f'{language}-languages.so']:
        if candidate.exists():
            return str(candidate.resolve())
    raise FileNotFoundError(f'No {language} grammar library; build the pinned grammars with python3 tools/setup_benchmark.py')


@lru_cache(maxsize=None)
def load_rules(language: str):
    if language not in LANGUAGES:
        raise NotImplementedError(language)
    return importlib.import_module(f'{language}.rules')


@lru_cache(maxsize=None)
def load_grammar(library: str, language: str) -> Grammar:
    module = load_rules(language)
    matchers = [module.FUNCTION] + [matcher for rule in module.RULES.values() for matcher in [rule, rule.target] if matcher]
    return Grammar(library, language, matchers)


class SCTS:
    def __init__(self, language: str):
        self.language = language
        self.module = load_rules(language)
        self.rules = self.module.RULES
        self.grammar = load_grammar(library_path(language), language)
        self.parser = self.grammar.parser

    def parse(self, code: str):
        return self.grammar.parse(code).tree

    def change_file_style(self, style_choice: Union[str, List[str]], code: str, format: bool = False) -> Tuple[str, bool, int]:
        """Apply one style (or several, in order). Returns (code, changed beyond whitespace, candidates)."""
        styles = style_choice if isinstance(style_choice, list) else [style_choice]
        new_code, candidates = code, 0
        for style in styles:
            new_code, count = self.grammar.parse(new_code).rewrite(self.rules[style])
            candidates += count
        changed = code.replace(' ', '').replace('\n', '') != new_code.replace(' ', '').replace('\n', '')
        return new_code, changed, candidates

    def get_file_popularity(self, style: str, code: str) -> int:
        """Number of nodes already in the form produced by `style` (styles 7.7 / 7.8 of C and C++)."""
        target = self.rules[style].target
        if target is None:
            raise ValueError(f'{self.language} style {style} has no target-form matcher')
        return len(self.grammar.parse(code).candidates(target))

    def get_func_block(self, style_choice: Union[str, List[str]], code: str, format: bool = False) -> Dict[str, str]:
        """{function name: source} for top-level functions; repeated names get _1, _2, ... suffixes."""
        functions = {}
        for node in self.grammar.parse(code).candidates(self.module.FUNCTION):
            name = self.module.function_name(node)
            key, suffix = name, 1
            while key in functions:
                key, suffix = f'{name}_{suffix}', suffix + 1
            functions[key] = text(node)
        return functions

    def see_tree(self, code: str, view: bool = True) -> None:
        from graphviz import Digraph
        dot = Digraph(comment='AST Tree')
        stack = [self.parse(code).root_node]
        while stack:
            node = stack.pop()
            name = f'{node.type}{node.start_byte},{node.end_byte}'.replace(':', 'colon')
            dot.node(name, shape='rectangle', label=node.type)
            if node.parent is not None:
                dot.edge(f'{node.parent.type}{node.parent.start_byte},{node.parent.end_byte}'.replace(':', 'colon'), name)
            if not node.child_count and text(node) != node.type:
                dot.node(name + 'leaf', shape='ellipse', label=text(node))
                dot.edge(name, name + 'leaf')
            stack.extend(node.children)
        dot.render('ast_tree', view=view)

    def tokenize(self, code: str) -> List[str]:
        tokens, stack = [], [self.parse(code).root_node]
        while stack:
            node = stack.pop()
            if node.children:
                stack.extend(reversed(node.children))
            else:
                tokens.append(text(node))
        return tokens

    def check_syntax(self, code: str) -> bool:
        return not self.parse(code).root_node.has_error

    def format(self, code: str) -> str:
        command = ['clang-format', '-style={IndentWidth: 4}', '-'] if self.language in ['c', 'cpp'] else ['yapf']
        return subprocess.run(command, input=code, text=True, capture_output=True, check=True).stdout
