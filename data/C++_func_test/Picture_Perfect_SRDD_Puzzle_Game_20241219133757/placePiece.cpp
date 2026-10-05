bool PuzzleBoard::placePiece(PuzzlePiece* piece, int x, int y) {
    if (x >= 0 && x < rows && y >= 0 && y < cols && boardGrid[x][y] == nullptr) {
        boardGrid[x][y] = piece;
        piece->setPosition(x, y);
        return true;
    }
    return false;
}