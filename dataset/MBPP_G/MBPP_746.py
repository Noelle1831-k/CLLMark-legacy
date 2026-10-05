def sector_area(r, a):
    if a >= 360:
        return None
    return a / 360 * (3.141592653589793 * r * r)