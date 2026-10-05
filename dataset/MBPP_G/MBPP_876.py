def lcm(x, y):
    from math import gcd
    return x * y // gcd(x, y)