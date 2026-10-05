#define MAX_N 3001
#define MAX_M 100001
typedef struct {
    int to;
    int length;
} Edge;
typedef struct {
    Edge edges[MAX_N];
    int size;
} Node;
Node nodes[MAX_N];
int mall[MAX_N];
int dist[MAX_N];
typedef struct {
    int node;
    int cost;
} QueueElement;
typedef struct {
    QueueElement data[MAX_M];
    int head, tail;
} Queue;
void push(Queue* q, int node, int cost) {
    q->data[q->tail].node = node;
    q->data[q->tail].cost = cost;
    q->tail++;
}
QueueElement pop(Queue* q) {
    return q->data[q->head++];
}
int isEmpty(Queue* q) {
    return q->head == q->tail;
}
int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        nodes[a].edges[nodes[a].size].to = b;
        nodes[a].edges[nodes[a].size].length = l;
        nodes[a].size++;
        nodes[b].edges[nodes[b].size].to = a;
        nodes[b].edges[nodes[b].size].length = l;
        nodes[b].size++;
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &mall[i]);
    }
    Queue q;
    q.head = q.tail = 0;
    for (int i = 1; i <= N; i++) {
        dist[i] = INT_MAX;
    }
    for (int i = 0; i < K; i++) {
        push(&q, mall[i], 0);
        dist[mall[i]] = 0;
    }
    while (!isEmpty(&q)) {
        QueueElement elem = pop(&q);
        int current = elem.node;
        int currentCost = elem.cost;
        if (currentCost > dist[current]) {
            continue;
        }
        for (int i = 0; i < nodes[current].size; i++) {
            int next = nodes[current].edges[i].to;
            int edgeCost = nodes[current].edges[i].length;
            if (dist[next] > currentCost + edgeCost) {
                dist[next] = currentCost + edgeCost;
                push(&q, next, dist[next]);
            }
        }
    }
    double maxDistance = 0.0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < nodes[i].size; j++) {
            int to = nodes[i].edges[j].to;
            int length = nodes[i].edges[j].length;
            double di = dist[i];
            double dt = dist[to];
            double l = length;
            if (di > dt) {
                double tmp = di;
                di = dt;
                dt = tmp;
            }
            double mid = (dt - di) / 2.0 + di;
            if (mid > maxDistance) {
                maxDistance = mid;
            }
        }
    }
    printf("%d\n", (int)(maxDistance + 0.5));
    return 0;
}