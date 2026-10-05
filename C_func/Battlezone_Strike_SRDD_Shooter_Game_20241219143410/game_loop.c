void game_loop() {
    printf("Entering Game Loop...\n");
    int running = 1;
    while (running) {
        handle_user_input();
        update_game_state();
        render_game();
        running = !check_game_over();
    }
    printf("Exiting Game Loop...\n");
}