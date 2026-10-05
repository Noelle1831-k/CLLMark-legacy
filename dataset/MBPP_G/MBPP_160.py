def solution(a, b, n):

    def gcd_extended(a, b):
        if a == 0:
            return (b, 0, 1)
        gcd, x1, y1 = gcd_extended(b % a, a)
        x = y1 - b // a * x1
        y = x1
        return (gcd, x, y)
    gcd, x, y = gcd_extended(a, b)
    if n % gcd != 0:
        return 'No solution'
    x *= n // gcd
    y *= n // gcd
    return ('x = ', x, ', y = ', y)