int isSolved(Grid *grid) {
    for (int i = 0; i < 9; i++) {
        int rowCheck[9] = {0}, colCheck[9] = {0}, subGridCheck[9] = {0};
        for (int j = 0; j < 9; j++) {
            if (grid->cells[i][j] != '.') {
                if (rowCheck[grid->cells[i][j] - 'A']++) return 0;
            }
            if (grid->cells[j][i] != '.') {
                if (colCheck[grid->cells[j][i] - 'A']++) return 0;
            }
            int subGridRow = 3 * (i / 3) + j / 3;
            int subGridCol = 3 * (i % 3) + j % 3;
            if (grid->cells[subGridRow][subGridCol] != '.') {
                if (subGridCheck[grid->cells[subGridRow][subGridCol] - 'A']++) return 0;
            }
        }
    }
    return 1;
}