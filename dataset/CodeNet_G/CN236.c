#define MAX_W 7
#define MAX_H 7
int W, H;
int board[MAX_H][MAX_W];
bool visited[MAX_H][MAX_W];
int emptyCells;
bool is_valid(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W && board[x][y] == 0;
}
bool can_draw_closed_loop(int x, int y, int start_x, int start_y, int count) {
    if (count == emptyCells) {
        for (int i = -1; i <= 1; i += 2) {
            for (int j = -1; j <= 1; j += 2) {
                if (x + i == start_x && y + j == start_y) {
                    return true;
                }
            }
        }
        return false;
    }
    visited[x][y] = true;
    bool result = false;
    int directions[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    for (int d = 0; d < 4; d++) {
        int nx = x + directions[d][0];
        int ny = y + directions[d][1];
        if (is_valid(nx, ny) && !visited[nx][ny]) {
            if (can_draw_closed_loop(nx, ny, start_x, start_y, count + 1)) {
                result = true;
                break;
            }
        }
    }
    visited[x][y] = false;
    return result;
}
void process_board() {
    emptyCells = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] == 0) {
                emptyCells++;
            }
            visited[i][j] = false;
        }
    }
    if (emptyCells == 0) {
        printf("No\n");
        return;
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] == 0) {
                if (can_draw_closed_loop(i, j, i, j, 1)) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
                return;
            }
        }
    }
}