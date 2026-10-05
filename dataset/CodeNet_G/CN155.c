typedef struct {
    int id;
    int x, y;
} Building;
double distance(Building a, Building b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
void findPath(int n, Building buildings[], int start, int goal, int path[], int *pathLen);
void solve(int n, Building buildings[], int m, int queries[][2], int results[][102]) {
    for (int i = 0; i < m; ++i) {
        int start = queries[i][0];
        int goal = queries[i][1];
        int path[102];
        int pathLen = 0;
        findPath(n, buildings, start, goal, path, &pathLen);
        if (pathLen == 0) {
            printf("NA\n");
        } else {
            for (int j = 0; j < pathLen; ++j) {
                printf("%d ", path[j]);
            }
            printf("\n");
        }
    }
}
void findPath(int n, Building buildings[], int start, int goal, int path[], int *pathLen) {
    int dist[101];
    int prev[101];
    for (int i = 1; i <= n; ++i) {
        dist[i] = (i == start) ? 0 : INT_MAX;
        prev[i] = -1;
    }
    int queue[101], front = 0, rear = 0;
    queue[rear++] = start;
    while (front < rear) {
        int current = queue[front++];
        for (int i = 1; i <= n; ++i) {
            if (i == current || distance(buildings[current - 1], buildings[i - 1]) > 50.0) {
                continue;
            }
            if (dist[i] > dist[current] + 1) {
                dist[i] = dist[current] + 1;
                prev[i] = current;
                queue[rear++] = i;
            }
        }
    }
    int index = goal;
    *pathLen = 0;
    while (index != -1) {
        path[(*pathLen)++] = index;
        index = prev[index];
    }
    if (path[*pathLen - 1] != start) {
        *pathLen = 0;
    }
    for (int i = 0; i < *pathLen / 2; ++i) {
        int tmp = path[i];
        path[i] = path[*pathLen - i - 1];
        path[*pathLen - i - 1] = tmp;
    }
}