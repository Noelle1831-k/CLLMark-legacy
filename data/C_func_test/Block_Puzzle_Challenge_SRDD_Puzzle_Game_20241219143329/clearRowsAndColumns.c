int clearRowsAndColumns(char grid[GRID_SIZE][GRID_SIZE]) {
    int cleared = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        int fullRow = 1;
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == '.') {
                fullRow = 0;
                break;
            }
        }
        if (fullRow) {
            for (int j = 0; j < GRID_SIZE; j++) {
                grid[i][j] = '.';
            }
            cleared++;
        }
    }
    for (int j = 0; j < GRID_SIZE; j++) {
        int fullColumn = 1;
        for (int i = 0; i < GRID_SIZE; i++) {
            if (grid[i][j] == '.') {
                fullColumn = 0;
                break;
            }
        }
        if (fullColumn) {
            for (int i = 0; i < GRID_SIZE; i++) {
                grid[i][j] = '.';
            }
            cleared++;
        }
    }
    return cleared;
}