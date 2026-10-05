void checkCollisions(Game *game) {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (game->projectiles[i].active) {
            for (int j = 0; j < MAX_ALIENS; j++) {
                if (game->aliens[j].isAlive && detectCollision(game->projectiles[i].x, game->projectiles[i].y, game->aliens[j].x, game->aliens[j].y)) {
                    game->aliens[j].isAlive = 0;
                    game->projectiles[i].active = 0;
                    game->score += 10;
                }
            }
        }
    }
}