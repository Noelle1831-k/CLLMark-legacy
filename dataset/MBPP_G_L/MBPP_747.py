def lcs_of_three(X, Y, Z, m, n, o):
    dp = [[[0 for _ in range(o + 1)] for __ in range(n + 1)] for ___ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            for k in range(1, o + 1):
                if X[i - 1] == Y[j - 1] == Z[k - 1]:
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1
                else:
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1])
    return dp[m][n][o]