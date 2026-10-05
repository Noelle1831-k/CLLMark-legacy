int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int removals(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare);
    int i = 0, j = 0, maxWindowSize = 0;
    while (j < n) {
        if (arr[j] - arr[i] <= k) {
            maxWindowSize = (j - i + 1) > maxWindowSize ? (j - i + 1) : maxWindowSize;
            j++;
        } else {
            i++;
        }
    }
    return n - maxWindowSize;
}
