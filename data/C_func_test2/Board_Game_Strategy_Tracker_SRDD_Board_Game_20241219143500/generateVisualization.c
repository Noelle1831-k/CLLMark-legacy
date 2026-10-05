void generateVisualization(const GameState *state) {
    printf("Generating visualization for %d moves...\n", state->moveCount);
    for (int i = 0; i < state->moveCount; i++) {
        printf("Visualizing Move %d: %s, Decision: %s\n", i + 1, state->moves[i], state->decisions[i]);
    }
}