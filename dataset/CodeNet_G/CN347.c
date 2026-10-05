int max(int a, int b) {
    return (a > b) ? a : b;
}
int absolute(int a) {
    return (a < 0) ? -a : a;
}
int calculateScoreDifference(int W, int H, int grid[H][W]) {
    int dp[H][W];
    for (int i = H - 1; i >= 0; i--) {
        for (int j = W - 1; j >= 0; j--) {
            if (i == H - 1 && j == W - 1) {
                dp[i][j] = grid[i][j];
            } else if (i == H - 1) {
                dp[i][j] = grid[i][j] - dp[i][j + 1];
            } else if (j == W - 1) {
                dp[i][j] = grid[i][j] - dp[i + 1][j];
            } else {
                dp[i][j] = grid[i][j] - max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return absolute(dp[0][0]);
}