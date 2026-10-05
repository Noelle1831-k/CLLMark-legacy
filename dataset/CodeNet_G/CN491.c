int calculate_pasta_schedules(int N, int K, int known_days[][2], int mod) {
    int dp[N + 1][4][4] = {0};
    int i, j, k, a, b;
    for (j = 0; j <= 3; ++j) {
        for (k = 0; k <= 3; ++k) {
            dp[0][j][k] = 1;
        }
    }
    for (i = 1; i <= N; ++i) {
        int fixed_pasta = 0;
        for (a = 0; a < K; ++a) {
            if (i == known_days[a][0]) {
                fixed_pasta = known_days[a][1];
                break;
            }
        }
        for (j = 1; j <= 3; ++j) {
            for (k = 1; k <= 3; ++k) {
                if (fixed_pasta && (fixed_pasta != j || fixed_pasta != k)) continue;
                for (b = 1; b <= 3; ++b) {
                    if (b != j || b != k) {
                        dp[i][k][j] += dp[i - 1][j][b];
                        dp[i][k][j] %= mod;
                    }
                }
            }
        }
    }
    int result = 0;
    for (j = 1; j <= 3; ++j) {
        for (k = 1; k <= 3; ++k) {
            result += dp[N][j][k];
            result %= mod;
        }
    }
    return result;
}