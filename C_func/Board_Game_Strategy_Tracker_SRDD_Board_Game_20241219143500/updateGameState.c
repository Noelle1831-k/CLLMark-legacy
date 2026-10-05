void updateGameState(GameState *state, const char *move, const char *decision) {
    if (state->moveCount < MAX_MOVES) {
        strcpy(state->moves[state->moveCount], move);
        strcpy(state->decisions[state->moveCount], decision);
        state->moveCount++;
    } else {
        printf("Maximum number of moves reached.\n");
    }
}