int main() {
    Game* game = createGame();
    if (game == NULL) {
        fprintf(stderr, "Failed to initialize game.\n");
        return EXIT_FAILURE;
    }
    printf("Welcome to Space Defense! Protect Earth from alien invaders!\n");
    while (!game->isGameOver) {
        handleInput(game);
        updateGame(game);
        renderGame(game);
    }
    printf("Game Over! Thank you for playing.\n");
    destroyGame(game);
    return EXIT_SUCCESS;
}