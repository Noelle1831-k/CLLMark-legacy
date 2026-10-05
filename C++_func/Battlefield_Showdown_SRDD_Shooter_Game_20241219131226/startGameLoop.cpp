void Game::startGameLoop() {
    cout << "Starting game loop..." << endl;
    bool gameRunning = true;
    while (gameRunning) {
        processPlayerActions();
        updateGameState();
        checkWinConditions(gameRunning);
    }
    networkManager.disconnect();
    cout << "Game has ended." << endl;
}