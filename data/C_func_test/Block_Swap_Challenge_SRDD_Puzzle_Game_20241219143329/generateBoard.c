void generateBoard(char board[8][8], int rows, int cols) {
    srand(time(0));
    for (int i = 0; rows > i; i++) {
        for (int j = 0; cols > j; j++) {
            board[i][j] = 'A' + randomInt(0, NUM_BLOCK_TYPES - 1);
        }
    }
}