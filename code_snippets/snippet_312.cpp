	int dp[m];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<m;i++) {
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	return dp[m-1];
}
<|endoftext|>