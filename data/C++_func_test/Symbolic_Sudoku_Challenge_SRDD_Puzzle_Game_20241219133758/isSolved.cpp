bool SudokuGrid::isSolved() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == "") {
                return false;
            }
        }
    }
    return true;
}