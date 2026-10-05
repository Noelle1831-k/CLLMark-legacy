int* extractSingly(int** testList, int* rows, int* cols, int* returnSize) {
    int* freq = (int*)calloc(101, sizeof(int));
    int totalSize = 0;
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            int val = testList[i][j];
            if (freq[val] == 0) {
                totalSize++;
            }
            freq[val]++;
        }
    }
    int* result = (int*)malloc(totalSize * sizeof(int));
    int index = 0;
    for (int i = 1; i <= 100; i++) {
        if (freq[i] > 0) {
            result[index++] = i;
        }
    }
    *returnSize = totalSize;
    free(freq);
    return result;
}