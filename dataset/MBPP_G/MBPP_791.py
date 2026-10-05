def remove_nested(test_tup):
    return tuple((x for x in test_tup if not isinstance(x, tuple)))