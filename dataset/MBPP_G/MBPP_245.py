def max_sum(arr, n):
    inc = [0] * n
    dec = [0] * n
    inc[0] = arr[0]
    for i in range(1, n):
        inc[i] = arr[i]
        for j in range(i):
            if arr[i] > arr[j]:
                inc[i] = max(inc[i], inc[j] + arr[i])
    dec[n - 1] = arr[n - 1]
    for i in range(n - 2, -1, -1):
        dec[i] = arr[i]
        for j in range(n - 1, i, -1):
            if arr[i] > arr[j]:
                dec[i] = max(dec[i], dec[j] + arr[i])
    max_sum = 0
    for i in range(n):
        max_sum = max(max_sum, inc[i] + dec[i] - arr[i])
    return max_sum