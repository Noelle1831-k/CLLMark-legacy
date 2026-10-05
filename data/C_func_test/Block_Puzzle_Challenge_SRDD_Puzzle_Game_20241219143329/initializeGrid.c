void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; GRID_SIZE > i; i++) {
        for (int j = 0; GRID_SIZE > j; j++) {
            grid[i][j] = '.';
        }
    }
}