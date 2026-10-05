#define MAX_N 1000
#define MAX_USERS 101
#define MAX_DATA 101
typedef struct {
    int type; 
    int user;
    int data;
} Relationship;
int graph[MAX_USERS + MAX_DATA][MAX_USERS + MAX_DATA]; 
int visited[MAX_USERS + MAX_DATA];
Relationship relations[MAX_N];
int num_relations;
int findCycle(int node) {
    if (visited[node] == 1) return 1;
    if (visited[node] == 2) return 0;
    visited[node] = 1;
    for (int i = 1; i < MAX_USERS + MAX_DATA; ++i) {
        if (graph[node][i] && findCycle(i)) return 1;
    }
    visited[node] = 2;
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    num_relations = n;
    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < n; ++i) {
        int user, data;
        char type[5];
        scanf("%d %s %d", &user, type, &data);
        int index = (type[0] == 'w') ? 1 : 0;
        relations[i] = (Relationship){index, user, data};
        if (index == 0) {
            graph[MAX_USERS + data][user] = 1;
        } else {
            graph[user][MAX_USERS + data] = 1;
        }
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i < MAX_USERS + MAX_DATA; ++i) {
        if (!visited[i] && findCycle(i)) {
            printf("1\n");
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
