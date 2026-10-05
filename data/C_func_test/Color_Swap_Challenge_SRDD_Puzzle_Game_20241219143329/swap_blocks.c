void swap_blocks(Board *board, int x1, int y1, int x2, int y2) {
    int temp = board->grid[x1][y1];
    board->grid[x1][y1] = board->grid[x2][y2];
    board->grid[x2][y2] = temp;
}