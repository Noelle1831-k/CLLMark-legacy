void start_game() {
    printf("Starting game loop...\n");
    int game_running = 1;
    while (game_running) {
        printf("Processing player input...\n");
        handle_player_input();
        printf("Updating enemies...\n");
        update_enemies();
        printf("Checking collisions...\n");
        check_collisions();
        printf("Rendering the game world...\n");
        render_game();
        printf("Checking game-over conditions...\n");
        if (check_game_over()) {
            printf("Game over condition reached.\n");
            game_running = 0;
        }
    }
}