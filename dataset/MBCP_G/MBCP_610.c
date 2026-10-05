int* removeKthElement(int* arr, int size, int k, int* new_size) {
    if (k < 0 || k >= size) {
        *new_size = size;
        return arr;
    }
    int *result = (int*)malloc((size - 1) * sizeof(int));
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (i != k) {
            result[index++] = arr[i];
        }
    }
    *new_size = size - 1;
    return result;
}