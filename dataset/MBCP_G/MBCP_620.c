int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int largestSubset(int* a, int n) {
    qsort(a, n, sizeof(int), compare);
    int *dp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        dp[i] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] % a[j] == 0) {
                dp[i] = (dp[i] > dp[j] + 1) ? dp[i] : dp[j] + 1;
            }
        }
    }
    int max = 1;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > max)
            max = dp[i];
    }
    free(dp);
    return max;
}