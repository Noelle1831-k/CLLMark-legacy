def find_tuples(test_list, K):
    return [tup for tup in test_list if all((ele % K == 0 for ele in tup))]