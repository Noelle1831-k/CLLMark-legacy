void PuzzleBoard::removePiece(int x, int y) {
    if (x >= 0 && x < rows && y >= 0 && y < cols) {
        boardGrid[x][y] = nullptr;
    }
}