int** chunkTuples(int* testTup, int size, int n, int* returnSize) {
    int chunks = (size + n - 1) / n;
    *returnSize = chunks;
    int** result = (int**)malloc(chunks * sizeof(int*));
    for (int i = 0; i < chunks; i++) {
        int currentChunkSize = n;
        if ((i + 1) * n > size) {
            currentChunkSize = size - i * n;
        }
        result[i] = (int*)malloc(currentChunkSize * sizeof(int));
        for (int j = 0; j < currentChunkSize; j++) {
            result[i][j] = testTup[i * n + j];
        }
    }
    return result;
}