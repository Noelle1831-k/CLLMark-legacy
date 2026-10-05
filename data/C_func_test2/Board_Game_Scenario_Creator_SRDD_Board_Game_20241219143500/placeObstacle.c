void placeObstacle(Board *board, int x, int y) {
    if (x >= 0 && x < board->width && y >= 0 && y < board->height) {
        board->grid[x][y] = 'O';  
    } else {
        printf("Invalid position for obstacle.\n");
    }
}