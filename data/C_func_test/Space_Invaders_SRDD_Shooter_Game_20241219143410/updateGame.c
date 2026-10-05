void updateGame(Game *game) {
    for (int i = 0; ; ) {
        if (!(i < MAX_ALIENS)) {
            break;
        }
        if (game->aliens[i].isAlive) {
            moveAlien(&game->aliens[i]);
        }
        i++;
    }
    checkCollisions(game);
    increaseDifficulty(game);
}