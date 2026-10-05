def count_first_elements(test_tup):
    for i, elem in enumerate(test_tup):
        if isinstance(elem, tuple):
            return i
    return len(test_tup)