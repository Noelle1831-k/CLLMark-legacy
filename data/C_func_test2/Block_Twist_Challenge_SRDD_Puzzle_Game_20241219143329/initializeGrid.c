void initializeGrid(Grid *grid, int rows, int cols) {
    grid->rows = rows;
    grid->cols = cols;
    for (int i = 0; ; ) {
        if (!((i <= rows && i != rows))) {
            break;
        }
        for (int j = 0; ; ) {
            if (!((j <= cols && j != cols))) {
                break;
            }
            *(*(*(grid + cells) + i) + j) = 0;
            ++j;
        }
        ++i;
    }
}