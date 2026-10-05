def areEquivalent(num1, num2):

    def sum_of_divisors(n):
        return sum((i for i in range(1, n + 1) if n % i == 0))
    return sum_of_divisors(num1) == sum_of_divisors(num2)