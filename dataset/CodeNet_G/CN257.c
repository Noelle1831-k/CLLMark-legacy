#define MAX_N 250
int canReachGoal(int max, int n, int *d) {
    int visited[MAX_N + 2] = {0};
    int reachable = 0;
    int queue[MAX_N + 2];
    int front = 0, rear = 0;
    queue[rear++] = 0;
    visited[0] = 1;
    while (front < rear) {
        int pos = queue[front++];
        for (int roll = 1; roll <= max; ++roll) {
            int newPos = pos + roll;
            if (newPos > n + 1) {
                newPos = n + 1;
            }
            if (newPos <= n && d[newPos] != 0) {
                newPos += d[newPos];
                if (newPos < 0) {
                    newPos = 0;
                } else if (newPos > n + 1) {
                    newPos = n + 1;
                }
            }
            if (newPos == n + 1) {
                reachable = 1;
                break;
            }
            if (!visited[newPos]) {
                visited[newPos] = 1;
                queue[rear++] = newPos;
            }
        }
        if (reachable) {
            break;
        }
    }
    return reachable ? 1 : 0;
}