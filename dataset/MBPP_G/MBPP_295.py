def sum_div(number):
    return sum((i for i in range(1, number) if number % i == 0))