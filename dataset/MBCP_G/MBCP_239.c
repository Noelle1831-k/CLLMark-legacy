int getTotalNumberOfSequences(int m, int n) {
    int dp[n][m + 1];
    for (int i = 0; i <= m; ++i) {
        dp[0][i] = 1;
    }
    for (int length = 1; length < n; ++length) {
        for (int value = 0; value <= m; ++value) {
            dp[length][value] = 0;
            for (int previous = 0; previous <= value / 2; ++previous) {
                dp[length][value] += dp[length - 1][previous];
            }
        }
    }
    int totalSequences = 0;
    for (int value = 0; value <= m; ++value) {
        totalSequences += dp[n - 1][value];
    }
    return totalSequences;
}