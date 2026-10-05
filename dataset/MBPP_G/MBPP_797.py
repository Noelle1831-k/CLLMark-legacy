def sum_in_Range(l, r):
    return sum((i for i in range(l, r + 1) if i % 2 != 0))