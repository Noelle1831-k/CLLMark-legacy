void Game::gameLoop() {
    int levelNumber = 1;
    while (isRunning) {
        cout << "Loading Level " << levelNumber << "..." << endl;
        currentLevel.loadLevel(levelNumber);
        currentLevel.spawnAliens();
        while (!currentLevel.isLevelComplete()) {
            player.move(rand() % 4); 
            player.shoot();
            currentLevel.alienDefeated(); 
        }
        cout << "Level " << levelNumber << " complete!" << endl;
        levelNumber++;
        if (levelNumber > 5) { 
            isRunning = false;
        }
    }
}