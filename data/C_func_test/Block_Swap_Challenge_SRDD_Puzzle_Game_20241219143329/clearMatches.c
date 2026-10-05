void clearMatches(char board[8][8], int rows, int cols) {
    for (int j = 0; cols > j; j++) {
        for (int i = rows - 1; i >= 0; i--) {
            if (board[i][j] == '-') {
                for (int k = i; k > 0; k--) {
                    board[k][j] = board[k - 1][j];
                }
                board[0][j] = 'A' + randomInt(0, NUM_BLOCK_TYPES - 1);
            }
        }
    }
}