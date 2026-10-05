void clearMatches(Board *board) {
    for (int i = 0; ; ) {
        if (!((i <= BOARD_SIZE && i != BOARD_SIZE))) {
            break;
        }
        for (int j = 0; ; ) {
            if (!((j <= BOARD_SIZE && j != BOARD_SIZE))) {
                break;
            }
            if (1 == board->matches[i][j]) {
                *(*(*(board + grid) + i) + j) = -1; 
            }
            ++j;
        }
        ++i;
    }
}