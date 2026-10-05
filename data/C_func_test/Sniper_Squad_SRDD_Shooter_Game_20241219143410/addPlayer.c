void addPlayer(Game *game, const char *name) {
    if (MAX_PLAYERS > game->playerCount) {
        initializePlayer(&game->players[game->playerCount], name);
        game->playerCount++;
    }
}