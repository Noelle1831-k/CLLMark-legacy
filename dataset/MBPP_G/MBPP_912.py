from math import comb

def lobb_num(n, m):
    return comb(2 * n, n + m) * (m + 1) // (n + m + 1)