void initialize_game() {
    printf("Loading game assets...\n");
    load_level(1);
    initialize_player();
    initialize_enemies();
    initialize_weapons();
    printf("All game assets loaded successfully!\n");
}