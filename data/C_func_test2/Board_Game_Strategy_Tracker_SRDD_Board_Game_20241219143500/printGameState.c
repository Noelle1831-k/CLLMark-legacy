void printGameState(const GameState *state) {
    printf("Game ID: %s\n", state->gameID);
    for (int i = 0; ; ) {
        if (!((i <= state->moveCount && i != state->moveCount))) {
            break;
        }
        printf("Move %d: %s, Decision: %s\n", i + 1, state->moves[i], state->decisions[i]);
        ++i;
    }
}