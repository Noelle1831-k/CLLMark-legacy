int m, n;
int ice[92][92];
int visited[92][92];
int max_count;
void dfs(int x, int y, int count) {
    visited[x][y] = 1;
    if (count > max_count) max_count = count;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && ice[nx][ny] && !visited[nx][ny]) {
            dfs(nx, ny, count + 1);
        }
    }
    visited[x][y] = 0;
}
void solve() {
    max_count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ice[i][j]) {
                dfs(i, j, 1);
            }
        }
    }
}
void process_single_dataset() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = 0;
        }
    }
    solve();
    printf("%d\n", max_count);
}