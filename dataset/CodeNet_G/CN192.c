#define MAX_M 10
#define MAX_N 100
typedef struct {
    int id;
    int time;
} Car;
typedef struct {
    Car upper;
    Car lower;
} ParkingSpace;
void process_cases() {
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF && (m != 0 || n != 0)) {
        int t[MAX_N];
        for (int i = 0; i < n; i++) {
            scanf("%d", &t[i]);
        }
        ParkingSpace parking[MAX_M];
        for (int i = 0; i < m; i++) {
            parking[i].upper.id = parking[i].upper.time = 0;
            parking[i].lower.id = parking[i].lower.time = 0;
        }
        int queue[MAX_N], front = 0, rear = 0;
        int output[MAX_N], outIndex = 0, currentTime = 0;
        for (int i = 0; i < n; i++) {
            queue[rear++] = i;
            currentTime += 10;
            while (front < rear) {
                for (int j = 0; j < m; j++) {
                    int lowerTimeout = parking[j].lower.time ? parking[j].lower.time + parking[j].lower.id * 10 : -1;
                    int upperTimeout = parking[j].upper.time ? parking[j].upper.time + parking[j].upper.id * 10 : -1;
                    if (lowerTimeout <= currentTime && lowerTimeout > 0) {
                        output[outIndex++] = parking[j].lower.id + 1;
                        parking[j].lower.id = 0;
                        parking[j].lower.time = 0;
                    }
                    if (upperTimeout <= currentTime && upperTimeout > 0 && parking[j].lower.id == 0) {
                        output[outIndex++] = parking[j].upper.id + 1;
                        parking[j].upper.id = 0;
                        parking[j].upper.time = 0;
                    }
                }
                for (int j = 0; j < m; j++) {
                    if (parking[j].upper.id == 0 && parking[j].lower.id == 0 && front < rear) {
                        int idx = queue[front++];
                        parking[j].lower.id = idx;
                        parking[j].lower.time = t[idx];
                    } else if (parking[j].upper.id == 0 && front < rear) {
                        int idx = queue[front++];
                        if (t[idx] <= parking[j].lower.time) {
                            parking[j].upper.id = parking[j].lower.id;
                            parking[j].upper.time = parking[j].lower.time;
                            parking[j].lower.id = idx;
                            parking[j].lower.time = t[idx];
                        } else {
                            parking[j].upper.id = idx;
                            parking[j].upper.time = t[idx];
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (parking[i].lower.id) {
                output[outIndex++] = parking[i].lower.id + 1;
            }
            if (parking[i].upper.id) {
                output[outIndex++] = parking[i].upper.id + 1;
            }
        }
        for (int i = 0; i < outIndex; i++) {
            if (i) putchar(' ');
            printf("%d", output[i]);
        }
        putchar('\n');
    }
}
