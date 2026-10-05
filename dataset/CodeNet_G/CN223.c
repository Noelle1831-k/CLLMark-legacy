#define MAX_W 50
#define MAX_H 50
#define INF 101
typedef struct {
    int x, y;
} Point;
typedef struct {
    int x1, y1, x2, y2, time;
} State;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int W, H;
int grid[MAX_H][MAX_W];
int visited[MAX_H][MAX_W][MAX_H][MAX_W];
int queuePos;
void push(Point queue[], Point p) {
    queue[queuePos++] = p;
}
Point pop(Point queue[]) {
    return queue[--queuePos];
}
int bfs(Point startT, Point startK) {
    Point queue[MAX_W * MAX_H * MAX_W * MAX_H];
    State initial = {startT.x, startT.y, startK.x, startK.y, 0};
    push(queue, (Point){initial.x1, initial.y1});
    visited[initial.x1][initial.y1][initial.x2][initial.y2] = initial.time;
    while (queuePos > 0) {
        State current;
        Point p = pop(queue);
        current.x1 = p.x;
        current.y1 = p.y;
        current.time = visited[p.x][p.y][current.x2][current.y2];
        if (current.time > 100) return INF;
        if (current.x1 == current.x2 && current.y1 == current.y2) return current.time;
        for (int i = 0; i < 4; ++i) {
            int nx1 = current.x1 + dx[i];
            int ny1 = current.y1 + dy[i];
            int nx2 = current.x2 - dx[i];
            int ny2 = current.y2 - dy[i];
            if (!(nx1 >= 0 && ny1 >= 0 && nx1 < W && ny1 < H && grid[ny1][nx1] == 0)) {
                nx1 = current.x1;
                ny1 = current.y1;
            }
            if (!(nx2 >= 0 && ny2 >= 0 && nx2 < W && ny2 < H && grid[ny2][nx2] == 0)) {
                nx2 = current.x2;
                ny2 = current.y2;
            }
            if (!visited[nx1][ny1][nx2][ny2]) {
                State next = {nx1, ny1, nx2, ny2, current.time + 1};
                visited[nx1][ny1][nx2][ny2] = next.time;
                push(queue, (Point){next.x1, next.y1});
            }
        }
    }
    return INF;
}
int main(void) {
    int tx, ty, kx, ky;
    while (1) {
        scanf("%d %d", &W, &H);
        if (W == 0 && H == 0) break;
        scanf("%d %d %d %d", &tx, &ty, &kx, &ky);
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                scanf("%d", &grid[i][j]);
                for (int k = 0; k < H; ++k)
                    memset(visited[i][j][k], 0, sizeof(visited[i][j][k]));
            }
        }
        int result = bfs((Point){tx - 1, ty - 1}, (Point){kx - 1, ky - 1});
        if (result >= INF) printf("NA\n");
        else printf("%d\n", result);
    }
    return 0;
}