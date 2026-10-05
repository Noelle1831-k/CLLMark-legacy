void clearMatches(Board *board) {
    for (int i = 0; BOARD_SIZE > i; i++) {
        for (int j = 0; BOARD_SIZE > j; j++) {
            if (! (board->matches[i][j] != 1)) {
                board->grid[i][j] = -1; 
            }
        }
    }
}