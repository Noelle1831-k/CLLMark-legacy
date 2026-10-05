#define SIZE 10
void apply_dye(int grid[][SIZE], int x, int y, int size) {
    int i, j;
    int range = size - 1;
    for (i = -range; i <= range; i++) {
        for (j = -range; j <= range; j++) {
            if (x + i >= 0 && x + i < SIZE && y + j >= 0 && y + j < SIZE) {
                grid[y + j][x + i]++;
            }
        }
    }
}
void solve(int n, int cloth[SIZE][SIZE]) {
    int result[12][3];
    int dyes[3][2] = {{1, 1}, {2, 2}, {3, 3}};
    int grid[SIZE][SIZE];
    int x, y, size;
    int count = 0;
    while (count < n) {
        int found = 0;
        for (y = 0; y < SIZE && !found; y++) {
            for (x = 0; x < SIZE && !found; x++) {
                for (size = 2; size >= 0; size--) {
                    int valid = 1;
                    for (int dy = -dyes[size][1]; dy <= dyes[size][1] && valid; dy++) {
                        for (int dx = -dyes[size][0]; dx <= dyes[size][0] && valid; dx++) {
                            int ny = y + dy;
                            int nx = x + dx;
                            if (ny < 0 || ny >= SIZE || nx < 0 || nx >= SIZE || cloth[ny][nx] <= 0) {
                                valid = 0;
                            }
                        }
                    }
                    if (valid) {
                        found = 1;
                        result[count][0] = x;
                        result[count][1] = y;
                        result[count][2] = size + 1;
                        apply_dye(cloth, x, y, size + 1);
                        count++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }
}
