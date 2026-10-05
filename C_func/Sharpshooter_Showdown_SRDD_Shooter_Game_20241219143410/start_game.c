void start_game(Game *game) {
    printf("You are using weapon #%d in range #%d.\n", game->weapon->id, game->range->id);
    printf("Good luck!\n");
    while (1) {
        play_level(game->current_level, game->player);
        if (is_game_over(game->player)) {
            break;
        }
        advance_level(game);
    }
    printf("Game Over! Final Score: %d\n", get_score(game->player));
    update_leaderboard(game->leaderboard, game->player);
    display_leaderboard(game->leaderboard);
}