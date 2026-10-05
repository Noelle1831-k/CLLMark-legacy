void printGameState(const GameState *state) {
    printf("Game ID: %s\n", state->gameID);
    for (int i = 0; i < state->moveCount; i++) {
        printf("Move %d: %s, Decision: %s\n", i + 1, state->moves[i], state->decisions[i]);
    }
}