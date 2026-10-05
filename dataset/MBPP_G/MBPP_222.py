def check_type(test_tuple):
    return len(set((type(elem) for elem in test_tuple))) == 1