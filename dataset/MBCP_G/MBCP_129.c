bool isMagicSquare(int **matrix, int n) {
    int i, j;
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += matrix[0][i];
    }
    for (i = 1; i < n; i++) {
        int rowSum = 0;
        for (j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != sum) {
            return false;
        }
    }
    for (i = 0; i < n; i++) {
        int colSum = 0;
        for (j = 0; j < n; j++) {
            colSum += matrix[j][i];
        }
        if (colSum != sum) {
            return false;
        }
    }
    int diagSum1 = 0, diagSum2 = 0;
    for (i = 0; i < n; i++) {
        diagSum1 += matrix[i][i];
        diagSum2 += matrix[i][n - i - 1];
    }
    if (diagSum1 != sum || diagSum2 != sum) {
        return false;
    }
    return true;
}