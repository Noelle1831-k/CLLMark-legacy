void Game::run() {
    while (!isGameOver) {
        if (!currentLevel.isComplete()) {
            processInput();
            update();
            render();
        } else {
            cout << "Level Complete! Moving to the next level." << endl;
            currentLevel = Level(currentLevel.getLevelNumber() + 1);
        }
    }
    endGame();
}