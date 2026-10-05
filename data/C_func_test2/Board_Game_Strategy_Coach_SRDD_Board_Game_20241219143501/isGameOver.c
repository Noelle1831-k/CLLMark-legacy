int isGameOver(GameState *state) {
    for (int i = 0; i < 4; i++) {
        if (state->playerScores[i] >= 50) return 1;
    }
    return 0;
}