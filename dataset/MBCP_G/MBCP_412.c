int* removeOdd(int* arr, int size, int* new_size) {
    int* result = (int*)malloc(size * sizeof(int));
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            result[index] = arr[i];
            index++;
        }
    }
    *new_size = index;
    return result;
}