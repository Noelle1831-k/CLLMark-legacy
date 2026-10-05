function maxaverageofpath(cost, n) {
	let dp = [];
	for (let i = 0; i < n; i++) {
		dp.push(Array(n + 1).fill(0));
	}
	dp[0][0] = cost[0][0];
	for (let i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + cost[i][0];
	}
	for (let i = 1; i < n; i++) {
		for (let j = 1; j < n; j++) {
			dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
		}
	}
	return dp[n - 1][n - 1] / (2 * n - 1);
}
