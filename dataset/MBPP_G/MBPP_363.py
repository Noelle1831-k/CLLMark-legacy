def add_K_element(test_list, K):
    return [tuple((ele + K for ele in sub)) for sub in test_list]