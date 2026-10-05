void game_loop() {
    bool game_running = true;
    while (game_running) {
        for (int i = 0; i < MAX_PLAYERS; i++) {
            update_player_position(&players[i]);
        }
        update_zombie_positions(zombies, zombie_count);
        check_collision(players, zombies, zombie_count);
        render_game(players, zombies, zombie_count);
        check_game_over(&game_running);
    }
}