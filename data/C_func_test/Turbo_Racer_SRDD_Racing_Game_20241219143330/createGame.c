Game* createGame() {
    Game* game = (Game*)malloc(sizeof(Game));
    game->vehicle = createVehicle();
    game->track = createTrack();
    game->ui = createUI();
    game->gameState = GAME_RUNNING;
    game->score = 0;
    return game;
}