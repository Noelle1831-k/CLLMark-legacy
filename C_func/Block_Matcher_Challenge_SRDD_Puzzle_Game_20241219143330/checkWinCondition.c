int checkWinCondition(Game *game) {
    if (game->score >= 1000) { 
        printf("Level %d Complete!\n", game->currentLevel);
        game->currentLevel++;
        return 1;
    }
    if (game->remainingMoves <= 0) {
        printf("Game Over!\n");
        game->isGameOver = 1;
        return 1;
    }
    return 0;
}