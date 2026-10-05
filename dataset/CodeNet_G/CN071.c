#define SIZE 8
void bombExplosion(char grid[SIZE][SIZE], int x, int y) {
    static int dx[] = {0, 1, 0, -1}; 
    static int dy[] = {1, 0, -1, 0};
    char visited[SIZE][SIZE] = {0}; 
    int queue[SIZE * SIZE][2]; 
    int front = 0, rear = 0;
    queue[rear][0] = x;
    queue[rear][1] = y;
    rear++;
    visited[y][x] = 1;
    while (front < rear) {
        int cx = queue[front][0];
        int cy = queue[front][1];
        front++;
        if (grid[cy][cx] == '1') {
            grid[cy][cx] = '0';
            for (int d = 0; d < 4; d++) {
                for (int step = 1; step <= 3; step++) {
                    int nx = cx + dx[d] * step;
                    int ny = cy + dy[d] * step;
                    if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && !visited[ny][nx]) {
                        queue[rear][0] = nx;
                        queue[rear][1] = ny;
                        rear++;
                        visited[ny][nx] = 1;
                    }
                }
            }
        }
    }
}
void solveDataSet(char grid[SIZE][SIZE], int startX, int startY, int dataSetNumber) {
    bombExplosion(grid, startX - 1, startY - 1);
    printf("Data %d:\n", dataSetNumber);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            putchar(grid[i][j]);
        }
        putchar('\n');
    }
}