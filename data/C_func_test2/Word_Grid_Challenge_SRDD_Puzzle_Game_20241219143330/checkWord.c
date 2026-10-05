int checkWord(char grid[10][10], const char *word) {
    int visited[10][10] = {0};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == word[0] && searchWord(grid, word, i, j, 0, visited)) {
                return 1;
            }
        }
    }
    return 0;
}