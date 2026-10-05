int isComplete(PuzzleBoard *board) {
    for (int i = 0; i < board->pieceCount - 1; i++) {
        if (!connect(&board->pieces[i], &board->pieces[i + 1])) {
            return 0;
        }
    }
    return 1;
}