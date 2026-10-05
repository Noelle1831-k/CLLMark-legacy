int findMax(int testList[][2], int rows) {
    int max = testList[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 2; j++) {
            if (testList[i][j] > max) {
                max = testList[i][j];
            }
        }
    }
    return max;
}