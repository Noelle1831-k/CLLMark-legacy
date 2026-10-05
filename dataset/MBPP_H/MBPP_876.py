def lcm(x, y):
    if x > y:
        z = x
    else:
        z = y
    while True:
        if (z % x == 0) and (z % y == 0):
            lcm_value = z
            break
        z += 1
    return lcm_value