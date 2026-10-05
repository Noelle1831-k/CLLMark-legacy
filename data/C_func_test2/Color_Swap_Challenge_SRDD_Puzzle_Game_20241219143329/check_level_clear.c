int check_level_clear(const Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE - 2; j++) {
            if (board->grid[i][j] == board->grid[i][j+1] && board->grid[i][j+1] == board->grid[i][j+2]) {
                return 0;  
            }
        }
    }
    for (int j = 0; j < BOARD_SIZE; j++) {
        for (int i = 0; i < BOARD_SIZE - 2; i++) {
            if (board->grid[i][j] == board->grid[i+1][j] && board->grid[i+1][j] == board->grid[i+2][j]) {
                return 0;  
            }
        }
    }
    return 1;  
}