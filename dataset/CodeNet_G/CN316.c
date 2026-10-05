typedef struct {
    int parent;
    int rank;
} UnionFind;
void make_set(UnionFind *uf, int n) {
    for (int i = 0; i < n; ++i) {
        uf[i].parent = i;
        uf[i].rank = 0;
    }
}
int find(UnionFind *uf, int a) {
    if (uf[a].parent != a)
        uf[a].parent = find(uf, uf[a].parent);
    return uf[a].parent;
}
void union_sets(UnionFind *uf, int a, int b) {
    int rootA = find(uf, a);
    int rootB = find(uf, b);
    if (rootA != rootB) {
        if (uf[rootA].rank < uf[rootB].rank) {
            uf[rootA].parent = rootB;
        } else if (uf[rootA].rank > uf[rootB].rank) {
            uf[rootB].parent = rootA;
        } else {
            uf[rootB].parent = rootA;
            uf[rootA].rank++;
        }
    }
}
int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    UnionFind *uf = malloc(N * sizeof(UnionFind));
    int *club = malloc(N * sizeof(int));
    make_set(uf, N);
    for (int i = 0; i < N; i++) club[i] = -1;
    int result = 0;
    for (int i = 0; i < K; i++) {
        int type, a, b;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d", &a, &b);
            a--; b--;
            if (find(uf, a) == find(uf, b)) continue;
            if ((club[a] != -1 && club[b] != -1 && club[a] != club[b]) || 
                (club[a] != -1 && club[a] == find(uf, b)) ||
                (club[b] != -1 && club[b] == find(uf, a))) {
                result = i + 1;
                break;
            }
            union_sets(uf, a, b);
        } else {
            scanf("%d %d", &a, &b);
            a--; b--;
            int root = find(uf, a);
            if (club[root] != -1 && club[root] != b) {
                result = i + 1;
                break;
            }
            club[root] = b;
        }
    }
    printf("%d\n", result);
    free(uf);
    free(club);
    return 0;
}
