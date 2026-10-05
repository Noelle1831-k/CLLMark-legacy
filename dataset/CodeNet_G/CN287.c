#define MAX_M 100
#define MAX_Q 100
typedef struct {
    int x1, y1, x2, y2;
} Wall;
typedef struct {
    int x, y;
} Point;
typedef struct {
    Point start, end;
} Query;
Wall walls[MAX_M];
Query queries[MAX_Q];
int countCrossedWalls(Point start, Point end, Wall* walls, int numWalls) {
    int count = 0;
    for (int i = 0; i < numWalls; i++) {
        Wall wall = walls[i];
        if ((wall.y1 == wall.y2 && ((start.y < wall.y1 && end.y >= wall.y1) || (start.y >= wall.y1 && end.y < wall.y1))) &&
            ((start.x < wall.x1 && end.x >= wall.x1) || (start.x >= wall.x1 && end.x < wall.x1))) {
            count++;
        } else if ((wall.x1 == wall.x2 && ((start.x < wall.x1 && end.x >= wall.x1) || (start.x >= wall.x1 && end.x < wall.x1))) &&
                   ((start.y < wall.y1 && end.y >= wall.y1) || (start.y >= wall.y1 && end.y < wall.y1))) {
            count++;
        }
    }
    return count;
}
int main() {
    int W, H, M, Q;
    scanf("%d %d %d", &W, &H, &M);
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        walls[i] = (Wall){x1, y1, x2, y2};
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int sx, sy, gx, gy;
        scanf("%d %d %d %d", &sx, &sy, &gx, &gy);
        queries[i] = (Query){(Point){sx, sy}, (Point){gx, gy}};
    }
    for (int i = 0; i < Q; i++) {
        int result = countCrossedWalls(queries[i].start, queries[i].end, walls, M);
        printf("%d\n", result);
    }
    return 0;
}