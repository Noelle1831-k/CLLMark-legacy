#define MAX_TOOLS 100
int solve(int D, int N, int a[], int e[], int r[]) {
    int dp[D + 1];
    for (int i = 0; i <= D; ++i)
        dp[i] = INT_MAX;
    dp[D] = 0;
    for (int exp = 0; exp <= D; ++exp) {
        if (dp[exp] == INT_MAX) continue;
        for (int i = 0; i < N; ++i) {
            if (exp >= r[i] && a[i] > 0) {
                int newD = exp - a[i] < 0 ? 0 : exp - a[i];
                if (dp[newD] > dp[exp] + 1) {
                    dp[newD] = dp[exp] + 1;
                }
            }
        }
    }
    return dp[0] != INT_MAX ? dp[0] : -1;
}
int main() {
    int D, N;
    while (scanf("%d %d", &D, &N) == 2 && (D != 0 || N != 0)) {
        int a[MAX_TOOLS], e[MAX_TOOLS], r[MAX_TOOLS];
        for (int i = 0; i < N; ++i) {
            scanf("%d %d %d", &a[i], &e[i], &r[i]);
        }
        int result = solve(D, N, a, e, r);
        if (result == -1) {
            printf("NA\n");
        } else {
            printf("%d\n", result);
        }
    }
    return 0;
}
