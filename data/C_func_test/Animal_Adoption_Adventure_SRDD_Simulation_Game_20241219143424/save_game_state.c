void save_game_state(Game* game) {
    printf("Saving game state...\n");
    FILE *file = fopen("savegame.txt", "w");
    if (file) {
        fprintf(file, "%d %d %d %d %d\n", game->is_running, game->funds, game->volunteers, game->animals_rescued, game->community_support);
        fclose(file);
    }
}