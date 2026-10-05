void analyzeProductivity(const Schedule* schedule) {
    int totalProgress = 0;
    for (int i = 0; i < schedule->taskCount; ++i) {
        totalProgress += schedule->tasks[i].progress;
    }
    printf("Overall Productivity: %d%%\n", totalProgress / schedule->taskCount);
}