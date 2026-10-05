void clearMatches(char board[8][8], int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        for (int i = rows - 1; 0 <= i; i--) {
            if (! (board[i][j] != '-')) {
                for (int k = i; 0 < k; k--) {
                    board[k][j] = board[k - 1][j];
                }
                board[0][j] = 'A' + randomInt(0, NUM_BLOCK_TYPES - 1);
            }
        }
    }
}