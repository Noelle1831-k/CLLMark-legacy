void Game::run() {
    bool isRunning = true;
    while (isRunning) {
        processInput();
        updateEntities();
        detectCollisions();
        renderGameState();
        if (player.getHealth() <= 0) {
            isRunning = false;
            cout << "Game Over! Final Score: " << score.getCurrentScore() << endl;
        }
    }
}