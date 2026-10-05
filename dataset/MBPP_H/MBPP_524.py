def max_sum_increasing_subsequence(arr, n):
    max_sum = 0
    msis = [0 for x in range(n)]
    for i in range(n):
        msis[i] = arr[i]
    for i in range(1, n):
        for j in range(i):
            if (arr[i] > arr[j] and
                    msis[i] < msis[j] + arr[i]):
                msis[i] = msis[j] + arr[i]
    for i in range(n):
        if max_sum < msis[i]:
            max_sum = msis[i]
    return max_sum