#define INF INT_MAX
int adj[101][101];
void floydWarshall(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adj[i][k] != INF && adj[k][j] != INF && adj[i][k] + adj[k][j] < adj[i][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
}
void initializeAdjMatrix(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                adj[i][j] = 0;
            } else {
                adj[i][j] = INF;
            }
        }
    }
}
int main() {
    int n, k;
    while (scanf("%d %d", &n, &k), n || k) {
        initializeAdjMatrix(n);
        int queries = 0;
        int responses[5000];
        for (int i = 0; i < k; i++) {
            int type, a, b, cost;
            scanf("%d %d %d", &type, &a, &b);
            if (type == 0) {
                queries++;
                floydWarshall(n);
                if (adj[a][b] == INF) {
                    responses[queries - 1] = -1;
                } else {
                    responses[queries - 1] = adj[a][b];
                }
            } else if (type == 1) {
                scanf("%d", &cost);
                if (adj[a][b] > cost) {
                    adj[a][b] = adj[b][a] = cost;
                }
            }
        }
        for (int i = 0; i < queries; i++) {
            printf("%d\n", responses[i]);
        }
    }
    return 0;
}