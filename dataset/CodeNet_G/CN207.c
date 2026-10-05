#define MAX_W 100
#define MAX_H 100
typedef struct {
    int color;
    int direction;
    int x;
    int y;
} Block;
int w, h, xs, ys, xg, yg, n;
Block blocks[30];
int board[MAX_H + 1][MAX_W + 1];
int visited[MAX_H + 1][MAX_W + 1];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int in_bounds(int x, int y) {
    return x >= 1 && x <= h && y >= 1 && y <= w;
}
void place_blocks() {
    memset(board, 0, sizeof(board));
    for (int i = 0; i < n; i++) {
        Block b = blocks[i];
        int x, y;
        if (b.direction == 0) {
            for (x = b.x; x < b.x + 2; x++) {
                for (y = b.y; y < b.y + 4; y++) {
                    board[x][y] = b.color;
                }
            }
        } else {
            for (x = b.x; x < b.x + 4; x++) {
                for (y = b.y; y < b.y + 2; y++) {
                    board[x][y] = b.color;
                }
            }
        }
    }
}
int dfs(int x, int y, int goal_x, int goal_y, int color) {
    if (x == goal_x && y == goal_y) return 1;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (in_bounds(nx, ny) && !visited[nx][ny] && board[nx][ny] == color) {
            if (dfs(nx, ny, goal_x, goal_y, color)) return 1;
        }
    }
    return 0;
}
void check_maze() {
    memset(visited, 0, sizeof(visited));
    int start_color = board[xs][ys];
    if (dfs(xs, ys, xg, yg, start_color)) {
        printf("OK\n");
    } else {
        printf("NG\n");
    }
}