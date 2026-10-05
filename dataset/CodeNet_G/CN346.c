#define MAX_N 1500
#define MAX_R 3000
typedef struct {
    int u, v, w;
} Edge;
Edge edges[MAX_R];
int dist[MAX_N][MAX_N];
int reachable[MAX_N];
int queue[MAX_N];
int head, tail;
void floyd_warshall(int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = (i == j) ? 0 : INT_MAX / 2;
    for (int i = 0; i < MAX_R; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        dist[u][v] = dist[v][u] = w;
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}
int main(int argc, char *argv[]) {
    int n, r, max_dist = 0;
    scanf("%d %d", &n, &r);
    for (int i = 0; i < r; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (Edge){u - 1, v - 1, w};
    }
    floyd_warshall(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (dist[i][j] > max_dist)
                max_dist = dist[i][j];
    for (int i = 0; i < n; ++i) reachable[i] = 0;
    head = tail = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dist[i][j] == max_dist) {
                if (!reachable[i]) {
                    queue[tail++] = i;
                    reachable[i] = 1;
                }
                if (!reachable[j]) {
                    queue[tail++] = j;
                    reachable[j] = 1;
                }
            }
        }
    }
    while (head < tail) {
        int u = queue[head++];
        for (int i = 0; i < n; ++i) {
            if (dist[u][i] + dist[i][u] == 2 * max_dist && !reachable[i]) {
                reachable[i] = 1;
                queue[tail++] = i;
            }
        }
    }
    int quiet_count = 0;
    for (int i = 0; i < n; ++i)
        if (!reachable[i])
            quiet_count++;
    printf("%d\n", quiet_count);
    for (int i = 0; i < n; ++i)
        if (!reachable[i])
            printf("%d\n", i + 1);
    return 0;
}
