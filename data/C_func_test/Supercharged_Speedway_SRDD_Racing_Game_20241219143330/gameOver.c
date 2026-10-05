int gameOver(Game *game) {
    return game->vehicle.position >= game->track.length; 
}