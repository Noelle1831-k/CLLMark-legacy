void initializeGame(Game *game) {
    generateTrack(&game->track, 100);
    placePowerUps(&game->track);
    initializeVehicle(&game->vehicle, 10, 1);
    game->score = 0;
}