#define MAX_N 1000
#define MAX_P 2000
typedef struct {
    int end;
    int time1;
    int time2;
} Line;
Line lines[MAX_N][MAX_N];
int line_count[MAX_N];
int dp[MAX_N][2];
int min(int a, int b) {
    return a < b ? a : b;
}
void dijkstra(int start_flag, int flag_count, int use_second_time) {
    int min_time[MAX_N];
    int visited[MAX_N] = {0};
    for (int i = 1; i <= flag_count; ++i) {
        min_time[i] = INT_MAX;
        visited[i] = 0;
    }
    min_time[start_flag] = 0;
    for (int i = 1; i <= flag_count; ++i) {
        int u = -1;
        for (int j = 1; j <= flag_count; ++j) {
            if (!visited[j] && (u == -1 || min_time[j] < min_time[u])) {
                u = j;
            }
        }
        if (min_time[u] == INT_MAX) break;
        visited[u] = 1;
        for (int j = 0; j < line_count[u]; ++j) {
            Line *line = &lines[u][j];
            int cost = use_second_time ? line->time2 : line->time1;
            if (min_time[u] + cost < min_time[line->end]) {
                min_time[line->end] = min_time[u] + cost;
            }
        }
    }
    for (int i = 1; i <= flag_count; ++i) {
        dp[i][use_second_time] = min_time[i];
    }
}
void solve_minimum_time(int flag_count) {
    dijkstra(1, flag_count, 0);
    dijkstra(1, flag_count, 1);
    int min_total_time = INT_MAX;
    for (int u = 1; u <= flag_count; ++u) {
        for (int j = 0; j < line_count[u]; ++j) {
            Line *line = &lines[u][j];
            int total_time = dp[u][0] + line->time2 + dp[line->end][1];
            min_total_time = min(min_total_time, total_time);
        }
    }
    printf("%d\n", min_total_time);
}