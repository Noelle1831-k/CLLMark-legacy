void evaluateCounterMoves(const GameState *state) {
    printf("Evaluating counter-moves...\n");
    if (state->resources[(state->currentPlayer + 1) % 4] > state->resources[state->currentPlayer]) {
        printf("Opponent may try to outbid you for resources.\n");
    } else {
        printf("Opponent is currently in a weaker position.\n");
    }
}