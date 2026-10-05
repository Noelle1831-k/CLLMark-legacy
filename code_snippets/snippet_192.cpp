	int n = str.length();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	int result = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (str[i] == str[j]) {
				if (i + 1 == j) {
					dp[i][j] = 1;
				} else {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				result = max(result, dp[i][j]);
			}
		}
	}
	return result;
}
int main() {
	string str = "AABEBCDD";
	cout << findLongestRepeatingSubseq(str) << endl;
	return 0;
}<|endoftext|>