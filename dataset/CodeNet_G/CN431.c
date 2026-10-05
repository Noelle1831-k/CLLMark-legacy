#define MAX_N 100
int visited[MAX_N + 1];
int adj[MAX_N + 1][MAX_N + 1];
int max_length;
void dfs(int node, int length, int total_nodes){
    visited[node] = 1;
    if (length > max_length) max_length = length;
    for (int i = 1; i <= total_nodes; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, length + 1, total_nodes);
        }
    }
    visited[node] = 0;
}
int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        memset(adj, 0, sizeof(adj));
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a][b] = adj[b][a] = 1;
        }
        max_length = 0;
        for (int i = 1; i <= MAX_N; i++) {
            memset(visited, 0, sizeof(visited));
            dfs(i, 1, MAX_N);
        }
        printf("%d\n", max_length);
    }
    return 0;
}