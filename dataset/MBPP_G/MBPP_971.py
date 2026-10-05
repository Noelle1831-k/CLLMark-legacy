def maximum_segments(n, a, b, c):
    if n == 0:
        return 0
    if n < 0:
        return -float('inf')
    return max(1 + maximum_segments(n - a, a, b, c), 1 + maximum_segments(n - b, a, b, c), 1 + maximum_segments(n - c, a, b, c))