void SudokuGrid::printGrid() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << (grid[i][j] == "" ? "." : grid[i][j]) << " ";
        }
        cout << endl;
    }
}