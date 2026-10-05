void updateGame(Game *game, char input) {
    updateMission(game->currentMission);
    updateAircraft(game->playerAircraft, input);
    checkCollisions(game);
}