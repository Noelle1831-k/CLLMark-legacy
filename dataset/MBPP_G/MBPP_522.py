def lbs(arr):
    n = len(arr)
    inc = [1] * n
    dec = [1] * n
    for i in range(1, n):
        for j in range(0, i):
            if arr[i] > arr[j] and inc[i] < inc[j] + 1:
                inc[i] = inc[j] + 1
    for i in range(n - 2, -1, -1):
        for j in range(n - 1, i, -1):
            if arr[i] > arr[j] and dec[i] < dec[j] + 1:
                dec[i] = dec[j] + 1
    max_lbs = 0
    for i in range(n):
        max_lbs = max(max_lbs, inc[i] + dec[i] - 1)
    return max_lbs