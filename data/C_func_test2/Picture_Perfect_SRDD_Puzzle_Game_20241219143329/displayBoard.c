void displayBoard(PuzzleBoard *board) {
    printf("Displaying board:\n");
    for (int i = 0; i < board->pieceCount; i++) {
        printf("Piece ID: %d, Rotation: %d, Position: (%d, %d)\n", 
               board->pieces[i].id, board->pieces[i].rotation, 
               board->pieces[i].x, board->pieces[i].y);
    }
}