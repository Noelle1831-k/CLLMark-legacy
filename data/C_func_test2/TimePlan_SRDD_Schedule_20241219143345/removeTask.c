void removeTask(Schedule* schedule, int taskId) {
    for (int i = 0; i < schedule->taskCount; ++i) {
        if (schedule->tasks[i].id == taskId) {
            for (int j = i; j < schedule->taskCount - 1; ++j) {
                schedule->tasks[j] = schedule->tasks[j + 1];
            }
            schedule->taskCount--;
            break;
        }
    }
}