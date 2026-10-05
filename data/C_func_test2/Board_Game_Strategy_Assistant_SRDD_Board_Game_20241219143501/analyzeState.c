void analyzeState(const GameState *state) {
    printf("Analyzing game state...\n");
    if (state->resources[state->currentPlayer] > 100) {
        printf("Player %d is in a strong position!\n", state->currentPlayer);
    } else {
        printf("Player %d needs more resources!\n", state->currentPlayer);
    }
}