bool modularSum(int arr[], int n, int m) {
    if (n > m) return true;
    bool *dp = (bool *)malloc(sizeof(bool) * m);
    memset(dp, false, sizeof(dp));
    for (int i = 0; i < n; i++) {
        if (dp[0]) return true;
        bool *temp = (bool *)malloc(sizeof(bool) * m);
        memcpy(temp, dp, sizeof(dp));
        for (int j = 0; j < m; j++) {
            if (dp[j]) {
                int index = (j + arr[i]) % m;
                temp[index] = true;
            }
        }
        temp[arr[i] % m] = true;
        memcpy(dp, temp, sizeof(temp));
    }
    return dp[0];
}