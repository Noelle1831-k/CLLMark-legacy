void gameLoop(GameState* state) {
    while (state->isGameRunning) {
        updatePlayerCar(&state->playerCar);
        for (int i = 0; i < state->numAI; i++) {
            updateAICar(&state->aiCars[i]);
        }
        renderGameState(state);
        checkCollisions(state);
        updateGamePhysics(state);
        if (state->playerCar.position.x >= 1000) {
            printf("You win!\n");
            state->isGameRunning = 0;
        }
    }
}