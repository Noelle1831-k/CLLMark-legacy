void GameManager::startGame() {
    cout << "Welcome to Picture Perfect!" << endl;
    while (currentLevel <= maxLevels) {
        GameLevel level(currentLevel);
        level.loadLevel();
        PuzzleBoard board(4, 4); 
        if (level.checkSolution(board)) {
            cout << "Level " << currentLevel << " completed!" << endl;
            ++currentLevel;
        } else {
            cout << "Try again!" << endl;
        }
    }
    endGame();
}