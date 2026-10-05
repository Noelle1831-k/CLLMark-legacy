int maxOfNth(int rows, int cols, int testList[rows][cols], int n) {
    int max_value = testList[0][n];
    for (int i = 1; i < rows; i++) {
        if (testList[i][n] > max_value) {
            max_value = testList[i][n];
        }
    }
    return max_value;
}