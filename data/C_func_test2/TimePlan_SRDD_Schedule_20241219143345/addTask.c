void addTask(Schedule* schedule, Task task) {
    if (schedule->taskCount < 100) {
        schedule->tasks[schedule->taskCount++] = task;
    }
}