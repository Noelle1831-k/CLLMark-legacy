int main() {
    Game *game = createGame();
    if (game == NULL) {
        fprintf(stderr, "Failed to initialize game.\n");
        return EXIT_FAILURE;
    }
    printf("Welcome to Air Combat Squadron!\n");
    printf("Press 'W' to move up, 'S' to move down, 'A' to move left, 'D' to move right.\n");
    startGame(game);
    destroyGame(game);
    return EXIT_SUCCESS;
}