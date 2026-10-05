int maxGold = 0;
vector<vector<int>> dp(m, vector<int>(n, 0));
for (int col = n-1; col >= 0; col--) {
    for (int row = 0; row < m; row++) {
        int right = (col == n-1) ? 0 : dp[row][col+1];
        int rightUp = (row == 0 || col == n-1) ? 0 : dp[row-1][col+1];
        int rightDown = (row == m-1 || col == n-1) ? 0 : dp[row+1][col+1];
        dp[row][col] = gold[row][col] + max(right, max(rightUp, rightDown));
    }
}
for (int i = 0; i < m; i++) {
    maxGold = max(maxGold, dp[i][0]);
}
return maxGold;
}