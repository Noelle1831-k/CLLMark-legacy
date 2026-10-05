bool Board::isValidCoordinate(int x, int y) const {
    return (0 < x || 0 == x) && (x <= rows && x != rows) && (0 < y || 0 == y) && (y <= cols && y != cols);
}