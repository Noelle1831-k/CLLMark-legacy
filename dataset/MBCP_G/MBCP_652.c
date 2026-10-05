void matrixToList(int ***matrix, int rows, int cols, int depth) {
    int *result[depth];
    for (int i = 0; i < depth; ++i) {
        result[i] = (int *)malloc(rows * cols * sizeof(int));
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < depth; ++k) {
                result[k][i * cols + j] = matrix[i][j][k];
            }
        }
    }
    printf("[");
    for (int i = 0; i < depth; ++i) {
        printf("(");
        for (int j = 0; j < rows * cols; ++j) {
            printf("%d", result[i][j]);
            if (j < rows * cols - 1) {
                printf(", ");
            }
        }
        printf(")");
        if (i < depth - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    for (int i = 0; i < depth; ++i) {
        free(result[i]);
    }
}
