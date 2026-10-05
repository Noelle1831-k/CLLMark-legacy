void freeGame(Game *game) {
    free(game->player->vehicle);
    free(game->player);
    free(game->track);
    free(game);
}