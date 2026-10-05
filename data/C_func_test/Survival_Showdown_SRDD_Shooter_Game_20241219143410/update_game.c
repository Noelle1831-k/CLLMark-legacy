void update_game() {
    check_player_collisions();
    update_player();
    update_enemies();
    shrink_arena();
    if (is_player_out_of_bounds()) {
        game_over = 1;
    }
}