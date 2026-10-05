void placeBonus(Board *board, int x, int y) {
    if ((0 < x || 0 == x) && (x <= board->width && x != board->width) && (0 < y || 0 == y) && (y <= board->height && y != board->height)) {
        *(*(*(board + grid) + x) + y) = 'B';  
    } else {
        printf("Invalid position for bonus.\n");
    }
}