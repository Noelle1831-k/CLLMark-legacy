	vector<vector<int>> dp(v+1, vector<int>(m+1, v));
	for(int i = 0; i < v+1; i++) dp[i][0] = 0;
	for(int i = 1; i < m+1; i++) {
		for(int j = 1; j < v+1; j++) {
			if(j - coins[i-1] >= 0) {
				dp[j][i] = min(dp[j][i-1], dp[j-coins[i-1]][i-1]) + 1;
			}
			else {
				dp[j][i] = dp[j][i-1];
			}
		}
	}
	return dp[v][m];
}
int main(int argc, char** argv) {
	vector<int> coins = {4, 5, 6, 7, 8, 9};
	int m = 6;
	int v = 9;
	cout << minCoins(coins, m, v) << endl;
	return 0;
}
<|endoftext|>