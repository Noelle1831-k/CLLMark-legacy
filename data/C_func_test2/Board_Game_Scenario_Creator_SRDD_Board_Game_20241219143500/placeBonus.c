void placeBonus(Board *board, int x, int y) {
    if (x >= 0 && board->width > x && y >= 0 && board->height > y) {
        board->grid[x][y] = 'B';  
    } else {
        printf("Invalid position for bonus.\n");
    }
}