#define MAX 12
#define INF 10000
typedef struct {
    int x, y, cost;
} Point;
int X, Y;
char maze[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int solve() {
    int start_x, start_y, goal_x, goal_y;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            if (maze[i][j] == 'S') {
                start_x = j;
                start_y = i;
            }
            if (maze[i][j] == 'G') {
                goal_x = j;
                goal_y = i;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    Point queue[MAX * MAX];
    int front = 0, rear = 0;
    queue[rear++] = (Point){start_x, start_y, 0};
    visited[start_y][start_x] = true;
    while (front < rear) {
        Point current = queue[front++];
        if (current.x == goal_x && current.y == goal_y) {
            return current.cost;
        }
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if (nx >= 0 && nx < X && ny >= 0 && ny < Y && !visited[ny][nx]) {
                if (maze[ny][nx] == '.' || maze[ny][nx] == 'G') {
                    visited[ny][nx] = true;
                    queue[rear++] = (Point){nx, ny, current.cost + 1};
                } else if (maze[ny][nx] == 'X') {
                    int ice_count = 0;
                    int step_count = 0;
                    int temp_nx = nx, temp_ny = ny;
                    while (maze[temp_ny][temp_nx] == 'X' && !visited[temp_ny][temp_nx]) {
                        ice_count++;
                        visited[temp_ny][temp_nx] = true;
                        step_count++;
                        temp_nx += dx[i];
                        temp_ny += dy[i];
                    }
                    int max_steps = ice_count / 2;
                    if (step_count <= max_steps) {
                        temp_nx = nx;
                        temp_ny = ny;
                        for (int sno = 0; sno < step_count; sno++) {
                            if (!visited[temp_ny][temp_nx]) {
                                visited[temp_ny][temp_nx] = true;
                                queue[rear++] = (Point){temp_nx, temp_ny, current.cost + 1 + sno};
                            }
                            temp_nx += dx[i];
                            temp_ny += dy[i];
                        }
                    }
                }
            }
        }
    }
    return INF;
}