int maxProfit(int* price, int n, int k) {
    if (n <= 0 || k <= 0) return 0;
    int dp[k+1][n];
    for(int i = 0; i <= k; i++) {
        int prevDiff = -price[0];
        for(int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                prevDiff = prevDiff > (dp[i-1][j-1] - price[j-1]) ? prevDiff : (dp[i-1][j-1] - price[j-1]);
                dp[i][j] = dp[i][j-1] > (prevDiff + price[j]) ? dp[i][j-1] : (prevDiff + price[j]);
            }
        }
    }
    return dp[k][n-1];
}
