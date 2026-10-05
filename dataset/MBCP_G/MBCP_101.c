int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int kthElement(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare);
    return arr[k - 1];
}