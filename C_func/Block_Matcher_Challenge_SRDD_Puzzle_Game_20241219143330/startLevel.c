void startLevel(Game *game) {
    printf("Starting Level %d\n", game->currentLevel);
    createBoard(&game->board);
    game->remainingMoves = 20; 
}