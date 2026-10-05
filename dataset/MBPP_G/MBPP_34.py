def find_missing(ar, N):
    total = (N + 1) * (N + 2) // 2
    return total - sum(ar)