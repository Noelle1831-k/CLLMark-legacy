int maximumSegments(int n, int a, int b, int c) {
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
        if (i >= a && dp[i - a] != -1) {
            dp[i] = dp[i - a] + 1;
        }
        if (i >= b && dp[i - b] != -1) {
            dp[i] = dp[i - b] + 1;
        }
        if (i >= c && dp[i - c] != -1) {
            dp[i] = dp[i - c] + 1;
        }
    }
    return dp[n] > -1 ? dp[n] : 0;
}