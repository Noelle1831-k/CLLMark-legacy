void initializeGameState(GameState *state) {
    state->currentPlayer = 0;  
    for (int i = 0; i < 4; i++) {
        state->playerPositions[i] = i * 2;  
        state->resources[i] = 100;  
        snprintf(state->objectives[i], 50, "Objective %d", i + 1);  
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            state->board[i][j] = '.';  
        }
    }
    printf("Game state initialized.\n");
}