def Sum(N):

    def is_prime(n):
        if n <= 1:
            return False
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                return False
        return True
    sum_prime_divisors = 0
    for i in range(2, N + 1):
        if N % i == 0 and is_prime(i):
            sum_prime_divisors += i
    return sum_prime_divisors