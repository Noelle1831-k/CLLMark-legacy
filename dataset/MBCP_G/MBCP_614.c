int cumulativeSum(int testList[][3], int rows) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            sum += testList[i][j];
        }
    }
    return sum;
}