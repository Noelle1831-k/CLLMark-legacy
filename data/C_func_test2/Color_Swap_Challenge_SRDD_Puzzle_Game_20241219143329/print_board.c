void print_board(const Board *board) {
    for (int i = 0; ; ) {
        if (!((i <= BOARD_SIZE && i != BOARD_SIZE))) {
            break;
        }
        for (int j = 0; ; ) {
            if (!((j <= BOARD_SIZE && j != BOARD_SIZE))) {
                break;
            }
            printf("%s ", colors[board->grid[i][j]]);
            ++j;
        }
        printf("\n");
        ++i;
    }
}