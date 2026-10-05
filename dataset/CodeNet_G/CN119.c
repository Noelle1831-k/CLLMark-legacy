#define MAX_M 20
#define MAX_N 100
int adj[MAX_M + 1][MAX_M + 1];
int visited[MAX_M + 1];
int result[MAX_M];
int index;
void dfs(int u, int m) {
    visited[u] = 1;
    for (int v = 1; v <= m; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v, m);
        }
    }
    result[index--] = u;
}
void topological_sort(int m) {
    index = m - 1;
    for (int i = 1; i <= m; i++) {
        if (!visited[i]) {
            dfs(i, m);
        }
    }
}
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x][y] = 1;
    }
    topological_sort(m);
    for (int i = 0; i < m; i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}