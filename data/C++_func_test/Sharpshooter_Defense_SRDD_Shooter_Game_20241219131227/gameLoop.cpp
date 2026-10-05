void Game::gameLoop() {
    while (true) {
        spawnEnemies();
        checkCollisions();
        updateGameState();
        if (isGameOver()) {
            printf("Game Over!\n");
            break;
        }
    }
}