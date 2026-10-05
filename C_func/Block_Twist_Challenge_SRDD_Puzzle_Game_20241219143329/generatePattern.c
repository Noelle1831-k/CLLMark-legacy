void generatePattern(Pattern *pattern, int rows, int cols) {
    pattern->rows = rows;
    pattern->cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pattern->shape[i][j] = rand() % 2;
        }
    }
}