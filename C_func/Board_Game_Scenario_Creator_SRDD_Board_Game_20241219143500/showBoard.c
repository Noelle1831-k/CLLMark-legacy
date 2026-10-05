void showBoard(Board *board) {
    for (int i = 0; i < board->width; i++) {
        for (int j = 0; j < board->height; j++) {
            printf("%c ", board->grid[i][j]);
        }
        printf("\n");
    }
}