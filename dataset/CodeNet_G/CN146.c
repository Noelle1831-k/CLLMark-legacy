#define MAX_N 15
typedef struct {
    int s;
    int d;
    int v;
} Warehouse;
Warehouse warehouses[MAX_N];
int n;
double calcTime(int order[]) {
    double time = 0.0;
    int accumulatedWeight = 0;
    int currentDistance = 0;
    for (int i = 0; i < n; ++i) {
        int index = order[i];
        accumulatedWeight += warehouses[index].v * 20;
        double speed = 2000.0 / (70 + accumulatedWeight);
        int nextDistance = warehouses[index].d;
        time += (nextDistance - currentDistance) / speed;
        currentDistance = nextDistance;
    }
    return time;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void findOptimalOrder(int depth, double *minTime, int currentOrder[], int used[], int result[]) {
    if (depth == n) {
        double time = calcTime(currentOrder);
        if (time < *minTime) {
            *minTime = time;
            for (int i = 0; i < n; i++)
                result[i] = warehouses[currentOrder[i]].s;
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            currentOrder[depth] = i;
            used[i] = 1;
            findOptimalOrder(depth + 1, minTime, currentOrder, used, result);
            used[i] = 0;
        }
    }
}
int main() {
    int currentOrder[MAX_N], result[MAX_N], used[MAX_N] = {0};
    double minTime = 1e9;
    findOptimalOrder(0, &minTime, currentOrder, used, result);
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
