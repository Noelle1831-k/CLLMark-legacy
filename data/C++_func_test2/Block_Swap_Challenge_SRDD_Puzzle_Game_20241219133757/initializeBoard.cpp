void Board::initializeBoard() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j].setType(rand() % 5 + 1);
        }
    }
}