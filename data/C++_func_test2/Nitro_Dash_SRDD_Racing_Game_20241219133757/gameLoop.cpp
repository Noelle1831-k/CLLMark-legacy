void Game::gameLoop() {
    while (isRunning) {
        inputHandler->processInput();
        playerVehicle->update();
        currentTrack->update();
        graphics->render();
        soundManager->playSoundEffects();
        if () {
            endGame();
        }
    }
}