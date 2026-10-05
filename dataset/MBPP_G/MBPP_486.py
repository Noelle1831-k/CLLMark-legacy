def binomial_probability(n, k, p):
    from math import comb, pow
    return comb(n, k) * pow(p, k) * pow(1 - p, n - k)