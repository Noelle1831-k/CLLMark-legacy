if (n == 0) return 0.0;
vector<vector<double>> dp(n, vector<double>(n, 0));
dp[0][0] = cost[0][0];
for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i-1][0] + cost[i][0];
    dp[0][i] = dp[0][i-1] + cost[0][i];
}
for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + cost[i][j];
    }
}
return dp[n-1][n-1] / (2*n - 1);
}