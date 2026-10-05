void updateGrid(Grid *grid, char *input) {
    int row = input[0] - '0', col = input[1] - '0';

    char symbol = input[2];
    grid->cells[row][col] = symbol;
}