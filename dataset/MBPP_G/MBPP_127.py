def multiply_int(x, y):
    result = 0
    negative = False
    if x < 0 and y < 0:
        x = -x
        y = -y
    elif x < 0:
        x = -x
        negative = True
    elif y < 0:
        y = -y
        negative = True
    for _ in range(y):
        result += x
    if negative:
        result = -result
    return result