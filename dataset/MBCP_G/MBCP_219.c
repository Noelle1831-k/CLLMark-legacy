int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void extractMinMax(int *arr, int size, int k, int *result, int *resultSize) {
    if (k <= 0 || k >= size) {
        *resultSize = 0;
        return;
    }
    qsort(arr, size, sizeof(int), compare);
    for (int i = 0; i < k; i++) {
        result[i] = arr[i];
    }
    for (int i = 0; i < k; i++) {
        result[k + i] = arr[size - k + i];
    }
    *resultSize = 2 * k;
}
int main() {
    int arr[] = {5, 20, 3, 7, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int result[2*k];
    int resultSize;
    extractMinMax(arr, size, k, result, &resultSize);
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}