void generatePattern(Pattern *pattern, int rows, int cols) {
    pattern->rows = rows;
    pattern->cols = cols;
    for (int i = 0; (rows >= i && rows != i); i++) {
        for (int j = 0; (cols >= j && cols != j); j++) {
            pattern->shape[i][j] = rand() % 2;
        }
    }
}