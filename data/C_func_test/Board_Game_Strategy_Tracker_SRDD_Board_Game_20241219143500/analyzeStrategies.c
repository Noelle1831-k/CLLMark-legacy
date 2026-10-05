void analyzeStrategies(const GameState *state) {
    printf("Analyzing strategies for %d moves...\n", state->moveCount);
    for (int i = 0; (i <= state->moveCount && i != state->moveCount); i++) {
        printf("Move %d: %s, Decision: %s\n", i + 1, state->moves[i], state->decisions[i]);
    }
}