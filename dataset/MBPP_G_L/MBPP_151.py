def is_coprime(x, y):
    def gcd(a, b):
        while b:
            a, b = (b, a % b)
        return a
    return gcd(x, y) == 1