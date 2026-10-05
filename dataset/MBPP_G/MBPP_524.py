def max_sum_increasing_subsequence(arr, n):
    dp = arr[0:]
    for i in range(1, n):
        for j in range(i):
            if arr[i] > arr[j] and dp[i] < dp[j] + arr[i]:
                dp[i] = dp[j] + arr[i]
    return max(dp)
print(max_sum_increasing_subsequence([1, 101, 2, 3, 100, 4, 5], 7))
print(max_sum_increasing_subsequence([3, 4, 5, 10], 4))
print(max_sum_increasing_subsequence([10, 5, 4, 3], 4))