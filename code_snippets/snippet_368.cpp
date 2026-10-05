	if (n <= 1)
		return n;
	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		int dp2 = max(dp[i - 1], dp[i - 2] + dp[i - 3]);
		int dp3 = max(dp[i - 2], dp[i - 3] + dp[i - 1]);
		dp[i] = max(dp2, dp3);
	}
	return dp[n];
}
int main() {
	int n;
	cin >> n;
	cout << breaksum(n);
	return 0;
}
<|endoftext|>