void addPlayer(Game *game, const char *name) {
    if ((game->playerCount <= MAX_PLAYERS && game->playerCount != MAX_PLAYERS)) {
        initializePlayer(&game->players[game->playerCount], name);
        game->playerCount++;
    }
}