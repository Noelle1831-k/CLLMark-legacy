def count_Squares(m, n):
    return sum(((m - i) * (n - i) for i in range(min(m, n)))) + 1