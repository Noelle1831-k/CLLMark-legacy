def sum_difference(n):
    sum_of_numbers = n * (n + 1) // 2
    squared_sum = sum_of_numbers ** 2
    sum_of_squares = sum((i ** 2 for i in range(1, n + 1)))
    return squared_sum - sum_of_squares