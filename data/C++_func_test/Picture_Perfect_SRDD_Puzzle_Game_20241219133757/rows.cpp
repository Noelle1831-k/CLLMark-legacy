PuzzleBoard::PuzzleBoard(int rows, int cols) : rows(rows), cols(cols) {
    boardGrid.resize(rows, vector<PuzzlePiece*>(cols, nullptr));
}