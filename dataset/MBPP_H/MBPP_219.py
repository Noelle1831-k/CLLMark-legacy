def extract_min_max(test_tup, K):
    res = []
    if K > len(test_tup) // 2:
        K = len(test_tup) // 2
    test_tup = list(test_tup)
    temp = sorted(test_tup)
    for idx, val in enumerate(temp):
        if idx < K or idx >= len(temp) - K:
            res.append(val)
    res = tuple(res)
    return (res)