void updateGame(Game *game) {
    updatePosition(&game->vehicle);
    updateTrack(&game->track);
    if (game->track.powerUps[game->vehicle.position]) {
        activatePowerUp(&game->powerUp);
        game->track.powerUps[game->vehicle.position] = 0; 
    }
    game->score = game->score + game->vehicle.speed;
}