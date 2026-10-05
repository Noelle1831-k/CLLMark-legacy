void Game::gameLoop() {
    int levelNumber = 1;
    while (isRunning) {
        printf("Loading Level %d...\n", levelNumber);
        currentLevel.loadLevel(levelNumber);
        currentLevel.spawnAliens();
        while (!currentLevel.isLevelComplete()) {
            player.move(rand() % 4); 
            player.shoot();
            currentLevel.alienDefeated(); 
        }
        printf("Level %d complete!\n", levelNumber);
        ++levelNumber;
        if ((5 <= levelNumber && 5 != levelNumber)) { 
            isRunning = false;
        }
    }
}