def index_multiplication(test_tup1, test_tup2):
    return tuple(((a * c, b * d) for (a, b), (c, d) in zip(test_tup1, test_tup2)))