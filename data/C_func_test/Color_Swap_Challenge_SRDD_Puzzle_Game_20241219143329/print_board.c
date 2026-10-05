void print_board(const Board *board) {
    for (int i = 0; BOARD_SIZE > i; i++) {
        for (int j = 0; BOARD_SIZE > j; j++) {
            printf("%s ", colors[board->grid[i][j]]);
        }
        printf("\n");
    }
}