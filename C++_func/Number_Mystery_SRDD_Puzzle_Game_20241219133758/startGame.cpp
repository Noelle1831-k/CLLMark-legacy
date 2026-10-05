void GameManager::startGame() {
    displayWelcomeMessage();
    while (!levelManager.isGameComplete()) {
        levelManager.loadNextLevel();
        if (levelManager.isHintNeeded()) {
            hintSystem.provideHint();
        }
    }
    cout << "Congratulations! You've completed all levels!" << endl;
}