Here is a C function implementing the described scheduling algorithm:
#define MAX_N 50000
#define MAX_D 200000
#define MAX_K 4
typedef struct {
    int id;
    int attr[MAX_K];
} Task;
int compare(const void *a, const void *b, void *order) {
    Task *taskA = (Task *)a;
    Task *taskB = (Task *)b;
    int *evalOrder = (int *)order;
    for (int i = 0; i < MAX_K; i++) {
        int diff = taskB->attr[evalOrder[i] - 1] - taskA->attr[evalOrder[i] - 1];
        if (diff != 0) return diff;
    }
    return taskA->id - taskB->id;
}
void executeTasks(int n, int k, Task tasks[], int evalOrder[], int depCount, int deps[][2], int changesCount, int changes[][MAX_K + 1]) {
    int indegree[MAX_N + 1] = {0};
    int order[MAX_N];
    int index = 0;
    int currentEvalOrder[MAX_K];
    for (int i = 0; i < k; i++) {
        currentEvalOrder[i] = evalOrder[i] - 1;
    }
    for (int i = 0; i < depCount; i++) {
        indegree[deps[i][1] - 1]++;
    }
    for (int count = 0; count < n;) {
        Task availableTasks[MAX_N];
        int numAvailable = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                availableTasks[numAvailable++] = tasks[i];
            }
        }
        qsort_r(availableTasks, numAvailable, sizeof(Task), compare, currentEvalOrder);
        Task selectedTask = availableTasks[0];
        printf("%d ", selectedTask.id + 1);
        for (int j = 0; j < numAvailable; j++) {
            if (availableTasks[j].id == selectedTask.id) {
                index = availableTasks[j].id;
                break;
            }
        }
        for (int i = 0; i < depCount; i++) {
            if (deps[i][0] - 1 == index) {
                indegree[deps[i][1] - 1]--;
            }
        }
        indegree[index] = -1;
        count++;
        if (changesCount > 0 && count == changes[0][0]) {
            for (int e = 0; e < k; e++) {
                currentEvalOrder[e] = changes[0][e + 1] - 1;
            }
            changes++;
            changesCount--;
        }
    }
}
