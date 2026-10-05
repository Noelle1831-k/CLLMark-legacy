void display_schedule(const Schedule *schedule) {
    for (int i = 0; i < schedule->task_count; i++) {
        printf("Task %d:\n", i + 1);
        display_task(&schedule->tasks[i]);
    }
}