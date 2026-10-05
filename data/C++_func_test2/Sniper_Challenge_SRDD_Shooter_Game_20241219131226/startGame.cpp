void GameEngine::startGame() {
    while (isRunning) {
        updateGame();
        renderGame();
        if (checkGameOver()) {
            cout << "All targets have been hit! Game Over!" << endl;
            isRunning = false;
        }
    }
}