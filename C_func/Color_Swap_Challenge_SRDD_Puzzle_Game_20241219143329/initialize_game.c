void initialize_game(Game *game) {
    game->level = 1;
    game->moves_left = MAX_MOVES;
    game->score = 0;
    game->game_over = 0;
}