def permute_string(s):
    from itertools import permutations
    return [''.join(p) for p in permutations(s)]