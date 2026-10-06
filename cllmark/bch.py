"""Systematic BCH(7,4,1) (the Hamming code) over GF(2) with generator g(x) = x^3 + x + 1.

A 4-bit message m becomes the 7-bit codeword m·x^3 + (m·x^3 mod g); decoding corrects a single bit error by
syndrome lookup and returns the message bits. Bits are most significant first.
"""

from __future__ import annotations

from collections.abc import Sequence

GENERATOR = 0b1011
CODE_LENGTH, MESSAGE_LENGTH = 7, 4


def remainder(dividend: int, divisor: int = GENERATOR) -> int:
    """Polynomial remainder over GF(2) (integers as coefficient bit vectors)."""
    degree = divisor.bit_length() - 1
    while dividend and dividend.bit_length() - 1 >= degree:
        dividend ^= divisor << (dividend.bit_length() - 1 - degree)
    return dividend


# Syndrome -> error pattern for every single-bit error (the error-free syndrome 0 needs no correction).
SYNDROMES = {remainder(1 << position): 1 << position for position in range(CODE_LENGTH)}


def encode(message: Sequence[int]) -> list[int]:
    """The 7-bit codeword of a 4-bit message."""
    value = 0
    for bit in message:
        value = (value << 1) | (bit & 1)
    shifted = value << (CODE_LENGTH - MESSAGE_LENGTH)
    codeword = shifted ^ remainder(shifted)
    return [(codeword >> position) & 1 for position in range(CODE_LENGTH - 1, -1, -1)]


def decode(received: Sequence[int]) -> list[int]:
    """The message bits of `received` after correcting at most one bit error.

    Received words of other lengths are read as integers in the same way, so a short extraction decodes to
    whatever its bits imply rather than failing.
    """
    value = 0
    for bit in received:
        value = (value << 1) | bit
    value ^= SYNDROMES.get(remainder(value), 0)
    return [(value >> position) & 1 for position in range(CODE_LENGTH - 1, CODE_LENGTH - MESSAGE_LENGTH - 1, -1)]
