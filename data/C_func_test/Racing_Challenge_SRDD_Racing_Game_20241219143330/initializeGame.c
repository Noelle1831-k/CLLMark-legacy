Game *initializeGame() {
    Game *game = (Game *)malloc(sizeof(Game));
    game->track = NULL;
    game->player = (Player *)malloc(sizeof(Player));
    game->player->vehicle = NULL;
    game->player->position = 0;
    game->player->score = 0;
    return game;
}