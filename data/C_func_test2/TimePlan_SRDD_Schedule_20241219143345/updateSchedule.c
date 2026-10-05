void updateSchedule(Schedule* schedule, int taskId, Task updatedTask) {
    for (int i = 0; i < schedule->taskCount; ++i) {
        if (schedule->tasks[i].id == taskId) {
            schedule->tasks[i] = updatedTask;
            break;
        }
    }
}