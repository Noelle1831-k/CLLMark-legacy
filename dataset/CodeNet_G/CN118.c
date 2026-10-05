#define MAX_SIZE 100
char orchard[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int H, W;
void dfs(int x, int y, char fruitType) {
    if (x < 0 || x >= H || y < 0 || y >= W || visited[x][y] || orchard[x][y] != fruitType)
        return;
    visited[x][y] = 1;
    dfs(x + 1, y, fruitType);
    dfs(x - 1, y, fruitType);
    dfs(x, y + 1, fruitType);
    dfs(x, y - 1, fruitType);
}
int countDistinctAreas() {
    int count = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!visited[i][j]) {
                dfs(i, j, orchard[i][j]);
                count++;
            }
        }
    }
    return count;
}