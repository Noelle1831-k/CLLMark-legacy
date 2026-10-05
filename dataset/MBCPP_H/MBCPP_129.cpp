    int result = 0;
    int n = myMatrix.size();
    for (int i = 0; i < n; i++) {
        int nRows = myMatrix[i].size();
        for (int j = 0; j < nRows; j++) {
            result = result + myMatrix[i][j] * myMatrix[i][j];
            if (i == j) {
                result += 2 * n;
            }
        }
    }
    return result % (2 * (n + 1));
}