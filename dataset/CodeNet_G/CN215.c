typedef struct {
    int x, y, state;
} Node;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int w, h;
char map[1000][1001];
int dist[1000][1000][32];
int queue_size;
Node queue[1000000];
int attr_order[5] = {1, 2, 3, 4, 5}; 
int is_in_map(int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h;
}
void bfs(int start_x, int start_y, int initial_mask) {
    memset(dist, -1, sizeof(dist));
    queue_size = 0;
    queue[queue_size++] = (Node){start_x, start_y, initial_mask};
    dist[start_y][start_x][initial_mask] = 0;
    for (int front = 0; front < queue_size; front++) {
        Node current = queue[front];
        int x = current.x, y = current.y, state = current.state;
        int cur_dist = dist[y][x][state];
        if (map[y][x] == 'G' && state == 31) {
            printf("%d %d\n", attr_order[state & 7], cur_dist);
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!is_in_map(nx, ny)) continue;
            int new_state = state;
            if (map[ny][nx] >= '1' && map[ny][nx] <= '5') {
                int attr = map[ny][nx] - '1';
                if (state & (1 << (attr == 0 ? 4 : attr - 1))) {
                    new_state = state | (1 << attr);
                }
            }
            if (dist[ny][nx][new_state] == -1) {
                dist[ny][nx][new_state] = cur_dist + 1;
                queue[queue_size++] = (Node){nx, ny, new_state};
            }
        }
    }
    printf("NA\n");
}
void process_dataset() {
    scanf("%d %d", &w, &h);
    int start_x = -1, start_y = -1, goal_x = -1, goal_y = -1;
    for (int i = 0; i < h; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < w; j++) {
            if (map[i][j] == 'S') {
                start_x = j;
                start_y = i;
            } else if (map[i][j] == 'G') {
                goal_x = j;
                goal_y = i;
            }
        }
    }
    if (start_x == -1 || goal_x == -1) {
        printf("NA\n");
        return;
    }
    int result = INT_MAX;
    int best_attr = -1;
    for (int initial_attr = 0; initial_attr < 5; initial_attr++) {
        bfs(start_x, start_y, 1 << initial_attr);
        if (dist[goal_y][goal_x][31] != -1) {
            if (dist[goal_y][goal_x][31] < result) {
                result = dist[goal_y][goal_x][31];
                best_attr = initial_attr;
            }
        }
    }
    if (best_attr == -1) {
        printf("NA\n");
    } else {
        printf("%d %d\n", attr_order[best_attr], result);
    }
}
