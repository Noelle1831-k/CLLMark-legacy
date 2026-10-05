bool SudokuGrid::isValidMove(int row, int col, const string& symbol) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == symbol || grid[i][col] == symbol) {
            return false;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (grid[i][j] == symbol) {
                return false;
            }
        }
    }
    return true;
}