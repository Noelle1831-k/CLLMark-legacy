#define MAXM 7
#define MAXG 10
#define MAXN 1000
int main(void) {
    int m, g;
    int ai[MAXM], bi[MAXM];
    int ni[MAXG];
    int dp[MAXN + 1], temp[MAXN + 1];
    while (scanf("%d", &m), m) {
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &ai[i], &bi[i]);
        }
        scanf("%d", &g);
        for (int i = 0; i < g; ++i) {
            scanf("%d", &ni[i]);
        }
        for (int game = 0; game < g; ++game) {
            int target = ni[game];
            memset(dp, 0, sizeof(dp));
            dp[0] = 1;
            for (int i = 0; i < m; ++i) {
                int value = ai[i];
                int count = bi[i];
                memcpy(temp, dp, sizeof(dp));
                for (int j = value; j <= target; ++j) {
                    temp[j] = 0;
                    for (int k = 1; k <= count && j - k * value >= 0; ++k) {
                        temp[j] += dp[j - k * value];
                    }
                }
                memcpy(dp, temp, sizeof(dp));
            }
            printf("%d\n", dp[target]);
        }
    }
    return 0;
}
