int beautifulSequences(int N, int M) {
    int MOD = 1000000007;
    long long dp[N + 1];
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] * 2; 
        if (i >= M) {
            dp[i] -= dp[i - M]; 
        }
        dp[i] = (dp[i] % MOD + MOD) % MOD; 
    }
    return dp[N];
}