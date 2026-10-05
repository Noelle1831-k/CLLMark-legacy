#define MAX_NODES 100000
#define MAX_EDGES 200000
typedef struct {
    int to;
    int next;
} Edge;
Edge edges[MAX_EDGES * 2];
int head[MAX_NODES + 1];
int values[MAX_NODES + 1];
int dp[MAX_NODES + 1];
int visited[MAX_NODES + 1];
int edge_count = 0;
void add_edge(int u, int v) {
    edges[edge_count].to = v;
    edges[edge_count].next = head[u];
    head[u] = edge_count++;
}
void dfs(int node) {
    visited[node] = 1;
    dp[node] = values[node];
    for (int i = head[node]; i != -1; i = edges[i].next) {
        int next = edges[i].to;
        if (!visited[next]) {
            dfs(next);
        }
        dp[node] = dp[node] > values[node] + dp[next] ? dp[node] : values[node] + dp[next];
    }
}
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &values[i]);
    }
    for (int i = 1; i <= N; i++) {
        head[i] = -1;
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    int max_value = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            max_value = max_value > dp[i] ? max_value : dp[i];
        }
    }
    printf("%d\n", max_value);
    return 0;
}