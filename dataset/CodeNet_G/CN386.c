#define MAXN 100001
#define MAXQ 100001
typedef struct {
    int to;
    int weight;
} Edge;
typedef struct {
    int *dist;
    int size;
} DistanceTable;
Edge edges[MAXN * 2];
int head[MAXN];
int nextEdge[MAXN * 2];
int edgeCount;
int N, Q;
int themes[MAXQ][3];
DistanceTable distances[MAXN];
void addEdge(int u, int v, int w) {
    edges[edgeCount] = (Edge){v, w};
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount++;
    edges[edgeCount] = (Edge){u, w};
    nextEdge[edgeCount] = head[v];
    head[v] = edgeCount++;
}
void dfs(int node, int parent, int d, int start) {
    distances[start].dist[node] = d;
    for (int i = head[node]; i != -1; i = nextEdge[i]) {
        int next = edges[i].to;
        if (next != parent) {
            dfs(next, node, d + edges[i].weight, start);
        }
    }
}
void precomputeDistances() {
    for (int i = 1; i <= N; ++i) {
        distances[i].dist = (int *)malloc((N + 1) * sizeof(int));
        dfs(i, -1, 0, i);
    }
}
int minCost(int a, int b, int c) {
    int min_cost = INT_MAX;
    for (int i = 1; i <= N; ++i) {
        int d1 = distances[a].dist[i];
        int d2 = distances[b].dist[i];
        int d3 = distances[c].dist[i];
        int max_dist = d1 > d2 ? (d1 > d3 ? d1 : d3) : (d2 > d3 ? d2 : d3);
        if (max_dist < min_cost) {
            min_cost = max_dist;
        }
    }
    return min_cost;
}
void solve() {
    precomputeDistances();
    for (int i = 0; i < Q; ++i) {
        int a = themes[i][0];
        int b = themes[i][1];
        int c = themes[i][2];
        printf("%d\n", minCost(a, b, c));
    }
    for (int i = 1; i <= N; ++i) {
        free(distances[i].dist);
    }
}
