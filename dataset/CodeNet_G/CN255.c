typedef struct {
    int length;
    int index;
} Pipe;
int cmp(const void *a, const void *b) {
    Pipe *pipeA = (Pipe *)a;
    Pipe *pipeB = (Pipe *)b;
    return pipeB->length - pipeA->length;
}
unsigned int getMaxSalary(int n, int *p, int *j) {
    Pipe pipes[65000];
    for (int i = 0; i < n; i++) {
        pipes[i].length = p[i];
        pipes[i].index = i;
    }
    qsort(pipes, n, sizeof(Pipe), cmp);
    int totalLength = 0;
    int used[65000] = {0};
    unsigned int salary = 0;
    for (int i = 0; i < n; i++) {
        int idx = pipes[i].index;
        used[idx] = 1;
        totalLength += pipes[i].length;
        salary += pipes[i].length;
        if (idx > 0 && used[idx - 1]) {
            totalLength += j[idx - 1];
            salary += j[idx - 1];
        }
        if (idx < n - 1 && used[idx + 1]) {
            totalLength += j[idx];
            salary += j[idx];
        }
    }
    return salary * n;
}