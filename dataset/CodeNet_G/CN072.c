#define MAX_NODES 100
#define INF 1000000
typedef struct {
    int u, v, weight;
} Edge;
Edge edges[MAX_NODES * (MAX_NODES - 1) / 2];
int parent[MAX_NODES];
int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}
void union_set(int u, int v) {
    parent[find(u)] = find(v);
}
int cmp(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}
int kruskal(int n, int m) {
    int mst_weight = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i;
    qsort(edges, m, sizeof(Edge), cmp);
    for (int i = 0; i < m; i++) {
        int u_set = find(edges[i].u);
        int v_set = find(edges[i].v);
        if (u_set != v_set) {
            union_set(u_set, v_set);
            mst_weight += edges[i].weight / 100 - 1;
        }
    }
    return mst_weight;
}
int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) && n != 0) {
        for (int i = 0; i < m; i++) {
            int u, v, d;
            scanf("%d,%d,%d", &u, &v, &d);
            edges[i].u = u;
            edges[i].v = v;
            edges[i].weight = d;
        }
        printf("%d\n", kruskal(n, m));
    }
    return 0;
}