def sum_of_square(n):
    from math import comb
    return sum((comb(n, k) ** 2 for k in range(n + 1)))