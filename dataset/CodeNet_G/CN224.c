#define MAX_NODES 106
#define INF INT_MAX
int m, n, k, d;
int cakeCalories[7];
int distances[MAX_NODES][MAX_NODES];
int minCalories = INF;
int visited[MAX_NODES];
int start, destination;
void dfs(int node, int netCalories) {
    if (node == destination) {
        if (netCalories < minCalories) {
            minCalories = netCalories;
        }
        return;
    }
    for (int i = 0; i < MAX_NODES; ++i) {
        if (distances[node][i] != INF && !visited[i]) {
            int caloriesBurned = k * distances[node][i];
            int newNetCalories = netCalories + caloriesBurned;
            if (i >= 1 && i <= m) {
                newNetCalories -= cakeCalories[i - 1];
            }
            visited[i] = 1;
            dfs(i, newNetCalories);
            visited[i] = 0;
        }
    }
}
int main() {
    while (scanf("%d %d %d %d", &m, &n, &k, &d), m) {
        for (int i = 0; i < m; ++i) {
            scanf("%d", &cakeCalories[i]);
        }
        memset(distances, INF, sizeof(distances));
        for (int i = 0; i < d; ++i) {
            char s[3], t[3];
            int e;
            scanf("%s %s %d", s, t, &e);
            int u = 0, v = 0;
            if (s[0] == 'H') u = 0;
            else if (s[0] == 'D') u = MAX_NODES - 1;
            else if (s[0] == 'C') u = s[1] - '0';
            else if (s[0] == 'L') u = m + (s[1] - '0');
            if (t[0] == 'H') v = 0;
            else if (t[0] == 'D') v = MAX_NODES - 1;
            else if (t[0] == 'C') v = t[1] - '0';
            else if (t[0] == 'L') v = m + (t[1] - '0');
            distances[u][v] = distances[v][u] = e;
        }
        minCalories = INF;
        memset(visited, 0, sizeof(visited));
        start = 0;
        destination = MAX_NODES - 1;
        visited[start] = 1;
        dfs(start, 0);
        printf("%d\n", minCalories);
    }
    return 0;
}
