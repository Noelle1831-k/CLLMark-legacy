def get_Min_Squares(n):
    if n <= 3:
        return n
    res = n
    x = 1
    while x * x <= n:
        temp = x * x
        res = min(res, 1 + get_Min_Squares(n - temp))
        x += 1
    return res