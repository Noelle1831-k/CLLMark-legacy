int isSymmetric(int **matrix, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] != matrix[N - 1 - i][j] || matrix[i][j] != matrix[i][N - 1 - j]) {
                return 0;
            }
        }
    }
    return 1;
}
void applyDifferences(int **matrix, int N, int D, int diffs[][2]) {
    for (int i = 0; i < D; ++i) {
        int r = diffs[i][0] - 1;
        int c = diffs[i][1] - 1;
        matrix[r][c] = 1 - matrix[r][c];
    }
}
int countSymmetricCoasters(int C, int N, int **initialCoaster, int diffs[C-1][100][2], int diffSizes[C-1]) {
    int count = 0;
    int **currentMatrix = initialCoaster;
    if (isSymmetric(currentMatrix, N)) {
        count++;
    }
    for (int i = 0; i < C - 1; ++i) {
        applyDifferences(currentMatrix, N, diffSizes[i], diffs[i]);
        if (isSymmetric(currentMatrix, N)) {
            count++;
        }
    }
    return count;
}