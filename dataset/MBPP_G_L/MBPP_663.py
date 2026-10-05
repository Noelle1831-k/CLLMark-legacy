def find_max_val(n, x, y):
    if y >= x:
        return -1
    max_k = n // x * x + y
    if max_k > n:
        max_k -= x
    return max_k