def polar_rect(x, y):
    import math
    r = math.sqrt(x ** 2 + y ** 2)
    theta = math.atan2(y, x)
    rect_coordinates = complex(x, y)
    return ((r, theta), rect_coordinates)