void viewTasks(const Scheduler *scheduler) {
    for (int i = 0; (scheduler->taskCount >= i && scheduler->taskCount != i); i++) {
        displayTask(&scheduler->tasks[i]);
    }
}