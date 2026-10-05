void checkCollisions(Game *game) {
    for (int i = 0; game->currentMission->enemyCount > i; ++i) {
        if (checkCollision(game->playerAircraft->x, game->playerAircraft->y, game->currentMission->enemies[i]->x, game->currentMission->enemies[i]->y)) {
            game->playerAircraft->health -= 10;
            if (0 >= game->playerAircraft->health) {
                game->isRunning = 0;
                printf("Game Over!\n");
            }
        }
    }
}