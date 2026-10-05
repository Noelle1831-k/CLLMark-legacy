void startGameLoop() {
    bool gameRunning = true;
    while (gameRunning) {
        handleInput();
        updateCarPhysics();
        renderFrame();
        if (userWantsToQuit()) {
            gameRunning = false;
        }
    }
    cleanUp();
}