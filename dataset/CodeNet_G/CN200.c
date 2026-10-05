#define MAX_M 100
#define MAX_N 3000
typedef struct {
    int to;
    int cost;
    int time;
} Edge;
typedef struct {
    Edge edges[MAX_N];
    int size;
} AdjList;
AdjList graph[MAX_M + 1];
int dist_cost[MAX_M + 1];
int dist_time[MAX_M + 1];
int queue[MAX_M + 1];
int in_queue[MAX_M + 1];
void initialize_graph(int stations) {
    for (int i = 1; i <= stations; i++) {
        graph[i].size = 0;
    }
}
void add_edge(int from, int to, int cost, int time) {
    graph[from].edges[graph[from].size++] = (Edge) {to, cost, time};
    graph[to].edges[graph[to].size++] = (Edge) {from, cost, time};
}
void spfa(int start, int stations, int is_cost) {
    for (int i = 1; i <= stations; i++) {
        dist_cost[i] = INT_MAX;
        dist_time[i] = INT_MAX;
        in_queue[i] = 0;
    }
    int front = 0, rear = 0;
    queue[rear++] = start;
    if (is_cost) dist_cost[start] = 0; 
    else dist_time[start] = 0;
    in_queue[start] = 1;
    while (front != rear) {
        int cur = queue[front++];
        if (front > MAX_M) front -= MAX_M + 1;
        in_queue[cur] = 0;
        for (int i = 0; i < graph[cur].size; i++) {
            int next = graph[cur].edges[i].to;
            int cost = graph[cur].edges[i].cost;
            int time = graph[cur].edges[i].time;
            if (is_cost) {
                if (dist_cost[next] > dist_cost[cur] + cost) {
                    dist_cost[next] = dist_cost[cur] + cost;
                    if (!in_queue[next]) {
                        queue[rear++] = next;
                        if (rear > MAX_M) rear -= MAX_M + 1;
                        in_queue[next] = 1;
                    }
                }
            } else {
                if (dist_time[next] > dist_time[cur] + time) {
                    dist_time[next] = dist_time[cur] + time;
                    if (!in_queue[next]) {
                        queue[rear++] = next;
                        if (rear > MAX_M) rear -= MAX_M + 1;
                        in_queue[next] = 1;
                    }
                }
            }
        }
    }
}
int get_result(int end, int is_cost) {
    if (is_cost) return dist_cost[end];
    return dist_time[end];
}
