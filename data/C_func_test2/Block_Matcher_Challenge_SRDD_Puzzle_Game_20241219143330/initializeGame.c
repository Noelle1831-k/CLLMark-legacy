void initializeGame(Game *game) {
    game->currentLevel = 1;
    game->score = 0;
    game->remainingMoves = 20; 
    game->isGameOver = 0;
    createBoard(&game->board);
}