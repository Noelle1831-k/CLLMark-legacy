def parabola_vertex(a, b, c):
    h = -b / (2 * a)
    k = a * h ** 2 + b * h + c
    return (h, k)