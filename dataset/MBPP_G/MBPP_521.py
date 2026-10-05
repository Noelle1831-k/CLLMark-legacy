def check_isosceles(x, y, z):
    if x + y > z and x + z > y and (y + z > x):
        return len(set([x, y, z])) == 2
    return False