bool Board::isValidCoordinate(int x, int y) const {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}