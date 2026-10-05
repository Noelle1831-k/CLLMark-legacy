GameState* createGameState() {
    GameState *state = (GameState*)malloc(sizeof(GameState));
    for (int i = 0; i < 4; i++) {
        state->playerPositions[i] = 0;
        state->resources[i] = 0;
        state->objectives[i] = 0;
        state->playerScores[i] = 0;
    }
    return state;
}