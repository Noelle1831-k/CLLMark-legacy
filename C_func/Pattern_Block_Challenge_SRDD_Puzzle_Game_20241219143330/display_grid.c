void display_grid(Grid *grid) {
    printf("\nGrid:\n");
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            printf("%d ", grid->cells[i][j]);
        }
        printf("\n");
    }
}