#define MAX_VERTICES 100
#define MAX_EDGES 300
typedef struct Edge {
    int from, to, cost;
} Edge;
int n, m;
Edge edges[MAX_EDGES];
int dist[MAX_VERTICES + 1];
int saved_cost[MAX_VERTICES + 1];
int adj[MAX_VERTICES + 1][MAX_VERTICES + 1];
int bellman_ford(int src, int dst) {
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].from;
            int v = edges[j].to;
            int cost = edges[j].cost;
            if (dist[u] != INT_MAX && dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
            }
        }
    }
    return dist[dst];
}
int find_min_cost() {
    int direct_cost = bellman_ford(1, n);
    for (int i = 1; i <= n; i++) saved_cost[i] = dist[i];
    int minimum_cost = direct_cost;
    for (int i = 0; i < m; i++) {
        int u = edges[i].from;
        int v = edges[i].to;
        int cost = edges[i].cost;
        for (int j = 0; j < m; j++) {
            if (j == i) continue;
            int x = edges[j].from;
            int y = edges[j].to;
            int second_cost = edges[j].cost;
            if (u == y && adj[v][x] && saved_cost[u] != INT_MAX &&
                saved_cost[u] + second_cost < minimum_cost) {
                minimum_cost = saved_cost[u] + second_cost;
            }
        }
    }
    return minimum_cost;
}
void process_datasets() {
    while (1) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                adj[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            int a = edges[i].from;
            int b = edges[i].to;
            adj[a][b] = 1;
        }
        printf("%d\n", find_min_cost());
        if (scanf("%d %d", &n, &m) != 2 || (n == 0 && m == 0)) break;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].cost);
        }
    }
}
