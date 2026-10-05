def check_abundant(n):
    divisors_sum = sum((i for i in range(1, n) if n % i == 0))
    return divisors_sum > n