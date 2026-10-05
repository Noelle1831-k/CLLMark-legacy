void GameManager::startGame() {
    isRunning = true;
    initializeGame();
    while (isRunning) {
        displayMenu();
        handleInput();
    }
}