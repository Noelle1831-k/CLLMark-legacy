#define MAX_N 5000
int parent[MAX_N+1];
int rank[MAX_N+1];
int visited[MAX_N+1];
int result[MAX_N];
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}
int main() {
    int n, m;
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
        visited[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        unite(a, b);
    }
    for (int i = 1; i <= n; i++) {
        int root = find(i);
        visited[root]++;
    }
    int index = 0;
    int ambiguity = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] > 0) {
            for (int j = 0; j < visited[i]; j++) {
                result[index++] = i;
            }
            if (visited[i] > 1) {
                ambiguity = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }
    printf("%d\n", ambiguity);
    return 0;
}