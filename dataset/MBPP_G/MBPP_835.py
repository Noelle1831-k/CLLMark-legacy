def slope(x1, y1, x2, y2):
    if x1 == x2:
        raise ValueError('Slope is undefined for vertical lines.')
    return (y2 - y1) / (x2 - x1)