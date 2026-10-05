def longest_subseq_with_diff_one(arr, n):
    dp = [1] * n
    for i in range(1, n):
        for j in range(i):
            if abs(arr[i] - arr[j]) == 1:
                dp[i] = max(dp[i], dp[j] + 1)
    return max(dp)