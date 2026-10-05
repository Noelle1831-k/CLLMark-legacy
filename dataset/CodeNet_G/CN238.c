int calculateStudyTime(int target, int sessionCount, int startTimes[], int endTimes[]) {
    int totalStudyTime = 0;
    for (int i = 0; i < sessionCount; i++) {
        totalStudyTime += endTimes[i] - startTimes[i];
    }
    return totalStudyTime;
}
void checkStudyTime(int target, int sessionCount, int startTimes[], int endTimes[]) {
    int totalStudyTime = calculateStudyTime(target, sessionCount, startTimes, endTimes);
    if (totalStudyTime >= target) {
        printf("OK\n");
    } else {
        printf("%d\n", target - totalStudyTime);
    }
}