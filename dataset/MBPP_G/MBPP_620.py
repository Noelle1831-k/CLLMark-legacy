def largest_subset(a, n):
    a.sort()
    dp = [1] * n
    for i in range(1, n):
        for j in range(i):
            if a[i] % a[j] == 0 or a[j] % a[i] == 0:
                dp[i] = max(dp[i], dp[j] + 1)
    return max(dp)