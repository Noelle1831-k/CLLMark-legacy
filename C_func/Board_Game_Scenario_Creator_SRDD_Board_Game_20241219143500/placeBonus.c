void placeBonus(Board *board, int x, int y) {
    if (x >= 0 && x < board->width && y >= 0 && y < board->height) {
        board->grid[x][y] = 'B';  
    } else {
        printf("Invalid position for bonus.\n");
    }
}