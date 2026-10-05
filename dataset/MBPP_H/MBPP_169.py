def get_pell(n):
    if (n <= 1):
        return n
    a = 1
    b = 2
    for i in range(3, n + 1):
        c = 2 * b + a
        a = b
        b = c
    return b if n > 1 else 1