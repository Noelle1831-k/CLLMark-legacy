def count_binary_seq(n):
    import math
    return math.comb(2 * n, n) / (n + 1)