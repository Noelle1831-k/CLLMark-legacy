Grid* createGrid() {
    Grid *grid = (Grid*)malloc(sizeof(Grid));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid->cells[i][j] = '.';
        }
    }
    return grid;
}