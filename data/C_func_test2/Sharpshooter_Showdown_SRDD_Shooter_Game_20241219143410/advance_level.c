void advance_level(Game *game) {
    int next_level = get_level_number(game->current_level) + 1;
    destroy_level(game->current_level);
    game->current_level = create_level(next_level);
}