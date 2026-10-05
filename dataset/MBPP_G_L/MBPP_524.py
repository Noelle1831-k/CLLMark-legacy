def max_sum_increasing_subsequence(arr, n):
    dp = arr[0:]
    for i in range(1, n):
        for j in range(i):
            if arr[i] > arr[j] and dp[i] < dp[j] + arr[i]:
                dp[i] = dp[j] + arr[i]
    return max(dp)
