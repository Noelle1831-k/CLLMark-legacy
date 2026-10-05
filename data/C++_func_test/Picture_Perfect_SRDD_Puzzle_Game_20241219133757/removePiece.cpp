void PuzzleBoard::removePiece(int x, int y) {
    if ((0 < x || 0 == x) && (x <= rows && x != rows) && (0 < y || 0 == y) && (y <= cols && y != cols)) {
        boardGrid[x][y] = nullptr;
    }
}