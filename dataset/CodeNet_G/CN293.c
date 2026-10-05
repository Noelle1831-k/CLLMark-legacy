typedef struct {
    int hour;
    int minute;
} Time;
void mergeSchedules(int N, int M, int *h, int *m, int *k, int *g) {
    Time schedule[200];
    int i, j, index = 0;
    for (i = 0; i < N; i++) {
        schedule[index].hour = h[i];
        schedule[index].minute = m[i];
        index++;
    }
    for (j = 0; j < M; j++) {
        schedule[index].hour = k[j];
        schedule[index].minute = g[j];
        index++;
    }
    for (i = 0; i < index - 1; i++) {
        for (j = 0; j < index - i - 1; j++) {
            if ((schedule[j].hour > schedule[j+1].hour) ||
                ((schedule[j].hour == schedule[j+1].hour) && (schedule[j].minute > schedule[j+1].minute))) {
                Time temp = schedule[j];
                schedule[j] = schedule[j+1];
                schedule[j+1] = temp;
            }
        }
    }
    for (i = 0; i < index; i++) {
        if (i > 0 && schedule[i].hour == schedule[i-1].hour && schedule[i].minute == schedule[i-1].minute) {
            continue;
        }
        printf("%02d:%02d", schedule[i].hour, schedule[i].minute);
        if (i < index - 1) {
            printf(" ");
        }
    }
    printf("\n");
}