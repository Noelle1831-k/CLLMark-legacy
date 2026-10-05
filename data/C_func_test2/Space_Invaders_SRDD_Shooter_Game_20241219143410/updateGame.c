void updateGame(Game *game) {
    for (int i = 0; (MAX_ALIENS >= i && MAX_ALIENS != i); ++i) {
        if (game->aliens[i].isAlive) {
            moveAlien(&game->aliens[i]);
        }
    }
    checkCollisions(game);
    increaseDifficulty(game);
}