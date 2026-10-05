void updateGame(Game *game) {
    for (int i = 0; i < MAX_ALIENS; i++) {
        if (game->aliens[i].isAlive) {
            moveAlien(&game->aliens[i]);
        }
    }
    checkCollisions(game);
    increaseDifficulty(game);
}