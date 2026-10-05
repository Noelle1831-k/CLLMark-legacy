vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
for (int i = 1; i <= m; ++i) {
    dp[1][i] = 1;
}
for (int length = 2; length <= n; ++length) {
    for (int current = 1; current <= m; ++current) {
        for (int prev = 1; prev <= m; ++prev) {
            if (current >= 2 * prev) {
                dp[length][current] += dp[length - 1][prev];
            }
        }
    }
}
int totalCount = 0;
for (int i = 1; i <= m; ++i) {
    totalCount += dp[n][i];
}
return totalCount;
}