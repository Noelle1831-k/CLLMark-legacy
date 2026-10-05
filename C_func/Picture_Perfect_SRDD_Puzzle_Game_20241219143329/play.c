void play(Game *game) {
    printf("Playing the game...\n");
    char command[10];
    int pieceId, rotation;
    while (!isComplete(&game->board)) {
        displayBoard(&game->board);
        printf("Enter command (rotate/move) and piece ID: ");
        scanf("%s %d", command, &pieceId);
        if (strcmp(command, "rotate") == 0) {
            rotatePiece(&game->board, pieceId);
        } else if (strcmp(command, "move") == 0) {
            printf("Enter new position (x y): ");
            int x, y;
            scanf("%d %d", &x, &y);
            movePiece(&game->board, pieceId, x, y);
        }
    }
    printf("Congratulations! You've completed the puzzle.\n");
}