#define MOD 1000000007
#define MAX_N 1000
#define MAX_CHILDREN 10
typedef struct {
    char type;
    int is_optional;
    int children[MAX_CHILDREN];
    int child_count;
} Node;
Node nodes[MAX_N + 1];
int N;
long long dfs(int index) {
    Node *node = &nodes[index];
    if (node->type == 'E') {
        return 1;
    }
    long long result = 1;
    if (node->type == 'A') {
        result = 0;
        for (int i = 0; i < node->child_count; i++) {
            result += dfs(node->children[i]);
            if (result >= MOD) result -= MOD;
        }
    } else if (node->type == 'R') {
        result = 0;
        int combinations[MAX_CHILDREN] = {1};
        for (int i = 0; i < node->child_count; i++) {
            for (int j = node->child_count; j > 0; j--) {
                combinations[j] += combinations[j - 1] * dfs(node->children[i]);
                if (combinations[j] >= MOD) combinations[j] %= MOD;
            }
        }
        for (int i = 1; i <= node->child_count; i++) {
            result += combinations[i];
            if (result >= MOD) result -= MOD;
        }
    }
    if (node->is_optional) {
        result++;
        if (result >= MOD) result -= MOD;
    }
    return result;
}
void parse_node(char *s, int index) {
    nodes[index].is_optional = (s[1] == '?');
    nodes[index].type = s[0];
    nodes[index].child_count = 0;
}
void parse_edge(int parent, int child) {
    nodes[parent].children[nodes[parent].child_count++] = child;
}
int main() {
    int s, t;
    char node_info[5];
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%s", node_info);
        parse_node(node_info, i);
    }
    for (int i = 1; i < N; i++) {
        scanf("%d %d", &s, &t);
        parse_edge(s, t);
    }
    printf("%lld\n", dfs(1) % MOD);
    return 0;
}
