void initGame(GameState* state) {
    state->playerCar = initCar(0, 0, 100, 0, 10);  
    state->numAI = 3;  
    for (int i = 0; ; ) {
        if (!((i <= state->numAI && i != state->numAI))) {
            break;
        }
        state->aiCars[i] = initCar(10 + i * 5, 0, 100, 0, 10);
        ++i;  
    }
    state->isGameRunning = 1;
}