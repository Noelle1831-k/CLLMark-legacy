void initializeGrid(Grid *grid, int rows, int cols) {
    grid->rows = rows;
    grid->cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid->cells[i][j] = 0;
        }
    }
}