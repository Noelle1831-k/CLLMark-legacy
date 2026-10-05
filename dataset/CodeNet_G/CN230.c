#define MAX_N 100
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
typedef struct {
    int floor;
    int jumps;
    int building;
} State;
int min_jumps(int n, int a[], int b[]) {
    int dp[2][MAX_N + 1];
    for (int i = 0; i <= n; i++) {
        dp[0][i] = dp[1][i] = INT_MAX;
    }
    dp[0][1] = dp[1][1] = 0;
    State queue[MAX_N * 2];
    int front = 0, rear = 0;
    queue[rear++] = (State){1, 0, 0};
    queue[rear++] = (State){1, 0, 1};
    while (front < rear) {
        State current = queue[front++];
        int current_floor = current.floor;
        int current_jumps = current.jumps;
        int current_building = current.building;
        if (current_floor < 1 || current_floor > n) continue;
        if (dp[current_building][current_floor] < current_jumps) continue;
        int next_floors[3] = {current_floor, current_floor + 1, current_floor + 2};
        int opposite_building = 1 - current_building;
        for (int i = 0; i < 3; i++) {
            int next_floor = next_floors[i];
            if (next_floor > n) continue;
            int wall_type = (current_building == 0) ? a[next_floor - 1] : b[next_floor - 1];
            int real_next_floor = next_floor;
            if (wall_type == 2) {
                while (real_next_floor > 1 && ((current_building == 0 ? a[real_next_floor - 2] : b[real_next_floor - 2]) == 2))
                    real_next_floor--;
            } else if (wall_type == 1 && real_next_floor < n) {
                real_next_floor++;
            }
            if (dp[opposite_building][real_next_floor] > current_jumps + 1) {
                dp[opposite_building][real_next_floor] = current_jumps + 1;
                queue[rear++] = (State){real_next_floor, current_jumps + 1, opposite_building};
            }
        }
    }
    int result = MIN(dp[0][n], dp[1][n]);
    return (result == INT_MAX) ? -1 : result;
}