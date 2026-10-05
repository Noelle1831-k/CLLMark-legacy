#define MAX_ROUTERS 100
#define MAX_PACKETS 1000
typedef struct {
    int destination;
    int ttl;
} Packet;
typedef struct {
    int connections[MAX_ROUTERS];
    int count;
} Router;
Router routers[MAX_ROUTERS + 1];
Packet packets[MAX_PACKETS];
int distance[MAX_ROUTERS + 1];
int queue[MAX_ROUTERS + 1];
int find_minimum_hops(int src, int dest, int ttl) {
    for (int i = 1; i <= MAX_ROUTERS; i++) {
        distance[i] = INT_MAX;
    }
    int front = 0, back = 0;
    queue[back++] = src;
    distance[src] = 0;
    while (front < back) {
        int current = queue[front++];
        int current_distance = distance[current];
        if (current_distance >= ttl) continue;
        for (int i = 0; i < routers[current].count; i++) {
            int neighbor = routers[current].connections[i];
            if (distance[neighbor] == INT_MAX) {
                distance[neighbor] = current_distance + 1;
                if (neighbor == dest) {
                    return current_distance + 1;
                }
                queue[back++] = neighbor;
            }
        }
    }
    return -1;
} 
int main() {
    for (int i = 0; i < MAX_PACKETS; i++) {
        int src = packets[i].destination;
        int dest = packets[i].ttl;
        int ttl = packets[i].ttl;
        int min_hops = find_minimum_hops(src, dest, ttl);
        if (min_hops == -1) {
            printf("NA\n");
        } else {
            printf("%d\n", min_hops);
        }
    }
    return 0;
}