int maxSquareSize(char grid[1000][1000], int n) {
    int dp[1001][1001] = {0};
    int maxSize = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (grid[i - 1][j - 1] == '.') {
                dp[i][j] = 1 + (dp[i - 1][j] < dp[i][j - 1] ? (dp[i - 1][j] < dp[i - 1][j - 1] ? dp[i - 1][j] : dp[i - 1][j - 1]) : (dp[i][j - 1] < dp[i - 1][j - 1] ? dp[i][j - 1] : dp[i - 1][j - 1]));
                if (dp[i][j] > maxSize) {
                    maxSize = dp[i][j];
                }
            }
        }
    }
    return maxSize;
}