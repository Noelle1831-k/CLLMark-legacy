def max_profit(price, k):
    n = len(price)
    if n == 0 or k == 0:
        return 0
    dp = [[0] * n for _ in range(k + 1)]
    for t in range(1, k + 1):
        max_diff = -price[0]
        for d in range(1, n):
            dp[t][d] = max(dp[t][d - 1], price[d] + max_diff)
            max_diff = max(max_diff, dp[t - 1][d] - price[d])
    return dp[k][-1]