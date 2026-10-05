int min(int a, int b) {
    return a < b ? a : b;
}
int calculate_min_risk(int n, int m, int stones[][150], int slipperiness[][150], int k[]) {
    int INF = INT_MAX / 2; 
    int dp[151][76][2]; 
    int i, j, x, y, mjump;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    dp[0][0][0] = 0;
    for (i = 0; i < n; i++) {
        for (mj = 0; mj <= m; mj++) {
            for (j = 0; j < k[i]; j++) {
                int current_pos = stones[i][j];
                int current_risk = slipperiness[i][j];
                int current_cost = dp[i][mj][0] != INF ? dp[i][mj][0] : INF;
                if (i + 1 <= n) {
                    for (x = 0; x < k[i+1]; x++) {
                        int next_pos = stones[i+1][x];
                        int next_risk = slipperiness[i+1][x];
                        int horizontal_move = next_pos - current_pos;
                        int new_cost = current_cost + (current_risk + next_risk) * (horizontal_move > 0 ? horizontal_move : -horizontal_move);
                        dp[i+1][mj][0] = min(dp[i+1][mj][0], new_cost);
                    }
                }
                if (mj < m && i + 2 <= n) {
                    for (y = 0; y < k[i+2]; y++) {
                        int next_pos = stones[i+2][y];
                        int next_risk = slipperiness[i+2][y];
                        int horizontal_move = next_pos - current_pos;
                        int new_cost = current_cost + (current_risk + next_risk) * (horizontal_move > 0 ? horizontal_move : -horizontal_move);
                        dp[i+2][mj+1][1] = min(dp[i+2][mj+1][1], new_cost);
                    }
                }
            }
        }
    }
    int result = INF;
    for (mj = 0; mj <= m; mj++) {
        result = min(result, dp[n][mj][0]);
        result = min(result, dp[n][mj][1]);
    }
    return result;
}