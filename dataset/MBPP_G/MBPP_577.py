def last_Digit_Factorial(n):
    if n >= 5:
        return 0
    factorial = 1
    for i in range(2, n + 1):
        factorial *= i
    return factorial % 10