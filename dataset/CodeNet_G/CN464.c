int H, W, N;
int grid[1001][1001];
void solve() {
    int x = 1, y = 1;
    for (int step = 0; step < N; ++step) {
        if (grid[x][y] == 1) {
            grid[x][y] = 0;
            y++;
        } else {
            grid[x][y] = 1;
            x++;
        }
        if (x > H || y > W) break;
    }
    printf("%d %d\n", x, y);
}