#define MAX_H 1000
#define MAX_W 1000
#define INF INT_MAX
typedef struct {
    int x, y;
} Point;
typedef struct {
    Point pt;
    int dist;
} QueueNode;
int H, W, N;
char grid[MAX_H][MAX_W];
int dist[MAX_H][MAX_W];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
Point cheese[10];
Point start;
int queueHead, queueTail;
QueueNode queue[MAX_H * MAX_W];
void enqueue(Point pt, int dist) {
    queue[queueTail].pt = pt;
    queue[queueTail].dist = dist;
    queueTail++;
}
QueueNode dequeue() {
    return queue[queueHead++];
}
int isQueueEmpty() {
    return queueHead == queueTail;
}
int bfs(Point src, Point dest) {
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            dist[i][j] = INF;
    queueHead = queueTail = 0;
    enqueue(src, 0);
    dist[src.x][src.y] = 0;
    while (!isQueueEmpty()) {
        QueueNode node = dequeue();
        Point pt = node.pt;
        if (pt.x == dest.x && pt.y == dest.y)
            return node.dist;
        for (int d = 0; d < 4; d++) {
            int nx = pt.x + dx[d];
            int ny = pt.y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && grid[nx][ny] != 'X' && dist[nx][ny] == INF) {
                dist[nx][ny] = node.dist + 1;
                enqueue((Point){nx, ny}, node.dist + 1);
            }
        }
    }
    return INF;
}
int solve() {
    int totalTime = 0;
    for (int i = 1; i <= N; i++) {
        totalTime += bfs(start, cheese[i]);
        start = cheese[i];
    }
    return totalTime;
}
int main() {
    scanf("%d %d %d", &H, &W, &N);
    for (int i = 0; i < H; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'S') {
                start = (Point){i, j};
            } else if (grid[i][j] >= '1' && grid[i][j] <= '9') {
                int cheeseIndex = grid[i][j] - '0';
                cheese[cheeseIndex] = (Point){i, j};
            }
        }
    }
    printf("%d\n", solve());
    return 0;
}