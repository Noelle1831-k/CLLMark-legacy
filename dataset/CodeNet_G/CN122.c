#define MAX_SPRINKLERS 10
#define GRID_SIZE 10
typedef struct {
    int x, y;
} Point;
int jump_positions[4][2] = {{0, 2}, {2, 0}, {0, -2}, {-2, 0}};
int is_within_bounds(int x, int y) {
    return x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE;
}
int is_within_sprinkler(int sx, int sy, int x, int y) {
    return abs(sx - x) <= 1 && abs(sy - y) <= 1;
}
int dfs(Point *sprinklers, int index, int n, Point current) {
    if (index == n) return 1;
    for (int i = 0; i < 4; i++) {
        Point next;
        next.x = current.x + jump_positions[i][0];
        next.y = current.y + jump_positions[i][1];
        if (is_within_bounds(next.x, next.y) &&
            is_within_sprinkler(sprinklers[index].x, sprinklers[index].y, next.x, next.y)) {
            if (dfs(sprinklers, index + 1, n, next)) return 1;
        }
    }
    return 0;
}
void check_survival(int px, int py, int n, Point *sprinklers) {
    if (is_within_sprinkler(sprinklers[0].x, sprinklers[0].y, px, py)) {
        puts(dfs(sprinklers, 1, n, (Point){px, py}) ? "OK" : "NA");
    } else {
        puts("NA");
    }
}