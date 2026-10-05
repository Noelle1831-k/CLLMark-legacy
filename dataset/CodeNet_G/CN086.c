#define MAX 101
#define INF 999999
typedef struct {
    int start, end;
} Road;
int roads[MAX][MAX];
int visited[MAX];
int pathCount;
int n;
void initialize_roads() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            roads[i][j] = 0;
        }
    }
}
void initialize_visited() {
    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }
}
void dfs(int current, int destination) {
    if (current == destination) {
        pathCount++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (roads[current][i] == 1 && !visited[i]) {
            visited[i] = 1;
            dfs(i, destination);
            visited[i] = 0;
        }
    }
}
int check_criteria() {
    initialize_visited();
    pathCount = 0;
    visited[1] = 1;
    dfs(1, 2);
    if (pathCount == 1) {
        return 1;
    }
    return 0;
}
void read_input_and_process() {
    int a, b;
    while (scanf("%d %d", &a, &b) && a && b) {
        roads[a][b] = 1;
        roads[b][a] = 1;
        if (a > n) n = a;
        if (b > n) n = b;
    }
}
int main() {
    while (1) {
        initialize_roads();
        n = 0;
        read_input_and_process();
        if (n == 0) break;
        printf(check_criteria() ? "OK\n" : "NG\n");
    }
    return 0;
}
