#define ROWS 12
#define COLS 12
int map[ROWS][COLS];
int visited[ROWS][COLS];
void dfs(int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || visited[x][y] || map[x][y] == 0)
        return;
    visited[x][y] = 1;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}
int countIslands() {
    int count = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                count++;
            }
        }
    }
    return count;
}
