void clearMatches(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->matches[i][j] == 1) {
                board->grid[i][j] = -1; 
            }
        }
    }
}