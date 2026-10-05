def maximize_elements(test_tup1, test_tup2):
    return tuple((max(t1, t2) for t1, t2 in zip(test_tup1, test_tup2)))