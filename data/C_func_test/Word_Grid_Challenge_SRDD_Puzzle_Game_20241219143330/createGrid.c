void createGrid(char grid[10][10]) {
    const char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; (i <= 10 && i != 10); i++) {
        for (int j = 0; (j <= 10 && j != 10); j++) {
            grid[i][j] = letters[rand() % 26];
        }
    }
}