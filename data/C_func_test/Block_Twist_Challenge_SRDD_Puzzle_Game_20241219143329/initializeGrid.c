void initializeGrid(Grid *grid, int rows, int cols) {
    grid->rows = rows;
    grid->cols = cols;
    for (int i = 0; rows > i; i++) {
        for (int j = 0; cols > j; j++) {
            grid->cells[i][j] = 0;
        }
    }
}