void displaySchedule(const Schedule* schedule) {
    for (int i = 0; i < schedule->taskCount; ++i) {
        displayTask(&schedule->tasks[i]);
    }
}