int W[2], H[2], X[2], Y[2];
int L[2][500][500];
int visited[2][500][500];
int queue[250000][3];
int front, rear, R, total_cells;
int bfs(int office, int auth_level) {
    front = rear = 0;
    queue[rear][0] = X[office] - 1;
    queue[rear][1] = Y[office] - 1;
    queue[rear++][2] = 1;
    visited[office][X[office] - 1][Y[office] - 1] = 1;
    int count = 0;
    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        int step = queue[front++][2];
        count++;
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int d = 0; d < 4; d++) {
            int nx = x + directions[d][0];
            int ny = y + directions[d][1];
            if (nx >= 0 && nx < W[office] && ny >= 0 && ny < H[office]) {
                if (!visited[office][nx][ny] && L[office][nx][ny] <= auth_level) {
                    visited[office][nx][ny] = 1;
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    queue[rear++][2] = step + 1;
                }
            }
        }
    }
    return count;
}
int check(int auth1, int auth2) {
    for (int i = 0; i < W[0]; i++)
        for (int j = 0; j < H[0]; j++)
            visited[0][i][j] = 0;
    for (int i = 0; i < W[1]; i++)
        for (int j = 0; j < H[1]; j++)
            visited[1][i][j] = 0;
    int rooms_visited = bfs(0, auth1) + bfs(1, auth2);
    return rooms_visited >= R;
}
int main() {
    int min_auth_sum;
    while (scanf("%d", &R) && R != 0) {
        total_cells = 0;
        for (int k = 0; k < 2; k++) {
            scanf("%d%d%d%d", &W[k], &H[k], &X[k], &Y[k]);
            total_cells += W[k] * H[k];
            for (int j = 0; j < H[k]; j++)
                for (int i = 0; i < W[k]; i++)
                    scanf("%d", &L[k][i][j]);
        }
        int low = 0, high = 100000000, mid;
        min_auth_sum = INT_MAX;
        while (low <= high) {
            mid = (low + high) / 2;
            if (check(mid, mid)) {
                min_auth_sum = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        printf("%d\n", min_auth_sum);
    }
    return 0;
}