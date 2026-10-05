void renderGame(Game *game) {
    renderVehicle(&game->vehicle);
    renderTrack(&game->track);
    renderPowerUps(&game->powerUp);
    printf("Current score: %d\n", game->score);
}