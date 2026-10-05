void remove_task(Schedule *schedule, int index) {
    if (index >= 0 && index < schedule->task_count) {
        for (int i = index; i < schedule->task_count - 1; i++) {
            schedule->tasks[i] = schedule->tasks[i + 1];
        }
        schedule->task_count--;
    } else {
        printf("Invalid task index!\n");
    }
}