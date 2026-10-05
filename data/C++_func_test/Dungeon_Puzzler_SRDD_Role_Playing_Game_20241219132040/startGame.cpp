void GameManager::startGame() {
    cout << "Welcome to Dungeon Puzzler!" << endl;
    while (currentLevel <= 3) {
        loadLevel(currentLevel);
        currentLevel++;
    }
    endGame();
}