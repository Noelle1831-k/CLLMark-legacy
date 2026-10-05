#define MAXN 100000
typedef struct Edge {
    int to, next, size;
} Edge;
Edge edges[MAXN * 2]; 
int head[MAXN];
int edge_count;
int N, K;
int visited[MAXN];
int parent[MAXN];
int depth[MAXN];
int cable_charge[MAXN * 2];
void add_edge(int a, int b, int size) {
    edges[edge_count].to = b;
    edges[edge_count].size = size;
    edges[edge_count].next = head[a];
    cable_charge[edge_count] = size % K == 0 ? 0 : size;
    head[a] = edge_count++;
}
void dfs_init(int node, int par, int dep) {
    parent[node] = par;
    depth[node] = dep;
    visited[node] = 1;
    for (int i = head[node]; i != -1; i = edges[i].next) {
        int to = edges[i].to;
        if (!visited[to]) {
            dfs_init(to, node, dep + 1);
        }
    }
}
void increase_cable_sizes(int x, int d) {
    for (int i = head[x]; i != -1; i = edges[i].next) {
        edges[i].size += d;
        cable_charge[i] = edges[i].size % K == 0 ? 0 : edges[i].size;
    }
}
int find_comm_charge(int s, int t) {
    int charge = 0;
    while (s != t) {
        if (depth[s] > depth[t]) {
            for (int i = head[s]; i != -1; i = edges[i].next) {
                if (edges[i].to == parent[s]) {
                    charge += cable_charge[i];
                    s = parent[s];
                    break;
                }
            }
        } else {
            for (int i = head[t]; i != -1; i = edges[i].next) {
                if (edges[i].to == parent[t]) {
                    charge += cable_charge[i];
                    t = parent[t];
                    break;
                }
            }
        }
    }
    return charge;
}
void execute_queries(char* queries[], int Q) {
    for (int i = 0; i < Q; ++i) {
        char* query_type = queries[i];
        if (strncmp(query_type, "add", 3) == 0) {
            int x, d;
            sscanf(query_type, "add %d %d", &x, &d);
            increase_cable_sizes(x, d);
        } else if (strncmp(query_type, "send", 4) == 0) {
            int s, t;
            sscanf(query_type, "send %d %d", &s, &t);
            printf("%d\n", find_comm_charge(s, t));
        }
    }
}
