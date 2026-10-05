def sum_gp(a, n, r):
    if r == 1:
        return a * n
    return a * (1 - r ** n) // (1 - r)