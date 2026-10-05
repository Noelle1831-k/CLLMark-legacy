def sum_Square(n):
    if n < 0:
        return False
    for i in range(int(n ** 0.5) + 1):
        j = n - i * i
        if j == int(j ** 0.5) ** 2:
            return True
    return False