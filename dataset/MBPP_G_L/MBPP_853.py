def sum_of_odd_Factors(n):
    total = 0
    for i in range(1, n + 1, 2):
        if n % i == 0:
            total += i
    return total