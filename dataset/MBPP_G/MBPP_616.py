def tuple_modulo(test_tup1, test_tup2):
    return tuple((a % b for a, b in zip(test_tup1, test_tup2)))