void destroyGame(Game *game) {
    destroyMission(game->currentMission);
    destroyAircraft(game->playerAircraft);
    free(game);
}