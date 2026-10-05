#define MAX_N 20
#define MAX_M 100
typedef struct {
    int u, v;
    int cost_uv, cost_vu;
} Road;
int n, m;
Road roads[MAX_M];
int start, goal, initial_money, pillar_cost;
int dist_from_start[MAX_N + 1];
int dist_to_start[MAX_N + 1];
void dijkstra(int source, int dist[], int reverse) {
    int visited[MAX_N + 1] = {0};
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;
    for (int i = 0; i < n; i++) {
        int min_dist = INT_MAX;
        int min_index = -1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_index = j;
            }
        }
        if (min_index == -1) break;
        visited[min_index] = 1;
        for (int j = 0; j < m; j++) {
            int u = roads[j].u;
            int v = roads[j].v;
            int cost = reverse ? roads[j].cost_vu : roads[j].cost_uv;
            if (reverse) {
                int temp = u; u = v; v = temp; 
            }
            if (dist[u] != INT_MAX && dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
            }
        }
    }
}
int calculate_max_reward() {
    dijkstra(start, dist_from_start, 0);
    dijkstra(goal, dist_to_start, 1);
    int round_trip_cost = dist_from_start[goal] + dist_to_start[start];
    if (round_trip_cost < 0 || round_trip_cost >= INT_MAX || 
        pillar_cost < 0 || pillar_cost > initial_money) {
        return 0;
    }
    int reward = initial_money - (pillar_cost + round_trip_cost);
    return reward >= 0 ? reward : 0;
}