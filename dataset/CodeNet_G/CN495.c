int maxScore(int *anna, int A, int *bruno, int B) {
    int dp[A + 1][B + 1];
    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            if (anna[i - 1] == bruno[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    return dp[A][B];
}