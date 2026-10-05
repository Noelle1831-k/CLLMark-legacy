def is_Perfect_Square(n):
    i = 1
    while (i * i <= n):
        if (i * i == n):
            return True
        i = i + 1
    return False