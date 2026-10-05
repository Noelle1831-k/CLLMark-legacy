def find_dissimilar(test_tup1, test_tup2):
    return tuple(sorted(set(test_tup1).symmetric_difference(test_tup2)))