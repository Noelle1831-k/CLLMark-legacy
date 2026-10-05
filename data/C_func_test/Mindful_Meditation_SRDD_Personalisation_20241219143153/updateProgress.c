void updateProgress() {
    printf("Updating user progress...\n");
    userProgress.sessionsCompleted++;
    userProgress.totalMinutes += preferences.sessionDuration;
    printf("Progress updated: Sessions Completed=%d, Total Minutes=%d\n",
           userProgress.sessionsCompleted, userProgress.totalMinutes);
}