#define MAX 100
int minCost(int n, int a[], int b[]) {
    int dp[MAX][MAX];
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + a[i] * b[k] * a[k + 1] * b[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[0][n - 1];
}