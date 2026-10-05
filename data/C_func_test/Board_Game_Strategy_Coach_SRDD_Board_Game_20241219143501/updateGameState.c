void updateGameState(GameState *state) {
    for (int i = 0; i < 4; i++) {
        state->playerPositions[i] += (state->resources[i] % 3) + 1;
        state->resources[i] += (state->playerPositions[i] % 2) + 1;
        state->objectives[i] = (state->playerPositions[i] + state->resources[i]) % 10;
        state->playerScores[i] = state->playerPositions[i] + state->resources[i];
    }
}