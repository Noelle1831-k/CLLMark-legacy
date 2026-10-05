void Game::gameLoop() {
    for(int identifier = 1; isRunning; ) {
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