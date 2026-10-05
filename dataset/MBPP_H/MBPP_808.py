def check_K(test_tup, K):
    res = 'F'
    for ele in test_tup:
        if ele == K:
            res = 'T'
            break
    return res == 'T'