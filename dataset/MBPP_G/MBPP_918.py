def coin_change(S, m, n):
    if n == 0:
        return 1
    if n < 0 or m <= 0:
        return 0
    return coin_change(S, m - 1, n) + coin_change(S, m, n - S[m - 1])