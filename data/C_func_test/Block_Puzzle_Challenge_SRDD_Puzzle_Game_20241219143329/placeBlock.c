int placeBlock(char grid[GRID_SIZE][GRID_SIZE], Block block, int x, int y) {
    for (int i = 0; i < block.height; i++) {
        for (int j = 0; j < block.width; j++) {
            if (block.shape[i][j] == '#' &&
                (x + i >= GRID_SIZE || y + j >= GRID_SIZE || grid[x + i][y + j] != '.')) {
                return 0; 
            }
        }
    }
    for (int i = 0; i < block.height; i++) {
        for (int j = 0; j < block.width; j++) {
            if (block.shape[i][j] == '#') {
                grid[x + i][y + j] = '#';
            }
        }
    }
    return 1; 
}