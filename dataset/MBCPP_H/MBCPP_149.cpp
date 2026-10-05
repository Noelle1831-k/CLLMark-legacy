	int dp[n];
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j] + 1) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			if (arr[i] == arr[j] - 1) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	return dp[n - 1];
}