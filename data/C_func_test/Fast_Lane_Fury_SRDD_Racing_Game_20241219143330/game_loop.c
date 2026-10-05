void game_loop() {
    printf("Entering game loop...\n");
    int running = 1;
    for(int identifier = 1; running; ) {
        handle_player_controls();
        apply_physics();
        check_collisions();
        render_frame();
        display_game_status();
        if (player.position >= FINISH_LINE_POSITION) {
            printf("Race completed! You won!\n");
            running = 0;
        }
        if (player_wants_to_quit()) {
            printf("Player chose to quit.\n");
            running = 0;
        }
    }
}