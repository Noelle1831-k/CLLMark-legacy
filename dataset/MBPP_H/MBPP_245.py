def max_sum(arr, n):
    MSIBS = arr[:]
    for i in range(n):
        for j in range(0, i):
            if arr[i] > arr[j] and MSIBS[i] < MSIBS[j] + arr[i]:
                MSIBS[i] = MSIBS[j] + arr[i]
    MSDBS = arr[:]
    for i in range(1, n):
        for j in range(0, i):
            if arr[-i-1] > arr[-j-1] and MSDBS[-i-1] < MSDBS[-j-1] + arr[-i-1]:
                MSDBS[-i-1] = MSDBS[-j-1] + arr[-i-1]
    max_sum = float("-Inf")
    for i, j, k in zip(MSIBS, MSDBS, arr):
        max_sum = max(max_sum, i + j - k)
    return max_sum