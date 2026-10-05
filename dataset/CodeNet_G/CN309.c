#define MOD 1000000007
typedef struct {
    int u, v, w;
} Edge;
int parent[101];
int rank[101];
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void union_set(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) return;
    if (rank[xr] < rank[yr]) {
        parent[xr] = yr;
    } else if (rank[xr] > rank[yr]) {
        parent[yr] = xr;
    } else {
        parent[yr] = xr;
        rank[xr]++;
    }
}
int compare_edges(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}
int N, M;
Edge edges[4951];
void solve() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    qsort(edges, M, sizeof(Edge), compare_edges);
    int max_distance = 0;
    long long ways = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            parent[j] = j;
            rank[j] = 0;
        }
        int e_count = 0;
        for (int j = 0; j < M; j++) {
            if (edges[j].w > edges[i].w) break;
            int pu = find(edges[j].u);
            int pv = find(edges[j].v);
            if (pu != pv) {
                union_set(pu, pv);
                e_count++;
            }
        }
        if (e_count == N - 1) {
            max_distance = edges[i].w;
            ways = (ways + 1) % MOD;
        }
    }
    printf("%d %lld\n", max_distance, ways);
}
