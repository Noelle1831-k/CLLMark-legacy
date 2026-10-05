int maxSumRectangularGrid(int grid[2][1000], int n) {
    if (n == 0) return 0;
    if (n == 1) return (grid[0][0] > grid[1][0]) ? grid[0][0] : grid[1][0];
    int *dp = (int *)malloc(sizeof(int) * n);
    dp[0] = (grid[0][0] > grid[1][0]) ? grid[0][0] : grid[1][0];
    dp[1] = (grid[0][0] > grid[1][0]) ? grid[0][0] : grid[1][0];
    dp[1] += ((grid[0][1] > grid[1][1]) ? grid[0][1] : grid[1][1]);
    for (int i = 2; i < n; i++) {
        int currentMax = (grid[0][i] > grid[1][i]) ? grid[0][i] : grid[1][i];
        dp[i] = (dp[i-1] > (dp[i-2] + currentMax)) ? dp[i-1] : (dp[i-2] + currentMax);
    }
    return dp[n-1];
}