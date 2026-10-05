int isPatternComplete(Grid *grid, Pattern *pattern) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            if (grid->cells[i][j] != pattern->shape[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}