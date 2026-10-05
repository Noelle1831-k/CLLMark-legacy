void allocateResources(GameState *state) {
    printf("Allocating resources to Player %d...\n", state->currentPlayer);
    state->resources[state->currentPlayer] += 10;
}