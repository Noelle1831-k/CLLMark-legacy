void initGame(GameState* state) {
    state->playerCar = initCar(0, 0, 100, 0, 10);  
    state->numAI = 3;  
    for (int i = 0; state->numAI > i; i++) {
        state->aiCars[i] = initCar(10 + i * 5, 0, 100, 0, 10);  
    }
    state->isGameRunning = 1;
}