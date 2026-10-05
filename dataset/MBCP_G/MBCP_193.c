int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int* removeTuple(int *arr, int size, int *newSize) {
    if (size == 0) {
        *newSize = 0;
        return NULL;
    }
    qsort(arr, size, sizeof(int), compare);
    int *result = (int*)malloc(size * sizeof(int));
    int index = 0;
    result[index++] = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] != arr[i - 1]) {
            result[index++] = arr[i];
        }
    }
    *newSize = index;
    return result;
}