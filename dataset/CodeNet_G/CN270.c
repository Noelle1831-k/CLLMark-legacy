#define MAX_S 100001
#define MAX_R 200001
typedef struct {
    int to;
    int distance;
} Edge;
typedef struct {
    Edge *edges;
    int edge_count;
    int edge_capacity;
} Graph;
Graph graph[MAX_S];
void add_edge(int u, int v, int w) {
    if (graph[u].edge_count == graph[u].edge_capacity) {
        graph[u].edge_capacity *= 2;
        graph[u].edges = realloc(graph[u].edges, graph[u].edge_capacity * sizeof(Edge));
    }
    graph[u].edges[graph[u].edge_count].to = v;
    graph[u].edges[graph[u].edge_count].distance = w;
    graph[u].edge_count++;
}
typedef struct {
    int node;
    int distance;
} DijkstraNode;
DijkstraNode min_heap[MAX_S];
int min_heap_size;
int min_heap_pos[MAX_S];
void heap_swap(int i, int j) {
    DijkstraNode temp = min_heap[i];
    min_heap[i] = min_heap[j];
    min_heap[j] = temp;
    min_heap_pos[min_heap[i].node] = i;
    min_heap_pos[min_heap[j].node] = j;
}
void heapify_up(int idx) {
    while (idx > 0 && min_heap[idx].distance < min_heap[(idx - 1) / 2].distance) {
        heap_swap(idx, (idx - 1) / 2);
        idx = (idx - 1) / 2;
    }
}
void heapify_down(int idx) {
    int smallest = idx;
    if (2 * idx + 1 < min_heap_size && min_heap[2 * idx + 1].distance < min_heap[smallest].distance) {
        smallest = 2 * idx + 1;
    }
    if (2 * idx + 2 < min_heap_size && min_heap[2 * idx + 2].distance < min_heap[smallest].distance) {
        smallest = 2 * idx + 2;
    }
    if (smallest != idx) {
        heap_swap(idx, smallest);
        heapify_down(smallest);
    }
}
void heap_push(int node, int distance) {
    min_heap[min_heap_size].node = node;
    min_heap[min_heap_size].distance = distance;
    min_heap_pos[node] = min_heap_size;
    heapify_up(min_heap_size);
    min_heap_size++;
}
DijkstraNode heap_pop() {
    DijkstraNode top = min_heap[0];
    min_heap_size--;
    heap_swap(0, min_heap_size);
    heapify_down(0);
    return top;
}
bool heap_empty() {
    return min_heap_size == 0;
}
void dijkstra(int start, int *dist) {
    for (int i = 1; i <= MAX_S; i++) {
        dist[i] = INT_MAX;
        min_heap_pos[i] = -1;
    }
    dist[start] = 0;
    min_heap_size = 0;
    heap_push(start, 0);
    while (!heap_empty()) {
        DijkstraNode dnode = heap_pop();
        int u = dnode.node;
        if (dnode.distance > dist[u]) continue;
        for (int i = 0; i < graph[u].edge_count; i++) {
            Edge edge = graph[u].edges[i];
            int v = edge.to;
            int weight = edge.distance;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                if (min_heap_pos[v] == -1) {
                    heap_push(v, dist[v]);
                } else {
                    min_heap[min_heap_pos[v]].distance = dist[v];
                    heapify_up(min_heap_pos[v]);
                }
            }
        }
    }
}
bool can_travel(int a, int b, int c, int d, int *dist_a, int *dist_memo) {
    return dist_a[c] + dist_memo[d] - dist_memo[c] + dist_a[b] == dist_a[b] && dist_a[d] >= dist_a[c];
}
int main() {
    int S, R;
    scanf("%d %d", &S, &R);
    for (int i = 1; i <= S; i++) {
        graph[i].edge_count = 0;
        graph[i].edge_capacity = 8;
        graph[i].edges = malloc(graph[i].edge_capacity * sizeof(Edge));
    }
    for (int i = 0; i < R; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    int a, b, Q;
    scanf("%d %d %d", &a, &b, &Q);
    int dist_a[MAX_S], dist_b[MAX_S];
    dijkstra(a, dist_a);
    dijkstra(b, dist_b);
    for (int i = 0; i < Q; i++) {
        int c, d;
        scanf("%d %d", &c, &d);
        printf(can_travel(a, b, c, d, dist_a, dist_b) ? "Yes\n" : "No\n");
    }
    for (int i = 1; i <= S; i++) {
        free(graph[i].edges);
    }
    return 0;
}
