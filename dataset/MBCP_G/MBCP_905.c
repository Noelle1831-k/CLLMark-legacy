int sumOfSquare(int n) {
    int sum = 0;
    long long C[n + 1][n + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    for (int i = 0; i <= n; ++i) {
        sum += C[n][i] * C[n][i];
    }
    return sum;
}