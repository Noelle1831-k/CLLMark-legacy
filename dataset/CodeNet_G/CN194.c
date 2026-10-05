#define MAX_M 20
#define MAX_N 20
#define INF INT_MAX
typedef struct {
    int x, y;
} Point;
typedef struct {
    Point start, end;
} Road;
typedef struct {
    Point location;
    int period;
} TrafficLight;
int M, N, D, ns, nc, nj;
TrafficLight trafficLights[MAX_M * MAX_N];
Road constructionRoads[MAX_M * MAX_N];
Road congestedRoads[MAX_M * MAX_N];
int congestionTime[MAX_M * MAX_N];
Point startPoint, endPoint;
int timeCost[MAX_M][MAX_N][MAX_M][MAX_N];
int minTime[MAX_M][MAX_N];
int visited[MAX_M][MAX_N];
int is_congested(Point p1, Point p2) {
    for (int i = 0; i < nj; i++) {
        if ((congestedRoads[i].start.x == p1.x && congestedRoads[i].start.y == p1.y && congestedRoads[i].end.x == p2.x && congestedRoads[i].end.y == p2.y) ||
            (congestedRoads[i].start.x == p2.x && congestedRoads[i].start.y == p2.y && congestedRoads[i].end.x == p1.x && congestedRoads[i].end.y == p1.y)) {
            return congestionTime[i];
        }
    }
    return 0;
}
int is_under_construction(Point p1, Point p2) {
    for (int i = 0; i < nc; i++) {
        if ((constructionRoads[i].start.x == p1.x && constructionRoads[i].start.y == p1.y && constructionRoads[i].end.x == p2.x && constructionRoads[i].end.y == p2.y) ||
            (constructionRoads[i].start.x == p2.x && constructionRoads[i].start.y == p2.y && constructionRoads[i].end.x == p1.x && constructionRoads[i].end.y == p1.y)) {
            return 1;
        }
    }
    return 0;
}
int is_red_signal(Point p, int time, int direction) {
    for (int i = 0; i < ns; i++) {
        if (trafficLights[i].location.x == p.x && trafficLights[i].location.y == p.y) {
            int period = trafficLights[i].period;
            int cycleTime = time % period;
            if (direction == 0 || direction == 2) {
                return cycleTime >= period / 2;
            } else {
                return cycleTime < period / 2;
            }
        }
    }
    return 0;
}
void dijkstra() {
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            minTime[i][j] = INF;
            visited[i][j] = 0;
        }
    }
    minTime[startPoint.x][startPoint.y] = 0;
    for (int count = 0; count < M * N; count++) {
        int min = INF, minIndexX = -1, minIndexY = -1;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && minTime[i][j] <= min) {
                    min = minTime[i][j];
                    minIndexX = i;
                    minIndexY = j;
                }
            }
        }
        if (minIndexX == -1 || minIndexY == -1) break;
        visited[minIndexX][minIndexY] = 1;
        Point current = {minIndexX, minIndexY};
        for (int i = 0; i < 4; i++) {
            Point next = {current.x + dx[i], current.y + dy[i]};
            if (next.x >= 0 && next.x < M && next.y >= 0 && next.y < N && !is_under_construction(current, next)) {
                int time = D + is_congested(current, next);
                if (is_red_signal(current, minTime[minIndexX][minIndexY], i)) {
                    time += trafficLights[i].period / 2;
                }
                if (minTime[current.x][current.y] + time < minTime[next.x][next.y]) {
                    minTime[next.x][next.y] = minTime[current.x][current.y] + time;
                }
            }
        }
    }
}
int get_shortest_time() {
    dijkstra();
    return minTime[endPoint.x][endPoint.y];
}
