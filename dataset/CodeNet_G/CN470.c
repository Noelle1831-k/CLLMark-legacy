#define MOD 100000
int countPaths(int w, int h) {
    int dp[w+1][h+1][2][2];
    for(int i = 0; i <= w; i++)
        for(int j = 0; j <= h; j++)
            for(int k = 0; k < 2; k++)
                for(int l = 0; l < 2; l++)
                    dp[i][j][k][l] = 0;
    dp[1][1][0][0] = dp[1][1][1][0] = 1;
    for(int i = 1; i <= w; i++) {
        for(int j = 1; j <= h; j++) {
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 2; l++) {
                    if(dp[i][j][k][l]) {
                        if(i < w && l == 0)
                            dp[i+1][j][k][1] = (dp[i+1][j][k][1] + dp[i][j][k][l]) % MOD;
                        if(j < h && k == 0)
                            dp[i][j+1][1][l] = (dp[i][j+1][1][l] + dp[i][j][k][l]) % MOD;
                    }
                }
            }
        }
    }
    return (dp[w][h][0][0] + dp[w][h][0][1] + dp[w][h][1][0] + dp[w][h][1][1]) % MOD;
}
