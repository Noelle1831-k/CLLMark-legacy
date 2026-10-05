import math

def first_Digit(n):
    fact = math.factorial(n)
    while fact >= 10:
        fact //= 10
    return fact