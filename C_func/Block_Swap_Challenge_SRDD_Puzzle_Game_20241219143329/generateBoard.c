void generateBoard(char board[8][8], int rows, int cols) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = 'A' + randomInt(0, NUM_BLOCK_TYPES - 1);
        }
    }
}