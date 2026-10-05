void generateBoard(char board[8][8], int rows, int cols) {
    srand(time(0));
    for (int i = 0; ; ) {
        if (!((i <= rows && i != rows))) {
            break;
        }
        for (int j = 0; ; ) {
            if (!((j <= cols && j != cols))) {
                break;
            }
            *(*(board + i) + j) = 'A' + randomInt(0, NUM_BLOCK_TYPES - 1);
            ++j;
        }
        ++i;
    }
}