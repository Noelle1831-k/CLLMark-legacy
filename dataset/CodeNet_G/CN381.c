#define MOD 1000000007
int main() {
    int N;
    scanf("%d", &N);
    char s[N + 1], t[N + 1];
    scanf("%s %s", s, t);
    long long dp[N];
    long long lastEntrance[26] = {0};
    dp[0] = 1;
    lastEntrance[s[0] - 'a'] = 1;
    for (int i = 1; i < N; i++) {
        dp[i] = 0;
        for (int ch = 0; ch < 26; ch++) {
            if (t[i] - 'a' == ch) {
                dp[i] = (dp[i] + lastEntrance[ch]) % MOD;
            }
        }
        lastEntrance[s[i] - 'a'] = (lastEntrance[s[i] - 'a'] + dp[i]) % MOD;
    }
    printf("%lld\n", dp[N - 1] % MOD);
    return 0;
}
