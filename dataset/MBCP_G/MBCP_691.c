void groupElement(int testList[][2], int n, int result[][100], int *resultSizes, int *uniqueKeys, int *keyCount) {
    int i, j, k, exists;
    *keyCount = 0;
    for (i = 0; i < n; ++i) {
        exists = 0;
        for (j = 0; j < *keyCount; ++j) {
            if (uniqueKeys[j] == testList[i][1]) {
                result[j][resultSizes[j]++] = testList[i][0];
                exists = 1;
                break;
            }
        }
        if (!exists) {
            uniqueKeys[*keyCount] = testList[i][1];
            result[*keyCount][0] = testList[i][0];
            resultSizes[*keyCount] = 1;
            (*keyCount)++;
        }
    }
    for (i = 0; i < *keyCount; ++i) {
        for (j = 0; j < resultSizes[i] - 1; ++j) {
            for (k = j + 1; k < resultSizes[i]; ++k) {
                if (result[i][j] > result[i][k]) {
                    int temp = result[i][j];
                    result[i][j] = result[i][k];
                    result[i][k] = temp;
                }
            }
        }
    }
}