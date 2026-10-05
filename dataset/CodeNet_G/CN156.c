#define INF 100000
typedef struct {
    int x, y;
} Point;
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int min(int a, int b) {
    return a < b ? a : b;
}
int bfs(char **map, int n, int m, Point start, Point goal) {
    int queue[m * n][3];
    int front = 0, rear = 0;
    int **visit = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        visit[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            visit[i][j] = INF;
        }
    }
    queue[rear][0] = start.x;
    queue[rear][1] = start.y;
    queue[rear][2] = 0;
    visit[start.y][start.x] = 0;
    rear++;
    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        int cost = queue[front][2];
        front++;
        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int ncost = cost + (map[ny][nx] == '#');
                if (ncost < visit[ny][nx]) {
                    visit[ny][nx] = ncost;
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    queue[rear][2] = ncost;
                    rear++;
                }
            }
        }
    }
    int result = visit[goal.y][goal.x];
    for (int i = 0; i < m; i++)
        free(visit[i]);
    free(visit);
    return result;
}
int solve() {
    int n, m;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        char **map = (char **)malloc(m * sizeof(char *));
        Point start, goal;
        for (int i = 0; i < m; i++) {
            map[i] = (char *)malloc(n + 1);
            scanf("%s", map[i]);
            for (int j = 0; j < n; j++) {
                if (map[i][j] == '.') {
                    start.x = j;
                    start.y = i;
                } else if (map[i][j] == '&') {
                    goal.x = j;
                    goal.y = i;
                }
            }
        }
        printf("%d\n", bfs(map, n, m, start, goal));
        for (int i = 0; i < m; i++)
            free(map[i]);
        free(map);
    }
    return 0;
}