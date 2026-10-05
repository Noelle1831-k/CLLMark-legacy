bool PuzzleBoard::isComplete() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (boardGrid[i][j] == nullptr) {
                return false;
            }
        }
    }
    return true;
}