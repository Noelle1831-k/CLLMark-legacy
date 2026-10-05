int* nthItems(int* list, int size, int n, int* resultSize) {
    if(n < 1) {
        *resultSize = 0;
        return NULL;
    }
    *resultSize = (size + n - 1) / n;
    int* result = (int*)malloc(*resultSize * sizeof(int));
    for(int i = 0, j = 0; i < size; i += n, j++) {
        result[j] = list[i];
    }
    return result;
}