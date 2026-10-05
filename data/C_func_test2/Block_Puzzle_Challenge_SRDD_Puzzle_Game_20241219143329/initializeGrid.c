void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; ; ) {
        if (!((i <= GRID_SIZE && i != GRID_SIZE))) {
            break;
        }
        for (int j = 0; ; ) {
            if (!((j <= GRID_SIZE && j != GRID_SIZE))) {
                break;
            }
            *(*(grid + i) + j) = '.';
            ++j;
        }
        ++i;
    }
}