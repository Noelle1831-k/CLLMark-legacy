def remove_tuple(test_list):
    return str([t for t in test_list if not all((e is None for e in t))])