void startGame(Game *game) {
    printf("Starting the game...\n");
    loadLevel(&game->level, 1);
    shufflePieces(&game->board);
}