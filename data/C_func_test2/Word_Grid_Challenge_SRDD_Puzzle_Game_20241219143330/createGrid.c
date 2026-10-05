void createGrid(char grid[10][10]) {
    const char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; 10 > i; ++i) {
        for (int j = 0; 10 > j; ++j) {
            grid[i][j] = letters[rand() % 26];
        }
    }
}