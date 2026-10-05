#define MAXN 100000
#define INT_MIN (-2147483647 - 1)
typedef struct {
    int score;
    int index;
} Node;
typedef struct {
    int u, v;
} Edge;
Node nodes[MAXN + 1];
Edge edges[MAXN];
int tree[MAXN + 1][2];
int tree_size[MAXN + 1] = {0};
int visited[MAXN + 1] = {0};
int n;
int max(int a, int b) {
    return a > b ? a : b;
}
int dfs(int u, int *max_score_through_root) {
    visited[u] = 1;
    int max1 = 0, max2 = 0;
    for (int i = 0; i < tree_size[u]; ++i) {
        int v = tree[u][i];
        if (!visited[v]) {
            int current_max_score = dfs(v, max_score_through_root);
            if (current_max_score > max1) {
                max2 = max1;
                max1 = current_max_score;
            } else if (current_max_score > max2) {
                max2 = current_max_score;
            }
        }
    }
    *max_score_through_root = max(*max_score_through_root, max1 + max2 + nodes[u].score);
    return max1 + nodes[u].score;
}
int main() {
    int u, v;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nodes[i].score);
        nodes[i].index = i;
    }
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
        tree[edges[i].u][tree_size[edges[i].u]++] = edges[i].v;
        tree[edges[i].v][tree_size[edges[i].v]++] = edges[i].u;
    }
    int overall_max_score = INT_MIN;
    dfs(1, &overall_max_score);
    printf("%d\n", overall_max_score);
    return 0;
}
