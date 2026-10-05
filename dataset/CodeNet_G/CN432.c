#define MAX_COORD 10001
int coverage_area(int n, int r, int rects[][4]) {
    int area = 0;
    int length = 0;
    int grid[MAX_COORD][MAX_COORD] = {0};
    for (int i = 0; i < n; ++i) {
        int x1 = rects[i][0], y1 = rects[i][1];
        int x2 = rects[i][2], y2 = rects[i][3];
        for (int x = x1; x < x2; ++x) {
            for (int y = y1; y < y2; ++y) {
                grid[x][y] = 1;
            }
        }
    }
    for (int x = 0; x < MAX_COORD; ++x) {
        for (int y = 0; y < MAX_COORD; ++y) {
            if (grid[x][y]) {
                area++;
                if (r == 2) {
                    if (x == 0 || !grid[x - 1][y]) length++;
                    if (x == MAX_COORD - 1 || !grid[x + 1][y]) length++;
                    if (y == 0 || !grid[x][y - 1]) length++;
                    if (y == MAX_COORD - 1 || !grid[x][y + 1]) length++;
                }
            }
        }
    }
    printf("%d\n", area);
    if (r == 2) {
        printf("%d\n", length);
    }
    return 0;
}