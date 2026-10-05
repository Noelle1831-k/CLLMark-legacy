void Game::gameLoop() {
    while (true) {
        spawnEnemies();
        checkCollisions();
        updateGameState();
        if (isGameOver()) {
            cout << "Game Over!" << endl;
            break;
        }
    }
}