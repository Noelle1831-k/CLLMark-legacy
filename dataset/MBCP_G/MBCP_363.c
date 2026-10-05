void addKElement(int rows, int cols, int testList[rows][cols], int k, int result[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = testList[i][j] + k;
        }
    }
}