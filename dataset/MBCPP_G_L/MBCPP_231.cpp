int dp[n][n];
for (int i = 0; i < n; i++){
    dp[n-1][i] = tri[n-1][i];
    }
for (int i = n-2; i >= 0; i--){
    for (int j = 0; j <= i; j++){
        dp[i][j] = tri[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
return dp[0][0];
}