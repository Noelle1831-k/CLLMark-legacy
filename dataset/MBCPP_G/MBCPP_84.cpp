if (n == 1 || n == 2) return 1;
vector<int> dp(n + 1);
dp[1] = 1;
dp[2] = 1;
for (int i = 3; i <= n; ++i) {
    dp[i] = dp[dp[i - 1]] + dp[i - dp[i - 1]];
}
return dp[n];
}