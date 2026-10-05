vector<bool> dp(m, false);
    dp[0] = true;
    for (int num : arr) {
        vector<bool> temp(dp);
        for (int i = 0; i < m; ++i) {
            if (dp[i]) {
                temp[(i + num) % m] = true;
            }
        }
        dp = temp;
    }
    return dp[0];
}