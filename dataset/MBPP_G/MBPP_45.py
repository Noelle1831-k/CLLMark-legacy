def get_gcd(l):
    from math import gcd
    from functools import reduce
    return reduce(gcd, l)