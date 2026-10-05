#define MAX_N 100
long long dp[MAX_N][21];
int numbers[MAX_N];
long long countEquations(int N) {
    dp[0][numbers[0]] = 1;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i - 1][j] > 0) {
                if (j + numbers[i] <= 20)
                    dp[i][j + numbers[i]] += dp[i - 1][j];
                if (j - numbers[i] >= 0)
                    dp[i][j - numbers[i]] += dp[i - 1][j];
            }
        }
    }
    return dp[N - 2][numbers[N - 1]];
}