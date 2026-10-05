def parabola_focus(a, b, c):
    h = -b / (2 * a)
    k = (4 * a * c - b ** 2 + 1) / (4 * a)
    return (h, k)