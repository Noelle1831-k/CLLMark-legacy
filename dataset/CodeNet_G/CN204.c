typedef struct {
    int x;
    int y;
    int r;
    int v;
} UFO;
int calculateIntrudingUFOs(int R, int N, UFO ufos[]) {
    int intrudingCount = 0;
    for (int i = 0; i < N; i++) {
        int timeToReach = ceil(sqrt(ufos[i].x * ufos[i].x + ufos[i].y * ufos[i].y) / ufos[i].v);
        double distanceAtTime = sqrt((ufos[i].x - ufos[i].v * timeToReach) * (ufos[i].x - ufos[i].v * timeToReach) + 
                                    (ufos[i].y - ufos[i].v * timeToReach) * (ufos[i].y - ufos[i].v * timeToReach));
        if (distanceAtTime <= R + ufos[i].r) {
            intrudingCount++;
        }
    }
    return intrudingCount;
}