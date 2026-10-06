"""CLLMark: code watermarking through semantics-preserving style rules.

Typical use on an in-memory project ({file name: source text})::

    from cllmark import StyleTransformer, analyze, embed, extract

    transformer = StyleTransformer("python")
    support = analyze(transformer, "python", files)
    marked = {**files, **embed(transformer, "python", files, support, [1, 0, 1, 0])}
    message_matches, codeword_matches = extract(transformer, "python", marked, support, [1, 0, 1, 0])

`cllmark.directories` offers the same steps on directories, and `python -m cllmark` on the command line.
"""

from .transform import LANGUAGES, StyleTransformer
from .watermark import analyze, embed, extract

__version__ = "0.1.0"
__all__ = ["LANGUAGES", "StyleTransformer", "__version__", "analyze", "embed", "extract"]
