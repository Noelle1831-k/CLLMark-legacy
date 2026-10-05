	int dp[m+1][n+1];
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if (x[i-1] == y[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
}
int main() {
	string X = "AGGTAB";
	string Y = "GXTXAYB";
	string Z = "ABCDGH";
	string W = "AEDFHR";
	string P = "AXYT";
	string Q = "AYZX";
	printf("Length of LCS is %d", longestCommonSubsequence(X, Y, 6, 7));
	printf("Length of LCS is %d", longestCommonSubsequence(Z, W, 6, 6));
	printf("Length of LCS is %d", longestCommonSubsequence(P, Q, 4, 4));
	return 0;
}
<|endoftext|>