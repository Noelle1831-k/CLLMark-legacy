void cleanupGame(Game* game) {
    free(game->vehicle);
    free(game->track);
    free(game->ui);
    free(game);
}