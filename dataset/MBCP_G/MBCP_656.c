int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int findMinSum(int a[], int b[], int n) {
    qsort(a, n, sizeof(int), compare);
    qsort(b, n, sizeof(int), compare);
    int minSum = 0;
    for (int i = 0; i < n; i++) {
        minSum += abs(a[i] - b[i]);
    }
    return minSum;
}