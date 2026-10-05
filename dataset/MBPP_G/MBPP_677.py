def validity_triangle(a, b, c):
    return a + b + c == 180 and all((x > 0 for x in [a, b, c]))