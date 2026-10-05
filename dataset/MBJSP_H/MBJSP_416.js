function breaksum(n) {
	var MAX = 1000000, dp = [0];
	dp[0] = 0; dp[1] = 1;
	for (var i = 2; i <= n; i++) {
		dp[i] = Math.max(dp[Math.floor(i/2)] + dp[Math.floor(i/3)] + dp[Math.floor(i/4)], i);
	}
	return dp[n];
}
