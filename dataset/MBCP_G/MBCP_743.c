void rotateRight(int *list, int size, int m, int n) {
    int new_size = size + n - m;
    int *result = (int *)malloc(new_size * sizeof(int));
    if (!result) return;
    int j = 0;
    for (int i = m; i < size; ++i, ++j) {
        result[j] = list[i];
    }
    for (int i = 0; i < m; ++i, ++j) {
        result[j] = list[i];
    }
    for (int i = size; i < new_size; ++i, ++j) {
        result[j] = list[i - size];
    }
    for (int i = 0; i < new_size; ++i) {
        list[i] = result[i];
    }
    free(result);
}