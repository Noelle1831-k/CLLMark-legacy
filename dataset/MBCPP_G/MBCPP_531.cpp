vector<int> dp(v + 1, INT_MAX);
dp[0] = 0;
for (int i = 1; i <= v; ++i) {
    for (int j = 0; j < m; ++j) {
        if (coins[j] <= i) {
            int sub_res = dp[i - coins[j]];
            if (sub_res != INT_MAX && sub_res + 1 < dp[i]) {
                dp[i] = sub_res + 1;
            }
        }
    }
}
return dp[v] == INT_MAX ? -1 : dp[v];
}