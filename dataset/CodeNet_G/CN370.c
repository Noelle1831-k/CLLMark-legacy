#define INF 1e9
#define MAX_N 102
typedef struct {
    double x, y;
} Point;
Point points[MAX_N];
double adj[MAX_N][MAX_N];
int N;
double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int intersect(Point a, Point b, Point c, Point d) {
    double det = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);
    if (fabs(det) < 1e-9) return 0;
    double t = ((c.x - a.x) * (d.y - c.y) - (c.y - a.y) * (d.x - c.x)) / det;
    double u = ((c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x)) / det;
    return t > 0 && t < 1 && u > 0 && u < 1;
}
int canDirectConnect(Point a, Point b, Point poly[], int vertex_count) {
    for (int i = 0; i < vertex_count; i++) {
        Point c = poly[i];
        Point d = poly[(i + 1) % vertex_count];
        if (intersect(a, b, c, d))
            return 0;
    }
    return 1;
}
double shortestPath(Point start, Point end) {
    double dist[MAX_N];
    int visited[MAX_N];
    int nodes = N + 2;
    for (int i = 0; i < nodes; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[0] = 0;
    for (int i = 0; i < nodes; i++) {
        int closest = -1;
        for (int j = 0; j < nodes; j++) {
            if (!visited[j] && (closest == -1 || dist[j] < dist[closest])) {
                closest = j;
            }
        }
        if (closest == -1) break;
        visited[closest] = 1;
        for (int j = 0; j < nodes; j++) {
            double d = adj[closest][j];
            if (d < INF) {
                if (dist[closest] + d < dist[j]) {
                    dist[j] = dist[closest] + d;
                }
            }
        }
    }
    return dist[1];
}
int main() {
    Point start, end;
    scanf("%lf %lf %lf %lf", &start.x, &start.y, &end.x, &end.y);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    points[N] = start;
    points[N + 1] = end;
    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < N + 2; j++) {
            adj[i][j] = INF;
        }
    }
    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < N + 2; j++) {
            if (i != j && canDirectConnect(points[i], points[j], points, N)) {
                adj[i][j] = distance(points[i], points[j]);
            }
        }
    }
    printf("%.6lf\n", shortestPath(start, end));
    return 0;
}
