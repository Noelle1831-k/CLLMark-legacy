from itertools import combinations_with_replacement

def combinations_colors(l, n):
    return tuple(combinations_with_replacement(l, n))