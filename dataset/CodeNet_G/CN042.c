void solveKnapsack(int W, int N, int values[], int weights[]) {
    int dp[1001][1001];
    int i, w;
    for(i = 0; i <= N; i++) {
        for(w = 0; w <= W; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(weights[i - 1] <= w)
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) ? 
                           (values[i - 1] + dp[i - 1][w - weights[i - 1]]) : dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    int max_value = dp[N][W];
    int min_weight = W;
    for(w = W; w >= 0; w--) {
        if(dp[N][w] == max_value) {
            min_weight = w;
        } else {
            break;
        }
    }
    static int case_num = 1;
    printf("Case %d: %d %d\n", case_num++, max_value, min_weight);
}