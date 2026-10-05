int** indexMultiplication(int testTup1[][2], int testTup2[][2], int size) {
    int** result = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        result[i][0] = testTup1[i][0] * testTup2[i][0];
        result[i][1] = testTup1[i][1] * testTup2[i][1];
    }
    return result;
}