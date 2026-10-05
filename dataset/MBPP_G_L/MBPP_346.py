def zigzag(n, k):
    if n == 0 and k == 0:
        return 1
    elif k < 0 or k > n:
        return 0
    return zigzag(n - 1, k - 1) + zigzag(n - 1, n - k)