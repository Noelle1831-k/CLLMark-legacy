int initializeGame(Game* game) {
    if (!game) {
        return -1;
    }
    initializeVehicle(game->vehicle);
    initializeTrack(game->track);
    initializeUI(game->ui);
    return 0;
}