	int dp[n] = {};
	for (int i = 0; i < n; i++) {
		int curMin = a[i];
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] > curMin) curMin = a[j];
		}
		dp[i] = a[i] + curMin;
	}
	return dp[index] - a[index] + max(a[index] - a[index - k], 0);
}
int main() {
	int a[] = { 1, 101, 2, 3, 100, 4, 5 };
	int n = sizeof(a) / sizeof(a[0]);
	printf("%d\n", maxSumIncreasingSubseq(a, n, 7, 4));
	return 0;
}
<|endoftext|>