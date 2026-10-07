"""Synthetic projects for the robust-watermark tests: many functions with distinct names and literals, so every
site has its own anchor key, built from constructs the rule pairs rewrite. Not a test module."""

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TOOLCHAIN = ROOT / ".benchmark-cache" / "toolchain"
LANGUAGES = ("python", "c", "cpp", "javascript")
HAS_GRAMMARS = all((TOOLCHAIN / f"{language}-languages.so").exists() for language in LANGUAGES)

HEADERS = {
    "javascript": "",
    "python": "",
    "c": "#include <stdio.h>\n",
    "cpp": "#include <iostream>\nusing namespace std;\n",
}
FUNCTION_START = {"javascript": r"function f", "python": r"def f", "c": r"int f", "cpp": r"int f"}


def function(language: str, i: int) -> str:
    if language == "javascript":
        return f"""function f{i}(a{i}, b{i}) {{
  let x{i} = a{i};
  x{i} = x{i} + b{i};
  if (a{i} === {i + 1}) {{ x{i} += 1; }}
  const o{i} = {{p: x{i}}};
  for (let k{i} = 0; k{i} < b{i}; k{i}++) {{ x{i} = x{i} * {i + 2}; }}
  return o{i}.p > {i};
}}
"""
    if language == "python":
        return f"""def f{i}(a{i}, b{i}):
    x{i} = a{i}
    x{i} += b{i}
    if a{i} == {i + 1}:
        print(x{i}, end="")
    for k{i} in b{i}:
        x{i} = x{i} * {i + 2}
    if x{i} not in b{i}:
        x{i} = x{i} if x{i} > {i} else b{i}
    return x{i} != {i + 3}
"""
    return f"""int f{i}(int a{i}, int b{i}) {{
    int x{i} = a{i};
    x{i} += b{i};
    if (a{i} == {i + 1}) {{ x{i} = x{i} - 1; }}
    for (int k{i} = 0; k{i} < b{i}; k{i}++) {{ x{i} = x{i} * {i + 2}; }}
    return x{i} > {i} ? a{i} : b{i};
}}
"""


def project(language: str, count: int, start: int = 0) -> str:
    return HEADERS[language] + "".join(function(language, i) for i in range(start, start + count))


def split(language: str, code: str) -> tuple[str, list[str]]:
    """The text before the first generated function, and the functions."""
    parts = re.split(rf"(?m)^(?={FUNCTION_START[language]}\d)", code)
    return parts[0], parts[1:]


def join(header: str, functions: list[str]) -> str:
    return header + "".join(functions)
