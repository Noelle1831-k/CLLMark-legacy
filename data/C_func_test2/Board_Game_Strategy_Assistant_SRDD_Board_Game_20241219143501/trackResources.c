void trackResources(const GameState *state) {
    printf("Tracking resources...\n");
    for (int i = 0; i < 4; i++) {
        printf("Player %d has %d resources.\n", i, state->resources[i]);
    }
}