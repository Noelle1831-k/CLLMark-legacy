function maxSumPairDiffLessthanK(arr, n, k) {
	arr.sort((a, b) => a - b);
	let dp = Array(n).fill(0);
	dp[0] = 0;
	for (let i = 1; i < n; i++) {
		if (arr[i] - arr[i - 1] < k) {
			if (i >= 2) {
				dp[i] = Math.max(dp[i - 2] + arr[i] + arr[i - 1], dp[i - 1]);
			} else {
				dp[i] = Math.max(dp[i - 1] + arr[i], arr[i] + arr[i - 1]);
			}
		} else {
			dp[i] = dp[i - 1];
		}
	}
	return dp[n - 1];
}
