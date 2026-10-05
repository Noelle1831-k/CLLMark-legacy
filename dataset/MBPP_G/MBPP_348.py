def find_ways(M):
    dp = [[0 for _ in range(M + 1)] for _ in range(M + 1)]
    dp[0][0] = 1
    for i in range(1, M + 1):
        dp[i][0] = dp[i - 1][0]
        for j in range(1, M + 1):
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]
    return dp[M][M] // 2
print(find_ways(4))
print(find_ways(6))
print(find_ways(8))