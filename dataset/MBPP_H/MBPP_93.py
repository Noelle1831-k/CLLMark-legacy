def power(a, b):
    if b == 0:
        return 1
    elif b == 1:
        return a
    elif a == 0 and b > 0:
        return 0
    else:
        return a * power(a, b - 1)