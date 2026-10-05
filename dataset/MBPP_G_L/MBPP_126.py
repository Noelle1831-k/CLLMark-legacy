def sum(a, b):
    def gcd(x, y):
        while y:
            x, y = (y, x % y)
        return x
    common_divisor = gcd(a, b)
    return sum((i for i in range(1, common_divisor + 1) if common_divisor % i == 0))