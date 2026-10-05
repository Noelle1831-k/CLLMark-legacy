#define MAXN 100000
int parent[MAXN];
int rank[MAXN];
int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}
void union_set(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootV] > rank[rootU]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        union_set(s, t);
    }
    int groups[MAXN] = {0};
    for (int i = 0; i < N; i++) {
        int root = find(i);
        groups[root]++;
    }
    int invited = 0;
    for (int i = 0; i < N; i++) {
        if (groups[i] > 0) {
            invited += groups[i];
        }
    }
    printf("%d\n", invited);
    return 0;
}
