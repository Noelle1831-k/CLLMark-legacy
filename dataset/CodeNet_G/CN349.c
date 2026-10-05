typedef struct {
    int idx;
    long x, y;
    char dir;
    long time;
} Ant;
int compare(const void* a, const void* b) {
    Ant* ant1 = (Ant*)a;
    Ant* ant2 = (Ant*)b;
    if (ant1->time != ant2->time) return ant1->time - ant2->time;
    return ant1->idx - ant2->idx;
}
void simulate_ant_fall(long W, long H, int N, long* antData, int* result) {
    Ant* ants = (Ant*)malloc(N * sizeof(Ant));
    for (int i = 0; i < N; ++i) {
        ants[i].idx = i + 1;
        ants[i].x = antData[i * 3 + 0];
        ants[i].y = antData[i * 3 + 1];
        ants[i].dir = (char)antData[i * 3 + 2];
        if (ants[i].dir == 'E') {
            ants[i].time = W - ants[i].x;
        } else {
            ants[i].time = H - ants[i].y;
        }
    }
    qsort(ants, N, sizeof(Ant), compare);
    for (int i = 0; i < N; ++i) {
        result[i] = ants[i].idx;
    }
    free(ants);
}