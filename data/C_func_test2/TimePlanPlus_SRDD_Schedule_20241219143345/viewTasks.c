void viewTasks(const Scheduler *scheduler) {
    for (int i = 0; i < scheduler->taskCount; i++) {
        displayTask(&scheduler->tasks[i]);
    }
}