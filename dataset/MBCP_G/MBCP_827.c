int sumColumn(int list[][4], int rows, int c) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += list[i][c];
    }
    return sum;
}