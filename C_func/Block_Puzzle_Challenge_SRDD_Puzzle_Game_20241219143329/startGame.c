void startGame() {
    printf("\nStarting the game...\n");
    GameState state;
    initializeGame(&state);
    runGameLoop(&state);
    saveScoreToLeaderboard(state.score);
    printf("Game Over! Your score: %d\n", state.score);
}