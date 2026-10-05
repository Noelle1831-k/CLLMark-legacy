void cleanup_game(Game *game) {
    printf("Cleaning up resources...\n");
    free_inventory(&(game->player.inventory));
    cleanup_world(&(game->world));
    printf("Game resources cleaned successfully.\n");
}