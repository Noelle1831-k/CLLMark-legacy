void removeEven(int *arr, int size, int *result, int *resultSize) {
    *resultSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            result[*resultSize] = arr[i];
            (*resultSize)++;
        }
    }
}