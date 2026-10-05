void destroy_game(Game *game) {
    destroy_player(game->player);
    destroy_level(game->current_level);
    destroy_leaderboard(game->leaderboard);
    destroy_weapon(game->weapon);
    destroy_shooting_range(game->range);
    free(game);
}