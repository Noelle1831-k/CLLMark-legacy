void largNnum(int *arr, int size, int n, int *result) {
    int i, j, max_index, temp;
    for (i = 0; i < n; i++) {
        max_index = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        if (max_index != i) {
            temp = arr[i];
            arr[i] = arr[max_index];
            arr[max_index] = temp;
        }
        result[i] = arr[i];
    }
}