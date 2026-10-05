int n = price.size();
if (n == 0 || k == 0) return 0;
vector<vector<int>> dp(k + 1, vector<int>(n, 0));
for (int t = 1; t <= k; ++t) {
    int maxDiff = -price[0];
    for (int d = 1; d < n; ++d) {
        dp[t][d] = max(dp[t][d-1], price[d] + maxDiff);
        maxDiff = max(maxDiff, dp[t-1][d] - price[d]);
    }
}
return dp[k][n-1];
}