def count_Rectangles(radius):
    rectangles = 0
    diameter = 2 * radius
    diameterSquare = diameter * diameter
    for a in range(1, diameter):
        for b in range(1, diameter):
            diagonalLengthSquare = (a * a + b * b)
            if (diagonalLengthSquare <= diameterSquare):
                rectangles += 1
    return rectangles