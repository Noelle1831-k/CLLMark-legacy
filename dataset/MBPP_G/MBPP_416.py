def breakSum(n):
    if n == 0:
        return 0
    return max(n, breakSum(n // 2) + breakSum(n // 3) + breakSum(n // 4))