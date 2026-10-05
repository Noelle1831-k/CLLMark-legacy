def rencontres_number(n, m):
    if m > n:
        return 0
    if n == 0 and m == 0:
        return 1
    if n == 1 and m == 0:
        return 0
    if n == 1 and m == 1:
        return 1
    return (n - 1) * (rencontres_number(n - 1, m) + rencontres_number(n - 2, m - 1))