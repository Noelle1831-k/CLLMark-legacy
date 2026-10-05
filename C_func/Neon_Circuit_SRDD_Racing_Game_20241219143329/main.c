int main() {
    if (!initializeGame()) {
        fprintf(stderr, "Failed to initialize game.\n");
        return EXIT_FAILURE;
    }
    while (!isGameOver()) {
        processInput();
        updateGame();
        renderGame();
        playBackgroundMusic();
    }
    cleanupGame();
    return EXIT_SUCCESS;
}