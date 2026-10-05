def trim_tuple(test_list, K):
    return [tuple(tup[K:len(tup)-K] if K < len(tup) // 2 else tup[K:len(tup) - K]) for tup in test_list]