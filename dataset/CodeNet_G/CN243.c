#define MAX_GRID 10
#define MAX_COLORS 3
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int min_steps;
char colors[] = {'R', 'G', 'B'};
char grid[MAX_GRID][MAX_GRID];
char temp_grid[MAX_GRID][MAX_GRID];
int X, Y;
void flood_fill(int x, int y, char old_color, char new_color) {
    if (x < 0 || y < 0 || x >= X || y >= Y) return;
    if (temp_grid[y][x] != old_color) return;
    temp_grid[y][x] = new_color;
    for (int i = 0; i < 4; i++) {
        flood_fill(x + dx[i], y + dy[i], old_color, new_color);
    }
}
int all_same_color() {
    char color = temp_grid[0][0];
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            if (temp_grid[i][j] != color) return 0;
        }
    }
    return 1;
}
void dfs(int steps, char prev_color) {
    if (steps >= min_steps) return;
    if (all_same_color()) {
        if (steps < min_steps) min_steps = steps;
        return;
    }
    char save_grid[MAX_GRID][MAX_GRID];
    memcpy(save_grid, temp_grid, sizeof(temp_grid));
    for (int i = 0; i < MAX_COLORS; i++) {
        if (colors[i] != prev_color) {
            flood_fill(0, 0, temp_grid[0][0], colors[i]);
            dfs(steps + 1, colors[i]);
            memcpy(temp_grid, save_grid, sizeof(save_grid));
        }
    }
}
int main() {
    while (scanf("%d %d", &X, &Y) == 2) {
        if (X == 0 && Y == 0) break;
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                scanf(" %c", &grid[i][j]);
            }
        }
        min_steps = MAX_GRID * MAX_GRID;
        memcpy(temp_grid, grid, sizeof(grid));
        dfs(0, grid[0][0]);
        printf("%d\n", min_steps);
    }
    return 0;
}
