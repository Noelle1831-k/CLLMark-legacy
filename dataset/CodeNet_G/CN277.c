typedef struct {
    int team;
    int time;
    int scoreChange;
} LogRecord;
int compareTimes(const void *a, const void *b) {
    LogRecord *logA = (LogRecord *)a;
    LogRecord *logB = (LogRecord *)b;
    if (logA->time != logB->time) {
        return logA->time - logB->time;
    }
    return logA->team - logB->team;
}
int main() {
    int N, R, L;
    scanf("%d %d %d", &N, &R, &L);
    LogRecord logs[R];
    for (int i = 0; i < R; i++) {
        scanf("%d %d %d", &logs[i].team, &logs[i].time, &logs[i].scoreChange);
    }
    qsort(logs, R, sizeof(LogRecord), compareTimes);
    int scores[N + 1];
    for (int i = 0; i <= N; i++) scores[i] = 0;
    int currentLead = 1;
    int maxScoreDuration[N + 1];
    for (int i = 0; i <= N; i++) maxScoreDuration[i] = 0;
    int lastSwitchTime = 0;
    for (int i = 0; i < R; i++) {
        int team = logs[i].team;
        if (logs[i].time != lastSwitchTime) {
            maxScoreDuration[currentLead] += logs[i].time - lastSwitchTime;
            lastSwitchTime = logs[i].time;
        }
        scores[team] += logs[i].scoreChange;
        if (scores[team] > scores[currentLead] || (scores[team] == scores[currentLead] && team < currentLead)) {
            currentLead = team;
        }
    }
    maxScoreDuration[currentLead] += L - lastSwitchTime;
    int result = 1;
    int maxDuration = maxScoreDuration[1];
    for (int i = 2; i <= N; i++) {
        if (maxScoreDuration[i] > maxDuration || (maxScoreDuration[i] == maxDuration && i < result)) {
            maxDuration = maxScoreDuration[i];
            result = i;
        }
    }
    printf("%d\n", result);
    return 0;
}