def answer(L, R):
    from math import gcd

    def lcm(x, y):
        return abs(x * y) // gcd(x, y)
    for x in range(L, R + 1):
        for y in range(x + 1, R + 1):
            if L <= lcm(x, y) <= R:
                return (x, y)
    return None