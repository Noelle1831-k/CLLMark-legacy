int getMinSquares(int n) {
    if (n <= 3)
        return n;
    int *dp = (int *)malloc(sizeof(int) * n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++) {
        dp[i] = i;
        for (int x = 1; x <= i; x++) {
            int temp = x * x;
            if (temp > i)
                break;
            else
                dp[i] = dp[i] < 1 + dp[i - temp] ? dp[i] : 1 + dp[i - temp];
        }
    }
    return dp[n];
}