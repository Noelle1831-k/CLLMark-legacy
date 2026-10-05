int main() {
    srand((unsigned int)time(NULL));
    Game* game = createGame();
    if (initializeGame(game) != 0) {
        printf("Failed to initialize the game!\n");
        return -1;
    }
    printf("Welcome to Turbo Racer! Get ready for an adrenaline-pumping experience!\n");
    while (game->gameState != GAME_OVER) {
        updateGame(game);
        renderGame(game);
    }
    printf("Game Over! Your final score: %d\n", game->score);
    cleanupGame(game);
    return 0;
}