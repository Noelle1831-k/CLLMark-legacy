#define MAX 15
int grid[MAX][MAX];
int X, Y;
int countPatterns(int x, int y) {
    if (y >= Y) {
        return 1;
    }
    if (x < 0 || x >= X || grid[x][y] == 1) {
        return 0;
    }
    if (grid[x][y] == 2) {
        return countPatterns(x, y + 2);
    }
    return countPatterns(x - 1, y + 1) + countPatterns(x, y + 1) + countPatterns(x + 1, y + 1);
}
int calculateTotalPatterns() {
    int totalPatterns = 0;
    for (int startX = 0; startX < X; startX++) {
        if (grid[startX][0] == 0) {
            totalPatterns += countPatterns(startX, 1);
        }
    }
    return totalPatterns;
}
