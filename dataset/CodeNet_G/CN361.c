#define MAXN 10000
int N, M;
int roads[MAXN][MAXN];
int visited[MAXN];
void dfs(int city) {
    visited[city] = 1;
    for (int i = 0; i < N; i++) {
        if (roads[city][i] && !visited[i]) {
            dfs(i);
        }
    }
}
void reverseDfs(int city) {
    visited[city] = 1;
    for (int i = 0; i < N; i++) {
        if (roads[i][city] && !visited[i]) {
            reverseDfs(i);
        }
    }
}
int kosaraju() {
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) {
        if (!visited[i]) dfs(i);
    }
    memset(visited, 0, sizeof(visited));
    int components = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            reverseDfs(i);
            components++;
        }
    }
    return components;
}
int main() {
    scanf("%d %d", &N, &M);
    memset(roads, 0, sizeof(roads));
    for (int i = 0; i < M; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        roads[s][t] = 1;
    }
    int components = kosaraju();
    printf("%d\n", components - 1);
    return 0;
}
