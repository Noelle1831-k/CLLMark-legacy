void Game::startGame() {
    while (!exitGame) {
        loadLevel(currentLevelNumber);
        displayGrid();
        cout << "Level " << currentLevelNumber << " loaded. Start placing blocks!" << endl;
        while (!grid.isGridFilled()) {
            handlePlayerInput();
        }
        cout << "Congratulations! You completed Level " << currentLevelNumber << "!" << endl;
        currentLevelNumber++;
    }
    cout << "Thank you for playing the Pattern Block Challenge!" << endl;
}