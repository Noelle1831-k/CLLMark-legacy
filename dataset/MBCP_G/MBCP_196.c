int** removeTuples(int** testList, int* testListSizes, int testListColSize, int k, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(testListColSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(testListColSize * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < testListColSize; i++) {
        if (testListSizes[i] != k) {
            result[*returnSize] = (int*)malloc(testListSizes[i] * sizeof(int));
            (*returnColumnSizes)[*returnSize] = testListSizes[i];
            for (int j = 0; j < testListSizes[i]; j++) {
                result[*returnSize][j] = testList[i][j];
            }
            (*returnSize)++;
        }
    }
    return result;
}