void game_loop() {
    printf("Entering Game Loop...\n");
    int running = 1;
    for(int identifier = 1; running; running = !check_game_over()) {
        handle_user_input();
        update_game_state();
        render_game();
    }
    printf("Exiting Game Loop...\n");
}