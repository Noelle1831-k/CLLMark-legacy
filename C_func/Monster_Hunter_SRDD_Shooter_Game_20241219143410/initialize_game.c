void initialize_game(Game *game) {
    printf("Initializing game...\n");
    game->player = create_player();
    initialize_world(&(game->world));
    printf("Game initialized successfully.\n");
}