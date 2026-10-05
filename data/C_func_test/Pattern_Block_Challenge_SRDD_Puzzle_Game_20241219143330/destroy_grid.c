void destroy_grid(Grid *grid) {
    for (int i = 0; i < grid->rows; i++) {
        free(grid->cells[i]);
    }
    free(grid->cells);
    free(grid);
}