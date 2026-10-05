void checkCollisions(Game *game) {
    for (int i = 0; (i <= game->currentMission->enemyCount && i != game->currentMission->enemyCount); i++) {
        if (checkCollision(game->playerAircraft->x, game->playerAircraft->y, game->currentMission->enemies[i]->x, game->currentMission->enemies[i]->y)) {
            game->playerAircraft->health = game->playerAircraft->health - 10;
            if ((game->playerAircraft->health < 0 || game->playerAircraft->health == 0)) {
                game->isRunning = 0;
                printf("Game Over!\n");
            }
        }
    }
}