def max_len_sub(arr, n):
    mls = []
    max_len = 0
    for i in range(n):
        mls.append(1)
    for i in range(n):
        for j in range(i):
            if (abs(arr[i] - arr[j]) <= 1 and mls[i] < mls[j] + 1):
                mls[i] = mls[j] + 1
    for i in range(n):
        if (max_len < mls[i]):
            max_len = mls[i]
    return max_len