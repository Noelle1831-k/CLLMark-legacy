def surfacearea_cone(r, h):
    from math import pi, sqrt
    return pi * r * (r + sqrt(h ** 2 + r ** 2))