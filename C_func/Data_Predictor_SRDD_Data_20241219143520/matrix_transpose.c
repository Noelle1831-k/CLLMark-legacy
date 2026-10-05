void matrix_transpose(double *matrix, double *transpose, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j * rows + i] = matrix[i * cols + j];
        }
    }
}