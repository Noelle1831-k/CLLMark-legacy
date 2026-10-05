void LevelManager::loadNextLevel() {
    if (!isGameComplete()) {
        currentLevel++;
        currentPuzzle.generatePuzzle(currentLevel);
        cout << "Level " << currentLevel << ": Solve the puzzle!" << endl;
    }
}