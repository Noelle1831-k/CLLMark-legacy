def tuple_to_dict(test_tup):
    return {test_tup[i]: test_tup[i + 1] for i in range(0, len(test_tup), 2)}