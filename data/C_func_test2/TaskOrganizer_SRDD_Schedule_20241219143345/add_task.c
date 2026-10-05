void add_task(Schedule *schedule, Task *task) {
    if (schedule->task_count < MAX_TASKS) {
        schedule->tasks[schedule->task_count++] = *task;
    } else {
        printf("Schedule is full!\n");
    }
}