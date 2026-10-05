double max(double a, double b) {
    return a > b ? a : b;
}
int main() {
    int n, m;
    double g[100][100];
    double dp[100][100];
    while (scanf("%d %d", &n, &m) == 2 && (n != 0 || m != 0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lf", &g[i][j]);
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            dp[1][i] = 1.0;
        }
        for (int k = 1; k <= m - 1; k++) {
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < n; i++) {
                    dp[k + 1][j] = max(dp[k + 1][j], dp[k][i] * g[i][j]);
                }
            }
        }
        double result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, dp[m][i]);
        }
        printf("%.2lf\n", result);
    }
    return 0;
}