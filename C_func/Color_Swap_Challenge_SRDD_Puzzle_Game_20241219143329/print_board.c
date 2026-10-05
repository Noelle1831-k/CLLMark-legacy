void print_board(const Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%s ", colors[board->grid[i][j]]);
        }
        printf("\n");
    }
}