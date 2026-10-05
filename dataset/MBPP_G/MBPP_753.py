def min_k(test_list, K):
    return sorted(test_list, key=lambda x: x[1])[0:K]