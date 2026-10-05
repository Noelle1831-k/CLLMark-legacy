if (n % 2 != 0) return 0;
int dp[n + 1];
dp[0] = 1;
dp[2] = 3;
for (int i = 4; i <= n; i += 2) {
    dp[i] = 4 * dp[i - 2] - dp[i - 4];
}
return dp[n];
}