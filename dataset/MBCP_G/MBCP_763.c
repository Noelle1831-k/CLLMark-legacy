int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int findMinDiff(int arr[], int n) {
    if (n < 2) return 0;
    qsort(arr, n, sizeof(int), cmpfunc);
    int min_diff = INT_MAX;
    for (int i = 0; i < n - 1; ++i) {
        int diff = arr[i + 1] - arr[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    return min_diff;
}