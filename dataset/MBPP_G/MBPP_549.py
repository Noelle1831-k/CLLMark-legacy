def odd_Num_Sum(n):
    return sum(((2 * i - 1) ** 5 for i in range(1, n + 1)))