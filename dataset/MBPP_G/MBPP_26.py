def check_k_elements(test_list, K):
    return all((len(tup) == K for tup in test_list)) if test_list else False