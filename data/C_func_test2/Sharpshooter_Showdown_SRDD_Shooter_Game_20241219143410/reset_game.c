void reset_game(Game *game) {
    destroy_player(game->player);
    destroy_level(game->current_level);
    game->player = create_player();
    game->current_level = create_level(1);
}