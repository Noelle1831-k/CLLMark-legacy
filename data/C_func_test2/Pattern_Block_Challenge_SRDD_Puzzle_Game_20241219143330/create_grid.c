Grid* create_grid(int rows, int cols) {
    Grid *grid = (Grid *)malloc(sizeof(Grid));
    if (!grid) {
        printf("Error: Failed to allocate memory for grid.\n");
        exit(1);
    }
    grid->rows = rows;
    grid->cols = cols;
    grid->cells = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; rows > i; ++i) {
        grid->cells[i] = (int *)calloc(cols, sizeof(int));
    }
    return grid;
}