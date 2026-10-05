def first_Factorial_Divisible_Number(x):
    n = 1
    factorial = 1
    while True:
        factorial *= n
        if factorial % x == 0:
            return n
        n += 1