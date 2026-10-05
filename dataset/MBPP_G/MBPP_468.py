def max_product(arr, n):
    dp = [0] * n
    for i in range(n):
        dp[i] = arr[i]
    for i in range(1, n):
        for j in range(i):
            if arr[i] > arr[j]:
                dp[i] = max(dp[i], dp[j] * arr[i])
    return max(dp)