#define MAXN 100000
#define MAXM 200000
#define INF INT_MAX
typedef struct {
    int to;
    int length;
} Edge;
typedef struct {
    Edge edges[MAXM];
    int head[MAXN + 1];
    int next[MAXM];
    int edgeCount;
} Graph;
typedef struct {
    int node;
    int distance;
} QueueNode;
typedef struct {
    QueueNode queue[MAXN];
    int front;
    int back;
} Queue;
void initGraph(Graph* graph) {
    graph->edgeCount = 0;
    for (int i = 1; i <= MAXN; ++i) {
        graph->head[i] = -1;
    }
}
void addEdge(Graph* graph, int u, int v, int length) {
    graph->edges[graph->edgeCount].to = v;
    graph->edges[graph->edgeCount].length = length;
    graph->next[graph->edgeCount] = graph->head[u];
    graph->head[u] = graph->edgeCount++;
}
void initQueue(Queue* queue) {
    queue->front = 0;
    queue->back = 0;
}
int isEmpty(Queue* queue) {
    return queue->front == queue->back;
}
void push(Queue* queue, int node, int distance) {
    queue->queue[queue->back].node = node;
    queue->queue[queue->back].distance = distance;
    queue->back++;
}
QueueNode pop(Queue* queue) {
    return queue->queue[queue->front++];
}
void bfs(Graph* graph, int n, int* festivalCities, int k, int* festivalDistance) {
    Queue queue;
    initQueue(&queue);
    for (int i = 1; i <= n; ++i) {
        festivalDistance[i] = INF;
    }
    for (int i = 0; i < k; ++i) {
        int city = festivalCities[i];
        festivalDistance[city] = 0;
        push(&queue, city, 0);
    }
    while (!isEmpty(&queue)) {
        QueueNode current = pop(&queue);
        int u = current.node;
        int d = current.distance;
        for (int edgeIndex = graph->head[u]; edgeIndex != -1; edgeIndex = graph->next[edgeIndex]) {
            int v = graph->edges[edgeIndex].to;
            int length = graph->edges[edgeIndex].length;
            if (festivalDistance[v] > d + length) {
                festivalDistance[v] = d + length;
                push(&queue, v, festivalDistance[v]);
            }
        }
    }
}
int main() {
    int n, m, k, q;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    Graph graph;
    initGraph(&graph);
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        addEdge(&graph, a, b, l);
        addEdge(&graph, b, a, l);
    }
    int festivalCities[k];
    for (int i = 0; i < k; ++i) {
        scanf("%d", &festivalCities[i]);
    }
    int festivalDistance[n + 1];
    bfs(&graph, n, festivalCities, k, festivalDistance);
    for (int i = 0; i < q; ++i) {
        int s, t;
        scanf("%d %d", &s, &t);
        int maxDistance = festivalDistance[s] > festivalDistance[t] ? festivalDistance[s] : festivalDistance[t];
        printf("%d\n", maxDistance);
    }
    return 0;
}