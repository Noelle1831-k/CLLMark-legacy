def count_element_freq(test_tuple):
    def flatten(test_tuple):
        for tup in test_tuple:
            if isinstance(tup, tuple):
                yield from flatten(tup)
            else:
                yield tup
    res = {}
    for ele in flatten(test_tuple):
        if ele not in res:
            res[ele] = 0
        res[ele] += 1
    return res