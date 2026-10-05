#define MAX_SIZE 1000
#define INF 1000000000
typedef struct {
    int x, y;
    int collected_items;
    int moves;
    int score;
} State;
int W, H;
char maze[MAX_SIZE][MAX_SIZE];
int scores[10][10];
int item_position[10][2];
int start[2], goal[2];
int visited[MAX_SIZE][MAX_SIZE][1024];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int bfs() {
    State queue[MAX_SIZE * MAX_SIZE * 1024];
    int front = 0, rear = 0;
    queue[rear++] = (State){start[0], start[1], 0, 0, 0};
    visited[start[0]][start[1]][0] = 0;
    while (front < rear) {
        State current = queue[front++];
        if (current.x == goal[0] && current.y == goal[1]) {
            if (current.collected_items == (1 << 10) - 1)
                return current.moves;
            continue;
        }
        for (int direction = 0; direction < 4; ++direction) {
            int nx = current.x + dx[direction];
            int ny = current.y + dy[direction];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            char symbol = maze[nx][ny];
            if (symbol == '#') continue;
            int next_items = current.collected_items;
            int extra_score = 0;
            if ('0' <= symbol && symbol <= '9') {
                int item = symbol - '0';
                if (!(current.collected_items & (1 << item))) {
                    next_items |= (1 << item);
                    for (int last_item = 0; last_item < 10; ++last_item) {
                        if (last_item == item) continue;
                        if (current.collected_items & (1 << last_item)) {
                            extra_score += scores[last_item][item];
                        }
                    }
                }
            } else if ('A' <= symbol && symbol <= 'J') {
                int item = symbol - 'A';
                if (current.collected_items & (1 << item)) continue;
            } else if ('a' <= symbol && symbol <= 'j') {
                int item = symbol - 'a';
                if (!(current.collected_items & (1 << item))) continue;
            }
            if (visited[nx][ny][next_items] > current.moves + 1) {
                visited[nx][ny][next_items] = current.moves + 1;
                State next = {nx, ny, next_items, current.moves + 1, current.score + extra_score};
                queue[rear++] = next;
            }
        }
    }
    return -1;
}
int max_score() {
    State queue[MAX_SIZE * MAX_SIZE * 1024];
    int front = 0, rear = 0;
    queue[rear++] = (State){goal[0], goal[1], (1 << 10) - 1, visited[goal[0]][goal[1]][(1 << 10) - 1], 0};
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
            for (int k = 0; k < 1024; ++k) {
                visited[i][j][k] = INF;
            }
        }
    }
    visited[goal[0]][goal[1]][(1 << 10) - 1] = 0;
    int max_score = 0;
    while (front < rear) {
        State current = queue[front++];
        if (current.x == start[0] && current.y == start[1]) {
            if (current.collected_items == 0) {
                if (current.score > max_score) max_score = current.score;
            }
            continue;
        }
        for (int direction = 0; direction < 4; ++direction) {
            int nx = current.x + dx[direction];
            int ny = current.y + dy[direction];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            char symbol = maze[nx][ny];
            if (symbol == '#') continue;
            int next_items = current.collected_items;
            int extra_score = 0;
            if ('0' <= symbol && symbol <= '9') {
                int item = symbol - '0';
                if (current.collected_items & (1 << item)) {
                    next_items &= ~(1 << item);
                    for (int prev_item = 0; prev_item < 10; ++prev_item) {
                        if (prev_item == item) continue;
                        if (!(next_items & (1 << prev_item))) {
                            extra_score += scores[item][prev_item];
                        }
                    }
                } else {
                    continue;
                }
            } else if ('A' <= symbol && symbol <= 'J') {
                int item = symbol - 'A';
                if (!(next_items & (1 << item))) continue;
            } else if ('a' <= symbol && symbol <= 'j') {
                int item = symbol - 'a';
                if (next_items & (1 << item)) continue;
            }
            if (visited[nx][ny][next_items] > current.moves - 1) {
                visited[nx][ny][next_items] = current.moves - 1;
                State next = {nx, ny, next_items, current.moves - 1, current.score + extra_score};
                queue[rear++] = next;
            }
        }
    }
    return max_score;
}
int main() {
    scanf("%d %d", &W, &H);
    for (int i = 0; i < H; ++i) {
        scanf("%s", maze[i]);
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            scanf("%d", &scores[i][j]);
        }
    }
    int item_count = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (maze[i][j] == 'S') {
                start[0] = i;
                start[1] = j;
            } else if (maze[i][j] == 'T') {
                goal[0] = i;
                goal[1] = j;
            } else if ('0' <= maze[i][j] && maze[i][j] <= '9') {
                int item = maze[i][j] - '0';
                item_position[item][0] = i;
                item_position[item][1] = j;
                item_count++;
            }
        }
    }
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
            for (int k = 0; k < 1024; ++k) {
                visited[i][j][k] = INF;
            }
        }
    }
    int min_moves = bfs();
    if (min_moves == -1) {
        printf("-1\n");
    } else {
        int max_s = max_score();
        printf("%d %d\n", min_moves, max_s);
    }
    return 0;
}
