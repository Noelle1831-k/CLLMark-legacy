#define MAX_N 100000
int N;
long long a[MAX_N];
bool visited[MAX_N];
bool can_finish[MAX_N];
void dfs(int start) {
    int position = start;
    while (true) {
        if (visited[position]) {
            break;
        }
        visited[position] = true;
        position = (position + a[position]) % N;
    }
    if (position == start) {
        position = start;
        while (!can_finish[position]) {
            can_finish[position] = true;
            position = (position + a[position]) % N;
        }
    }
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    int result = 0;
    for (int i = 0; i < N; ++i) {
        if (can_finish[i]) {
            result++;
        }
    }
    printf("%d\n", result);
    return 0;
}