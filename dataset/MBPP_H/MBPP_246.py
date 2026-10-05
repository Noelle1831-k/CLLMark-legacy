def babylonian_squareroot(number):
    if (number == 0):
        return 0
    g = number / 2.0
    g2 = 0
    while (abs(g - g2) > 1e-10):
        n = number / g
        g2 = g
        g = (g + n) / 2
    return g