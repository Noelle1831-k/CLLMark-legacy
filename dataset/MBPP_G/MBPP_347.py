def count_Squares(m, n):
    total_squares = 0
    for size in range(1, min(m, n) + 1):
        total_squares += (m - size + 1) * (n - size + 1)
    return total_squares