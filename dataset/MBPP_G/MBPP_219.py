def extract_min_max(test_tup, K):
    sorted_tup = sorted(test_tup)
    min_k_elements = sorted_tup[0:K]
    max_k_elements = sorted_tup[-K:]
    return tuple(min_k_elements + max_k_elements)