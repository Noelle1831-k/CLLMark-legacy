void removePiece(PuzzleBoard *board, int pieceId) {
    for (int i = 0; i < board->pieceCount; i++) {
        if (board->pieces[i].id == pieceId) {
            for (int j = i; j < board->pieceCount - 1; j++) {
                board->pieces[j] = board->pieces[j + 1];
            }
            board->pieceCount--;
            break;
        }
    }
}