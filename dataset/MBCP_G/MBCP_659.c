int* find_duplicates(int* arr, int size, int* dup_size) {
    int* count = (int*)calloc(1001, sizeof(int));
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            count[1000 + (-arr[i])] += 1;
        } else {
            count[arr[i]] += 1;
        }
    }
    int* duplicates = (int*)malloc(size * sizeof(int));
    int index = 0;
    for (int i = 0; i < 1001; i++) {
        if (count[i] > 1) {
            if (i > 500) {
                duplicates[index++] = -(i - 1000);
            } else {
                duplicates[index++] = i;
            }
        }
    }
    free(count);
    *dup_size = index;
    return duplicates;
}