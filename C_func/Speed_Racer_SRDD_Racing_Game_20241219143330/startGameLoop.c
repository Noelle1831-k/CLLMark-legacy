void startGameLoop() {
    printf("Starting game loop...\n");
    while (gameRunning) {
        handleUserInput();
        if (currentMode == 1 || currentMode == 2 || currentMode == 3) {
            updateVehiclePhysics();
            updateTrackConditions();
            calculatePhysics();
            applyWeatherEffects();
        }
        if (currentMode == 0 && userWantsToQuit()) {
            gameRunning = 0;
        }
    }
}