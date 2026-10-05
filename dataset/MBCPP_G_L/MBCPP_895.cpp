if (a.empty()) return 0;
if (a.size() == 1) return a[0];
int n = a.size();
vector<int> dp(n, 0);
dp[0] = a[0];
dp[1] = max(a[0], a[1]);
for (int i = 2; i < n; i++) {
    dp[i] = max(dp[i-1], dp[i-2] + a[i]);
}
return dp[n-1];
}