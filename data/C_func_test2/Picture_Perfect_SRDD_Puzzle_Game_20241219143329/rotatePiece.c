void rotatePiece(PuzzleBoard *board, int pieceId) {
    for (int i = 0; i < board->pieceCount; i++) {
        if (board->pieces[i].id == pieceId) {
            rotate(&board->pieces[i]);
            break;
        }
    }
}