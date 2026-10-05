int maxSumOfThreeConsecutive(int arr[], int n) {
    if (n == 0) return 0;
    if (n == 1) return arr[0];
    if (n == 2) return arr[0] + arr[1];
    int *dp = (int *)malloc(sizeof(int) * n);
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = arr[0] + arr[1] > arr[0] + arr[2] ? arr[0] + arr[1] : arr[0] + arr[2];
    dp[2] = dp[2] > arr[1] + arr[2] ? dp[2] : arr[1] + arr[2];
    for (int i = 3; i < n; i++) {
        int include_current = arr[i] + dp[i-2] > arr[i] + arr[i-1] + dp[i-3] ? arr[i] + dp[i-2] : arr[i] + arr[i-1] + dp[i-3];
        dp[i] = dp[i-1] > include_current ? dp[i-1] : include_current;
    }
    return dp[n-1];
}