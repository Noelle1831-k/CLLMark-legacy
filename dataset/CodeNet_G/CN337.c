typedef struct {
    int x, y;
} Point;
typedef struct {
    int u, v;
    double length;
} Edge;
#define MAX_V 100
#define MAX_R 1000
Point villages[MAX_V];
Edge edges[MAX_R * 2];
int parent[MAX_V];
double calculateDistance(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->length > ((Edge *)b)->length ? 1 : -1;
}
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
void unite(int x, int y) {
    parent[find(x)] = find(y);
}
double minimumRoadLength(int V, int R) {
    for (int i = 0; i < V; ++i) {
        parent[i] = i;
    }
    int edgeCount = 0;
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            edges[edgeCount].u = i;
            edges[edgeCount].v = j;
            edges[edgeCount].length = calculateDistance(villages[i], villages[j]);
            edgeCount++;
        }
    }
    qsort(edges, edgeCount, sizeof(Edge), compareEdges);
    double totalLength = 0.0;
    for (int i = 0; i < edgeCount; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            unite(u, v);
            totalLength += edges[i].length;
        }
    }
    return totalLength;
}