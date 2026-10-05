Game* createGame() {
    Game *game = (Game*)malloc(sizeof(Game));
    if (!game) return NULL;
    game->currentMission = createMission();
    game->playerAircraft = createAircraft();
    game->score = 0;
    game->isRunning = 1;
    return game;
}