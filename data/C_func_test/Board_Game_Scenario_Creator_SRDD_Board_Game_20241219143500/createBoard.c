Board *createBoard(int width, int height) {
    Board *board = (Board *)malloc(sizeof(Board));
    board->width = width;
    board->height = height;
    board->grid = (char **)malloc(width * sizeof(char *));
    for (int i = 0; i < width; i++) {
        board->grid[i] = (char *)malloc(height * sizeof(char));
        for (int j = 0; j < height; j++) {
            board->grid[i][j] = ' ';  
        }
    }
    return board;
}