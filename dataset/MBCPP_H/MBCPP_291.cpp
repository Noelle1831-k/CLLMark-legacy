	int dp[n+1][k+1];
	dp[1][k] = k;
	dp[2][k] = k * k;
	for(int i = 3; i <= n; i++) {
		dp[i][k] = (k - 1) * (dp[i - 1][k] + dp[i - 2][k]);
	}
	return dp[n][k];
}