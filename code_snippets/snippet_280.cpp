	int m = grid.size();
	int dp[m][n] = {};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0)
				dp[i][j] = grid[i][j];
			else if (i == 0)
				dp[i][j] = dp[i][j - 1] + grid[i][j];
			else if (j == 0)
				dp[i][j] = dp[i - 1][j] + grid[i][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	}
	int result = INT_MIN;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = i; k < m; k++) {
				for (int l = j; l < n; l++) {
					result = max(result, dp[k][l] - dp[i - 1][l] - dp[k][j - 1] + dp[i - 1][j - 1]);
				}
			}
		}
	}
	return result;
}
int main() {
	vector<vector<int>> grid{{1, 4, 5}, {2, 0, 0}};
	cout << maxSumRectangularGrid(grid, 3) << "\n";  
	vector<vector<int>> grid{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
	cout << maxSumRectangularGrid(grid, 5) << "\n";  
	vector<vector<int>> grid{{7, 9, 11, 15, 19}, {21, 25, 28, 31, 32}};
	cout << maxSumRectangularGrid(grid, 5) << "\n";  
}
<|endoftext|>