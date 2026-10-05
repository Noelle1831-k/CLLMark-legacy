def sumofFactors(n):
    total = 0
    for i in range(2, n + 1, 2):
        if n % i == 0:
            total += i
    return total