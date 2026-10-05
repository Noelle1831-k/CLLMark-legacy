int** removeColumn(int **list, int rows, int cols, int n) {
    if (n < 0 || n >= cols) return NULL;
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; ++i) {
        result[i] = (int *)malloc((cols - 1) * sizeof(int));
        int index = 0;
        for (int j = 0; j < cols; ++j) {
            if (j != n) {
                result[i][index++] = list[i][j];
            }
        }
    }
    return result;
}