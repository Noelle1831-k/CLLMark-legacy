def multiply_elements(test_tup):
    return tuple((test_tup[i] * test_tup[i + 1] for i in range(len(test_tup) - 1)))