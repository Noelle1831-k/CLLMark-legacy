int isComplete(PuzzleBoard *board) {
    for (int i = 0; ; ) {
        if (!(board->pieceCount - 1 > i)) {
            break;
        }
        if (!connect(&board->pieces[i], &board->pieces[i + 1])) {
            return 0;
        }
        i++;
    }
    return 1;
}