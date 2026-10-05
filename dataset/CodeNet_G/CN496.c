#define MAX_N 3000
#define MAX_T 3000
#define MAX_A 100000
int N, T, S;
int A[MAX_N + 1], B[MAX_N + 1];
int dp[MAX_N + 1][MAX_T + 1];
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    scanf("%d %d %d", &N, &T, &S);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &A[i], &B[i]);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= T; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= B[i] && !(j - B[i] < S && S < j)) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - B[i]] + A[i]);
            }
        }
    }
    printf("%d\n", dp[N][T]);
    return 0;
}
