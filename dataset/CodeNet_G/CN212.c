#define MAX_N 100
#define MAX_M 500
int min(int a, int b) {
    return a < b ? a : b;
}
typedef struct {
    int u, v, cost;
} Edge;
int compare_edges(const void *a, const void *b) {
    return ((Edge *)a)->cost - ((Edge *)b)->cost;
}
int bellman_ford(int n, int m, Edge edges[], int s, int d, int c) {
    int dist[MAX_N + 1][11];
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= c; k++) {
            dist[i][k] = INT_MAX;
        }
    }
    dist[s][0] = 0;
    for (int k = 0; k <= c; k++) {
        for (int i = 0; i < m; i++) {
            int u = edges[i].u, v = edges[i].v, cost = edges[i].cost;
            if (dist[u][k] != INT_MAX) {
                dist[v][k] = min(dist[v][k], dist[u][k] + cost);
                if (k < c) {
                    dist[v][k + 1] = min(dist[v][k + 1], dist[u][k] + cost / 2);
                }
            }
            if (dist[v][k] != INT_MAX) {
                dist[u][k] = min(dist[u][k], dist[v][k] + cost);
                if (k < c) {
                    dist[u][k + 1] = min(dist[u][k + 1], dist[v][k] + cost / 2);
                }
            }
        }
    }
    int answer = INT_MAX;
    for (int k = 0; k <= c; k++) {
        answer = min(answer, dist[d][k]);
    }
    return answer;
}
int main() {
    int c, n, m, s, d;
    Edge edges[MAX_M];
    while (scanf("%d %d %d %d %d", &c, &n, &m, &s, &d), c || n || m || s || d) {
        for (int i = 0; i < m; i++) {
            int a, b, f;
            scanf("%d %d %d", &a, &b, &f);
            edges[i].u = a;
            edges[i].v = b;
            edges[i].cost = f;
        }
        qsort(edges, m, sizeof(Edge), compare_edges);
        printf("%d\n", bellman_ford(n, m, edges, s, d, c));
    }
    return 0;
}