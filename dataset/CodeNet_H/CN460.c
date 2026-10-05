int main(void)
{
    int i, j, k;
    int n, m, s;
    int dp[50][3001];
    while (1){
        scanf("%d%d%d", &n, &m, &s);
        if (n == 0){
            break;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (i = 1; i <= m; i++){
            for (j = n * n; j >= 1; j--){
                for (k = i; k <= s; k++){
                    dp[j][k] += dp[j - 1][k - i];
                    if (dp[j][k] >= 100000){
                        dp[j][k] -= 100000;
                    }
                }
            }
        }
        printf("%d\n", dp[n * n][s]);
    }
    return (0);
}