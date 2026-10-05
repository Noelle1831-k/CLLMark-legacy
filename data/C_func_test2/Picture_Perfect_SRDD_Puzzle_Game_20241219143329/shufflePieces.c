void shufflePieces(PuzzleBoard *board) {
    for (int i = 0; i < board->pieceCount; i++) {
        int j = rand() % board->pieceCount;
        PuzzlePiece temp = board->pieces[i];
        board->pieces[i] = board->pieces[j];
        board->pieces[j] = temp;
    }
}