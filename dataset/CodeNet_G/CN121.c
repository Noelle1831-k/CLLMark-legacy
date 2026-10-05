#define WIDTH 4
#define HEIGHT 2
#define SIZE 8
typedef struct {
    int state[SIZE];
    int zero_pos;
    int depth;
} Puzzle;
typedef struct {
    Puzzle puzzles[362880]; 
    int front, rear;
} Queue;
void init_queue(Queue *q) {
    q->front = q->rear = 0;
}
int is_empty(Queue *q) {
    return q->front == q->rear;
}
void enqueue(Queue *q, Puzzle p) {
    q->puzzles[q->rear++] = p;
}
Puzzle dequeue(Queue *q) {
    return q->puzzles[q->front++];
}
int is_goal(Puzzle *p) {
    for (int i = 0; i < SIZE; i++) {
        if (p->state[i] != i) return 0;
    }
    return 1;
}
int in_bounds(int pos) {
    return pos >= 0 && pos < SIZE;
}
int is_duplicate(Puzzle *p, Puzzle visited[]) {
    for (int i = 0; i < SIZE; i++) {
        if (memcmp(p->state, visited[i].state, SIZE * sizeof(int)) == 0)
            return 1;
    }
    return 0;
}
int bfs(int initial_state[]) {
    Queue queue;
    init_queue(&queue);
    Puzzle initial = { .depth = 0 };
    memcpy(initial.state, initial_state, SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++) {
        if (initial.state[i] == 0) {
            initial.zero_pos = i;
            break;
        }
    }
    enqueue(&queue, initial);
    Puzzle visited[362880];
    memset(visited, -1, sizeof(visited));
    int directions[] = { -1, 1, -WIDTH, WIDTH };
    while (!is_empty(&queue)) {
        Puzzle current = dequeue(&queue);
        if (is_goal(&current)) {
            return current.depth;
        }
        for (int i = 0; i < 4; i++) {
            int new_zero_pos = current.zero_pos + directions[i];
            if (in_bounds(new_zero_pos) &&
                !(current.zero_pos % WIDTH == WIDTH - 1 && i == 1) &&
                !(current.zero_pos % WIDTH == 0 && i == -1)) {
                Puzzle next = current;
                next.state[current.zero_pos] = next.state[new_zero_pos];
                next.state[new_zero_pos] = 0;
                next.zero_pos = new_zero_pos;
                next.depth = current.depth + 1;
                if (!is_duplicate(&next, visited)) {
                    enqueue(&queue, next);
                }
            }
        }
    }
    return -1;
}