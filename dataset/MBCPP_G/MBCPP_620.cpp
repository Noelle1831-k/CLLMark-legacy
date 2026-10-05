sort(a.begin(), a.end());
vector<int> dp(n, 1);
for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
        if (a[i] % a[j] == 0) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
}
return *max_element(dp.begin(), dp.end());
}