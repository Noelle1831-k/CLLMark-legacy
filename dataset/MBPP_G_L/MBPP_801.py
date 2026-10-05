def test_three_equal(x, y, z):
    if x == y == z:
        return 3
    elif x == y or y == z or x == z:
        return 2
    else:
        return 0