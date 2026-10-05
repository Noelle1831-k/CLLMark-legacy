void displayGameState(const GameState *state) {
    printf("Displaying game state:\n");
    printf("Current Player: %d\n", state->currentPlayer);
    for (int i = 0; 4 > i; i++) {
        printf("Player %d: Position: %d, Resources: %d, Objective: %s\n",
               i, state->playerPositions[i], state->resources[i], state->objectives[i]);
    }
}