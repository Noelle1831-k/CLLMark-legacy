vector<int> dp(n, 0);
for (int i = 0; i <= index; ++i) {
    dp[i] = a[i];
    for (int j = 0; j < i; ++j) {
        if (a[i] > a[j]) {
            dp[i] = max(dp[i], dp[j] + a[i]);
        }
    }
}
int maxSum = 0;
for (int i = 0; i <= index; ++i) {
    if (a[i] < a[k]) {
        maxSum = max(maxSum, dp[i]);
    }
}
return maxSum + a[k];
}