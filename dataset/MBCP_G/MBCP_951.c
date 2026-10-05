void maxSimilarIndices(int testList1[][2], int testList2[][2], int rows, int result[][2]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 2; j++) {
            if (testList2[i][j] >= testList1[i][j]) {
                result[i][j] = testList2[i][j];
            } else {
                result[i][j] = testList1[i][j];
            }
        }
    }
}