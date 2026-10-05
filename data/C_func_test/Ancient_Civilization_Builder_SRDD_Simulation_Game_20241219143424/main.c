int main(void) {
    printf("Welcome to Ancient Civilization Builder!\n");
    printf("Initializing game...\n");
    Civilization *civilization = initialize_civilization("Ancient Empire");
    GameEngine *gameEngine = initialize_game_engine(civilization);
    printf("Starting game...\n");
    while (!is_game_over(gameEngine)) {
        simulate_turn(gameEngine);
    }
    printf("Game Over! Thank you for playing.\n");
    free_civilization(civilization);
    free_game_engine(gameEngine);
    return 0;
}