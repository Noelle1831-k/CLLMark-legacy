typedef struct {
    int src, dest, cost;
} Bridge;
int compare(const void *a, const void *b) {
    return ((Bridge *)a)->cost - ((Bridge *)b)->cost;
}
int findParent(int city, int *parent) {
    if (parent[city] != city) {
        parent[city] = findParent(parent[city], parent);
    }
    return parent[city];
}
int kruskal(int n, int m, Bridge bridges[]) {
    qsort(bridges, m, sizeof(Bridge), compare);
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int totalCost = 0, edgesUsed = 0;
    for (int i = 0; i < m && edgesUsed < n - 1; i++) {
        int uParent = findParent(bridges[i].src, parent);
        int vParent = findParent(bridges[i].dest, parent);
        if (uParent != vParent) {
            totalCost += bridges[i].cost;
            parent[uParent] = vParent;
            edgesUsed++;
        }
    }
    return totalCost;
}