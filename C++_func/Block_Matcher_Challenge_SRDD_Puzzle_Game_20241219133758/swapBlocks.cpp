bool Board::swapBlocks(int x1, int y1, int x2, int y2) {
    if (isValidCoordinate(x1, y1) && isValidCoordinate(x2, y2)) {
        Block temp = grid[x1][y1];
        grid[x1][y1] = grid[x2][y2];
        grid[x2][y2] = temp;
        return true;
    }
    return false;
}