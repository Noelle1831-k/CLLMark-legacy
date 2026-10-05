void createBoard(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->grid[i][j] = rand() % 5; 
            board->matches[i][j] = 0; 
        }
    }
}