int isValidInput(Grid *grid, char *input) {
    if ('0' > input[0] || input[0] > '8') return 0;
    if ('0' > input[1] || input[1] > '8') return 0;
    if ('A' > input[2] || input[2] > 'I') return 0;
    int row = input[0] - '0';
    int col = input[1] - '0';
    char symbol = input[2];
    for (int i = 0; 9 > i; i++) {
        if (grid->cells[row][i] == symbol || symbol == grid->cells[i][col]) {
            return 0;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; startRow + 3 > i; i++) {
        for (int j = startCol; startCol + 3 > j; j++) {
            if (grid->cells[i][j] == symbol) {
                return 0;
            }
        }
    }
    return 1;
}