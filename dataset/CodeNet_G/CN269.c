#define MAX_D 8
#define MAX_K 8
#define MAX_M 200
#define MAX_P 200
#define MAX_N 200
int D, K, L, M, N, P;
int c[MAX_D][MAX_K];
int r[MAX_M][MAX_K];
int t[MAX_P][MAX_K];
int dp[1 << MAX_N][MAX_M][MAX_D + 1];
int cost(int task, int bag, int day) {
    int addCost = 0;
    for (int k = 0; k < K; k++) {
        int diff = r[task][k] - t[bag][k];
        if (diff > 0) {
            addCost += diff * c[day][k];
        }
    }
    return addCost;
}
int minCost() {
    for (int mask = 0; mask < (1 << N); mask++)
        for (int task = 0; task < M; task++)
            for (int day = 0; day <= D; day++)
                dp[mask][task][day] = INT_MAX;
    dp[0][0][0] = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
        for (int task = 0; task < M; task++) {
            for (int day = 0; day < D; day++) {
                if (dp[mask][task][day] == INT_MAX) continue;
                for (int next = 0; next < P; next++) {
                    int new_mask = mask;
                    int found = 0;
                    for (int student = 0; student < N; student++) {
                        if (!(mask & (1 << student)) && task < M) {
                            new_mask |= (1 << student);
                            found = 1;
                            int curCost = dp[mask][task][day] + cost(task, next, day);
                            if (curCost < dp[new_mask][task + 1][day + 1]) {
                                dp[new_mask][task + 1][day + 1] = curCost;
                            }
                        }
                    }
                    if (!found) {
                        int curCost = dp[mask][task][day];
                        if (curCost < dp[mask][task][day + 1]) {
                            dp[mask][task][day + 1] = curCost;
                        }
                    }
                }
            }
        }
    }
    int result = INT_MAX;
    for (int day = 1; day <= D; day++) {
        if (dp[(1 << N) - 1][N][day] < result) {
            result = dp[(1 << N) - 1][N][day];
        }
    }
    return (result == INT_MAX) ? -1 : result;
}
