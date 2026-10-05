def max_run_uppercase(test_str):
    cnt = 0
    res = 0
    for idx in range(0, len(test_str)):
        if test_str[idx].isupper():
            cnt += 1
        else:
            res = max(res, cnt)
            cnt = 0
    res = max(res, cnt)
    return res