int i, j;
vector<vector<int>> dp(m+1, vector<int>(n+1));
dp[0][0] = cost[0][0];
for(i = 1; i <= m; i++) {
    dp[i][0] = dp[i-1][0] + cost[i][0];
    }
for(j = 1; j <= n; j++) {
    dp[0][j] = dp[0][j-1] + cost[0][j];
    }
for(i = 1; i <= m; i++){
    for(j = 1; j <= n; j++){
        dp[i][j] = cost[i][j] + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
    }
return dp[m][n];
}