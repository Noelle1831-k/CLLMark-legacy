def find_k_product(test_list, K):
    result = 1
    for tup in test_list:
        result *= tup[K]
    return result