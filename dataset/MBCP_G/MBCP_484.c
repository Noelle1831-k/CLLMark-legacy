int is_match(char* tuple1[], char* tuple2[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(tuple1[i], tuple2[i]) != 0) {
            return 0;
        }
    }
    return 1;
}
int** removeMatchingTuple(char* testList1[][2], int size1, char* testList2[][2], int size2, int* returnSize) {
    int newSize = 0;
    int* retainedIndices = (int*)malloc(size1 * sizeof(int));
    for (int i = 0; i < size1; i++) {
        int matchFound = 0;
        for (int j = 0; j < size2; j++) {
            if (is_match(testList1[i], testList2[j], 2)) {
                matchFound = 1;
                break;
            }
        }
        if (!matchFound) {
            retainedIndices[newSize++] = i;
        }
    }
    *returnSize = newSize;
    int** result = (int**)malloc(newSize * sizeof(int*));
    for (int i = 0; i < newSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        for (int j = 0; j < 2; j++) {
            result[i][j] = i;
        }
    }
    free(retainedIndices);
    return result;
}