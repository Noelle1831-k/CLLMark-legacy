void explainStrategy(const GameState *state) {
    printf("Explaining strategy...\n");
    if (state->resources[state->currentPlayer] > 50) {
        printf("You have enough resources to make an aggressive move.\n");
    } else {
        printf("It might be wise to gather more resources before taking action.\n");
    }
}