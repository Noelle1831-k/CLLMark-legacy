typedef struct {
    int u, v;
} Edge;
int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    if (edgeA->u == edgeB->u) return edgeA->v - edgeB->v;
    return edgeA->u - edgeB->u;
}
int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int canBeArrangedOnLine(int n, int m, Edge edges[]) {
    if (m == 0) return 1;
    qsort(edges, m, sizeof(Edge), compareEdges);
    int sizes = 0;
    int* degrees = (int*)calloc(n + 1, sizeof(int));
    int* endpoint = (int*)calloc(2 * m, sizeof(int));
    for (int i = 0; i < m; i++) {
        degrees[edges[i].u]++;
        degrees[edges[i].v]++;
        int match = -1;
        for (int j = 0; j < sizes; j++) {
            if (endpoint[j] == edges[i].u || endpoint[j] == edges[i].v) {
                match = j;
                break;
            }
        }
        if (match != -1) {
            int newEndpoint = (endpoint[match] == edges[i].u) ? edges[i].v : edges[i].u;
            endpoint[match] = newEndpoint;
            for (int j = match + 1; j < sizes; j++) {
                if (endpoint[j] == edges[i].u || endpoint[j] == edges[i].v) {
                    endpoint[j] = -1;
                }
            }
        } else {
            endpoint[sizes++] = edges[i].u;
            endpoint[sizes++] = edges[i].v;
        }
    }
    int valid = 1;
    for (int i = 1; i <= n && valid; i++) {
        if (degrees[i] > 2) {
            valid = 0;
        }
    }
    free(degrees);
    free(endpoint);
    return valid;
}