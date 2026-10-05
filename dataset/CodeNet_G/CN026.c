#define GRID_SIZE 10
int grid[GRID_SIZE][GRID_SIZE];
void applyInkDrop(int x, int y, int size) {
    int i, j;
    if (size >= 1) {
        for (i = x - 1; i <= x + 1; i++) {
            for (j = y - 1; j <= y + 1; j++) {
                if (i >= 0 && i < GRID_SIZE && j >= 0 && j < GRID_SIZE) {
                    grid[i][j]++;
                }
            }
        }
    }
    if (size >= 2) {
        for (i = x - 1; i <= x + 1; i++) {
            if (y - 2 >= 0) grid[i][y - 2]++;
            if (y + 2 < GRID_SIZE) grid[i][y + 2]++;
        }
        for (j = y - 1; j <= y + 1; j++) {
            if (x - 2 >= 0) grid[x - 2][j]++;
            if (x + 2 < GRID_SIZE) grid[x + 2][j]++;
        }
    }
    if (size == 3) {
        if (x - 2 >= 0 && y - 2 >= 0) grid[x - 2][y - 2]++;
        if (x - 2 >= 0 && y + 2 < GRID_SIZE) grid[x - 2][y + 2]++;
        if (x + 2 < GRID_SIZE && y - 2 >= 0) grid[x + 2][y - 2]++;
        if (x + 2 < GRID_SIZE && y + 2 < GRID_SIZE) grid[x + 2][y + 2]++;
    }
}
void processDrops(int drops[][3], int numberOfDrops) {
    int i, x, y, size;
    for (i = 0; i < numberOfDrops; i++) {
        x = drops[i][0];
        y = drops[i][1];
        size = drops[i][2];
        applyInkDrop(x, y, size);
    }
}
int countZeroDensity() {
    int i, j, count = 0;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) count++;
        }
    }
    return count;
}
int findMaxDensity() {
    int i, j, max = 0;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] > max) max = grid[i][j];
        }
    }
    return max;
}
