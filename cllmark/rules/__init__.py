"""Style rules per language, the rule engine they are written in, and the watermark rule pairs.

`styles.json` is the style catalog: language -> style id -> [category, name]. Each language module exposes `RULES`,
mapping every style id of its catalog entry to a `Rule`.
"""

from pathlib import Path

STYLES_PATH = Path(__file__).resolve().parent / "styles.json"
