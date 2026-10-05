int maxCargoCapacity(int H, int N, int inhibited[][2]) {
    int grid[4][10000] = {0};
    int count = 0;
    for (int i = 0; i < N; i++) {
        int x = inhibited[i][0];
        int y = inhibited[i][1];
        grid[x][y] = -1;
    }
    for (int y = 0; y < H - 1; y++) {
        for (int x = 0; x < 3; x++) {
            if (grid[x][y] == 0 && grid[x + 1][y] == 0 &&
                grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0) {
                count++;
                grid[x][y] = grid[x + 1][y] = grid[x][y + 1] = grid[x + 1][y + 1] = 1;
            }
        }
    }
    return count;
}
