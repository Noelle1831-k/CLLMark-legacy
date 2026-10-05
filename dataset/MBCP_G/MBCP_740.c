void tupleToDict(int *arr, int size, int (*result)[2], int *res_size) {
    *res_size = size / 2;
    for (int i = 0, j = 0; i < size; i += 2, j++) {
        result[j][0] = arr[i];
        result[j][1] = arr[i + 1];
    }
}