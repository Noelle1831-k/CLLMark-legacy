#define MAX_QUEUE 10000
typedef struct {
    int queue[MAX_QUEUE];
    int front;
    int rear;
} Lane;
void initLane(Lane *lane) {
    lane->front = 0;
    lane->rear = 0;
}
int isEmpty(Lane *lane) {
    return lane->front == lane->rear;
}
void enqueue(Lane *lane, int car) {
    lane->queue[lane->rear++] = car;
}
int dequeue(Lane *lane) {
    return lane->queue[lane->front++];
}
int queueSize(Lane *lane) {
    return lane->rear - lane->front;
}
Lane lanes[10];
void processGasStation(int N, int M, int info[M][2], int result[M]) {
    for (int i = 0; i < N; i++) {
        initLane(&lanes[i]);
    }
    int resultIndex = 0;
    for (int i = 0; i < M; i++) {
        if (info[i][0] == 1) {
            int carNum = info[i][1];
            int minLaneIndex = 0;
            for (int j = 1; j < N; j++) {
                if (queueSize(&lanes[j]) < queueSize(&lanes[minLaneIndex])) {
                    minLaneIndex = j;
                }
            }
            enqueue(&lanes[minLaneIndex], carNum);
        } else {
            int laneNumber = info[i][1] - 1;
            result[resultIndex++] = dequeue(&lanes[laneNumber]);
        }
    }
    for (int i = 0; i < resultIndex; i++) {
        printf("%d\n", result[i]);
    }
}