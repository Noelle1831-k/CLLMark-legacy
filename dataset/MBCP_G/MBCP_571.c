int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int maxSumPairDiffLessthanK(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare);
    int sum = 0;
    for (int i = n - 1; i > 0; i--) {
        if (arr[i] - arr[i - 1] < k) {
            sum += arr[i] + arr[i - 1];
            i--;
        }
    }
    return sum;
}