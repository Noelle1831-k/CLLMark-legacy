void combineLists(int *num1, int size1, int *num2, int size2, int **result, int *resultSize) {
    *resultSize = size1 + size2;
    *result = (int *)malloc((*resultSize) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (num1[i] < num2[j]) {
            (*result)[k++] = num1[i++];
        } else {
            (*result)[k++] = num2[j++];
        }
    }
    while (i < size1) {
        (*result)[k++] = num1[i++];
    }
    while (j < size2) {
        (*result)[k++] = num2[j++];
    }
}