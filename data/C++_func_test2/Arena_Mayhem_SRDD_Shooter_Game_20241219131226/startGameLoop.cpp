void GameEngine::startGameLoop() {
    while (true) {
        handleInput();
        updateGameState();
        render();
    }
}