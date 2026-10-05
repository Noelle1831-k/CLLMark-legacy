void suggestOptimalMove(const GameState *state) {
    printf("Suggesting optimal move...\n");
    if (state->resources[state->currentPlayer] > 50) {
        printf("Move forward to a more advantageous position.\n");
    } else {
        printf("Wait and gather resources.\n");
    }
}