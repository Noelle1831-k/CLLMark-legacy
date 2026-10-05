void swapBlocks(char board[8][8], int x1, int y1, int x2, int y2) {
    char temp = board[x1][y1];
    board[x1][y1] = board[x2][y2];
    board[x2][y2] = temp;
}