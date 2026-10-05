def min_cost(cost, m, n):
    dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
    dp[0][0] = cost[0][0]
    for i in range(1, m + 1):
        dp[i][0] = dp[i - 1][0] + cost[i][0]
    for j in range(1, n + 1):
        dp[0][j] = dp[0][j - 1] + cost[0][j]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            dp[i][j] = cost[i][j] + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
    return dp[m][n]