int main() {
    printf("=========================================\n");
    printf("  Welcome to the Pattern Block Challenge!\n");
    printf("=========================================\n\n");
    GameEngine *engine = create_game_engine();
    if (!load_levels(engine)) {
        printf("Error: Failed to load levels. Exiting...\n");
        destroy_game_engine(engine);
        return 1;
    }
    run_game(engine);
    destroy_game_engine(engine);
    printf("\n=========================================\n");
    printf(" Thank you for playing Pattern Block Challenge!\n");
    printf("=========================================\n");
    return 0;
}