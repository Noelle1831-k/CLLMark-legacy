int countPaths(int a, int b, int n, int constructions[][2]) {
    int dp[17][17] = {0};
    int blocked[17][17] = {0};
    for (int i = 0; i < n; i++) {
        blocked[constructions[i][0]][constructions[i][1]] = 1;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (blocked[i][j]) continue;
            if (i > 1) dp[i][j] += dp[i-1][j];
            if (j > 1) dp[i][j] += dp[i][j-1];
        }
    }
    return dp[a][b];
}