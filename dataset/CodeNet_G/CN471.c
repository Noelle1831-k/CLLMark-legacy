#define MAX_N 10
#define MAX_M 10
int m, n;
int map[MAX_N][MAX_M];
int house_count;
int start_x, start_y;
int visited[MAX_N][MAX_M];
int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int dfs(int x, int y, int delivered) {
    if (delivered == house_count) {
        return 1;
    }
    int ways = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        while (is_valid(nx, ny) && (map[nx][ny] == 0 || (map[nx][ny] == 2 && delivered == house_count))) {
            nx += directions[i][0];
            ny += directions[i][1];
        }
        if (is_valid(nx, ny) && map[nx][ny] == 1 && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            ways += dfs(nx, ny, delivered + 1);
            visited[nx][ny] = 0;
        }
    }
    return ways;
}
int count_paths() {
    return dfs(start_x, start_y, 0);
}