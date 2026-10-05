void dropBlocks(Board *board) {
    for (int j = 0; j < BOARD_SIZE; j++) {
        for (int i = BOARD_SIZE - 1; i >= 0; i--) {
            if (board->grid[i][j] == -1) {
                for (int k = i; k > 0; k--) {
                    board->grid[k][j] = board->grid[k - 1][j];
                }
                board->grid[0][j] = rand() % 5; 
            }
        }
    }
}