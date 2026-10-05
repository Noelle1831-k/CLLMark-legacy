int searchWord(char grid[10][10], const char *word, int x, int y, int index, int visited[10][10]) {
    if (index == strlen(word)) {
        return 1;
    }
    if (!isSafe(x, y, visited) || grid[x][y] != word[index]) {
        return 0;
    }
    visited[x][y] = 1;
    int rowNum[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colNum[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int dir = 0; dir < 8; dir++) {
        if (searchWord(grid, word, x + rowNum[dir], y + colNum[dir], index + 1, visited)) {
            return 1;
        }
    }
    visited[x][y] = 0;
    return 0;
}