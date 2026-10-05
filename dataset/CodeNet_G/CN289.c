typedef struct {
    int to;
    struct Node* next;
} Node;
typedef struct {
    int id;
    int dist;
} QueueNode;
typedef struct {
    QueueNode* data;
    int head, tail, size;
} Queue;
int min(int a, int b) {
    return a < b ? a : b;
}
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (QueueNode*)malloc(size * sizeof(QueueNode));
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
    return queue;
}
void enqueue(Queue* queue, int id, int dist) {
    queue->data[queue->tail].id = id;
    queue->data[queue->tail].dist = dist;
    queue->tail = (queue->tail + 1) % queue->size;
}
QueueNode dequeue(Queue* queue) {
    QueueNode node = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return node;
}
int isQueueEmpty(Queue* queue) {
    return queue->head == queue->tail;
}
void bfs(int start, Node** adj, int* dist, int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;
    Queue* queue = createQueue(n);
    enqueue(queue, start, 0);
    while (!isQueueEmpty(queue)) {
        QueueNode node = dequeue(queue);
        for (Node* cur = adj[node.id]; cur != NULL; cur = cur->next) {
            if (dist[cur->to] == INT_MAX) {
                dist[cur->to] = node.dist + 1;
                enqueue(queue, cur->to, dist[cur->to]);
            }
        }
    }
    free(queue->data);
    free(queue);
}
int commonAncestor(int u, int v, int* parent, int* depth) {
    while (u != v) {
        if (depth[u] > depth[v]) {
            u = parent[u];
        } else {
            v = parent[v];
        }
    }
    return u;
}
int findAmbushPlace(int target, Node** adj, int n) {
    int* dist = (int*)malloc(n * sizeof(int));
    int* revDist = (int*)malloc(n * sizeof(int));
    int* parent = (int*)malloc(n * sizeof(int));
    int* depth = (int*)malloc(n * sizeof(int));
    bfs(0, adj, dist, n);
    Node** reverseAdj = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        reverseAdj[i] = NULL;
        for (Node* node = adj[i]; node != NULL; node = node->next) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->to = i;
            newNode->next = reverseAdj[node->to];
            reverseAdj[node->to] = newNode;
        }
    }
    bfs(target, reverseAdj, revDist, n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            parent[i] = -1;
            depth[i] = 0;
        } else if (revDist[i] < INT_MAX) {
            int common = commonAncestor(0, i, parent, depth);
            depth[i] = depth[common] + revDist[i];
            parent[i] = common;
        }
    }
    free(revDist);
    free(parent);
    free(depth);
    int minDist = INT_MAX;
    int ambushPlace = -1;
    for (int i = 1; i < n; i++) {
        if (dist[i] < minDist && dist[i] + revDist[i] == dist[target]) {
            minDist = dist[i];
            ambushPlace = i;
        }
    }
    for (int i = 0; i < n; i++) {
        Node* node = reverseAdj[i];
        while (node) {
            Node* next = node->next;
            free(node);
            node = next;
        }
    }
    free(reverseAdj);
    free(dist);
    return ambushPlace + 1;
}