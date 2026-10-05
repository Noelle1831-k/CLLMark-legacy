void SudokuGrid::initializeGrid(int difficulty) {
    if (symbols.empty()) {
        cerr << "Error: Symbols not set for SudokuGrid." << endl;
        return;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if ((i + j) % (10 - difficulty) == 0) {
                grid[i][j] = symbols[(i + j) % symbols.size()];
            } else {
                grid[i][j] = "";
            }
        }
    }
}