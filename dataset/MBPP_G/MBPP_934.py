def dealnnoy_num(n, m):
    if n == 0 or m == 0:
        return 1
    return dealnnoy_num(n - 1, m) + dealnnoy_num(n, m - 1) + dealnnoy_num(n - 1, m - 1)