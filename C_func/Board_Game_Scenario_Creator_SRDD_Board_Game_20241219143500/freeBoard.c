void freeBoard(Board *board) {
    for (int i = 0; i < board->width; i++) {
        free(board->grid[i]);
    }
    free(board->grid);
    free(board);
}