if (m % 2 != 0) return 0; 
int n = m / 2;
vector<int> dp(n + 1, 0);
dp[0] = 1;
for (int i = 1; i <= m; ++i) {
    for (int j = min(i, n); j > 0; --j) {
        dp[j] = dp[j] + dp[j - 1];
    }
}
return dp[n];
}