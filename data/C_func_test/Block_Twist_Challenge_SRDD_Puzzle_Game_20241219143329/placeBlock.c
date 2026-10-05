int placeBlock(Grid *grid, Block *block, int rotation) {
    rotateBlock(block, rotation);
    for (int i = 0; i < block->rows; i++) {
        for (int j = 0; j < block->cols; j++) {
            int x = block->x + i;
            int y = block->y + j;
            if (x >= grid->rows || y >= grid->cols || x < 0 || y < 0) {
                return 0;
            }
            if (block->shape[i][j] == 1 && grid->cells[x][y] != 0) {
                return 0;
            }
        }
    }
    for (int i = 0; i < block->rows; i++) {
        for (int j = 0; j < block->cols; j++) {
            int x = block->x + i;
            int y = block->y + j;
            if (block->shape[i][j] == 1) {
                grid->cells[x][y] = 1;
            }
        }
    }
    return 1;
}