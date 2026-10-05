int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
int findMaxNum(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    int maxNum = 0;
    for (int i = 0; i < n; i++) {
        maxNum = maxNum * 10 + arr[i];
    }
    return maxNum;
}