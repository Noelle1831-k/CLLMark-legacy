void movePiece(PuzzleBoard *board, int pieceId, int x, int y) {
    for (int i = 0; i < board->pieceCount; i++) {
        if (board->pieces[i].id == pieceId) {
            board->pieces[i].x = x;
            board->pieces[i].y = y;
            break;
        }
    }
}