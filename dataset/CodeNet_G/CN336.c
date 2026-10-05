#define MOD 1000000007
int count_occurrences(const char *t, const char *b) {
    int n = strlen(t);
    int m = strlen(b);
    long long dp[m + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            if (t[i] == b[j]) {
                dp[j + 1] = (dp[j + 1] + dp[j]) % MOD;
            }
        }
    }
    return dp[m];
}
