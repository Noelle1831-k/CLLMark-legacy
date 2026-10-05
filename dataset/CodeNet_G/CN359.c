typedef struct {
    int x;
    int y;
} Position;
int compare_x(const void *a, const void *b) {
    Position *posA = (Position *)a;
    Position *posB = (Position *)b;
    return posA->x - posB->x;
}
int compare_y(const void *a, const void *b) {
    Position *posA = (Position *)a;
    Position *posB = (Position *)b;
    return posA->y - posB->y;
}
int minCostToClearEnemies(int W, int H, int N, Position enemies[]) {
    if (N == 0) return 0;
    qsort(enemies, N, sizeof(Position), compare_x);
    int medianX = enemies[N / 2].x;
    qsort(enemies, N, sizeof(Position), compare_y);
    int medianY = enemies[N / 2].y;
    int minCost = 0;
    for (int i = 0; i < N; ++i) {
        minCost += abs(enemies[i].x - medianX) + abs(enemies[i].y - medianY);
    }
    return minCost;
}