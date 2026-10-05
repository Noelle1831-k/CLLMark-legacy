	int dp[n+1];
	for (int i = 0; i <= n; i++) {
		dp[i] = 0;
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i - j < 0) {
				break;
			}
			dp[i] += dp[i - j];
		}
	}
	return dp[n];
}
int main() {
	int m, n;
	m = 4;
	n = 10;
	cout << "Total sequences of length " << n << " and max value m = " << m << " = " << getTotalNumberOfSequences(m, n) << endl;
	return 0;
}
<|endoftext|>