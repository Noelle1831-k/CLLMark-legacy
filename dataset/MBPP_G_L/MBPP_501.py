def num_comm_div(x, y):
    from math import gcd
    n = gcd(x, y)
    count = 0
    for i in range(1, n + 1):
        if n % i == 0:
            count += 1
    return count