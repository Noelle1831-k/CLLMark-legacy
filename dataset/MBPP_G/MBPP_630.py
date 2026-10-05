def get_coordinates(test_tup):
    x, y = test_tup
    return [[i, j] for i in range(x - 1, x + 2) for j in range(y - 1, y + 2)]