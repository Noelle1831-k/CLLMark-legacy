def find_k_product(test_list, K):
    def get_product(val):
        res = 1
        for ele in val:
            res *= ele
        return res
    res = get_product([sub[K] for sub in test_list])
    return (res)