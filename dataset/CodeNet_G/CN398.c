typedef struct {
    int x, y;
    int index;
} City;
int compareX(const void *a, const void *b) {
    return ((City *)a)->x - ((City *)b)->x;
}
int compareY(const void *a, const void *b) {
    return ((City *)a)->y - ((City *)b)->y;
}
typedef struct {
    int u, v;
    int cost;
} Edge;
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->cost - ((Edge *)b)->cost;
}
int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}
void unite(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}
void calculateMinCost(int N, City cities[]) {
    Edge *edges = (Edge *)malloc(2 * (N - 1) * sizeof(Edge));
    int eCount = 0;
    qsort(cities, N, sizeof(City), compareX);
    for (int i = 0; i < N - 1; i++) {
        edges[eCount].u = cities[i].index;
        edges[eCount].v = cities[i + 1].index;
        edges[eCount].cost = abs(cities[i].x - cities[i + 1].x);
        eCount++;
    }
    qsort(cities, N, sizeof(City), compareY);
    for (int i = 0; i < N - 1; i++) {
        edges[eCount].u = cities[i].index;
        edges[eCount].v = cities[i + 1].index;
        edges[eCount].cost = abs(cities[i].y - cities[i + 1].y);
        eCount++;
    }
    qsort(edges, eCount, sizeof(Edge), compareEdges);
    int *parent = (int *)malloc(N * sizeof(int));
    int *rank = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    int minCost = 0;
    for (int i = 0; i < eCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int setU = find(parent, u);
        int setV = find(parent, v);
        if (setU != setV) {
            minCost += edges[i].cost;
            unite(parent, rank, setU, setV);
        }
    }
    printf("%d\n", minCost);
    free(edges);
    free(parent);
    free(rank);
}
