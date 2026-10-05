def max_Prime_Factors(n):

    def is_prime(num):
        if num < 2:
            return False
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                return False
        return True
    largest_prime = 1
    divisor = 2
    while divisor <= n:
        if n % divisor == 0 and is_prime(divisor):
            largest_prime = divisor
            n //= divisor
        else:
            divisor += 1
    return largest_prime