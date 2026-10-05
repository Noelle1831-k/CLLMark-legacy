def trim_tuple(test_list, K):
    res = []
    for ele in test_list:
        N = len(ele)
        if 2 * K < N:
            res.append(tuple(list(ele)[K: N - K]))
        else:
            res.append(())
    return res