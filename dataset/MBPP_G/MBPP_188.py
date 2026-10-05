def prod_Square(n):
    from math import isqrt
    for i in range(isqrt(n) + 1):
        for j in range(isqrt(n) + 1):
            if i * i * j * j == n:
                return True
    return False