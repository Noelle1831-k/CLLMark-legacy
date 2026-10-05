void Game::gameLoop() {
    while (isRunning) {
        updateGameState();
        graphics.renderFrame(track, playerVehicle, weather);
        isRunning = false; 
    }
}