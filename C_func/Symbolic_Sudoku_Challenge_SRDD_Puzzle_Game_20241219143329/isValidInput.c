int isValidInput(Grid *grid, char *input) {
    if (input[0] < '0' || input[0] > '8') return 0;
    if (input[1] < '0' || input[1] > '8') return 0;
    if (input[2] < 'A' || input[2] > 'I') return 0;
    int row = input[0] - '0';
    int col = input[1] - '0';
    char symbol = input[2];
    for (int i = 0; i < 9; i++) {
        if (grid->cells[row][i] == symbol || grid->cells[i][col] == symbol) {
            return 0;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (grid->cells[i][j] == symbol) {
                return 0;
            }
        }
    }
    return 1;
}