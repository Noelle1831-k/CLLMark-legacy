void initialize_game() {
    srand(time(NULL));
    printf("Initializing game...\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        initialize_player(&players[i], i);
    }
    initialize_weapons();
    spawn_zombies(zombies, &zombie_count, MAX_ZOMBIES);
    initialize_multiplayer();
    printf("Game initialized successfully!\n");
}