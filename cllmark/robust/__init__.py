"""Robust keyed watermark: position-free anchors, whitened keyed targets, blind binomial detection.

The interface other modules depend on: `Scheme`, `Observation`, `observe`, `embed`/`EmbedResult`,
`detect`/`Detection`, `binomial_tail`. Design: docs/plans/2026-10-07-robust-watermark.md.
"""

from .anchors import Observation, observe
from .detect import Detection, binomial_tail, detect
from .embed import EmbedResult, embed
from .keys import Scheme, derive_key, derive_message

__all__ = [
    "Detection",
    "EmbedResult",
    "Observation",
    "Scheme",
    "binomial_tail",
    "derive_key",
    "derive_message",
    "detect",
    "embed",
    "observe",
]
