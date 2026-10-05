void GameManager::startGame() {
    cout << "Choose difficulty level (1-3): ";
    cin >> difficulty;
    symbolSet.generateSymbols();
    grid.setSymbols(symbolSet.getSymbols());
    grid.initializeGrid(difficulty);
    while (!grid.isSolved()) {
        grid.printGrid();
        processInput();
    }
    cout << "Congratulations! You solved the Sudoku!" << endl;
}