def zip_tuples(test_tup1, test_tup2):
    result = []
    min_length = min(len(test_tup1), len(test_tup2))
    extended_tup2 = (test_tup2 * (len(test_tup1) // len(test_tup2) + 1))[0:len(test_tup1)]
    for i in range(len(test_tup1)):
        result.append((test_tup1[i], extended_tup2[i]))
    return result