int minFlipCount(int N, int p[]) {
    int i, j, dp[N + 1];
    for (i = 0; i <= N; i++) dp[i] = 1000000000;
    dp[0] = 0;
    for (i = 0; i < N; i++) {
        if (i == 0) {
            dp[i + 1] = dp[i] + p[i]; 
        } else {
            dp[i + 1] = dp[i] + p[i]; 
            dp[i + 1] = (dp[i + 1] < dp[i - 1] + p[i] + p[i - 1]) ? dp[i + 1] : dp[i - 1] + p[i] + p[i - 1];
        }
    }
    return dp[N];
}